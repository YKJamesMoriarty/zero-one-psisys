#include "stdafx.h"
#include "PyrkService.h"
#include "../../dao/Pyrk/PyrkDao.h"
#include"domain/do/Pyrk/QueryPyrkBillListDo.h"
#include "../../../lib-common/include/SnowFlake.h"
#include "../../../lib-common/include/StringUtil.h"
#include <ctime>
#include <algorithm>
//#include "../../dao/sample/SampleDAO.h"
PageVO<QueryPyrkBillListVO> PyrkService::queryAllFitBill(const QueryPyrkBillListQuery& query) {
	//�������ض���
	PageVO<QueryPyrkBillListVO> pages;
	pages.setPageIndex(query.getPageIndex());
	pages.setPageSize(query.getPageSize());

	//��ѯ����������
	QueryPyrkBillListDo obj; //���ǲ�ѯ���ݿ������  ��װ����
	obj.setId(query.getId());
	obj.setBeginData(query.getBeginData());
	obj.setEndData(query.getEndData());
	obj.setTheme(query.getTheme());
	obj.setStage(query.getStage());
	obj.setIsClosed(query.getIsClosed());
	obj.setIsEffective(query.getIsEffective());
	obj.setIsVoided(query.getIsVoided());
	//SampleDAO dao;
	return pages;
}

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
	PyrkDao dao;

	// �ϴ�����
	// ���崫�����ݿ��ڵĸ�������
	string attachment = "";
	for (auto& file : dto.getFiles()) {
		string fileName = dao.insertAttachment(file);
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
	data1.setId(to_string(sf.nextId()));
	data1.setBillNo(dto.getBillNo());
	data1.setBillDate(dto.getBillDate());
	data1.setSubject(dto.getSubject());
	data1.setStockIoType("102"); // "102":��ӯ���
	data1.setHandler(dto.getHandler());
	data1.setRemark(dto.getRemark());
	data1.setBillStage((dto.getSave() == 0 ? "12" : "14")); // "12":������, "14":������
	data1.setAttachment(attachment);
	data1.setSysOrgCode(dao.selectOrgCodeByUsername(payload.getUsername()));
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
	dao.getSqlSession()->beginTransaction();
	// ִ���������
	uint64_t row = dao.insert(data1);
	if (row == 0) {
		// �ع�
		dao.getSqlSession()->rollbackTransaction();
		// ɾ������
		vector<string_view> fileNames = split(attachment, ",");
		for (const auto& file : fileNames) {
			dao.deleteAttachment(string(file));
		}
		return -2;
	}
	// ��װ��ϸ����
	StkIoEntryDO data2;
	string mid = dao.selectBillIdByBillNo(dto.getBillNo());
	for (auto& entry : dto.getDetail()) {
		data2.setId(to_string(sf.nextId()));
		data2.setMid(mid);
		data2.setBillNo(dto.getBillNo());
		data2.setEntryNo(to_string(entry.getEntryNo()));
		data2.setMaterialId(dao.selectMaterialIdByAuxName(entry.getMaterial()));
		data2.setBatchNo((dto.getBillNo() + "-" + to_string(entry.getEntryNo())));
		data2.setWarehouseId(dao.selectWarehouseIdByAuxName(entry.getWarehouse()));
		data2.setStockIoDirection("1");
		data2.setUnitId(dao.selectUnitIdByName(entry.getUnit()));
		data2.setQty(entry.getQty());
		data2.setCost(entry.getCost());
		data2.setRemark(entry.getRemark());
		data2.setCustom1(entry.getCustom1());
		data2.setCustom2(entry.getCustom2());
		if (dao.insert(data2) == 0) {
			// �ع�
			dao.getSqlSession()->rollbackTransaction();
			// ɾ������
			vector<string_view> fileNames = split(attachment, ",");
			for (const auto& file : fileNames) {
				dao.deleteAttachment(string(file));
			}
			return -3;
		}
	}
	// �ύ
	dao.getSqlSession()->commitTransaction();
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
	PyrkDao dao;
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
	PyrkDao dao;

	// ��ѯ���ж�Ӧ���ݵĸ�����
	string attachments = dao.selectAttachmentByBillNo(dto.getBillNo());
	// ������ɾ���ĸ����б�
	list<string> needDeleteFile;
	// �����������ĸ����б�
	list<string> needUploadFile;

	// ��װ����
	StkIoDO data1;
	SnowFlake sf(1, 5);
	data1.setId(to_string(sf.nextId()));
	data1.setBillNo(dto.getBillNo());
	data1.setBillDate(dto.getBillDate());
	data1.setSubject(dto.getSubject());
	data1.setStockIoType("102"); // "102":��ӯ���
	data1.setHandler(dto.getHandler());
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
				string f = dao.insertAttachment(file);
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
	data1.setSysOrgCode(dao.selectOrgCodeByUsername(payload.getUsername()));
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
	dao.getSqlSession()->beginTransaction();
	// ִ���������
	uint64_t row = dao.update(data1);
	if (row == 0) {
		// �ع�
		dao.getSqlSession()->rollbackTransaction();
		// ɾ�������ĸ���
		for (const auto& file : needUploadFile) {
			dao.deleteAttachment(file);
		}
		return -2;
	}
	// ��װ��ϸ����
	StkIoEntryDO data2;
	string mid = dao.selectBillIdByBillNo(dto.getBillNo());
	for (auto& entry : dto.getDetail()) {
		data2.setId(to_string(sf.nextId()));
		data2.setMid(mid);
		data2.setBillNo(dto.getBillNo());
		data2.setEntryNo(to_string(entry.getEntryNo()));
		data2.setMaterialId(dao.selectMaterialIdByAuxName(entry.getMaterial()));
		data2.setBatchNo((dto.getBillNo() + "-" + to_string(entry.getEntryNo())));
		data2.setWarehouseId(dao.selectWarehouseIdByAuxName(entry.getWarehouse()));
		data2.setStockIoDirection("1");
		data2.setUnitId(dao.selectUnitIdByName(entry.getUnit()));
		data2.setQty(entry.getQty());
		data2.setCost(entry.getCost());
		data2.setRemark(entry.getRemark());
		data2.setCustom1(entry.getCustom1());
		data2.setCustom2(entry.getCustom2());
		if (dao.update(data2) == 0) {
			// �ع�
			dao.getSqlSession()->rollbackTransaction();
			// ɾ�������ĸ���
			for (const auto& file : needUploadFile) {
				dao.deleteAttachment(file);
			}
			return -3;
		}
	}
	// �ύ
	dao.getSqlSession()->commitTransaction();
	// ɾ����Ҫɾ���ĸ���
	for (const auto& file : needDeleteFile) {
		dao.deleteAttachment(file);
	}
	return row;
}
