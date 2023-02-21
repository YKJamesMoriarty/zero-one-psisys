#include "stdafx.h"
#include "PyrkService.h"
#include "../../dao/Pyrk/PyrkDao.h"
#include"domain/do/Pyrk/QueryPyrkBillListDo.h"
#include <ctime>
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

int PyrkService::saveData(const PyrkBillDetailDTO& dto, const PayloadDTO& payload)
{
	// ����У�鸨������
	auto f = [](const PyrkBillDetailDTO& dto) {
		for (auto& list : dto.getDetail()) {
			if (list.getEntryNo() < 0 || list.getQty() < 0 || list.getCost() < 0) {
				return true;
			}
		}
		return false;
	};
	// ����У��
	if ((dto.getSave() != 0 && dto.getSave() != 1) || f(dto)) {
		return -1;
	}

	// ����DAO�����
	PyrkDao dao;

	// �ϴ�����
	// ���崫�����ݿ��ڵĸ�������
	string attachment = "";
	for (auto& file : dto.getFiles()) {
		string fileName = dao.insertFile(file);
		if (!fileName.empty()) {
			attachment += fileName;
			attachment += ",";
		}
	}
	int n = attachment.size();

	// ��װ����
	StkIoDO data1;
	data1.setBillNo(dto.getBillNo());
	data1.setBillDate(dto.getBillDate());
	data1.setSubject(dto.getSubject());
	data1.setStockIoType("102");
	data1.setHandler(dto.getHandler());
	data1.setRemark(dto.getRemark());
	data1.setBillStage((dto.getSave() == 0 ? "12" : "14"));
	data1.setAttachment((n != 0 ? attachment.substr(0, n - 1) : ""));
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
	// ִ���������
	uint64_t id = dao.insert(data1);
	if (id == 0) {
		return -2;
	}
	// ��װ��ϸ����
	StkIoEntryDO data2;
	string mid = dao.selectBillIdByBillNo(dto.getBillNo());
	for (auto& entry : dto.getDetail()) {
		data2.setMid(mid);
		data2.setEntryNo(to_string(entry.getEntryNo()));
		data2.setMaterialId(entry.getMaterialId());
		data2.setBatchNo((dto.getBillNo() + "-" + to_string(entry.getEntryNo())));
		data2.setWarehouseId(entry.getWarehouseId());
		data2.setStockIoDirection("1");
		data2.setUnitId(entry.getUnitId());
		data2.setQty(entry.getQty());
		data2.setCost(entry.getCost());
		data2.setRemark(entry.getRemark());
		data2.setCustom1(entry.getCustom1());
		data2.setCustom2(entry.getCustom2());
		if (dao.insert(data2) <= 0) {
			return -3;
		}
	}
	
	return id;
}

int PyrkService::updateApproval(const ApprovalDTO& dto, const PayloadDTO& payload)
{
	return int();
}
