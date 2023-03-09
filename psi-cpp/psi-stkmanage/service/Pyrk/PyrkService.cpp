#include "stdafx.h"
#include "PyrkService.h"
#include "../../dao/Pyrk/PyrkDAO.h"
#include "../../dao/CommonDAO.h"
#include "FastDfsClient.h"
#include "../../../lib-common/include/SnowFlake.h"
#include "../../../lib-common/include/StringUtil.h"
#include "../../../lib-common/include/SimpleDateTimeFormat.h"
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
	
#ifdef LINUX
	// ����ͻ��˶���
	FastDfsClient client("conf/client.conf", 3);
#else
	// ����ͻ��˶���
	FastDfsClient client("1.15.240.108");
#endif

	// ���崫�����ݿ��ڵĸ�������
	string attachment = "";
	for (auto& file : dto.getFiles()) {
		string fileName = client.uploadFile(file);
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
	data1.setCreateTime(SimpleDateTimeFormat::format());
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
				client.deleteFile(string(file));
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
		data2.setEntryNo(entry.getEntryNo());
		data2.setMaterialId(entry.getMaterial());
		data2.setBatchNo((dto.getBillNo() + "-" + to_string(entry.getEntryNo())));
		data2.setWarehouseId(entry.getWarehouse());
		data2.setStockIoDirection("1");
		data2.setUnitId(entry.getUnit());
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
					client.deleteFile(string(file));
				}
			}
			return -3;
		}
	}
	// �ύ
	pDao.getSqlSession()->commitTransaction();
	return (int)row;
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
	string time = SimpleDateTimeFormat::format();
	data.setUpdateTime(time);
	if (dto.getApprovalResultType() == 1) { // ���ͨ��
		data.setIsEffective(1);
		data.setEffectiveTime(time);
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

#ifdef LINUX
	// ����ͻ��˶���
	FastDfsClient client("conf/client.conf", 3);
#else
	// ����ͻ��˶���
	FastDfsClient client("1.15.240.108");
#endif


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
				string f = client.uploadFile(file);
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
	data1.setUpdateTime(SimpleDateTimeFormat::format());
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
				client.deleteFile(file);
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
			data2.setEntryNo(entry.getEntryNo());
			data2.setMaterialId(entry.getMaterial());
			data2.setBatchNo((dto.getBillNo() + "-" + to_string(entry.getEntryNo())));
			data2.setWarehouseId(entry.getWarehouse());
			data2.setUnitId(entry.getUnit());
			data2.setQty(entry.getQty());
			data2.setCost(entry.getCost());
			data2.setRemark(entry.getRemark());
			data2.setCustom1(entry.getCustom1());
			data2.setCustom2(entry.getCustom2());
			auto it = find(oldEntryNo.begin(), oldEntryNo.end(), data2.getEntryNo());
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
							client.deleteFile(file);
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
			client.deleteFile(file);
		}
	}
	return (int)row;
}

int PyrkService::updateStateToClose(const string& billNo, const PayloadDTO& payload)
{
	StkIoDO data;
	data.setBillNo(billNo);
	data.setIsClosed(1);
	data.setUpdateTime(SimpleDateTimeFormat::format());
	data.setUpdateBy(payload.getUsername());
	PyrkDAO dao;
	return dao.updateState(data);
}

int PyrkService::updateStateToUnclose(const string& billNo, const PayloadDTO& payload)
{
	StkIoDO data;
	data.setBillNo(billNo);
	data.setIsClosed(0);
	data.setUpdateTime(SimpleDateTimeFormat::format());
	data.setUpdateBy(payload.getUsername());
	PyrkDAO dao;
	return dao.updateState(data);
}

int PyrkService::updateStateToVoid(const string& billNo, const PayloadDTO& payload)
{
	StkIoDO data;
	data.setBillNo(billNo);
	data.setIsVoided(1);
	data.setUpdateTime(SimpleDateTimeFormat::format());
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

#ifdef LINUX
	// ����ͻ��˶���
	FastDfsClient client("conf/client.conf", 3);
#else
	// ����ͻ��˶���
	FastDfsClient client("1.15.240.108");
#endif

	string attachments = cDao.selectAttachmentByBillNo(billNo);
	if (!attachments.empty()) { // ɾ������
		vector<string_view> attachment = split(attachments, ",");
		for (const auto& file : attachment) {
			client.deleteFile(string(file));
		}
	}
	// ɾ������
	return pDao.deleteBillById(billNo);
}


//��ѯ�����б�
PageVO<QueryPyrkBillListVO> PyrkService::listPyrkBillList(const QueryPyrkBillListQuery& query)
{
	//�������ض���
	PageVO<QueryPyrkBillListVO> billList;

	PyrkDAO dao;



	list<StkIoDO> result = dao.selectBillList(query);
	list<QueryPyrkBillListVO> vr;
	for (StkIoDO sub : result)
	{
		QueryPyrkBillListVO vo;
		vo.setId(sub.getId());
		vo.setBillNo(sub.getBillNo());
		vo.setBillDate(sub.getBillDate());
		vo.setSrcBillType(sub.getSrcBillType());
		vo.setSrcBillId(sub.getSrcBillId());
		vo.setSrcNo(sub.getSrcNo());
		vo.setSubject(sub.getSubject());
		vo.setIsRubric(sub.getIsRubric());
		vo.setStockIoType(sub.getStockIoType());
		vo.setOpDept(sub.getOpDept());
		vo.setOperator1(sub.getOperator1());
		vo.setHandler(sub.getHandler());
		vo.setHasRp(sub.getHasRp());
		vo.setHasSwell(sub.getHasSwell());
		vo.setSupplierId(sub.getSupplierId());
		vo.setCustomerId(sub.getCustomerId());
		vo.setInvoiceType(sub.getInvoiceType());
		vo.setCost(sub.getCost());
		vo.setSettleAmt(sub.getSettleAmt());
		vo.setSettledAmt(sub.getSettledAmt());
		vo.setInvoicedAmt(sub.getInvoicedAmt());
		vo.setAttachment(sub.getAttachment());
		vo.setRemark(sub.getRemark());
		vo.setIsAuto(sub.getIsAuto());
		vo.setBillStage(sub.getBillStage());
		vo.setApprover(sub.getApprover());
		vo.setBpmiInstanceId(sub.getBpmiInstanceId());
		vo.setApprovalResultType(sub.getApprovalResultType());
		vo.setApprovalRemark(sub.getApprovalRemark());
		vo.setIsEffective(sub.getIsEffective());
		vo.setEffectiveTime(sub.getEffectiveTime());
		vo.setIsClosed(sub.getIsClosed());
		vo.setIsVoided(sub.getIsVoided());
		vo.setSysOrgCode(sub.getSysOrgCode());
		vo.setCreateBy(sub.getCreateBy());
		vo.setCreateTime(sub.getCreateTime());
		vo.setUpdateBy(sub.getUpdateBy());
		vo.setUpdateTime(sub.getUpdateTime());
		vo.setVersion(sub.getVersion());

		vr.push_back(vo);
	}
	billList.setRows(vr);

	return billList;
}

//��ѯ������ϸ��Ϣ
QueryPyrkBillDetailsVO PyrkService::getPyrkBillDetails(const QueryPyrkBillDetailsQuery& query)
{
	//�������ض���
	QueryPyrkBillDetailsVO details;

	//
	StkIoDO SIDO;
	SIDO.setBillNo(query.getBillNo());
	StkIoEntryDO SIEDO;
	SIEDO.setBillNo(query.getBillNo());

	PyrkDAO dao;

	list<StkIoDO> result = dao.selectBillListByBillNo(query.getBillNo());

	for (StkIoDO sub : result)
	{
		details.setId(sub.getId());
		details.setBillNo(sub.getBillNo());
		details.setBillDate(sub.getBillDate());
		details.setSrcBillType(sub.getSrcBillType());
		details.setSrcBillId(sub.getSrcBillId());
		details.setSrcNo(sub.getSrcNo());
		details.setSubject(sub.getSubject());
		details.setIsRubric(sub.getIsRubric());
		details.setStockIoType(sub.getStockIoType());
		details.setOpDept(sub.getOpDept());
		details.setOperator1(sub.getOperator1());
		details.setHandler(sub.getHandler());
		details.setHasRp(sub.getHasRp());
		details.setHasSwell(sub.getHasSwell());
		details.setSupplierId(sub.getSupplierId());
		details.setCustomerId(sub.getCustomerId());
		details.setInvoiceType(sub.getInvoiceType());
		details.setCost(sub.getCost());
		details.setSettleAmt(sub.getSettleAmt());
		details.setSettledAmt(sub.getSettledAmt());
		details.setInvoicedAmt(sub.getInvoicedAmt());
		details.setAttachment(sub.getAttachment());
		details.setRemark(sub.getRemark());
		details.setIsAuto(sub.getIsAuto());
		details.setBillStage(sub.getBillStage());
		details.setApprover(sub.getApprover());
		details.setBpmiInstanceId(sub.getBpmiInstanceId());
		details.setApprovalResultType(sub.getApprovalResultType());
		details.setApprovalRemark(sub.getApprovalRemark());
		details.setIsEffective(sub.getIsEffective());
		details.setEffectiveTime(sub.getEffectiveTime());
		details.setIsClosed(sub.getIsClosed());
		details.setIsVoided(sub.getIsVoided());
		details.setSysOrgCode(sub.getSysOrgCode());
		details.setCreateBy(sub.getCreateBy());
		details.setCreateTime(sub.getCreateTime());
		details.setUpdateBy(sub.getUpdateBy());
		details.setUpdateTime(sub.getUpdateTime());
		details.setVersion(sub.getVersion());
	}


	list<StkIoEntryDO> result1 = dao.selectBillDetails(query.getBillNo());
	list<PyrkBillEntryVO> vr;
	for (StkIoEntryDO sub : result1)
	{
		PyrkBillEntryVO vo;
		vo.setBatchNo(sub.getBatchNo());
		vo.setBillNo(sub.getBillNo());
		vo.setCost(sub.getCost());
		vo.setCustom1(sub.getCustom1());
		vo.setCustom2(sub.getCustom2());
		vo.setDiscountRate(sub.getDiscountRate());
		vo.setEntryNo(sub.getEntryNo());
		vo.setExpense(sub.getExpense());
		vo.setInvoicedAmt(sub.getInvoicedAmt());
		vo.setInvoicedQty(sub.getInvoicedQty());
		vo.setMaterialId(sub.getMaterialId());
		vo.setMid(sub.getMid());
		vo.setPrice(sub.getPrice());
		vo.setQty(sub.getQty());
		vo.setRemark(sub.getRemark());
		vo.setSettleAmt(sub.getSettleAmt());
		vo.setSettleQty(sub.getSettleQty());
		vo.setSrcBillId(sub.getSrcBillId());
		vo.setSrcBillType(sub.getSrcBillType());
		vo.setSrcBillType(sub.getSrcBillType());
		vo.setSrcNo(sub.getSrcNo());
		vo.setStockIoDirection(sub.getStockIoDirection());
		vo.setSupplierId(sub.getSupplierId());
		vo.setSwellQty(sub.getSwellQty());
		vo.setTax(sub.getTax());
		vo.setTaxRate(sub.getTaxRate());
		vo.setUnitId(sub.getUnitId());
		vo.setVersion(sub.getVersion());
		vo.setWarehouseId(sub.getWarehouseId());

		vr.push_back(vo);
	}
	details.setEntry(vr);

	PyrkDAO CDAO;

	return details;

}
