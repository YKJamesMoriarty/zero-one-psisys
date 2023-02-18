#include "stdafx.h"
#ifndef __PAY_INTO_DTO_
#define __PAY_INTO_DTO_

#include "../../GlobalInclude.h"
#include "../FileDTO.h"
//�ļ��ϴ�DTO
class PayIntoDTO : public FileDTO
{
	// ���
	CC_SYNTHESIZE(int, id, Id);
	//��������
	CC_SYNTHESIZE(string, payment_type, Payment_type);
	//��Ӧ��
	CC_SYNTHESIZE(string, supplier_id, Supplier_id);
	//ҵ����
	CC_SYNTHESIZE(string, op_dept, Op_dept);
	//ҵ��Ա
	CC_SYNTHESIZE(string, op, Operator);
	//������
	CC_SYNTHESIZE(string, amt, Amt);
	//�Ѹ����
	CC_SYNTHESIZE(int, paid_amt, Paid_amt);
	//��ע
	CC_SYNTHESIZE(string, remark, Remark);
	//���ݱ��
	CC_SYNTHESIZE(string, bill_no, Bill_no);
	//�����������
	CC_SYNTHESIZE(string, approval_result_type, Approval_result_type);
	//�޸���
	CC_SYNTHESIZE(string, update_by, Update_by);
	//������
	CC_SYNTHESIZE(bool, is_voided, Is_voided);
	//�Ƿ���Ч
	CC_SYNTHESIZE(bool, is_effective, Is_effective);
	//������
	CC_SYNTHESIZE(string, approver, Approver);
	//��������
	CC_SYNTHESIZE(string, bill_date, Bill_date);
	//�Ƿ��Զ�����
	CC_SYNTHESIZE(bool, is_auto, Is_auto);
	//�Ƿ����
	CC_SYNTHESIZE(int, is_rubric, Is_rubric);
	//�Ƶ�����
	CC_SYNTHESIZE(string, sys_org_code, Sys_org_code);
	//�Ƶ�ʱ��
	CC_SYNTHESIZE(string, create_time, Create_time);
	//�Ƶ���
	CC_SYNTHESIZE(string, create_by, Create_by);
	//��Чʱ��
	CC_SYNTHESIZE(string, effective_time, Effective_time);
	//�ѹر�
	CC_SYNTHESIZE(int, is_closed, Is_closed);
	//���ݽ׶�
	CC_SYNTHESIZE(string, bill_stage, Bill_stage);

public:

	friend void from_json(const json& j, PayIntoDTO& t)
	{
		BIND_FROM_TO_I(j, t, id);
		BIND_FROM_TO_NORMAL(j, t, bill_no);
		BIND_FROM_TO_NORMAL(j, t, bill_date);
		BIND_FROM_TO_NORMAL(j, t, supplier_id);
		BIND_FROM_TO_NORMAL(j, t, op_dept);
		BIND_FROM_TO_NORMAL(j, t, op);
		BIND_FROM_TO_D(j, t, payment_type);
		BIND_FROM_TO_NORMAL(j, t, amt);
		BIND_FROM_TO_D(j, t, is_closed);
		BIND_FROM_TO_I(j, t, paid_amt);
		BIND_FROM_TO_NORMAL(j, t, effective_time);
		BIND_FROM_TO_I(j, t, is_effective);
		BIND_FROM_TO_I(j, t, is_voided);
		BIND_FROM_TO_NORMAL(j, t, approval_result_type);
		BIND_FROM_TO_NORMAL(j, t, update_by);
		BIND_FROM_TO_NORMAL(j, t, bill_stage);
		BIND_FROM_TO_NORMAL(j, t, remark);
		BIND_FROM_TO_NORMAL(j, t, approver);
		BIND_FROM_TO_I(j, t, is_auto);
		BIND_FROM_TO_I(j, t, is_rubric);
		BIND_FROM_TO_NORMAL(j, t, create_by);
		BIND_FROM_TO_NORMAL(j, t, create_time);
		BIND_FROM_TO_NORMAL(j, t, sys_org_code);
	}
};


#endif  //__PURINQUIRYINTODTO_H__
