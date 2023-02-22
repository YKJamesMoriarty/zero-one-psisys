#include "stdafx.h"
#include "PrePayService.h"
#include "../../dao/prepayment/PrepaymentDAO.h"

// ��ҳ��ѯ Ԥ�����뵥��������(�������)
PageVO<PrepaymentBillVO> PrePayService::listAll(const PrepayBillQuery& query)
{
	//�������ض���
	PageVO<PrepaymentBillVO> pages;
	pages.setPageIndex(query.getPageIndex());
	pages.setPageSize(query.getPageSize());

	//��ѯ����������
	PrepaymentDO obj;
	obj.setBill_no(query.getBill_no());
	obj.setBill_date(query.getBill_date());
	PrepaymentDAO dao;
	uint64_t count = dao.count(obj);
	if (count <= 0)
	{
		return pages;
	}

	//��ҳ��ѯ����
	pages.setTotal(count);
	pages.calcPages();
	list<PrepaymentDO> result = dao.selectWithPage(obj, query.getPageIndex(), query.getPageSize());
	list<PrepaymentBillVO> vr;
	for (PrepaymentDO sub : result)
	{
		PrepaymentBillVO vo;
		vo.setId(sub.getId());
		vo.setBill_no(sub.getBill_no());
		vo.setBill_date(sub.getBill_date());
		vo.setAmt(sub.getAmt());
		vr.push_back(vo);
	}
	pages.setRows(vr);
	return pages;
}
// ��ѯָ��������ϸ��Ϣ-ͨ�����ݱ�Ų�ѯ����
PageVO<PrepaymentDetailBillVO> PrePayService::getAll(const PrepayDetailBillQuery& query) {
	PageVO<PrepaymentDetailBillVO> pages;
	//PrepaymentDO obj;
	//obj.setBill_no(query.getBill_no());
	//PrepaymentDAO dao;
	//list <PrepaymentDO> result=dao.selectByBill_no(query.getBill_no());
	//list<PrepaymentDetailBillVO> vr;
	//for (PrepaymentDO sub : result)
	//{
	//	PrepaymentBillVO vo;
	//	vo.setId(vo.getId());
	//	vo.setBill_no(vo.getBill_no());
	//	vo.setBill_date(vo.getBill_date());
	//	vo.setAmt(vo.getAmt());
	//	vr.push_back(vo);
	//}
	//pages.setRows(vr);
	return pages;
}

// ��������
uint64_t PrePayService::saveData(const AddPayDTO& dto)
{
	//��װ����
	PrepaymentDO data;
	data.setBill_no(dto.getBill_no());
	data.setBill_date(dto.getBill_date());
	data.setAmt(dto.getAmt());
	//ִ���������
	PrepaymentDAO dao;
	return dao.insertPrepay(data);
}

// �޸�����
bool PrePayService::updateData(const PrepaymentDTO& dto)
{
	//��װ��������
	PrepaymentDO data;
	data.setId(dto.getId());
	data.setBill_no(dto.getBill_no());
	data.setBill_date(dto.getBill_date());
	data.setAmt(dto.getAmt());
	//ִ�������޸�
	PrepaymentDAO dao;
	return dao.updatePrepay(data) == 1;
}

// ͨ��IDɾ������
bool PrePayService::removeData(uint64_t id)
{
	PrepaymentDAO dao;
	return dao.deleteById(id) == 1;
}

// �޸ĵ���״̬
bool PrePayService::updateStatus(const PayModBillStatusDTO& dto)
{
	//��װ��������
	PrepaymentDO data;
	data.setId(dto.getId());
	data.setBill_no(dto.getBill_no());
	//ִ�������޸�
	PrepaymentDAO dao;
	return dao.updateStatus(data) == 1;
}

// ���浼������