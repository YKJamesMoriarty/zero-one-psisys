#include "stdafx.h"
#include "PaymentService.h"
#include "../../dao/Payment/PaymentDAO.h"

// ͨ��IDɾ������
bool PaymentService::DePayment(const DePaymentDTO& dto)
{
	//��װ��������
	PaymentDAO dao;
	FinPayReqDO data;
	data.setId(dto.getId());
	data.setBill_no(dto.getBill_no());
	//ִ�������޸�
	if (dto.getId() != "" || dto.getBill_no() != "")
	{
		data.setId(dto.getId());
		return dao.deleteById(data) == 1;
	}
}

// �޸ĵ���״̬
bool PaymentService::ChangePayStatus(const PaymentChangeDTO& dto)
{
	//��װ��������
	FinPayReqDO data;
	data.setId(dto.getId());
	data.setBill_no(dto.getBill_no());
	//ִ�������޸�
	PaymentDAO dao;
	if (dto.getOpType() == PaymentChangeDTO::CLOSE || dto.getOpType() == PaymentChangeDTO::UNCLOSE)
	{
		data.setIs_closed(dto.getIs_closed());
		return dao.ChangeStatusClose(data) == 1;
	}
	else if (dto.getOpType() == PaymentChangeDTO::CANCEL)
	{
		data.setIs_voided(dto.getIs_voided());
		return dao.ChangeStatusCancel(data) == 1;
	}
}

// �������
bool PaymentService::AddPay(const AddPaymentDTO& dto)
{
	//��װ��������
	FinPayReqDO data;
	data.setBill_no(dto.getBill_no());
	data.setId(dto.getId());
	//ִ�������޸�
	PaymentDAO dao;
	if ( dto.getBill_no() != "")
	{
		data.setId(dto.getId());
		return dao.insertPrepay(data) == 1;
	}
}

// ��������
uint64_t PaymentService::saveData(const AddPaymentDTO& dto, const PayloadDTO& payload)
{
	//���Ƚ�����������ӽ����ݿ�
	//��װ��������
	FinPayReqDO data;
	SnowFlake sf(1, 3);
	string id = to_string(sf.nextId());
	string BillNo = dto.getBillNo();
	string time = getTime();
	//�����ǽ���id����ʹ��ѩ���㷨
	data.setId(id);
	//��ȡ������Ϣ
	data.setBillNo(BillNo);
	MODIFY(BillDate);
	MODIFY(RequestDept);
	MODIFY(Requester);
	MODIFY(RequestTime);
	MODIFY(BillStage);
	//��ȡ�û�����Ϣ���˴�Ϊ��Ӷ�������Ϣ
	data.setSysOrgCode(payload.getDepartment());
	data.setCreateBy(payload.getUsername());
	data.setCreateTime(time);
	data.setUpdateBy(payload.getUsername());
	data.setUpdateTime(time);
	//���⴦����
	MODIFY_DEFAULT(Attachment);
	//����Ĭ��ֵʱ�Ĵ���
	MODIFY_DEFAULT(SrcBillType);
	MODIFY_DEFAULT(SrcBillId);
	MODIFY_DEFAULT(SrcNo);
	MODIFY_DEFAULT(Subject);
	MODIFY_DEFAULT(PurType);
	MODIFY_DEFAULT(Qty);
	MODIFY_DEFAULT(Amt);
	MODIFY_DEFAULT(OrderedQty);
	MODIFY_DEFAULT(Remark);
	MODIFY_DEFAULT(Version);
	//ִ�������޸�
	PurReqDAO dao;
	//Ȼ�󽫶�����ϸ��ӽ����ݿ�
	for (PurReqEntryDTO& dto : dto.getDetail()) {
		PurReqEntryAdamDO data;
		//�����ǽ���id����ʹ��ѩ���㷨
		data.setId(to_string(sf.nextId()));
		//���ú���������Ӽ�
		data.setMid(id);
		data.setBillNo(BillNo);
		//���б���ֵ�Ĳ���
		MODIFY(EntryNo);
		MODIFY(MaterialId);
		MODIFY(UnitId);
		MODIFY(Qty);
		MODIFY(OrderedQty);
		//Ĭ��ֵ����
		MODIFY_DEFAULT(SrcBillType);
		MODIFY_DEFAULT(SrcEntryId);
		MODIFY_DEFAULT(SrcNo);
		MODIFY_DEFAULT(TaxRate);
		MODIFY_DEFAULT(SrcNo);
		MODIFY_DEFAULT(Price);
		MODIFY_DEFAULT(Amt);
		MODIFY_DEFAULT(SuggestSupplierId);
		MODIFY_DEFAULT(Remark);
		MODIFY_DEFAULT(Custom1);
		MODIFY_DEFAULT(Custom2);
		MODIFY_DEFAULT(Version);
		dao.insertEntry(data);
	}
	return dao.insert(data);
}