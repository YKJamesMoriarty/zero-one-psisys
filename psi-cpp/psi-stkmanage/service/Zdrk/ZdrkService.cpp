#include "stdafx.h"
#include "ZdrkService.h"
#include "../psi-stkmanage/dao/CommonDAO.h"
#include "../../dao/Zdrk/ZdrkDAO.h"
#include "../../../lib-common/include/SnowFlake.h"
#include "FastDfsClient.h"
#include <ctime>

int ZdrkService::saveBillData(const AddZdrkBillDTO& dto, const PayloadDTO& payload)
{
	// ����У��
	if ((dto.getSave() != 0 && dto.getSave() != 1) ||
		[](const AddZdrkBillDTO& dto) {
			for (auto& list : dto.getDetail()) {
				if (list.getEntryNo() < 0 || list.getQty() < 0 || list.getCost() < 0 || list.getPrice() < 0) {
					return true;
				}
			}
			return false;
		}(dto)) {
		return -1;
	}

	// ����DAO�����
	ZdrkDAO zDao;
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
		cout << fileName << endl;
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
	data1.setStockIoType("198"); // "198":�Ƕ����
	data1.setSupplierId(dto.getSupplier());
	data1.setHandler(dto.getHandler());
	data1.setCost([](const list<ZdrkBillDetailDTO>& details) {
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
	zDao.getSqlSession()->beginTransaction();
	// ִ���������
	uint64_t row = zDao.insert(data1);
	if (row == 0) {//ʧ��
		// �ع�
		zDao.getSqlSession()->rollbackTransaction();
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
		data2.setPrice(entry.getPrice());
		data2.setCost(entry.getCost());
		data2.setRemark(entry.getRemark());
		data2.setCustom1(entry.getCustom1());
		data2.setCustom2(entry.getCustom2());
		if (zDao.insert(data2) == 0) {
			// �ع�
			zDao.getSqlSession()->rollbackTransaction();
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
	zDao.getSqlSession()->commitTransaction();
	return row;
}

int ZdrkService::updateBillData(const ModifyZdrkBillDTO& dto, const PayloadDTO& payload)
{
	// ����У��
	if ((dto.getSave() != 0 && dto.getSave() != 1) ||
		[](const ModifyZdrkBillDTO& dto) {
			for (auto& list : dto.getDetail()) {
				if (list.getEntryNo() < 0 || list.getQty() < 0 || list.getCost() < 0 || list.getPrice() < 0) {
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
	ZdrkDAO zDao;
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
	data1.setSupplierId(dto.getSupplier());
	data1.setHandler(dto.getHandler());
	data1.setCost([](const list<ZdrkBillDetailDTO>& details) {
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

	// ���ɵ�ǰʱ��
	time_t rawtime;
	struct tm* info;
	char buffer[80];
	time(&rawtime);
	info = localtime(&rawtime);
	strftime(buffer, 80, "%Y-%m-%d %H:%M:%S", info);

	data1.setUpdateTime(string(buffer));
	// ����ʼ
	zDao.getSqlSession()->beginTransaction();
	// ִ���������
	uint64_t row = zDao.update(data1);
	if (row == 0) {
		// �ع�
		zDao.getSqlSession()->rollbackTransaction();
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
			data2.setSupplierId(dto.getSupplier());
			data2.setQty(entry.getQty());
			data2.setPrice(entry.getPrice());
			data2.setCost(entry.getCost());
			data2.setRemark(entry.getRemark());
			data2.setCustom1(entry.getCustom1());
			data2.setCustom2(entry.getCustom2());
			auto it = find(oldEntryNo.begin(), oldEntryNo.end(), data2.getEntryNo());
			if (it != oldEntryNo.end()) { // ����ԭ�е���ϸ
				zDao.update(data2);
				oldEntryNo.erase(it);
			}
			else { // ������ϸ
				SnowFlake sf(1, 5);
				data2.setId(to_string(sf.nextId()));
				data2.setMid(cDao.selectBillIdByBillNo(dto.getBillNo()));
				data2.setStockIoDirection("1");
				if (zDao.insert(data2) == 0) {
					// �ع�
					zDao.getSqlSession()->rollbackTransaction();
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
				zDao.deleteDetailById(dto.getBillNo(), entryNo);
			}
		}
	}

	// �ύ
	zDao.getSqlSession()->commitTransaction();
	// ɾ����Ҫɾ���ĸ���
	if (!needDeleteFile.empty()) {
		for (const auto& file : needDeleteFile) {
			client.deleteFile(file);
		}
	}
	return row;
}

int ZdrkService::updateApproval(const ApprovalDTO& dto, const PayloadDTO& payload)
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
	ZdrkDAO dao;
	//// ����ʼ
	//dao.getSqlSession()->beginTransaction();
	// ִ�и�������
	int row = dao.updateApproval(data);
	if (row == 0) {
		return -2;
	}
	return row;
}

int ZdrkService::updateStateToClose(const string& billNo, const PayloadDTO& payload)
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
	ZdrkDAO dao;
	return dao.updateState(data);
}

int ZdrkService::updateStateToUnclose(const string& billNo, const PayloadDTO& payload)
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
	ZdrkDAO dao;
	return dao.updateState(data);
}

int ZdrkService::updateStateToVoid(const string& billNo, const PayloadDTO& payload)
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
	ZdrkDAO dao;
	return dao.updateState(data);
}

int ZdrkService::removeBillById(const string& billNo)
{
	ZdrkDAO pDao;
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
PageVO<QueryZdrkBillListVO> ZdrkService::listZdrkBillList(const QueryZdrkBillListQuery& query)
{
	//�������ض���
	PageVO<QueryZdrkBillListVO> billList;
	StkIoDO obj;

	ZdrkDAO dao;

	list<StkIoDO> result = dao.selectBillList(query);
	list<QueryZdrkBillListVO> vr;
	for (StkIoDO sub : result)
	{
		QueryZdrkBillListVO vo;
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
QueryZdrkBillDetailsVO ZdrkService::getZdrkBillDetails(const QueryZdrkBillDetailsQuery& query)
{
	//�������ض���
	QueryZdrkBillDetailsVO details;

	//
	StkIoDO SIDO;
	SIDO.setBillNo(query.getBillNo());
	StkIoEntryDO SIEDO;
	SIEDO.setBillNo(query.getBillNo());

	ZdrkDAO dao;

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
	list<ZdrkBillEntryVO> vr;
	for (StkIoEntryDO sub : result1)
	{
		ZdrkBillEntryVO vo;
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



	return details;

}
