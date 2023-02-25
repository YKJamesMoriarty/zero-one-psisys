#include "stdafx.h"
#include "PyrkService.h"
#include "../../dao/Pyrk/PyrkDao.h"
#include "../../dao/CommonDAO.h"
#include "../../../lib-common/include/SnowFlake.h"
#include "../../../lib-common/include/StringUtil.h"
#include <ctime>
#include <algorithm>

int PyrkService::saveBillData(const PyrkBillDetailDTO& dto, const PayloadDTO& payload)
{
	// ����У��
	if ((dto.getSave() != 0 && dto.getSave() != 1) ||
		[](const PyrkBillDetailDTO& dto) {
			for (auto& list : dto.getDetail()) {
				if (list.getEntryNo() < 0 || list.getQty() < 0 || list.getCost() < 0) {
					return true;
				}
			}
			return false;
		}(dto)) {
		return -1;
	}

	// ����DAO�����
	PyrkDAO pDao;
	CommonDAO cDao;

	// �ϴ�����
	// ���崫�����ݿ��ڵĸ�������
	string attachment = "";
	for (auto& file : dto.getFiles()) {
		string fileName = cDao.insertAttachment(file);
		if (!fileName.empty()) {
			if (attachment.size() != 0) {
				attachment += ",";
			}
			attachment += fileName;
		}
		else {
			return -4;
		}
	}

	// ��װ����
	StkIoDO data1;
	SnowFlake sf(1, 5);
	string mid = to_string(sf.nextId());
	data1.setId(mid);
	data1.setBillNo(dto.getBillNo());
	data1.setBillDate(dto.getBillDate());
	data1.setSubject(dto.getSubject());
	data1.setStockIoType("102"); // "102":��ӯ���
	data1.setHandler(dto.getHandler());
	data1.setCost([](const list<DetailDTO>& details) {
		double cost = 0;
		for (const auto& entry : details) {
			cost += entry.getCost();
		}
		return cost;
	}(dto.getDetail()));
	data1.setRemark(dto.getRemark());
	data1.setBillStage((dto.getSave() == 0 ? "12" : "14")); // "12":������, "14":������
	data1.setAttachment(attachment);
	data1.setSysOrgCode(cDao.selectOrgCodeByUsername(payload.getUsername()));
	data1.setCreateBy(payload.getUsername());
	// ���ɵ�ǰʱ��
	time_t rawtime;
	struct tm* info;
	char buffer[80];
	time(&rawtime);
	info = localtime(&rawtime);
	strftime(buffer, 80, "%Y-%m-%d %H:%M:%S", info);

	data1.setCreateTime(string(buffer));
	// ����ʼ
	pDao.getSqlSession()->beginTransaction();
	// ִ���������
	uint64_t row = pDao.insert(data1);
	if (row == 0) {
		// �ع�
		pDao.getSqlSession()->rollbackTransaction();
		// ɾ������
		vector<string_view> fileNames = split(attachment, ",");
		if (!fileNames.empty()) {
			for (const auto& file : fileNames) {
				cDao.deleteAttachment(string(file));
			}
		}
		return -2;
	}
	// ��װ��ϸ����
	StkIoEntryDO data2;
	for (auto& entry : dto.getDetail()) {
		data2.setId(to_string(sf.nextId()));
		data2.setMid(mid);
		data2.setBillNo(dto.getBillNo());
		data2.setEntryNo(to_string(entry.getEntryNo()));
		data2.setMaterialId(cDao.selectMaterialIdByAuxName(entry.getMaterial()));
		data2.setBatchNo((dto.getBillNo() + "-" + to_string(entry.getEntryNo())));
		data2.setWarehouseId(cDao.selectWarehouseIdByAuxName(entry.getWarehouse()));
		data2.setStockIoDirection("1");
		data2.setUnitId(cDao.selectUnitIdByName(entry.getUnit()));
		data2.setQty(entry.getQty());
		data2.setCost(entry.getCost());
		data2.setRemark(entry.getRemark());
		data2.setCustom1(entry.getCustom1());
		data2.setCustom2(entry.getCustom2());
		if (pDao.insert(data2) == 0) {
			// �ع�
			pDao.getSqlSession()->rollbackTransaction();
			// ɾ������
			vector<string_view> fileNames = split(attachment, ",");
			if (!fileNames.empty()) {
				for (const auto& file : fileNames) {
					cDao.deleteAttachment(string(file));
				}
			}
			return -3;
		}
	}
	// �ύ
	pDao.getSqlSession()->commitTransaction();
	return row;
}

int PyrkService::updateApproval(const ApprovalDTO& dto, const PayloadDTO& payload)
{
	// ����У��
	if (dto.getApprovalResultType() != 1 && dto.getApprovalResultType() != 2) {
		return -1;
	}
	// ��װ����
	StkIoDO data;
	data.setBillNo(dto.getBillId());
	data.setApprovalResultType(to_string(dto.getApprovalResultType()));
	data.setApprovalRemark(dto.getApprovalRemark());
	data.setApprover(payload.getUsername());
	data.setUpdateBy(payload.getUsername());
	// ���ɵ�ǰʱ��
	time_t rawtime;
	struct tm* info;
	char buffer[80];
	time(&rawtime);
	info = localtime(&rawtime);
	strftime(buffer, 80, "%Y-%m-%d %H:%M:%S", info);

	data.setUpdateTime(string(buffer));
	if (dto.getApprovalResultType() == 1) { // ���ͨ��
		data.setIsEffective(1);
		data.setEffectiveTime(string(buffer));
		data.setIsClosed(1);
		data.setBillStage("34"); // "34":ִ����
	}
	else { // ��˾ܾ�
		data.setBillStage("24"); // "24":������
	}

	// ����DAO�����
	PyrkDAO dao;
	//// ����ʼ
	//dao.getSqlSession()->beginTransaction();
	// ִ�и�������
	int row = dao.updateApproval(data);
	if (row == 0) {
		return -2;
	}
	return row;
}

int PyrkService::updateBillData(const PyrkBillDetailDTO& dto, const PayloadDTO& payload)
{
	// ����У��
	if ((dto.getSave() != 0 && dto.getSave() != 1) || 
		[](const PyrkBillDetailDTO& dto) {
			for (auto& list : dto.getDetail()) {
				if (list.getEntryNo() < 0 || list.getQty() < 0 || list.getCost() < 0) {
					return true;
				}
			}
			return false;
		}(dto)) {
		return -1;
	}

	// ����DAO�����
	PyrkDAO pDao;
	CommonDAO cDao;

	// ��ѯ���ж�Ӧ���ݵĸ�����
	string attachments = cDao.selectAttachmentByBillNo(dto.getBillNo());
	// ������ɾ���ĸ����б�
	list<string> needDeleteFile;
	// �����������ĸ����б�
	list<string> needUploadFile;

	// ��װ����
	StkIoDO data1;
	data1.setBillNo(dto.getBillNo());
	data1.setBillDate(dto.getBillDate());
	data1.setSubject(dto.getSubject());
	data1.setHandler(dto.getHandler());
	data1.setCost([](const list<DetailDTO>& details) {
		double cost = 0;
		for (const auto& entry : details) {
			cost += entry.getCost();
		}
		return cost;
		}(dto.getDetail()));
	data1.setRemark(dto.getRemark());
	data1.setBillStage((dto.getSave() == 0 ? "12" : "14")); // "12":������, "14":������
	data1.setAttachment([&](list<string> files) -> string { // ���¸���
		string result = "";
		// ���ݱ��и������б�
		vector<string_view> fileNames = split(attachments, ",");
		for (const auto& file : files) {
			auto it = find(fileNames.begin(), fileNames.end(), file);
			if (it != fileNames.end()) { // ԭ�еĸ���
				if (!result.empty()) {
					result += ",";
				}
				result += file;
				fileNames.erase(it);
			}
			else { // ��������
				if (!result.empty()) {
					result += ",";
				}
				string f = cDao.insertAttachment(file);
				result += f;
				needUploadFile.push_back(f);
			}
		}
		if (!fileNames.empty()) { // ��¼��Ҫɾ���ĸ���
			for (const auto& file : fileNames) {
				needDeleteFile.push_back(string(file));
			}
		}
		return result;
	}(dto.getFiles()));
	data1.setUpdateBy(payload.getUsername());

	// ���ɵ�ǰʱ��
	time_t rawtime;
	struct tm* info;
	char buffer[80];
	time(&rawtime);
	info = localtime(&rawtime);
	strftime(buffer, 80, "%Y-%m-%d %H:%M:%S", info);

	data1.setUpdateTime(string(buffer));
	// ����ʼ
	pDao.getSqlSession()->beginTransaction();
	// ִ���������
	uint64_t row = pDao.update(data1);
	if (row == 0) {
		// �ع�
		pDao.getSqlSession()->rollbackTransaction();
		// ɾ�������ĸ���
		if (!needUploadFile.empty()) {
			for (const auto& file : needUploadFile) {
				cDao.deleteAttachment(file);
			}
		}
		return -2;
	}

	if (!dto.getDetail().empty()) {
		// ��װ��ϸ����
		StkIoEntryDO data2;
		// ԭ�����ڵ���ϸ��¼��
		list<int> oldEntryNo = cDao.selectEntryNoByBillNo(dto.getBillNo());
		for (auto& entry : dto.getDetail()) {
			data2.setBillNo(dto.getBillNo());
			data2.setEntryNo(to_string(entry.getEntryNo()));
			data2.setMaterialId(cDao.selectMaterialIdByAuxName(entry.getMaterial()));
			data2.setBatchNo((dto.getBillNo() + "-" + to_string(entry.getEntryNo())));
			data2.setWarehouseId(cDao.selectWarehouseIdByAuxName(entry.getWarehouse()));
			data2.setUnitId(cDao.selectUnitIdByName(entry.getUnit()));
			data2.setQty(entry.getQty());
			data2.setCost(entry.getCost());
			data2.setRemark(entry.getRemark());
			data2.setCustom1(entry.getCustom1());
			data2.setCustom2(entry.getCustom2());
			auto it = find(oldEntryNo.begin(), oldEntryNo.end(), atoi(data2.getEntryNo().c_str()));
			if (it != oldEntryNo.end()) { // ����ԭ�е���ϸ
				pDao.update(data2);
				oldEntryNo.erase(it);
			}
			else { // ������ϸ
				SnowFlake sf(1, 5);
				data2.setId(to_string(sf.nextId()));
				data2.setMid(cDao.selectBillIdByBillNo(dto.getBillNo()));
				data2.setStockIoDirection("1");
				if (pDao.insert(data2) == 0) {
					// �ع�
					pDao.getSqlSession()->rollbackTransaction();
					// ɾ�������ĸ���
					if (!needUploadFile.empty()) {
						for (const auto& file : needUploadFile) {
							cDao.deleteAttachment(file);
						}
					}
					return -3;
				}
			}
		}
		if (!oldEntryNo.empty()) {
			for (const auto& entryNo : oldEntryNo) { // ɾ��Ӧ��ɾ������ϸ
				pDao.deleteDetailById(dto.getBillNo(), entryNo);
			}
		}
	}
	
	// �ύ
	pDao.getSqlSession()->commitTransaction();
	// ɾ����Ҫɾ���ĸ���
	if (!needDeleteFile.empty()) {
		for (const auto& file : needDeleteFile) {
			cDao.deleteAttachment(file);
		}
	}
	return row;
}

int PyrkService::updateStateToClose(const string& billNo, const PayloadDTO& payload)
{
	StkIoDO data;
	data.setBillNo(billNo);
	data.setIsClosed(1);
	
	// ���ɵ�ǰʱ��
	time_t rawtime;
	struct tm* info;
	char buffer[80];
	time(&rawtime);
	info = localtime(&rawtime);
	strftime(buffer, 80, "%Y-%m-%d %H:%M:%S", info);

	data.setUpdateTime(buffer);
	data.setUpdateBy(payload.getUsername());
	PyrkDAO dao;
	return dao.updateState(data);
}

int PyrkService::updateStateToUnclose(const string& billNo, const PayloadDTO& payload)
{
	StkIoDO data;
	data.setBillNo(billNo);
	data.setIsClosed(0);

	// ���ɵ�ǰʱ��
	time_t rawtime;
	struct tm* info;
	char buffer[80];
	time(&rawtime);
	info = localtime(&rawtime);
	strftime(buffer, 80, "%Y-%m-%d %H:%M:%S", info);

	data.setUpdateTime(buffer);
	data.setUpdateBy(payload.getUsername());
	PyrkDAO dao;
	return dao.updateState(data);
}

int PyrkService::updateStateToVoid(const string& billNo, const PayloadDTO& payload)
{
	StkIoDO data;
	data.setBillNo(billNo);
	data.setIsVoided(1);

	// ���ɵ�ǰʱ��
	time_t rawtime;
	struct tm* info;
	char buffer[80];
	time(&rawtime);
	info = localtime(&rawtime);
	strftime(buffer, 80, "%Y-%m-%d %H:%M:%S", info);

	data.setUpdateTime(buffer);
	data.setUpdateBy(payload.getUsername());
	PyrkDAO dao;
	return dao.updateState(data);
}

int PyrkService::removeBillById(const string& billNo)
{
	PyrkDAO pDao;
	CommonDAO cDao;
	// ɾ����ϸ
	pDao.deleteDetailById(billNo);
	// ����
	string attachments = cDao.selectAttachmentByBillNo(billNo);
	if (!attachments.empty()) { // ɾ������
		vector<string_view> attachment = split(attachments, ",");
		for (const auto& file : attachment) {
			cDao.deleteAttachment(string(file));
		}
	}
	// ɾ������
	return pDao.deleteBillById(billNo);
}
