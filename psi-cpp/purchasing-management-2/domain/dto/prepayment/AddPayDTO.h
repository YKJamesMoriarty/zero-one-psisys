#pragma once
#ifndef _ADD_PAY_DTO_
#define _ADD_PAY_DTO_

#include "../../GlobalInclude.h"
#include "AddPayDetailDTO.h"
/**
 * �ɹ�Ԥ������-���Ԥ������-�������
 * �������뵥����fin_payment_req
 */
class AddPayDTO
{
	//------------------ֱ������------------------------
	// ID
	CC_SYNTHESIZE(string, id, Id);
	// ���ݱ��
	CC_SYNTHESIZE(string, bill_no, Bill_no);
	// ��������
	CC_SYNTHESIZE(string, bill_date, Bill_date);
	// ��������
	CC_SYNTHESIZE(string, subject, Subject);
	// ҵ��Ա
	CC_SYNTHESIZE(string, op, Operator);
	// ҵ����
	CC_SYNTHESIZE(string, op_dept, Op_dept);
	// ��Ӧ��
	CC_SYNTHESIZE(string, supplier_id, Supplier_id);
	// ������ע
	CC_SYNTHESIZE(string, remark, At_remark);
	// ����
	CC_SYNTHESIZE(string, attachment, Attachment);
	// ��ϸ
	CC_SYNTHESIZE(std::list<AddPayDetailDTO>, detail, Detail);
	//------------------������------------------------
	// ���ݽ׶�
	CC_SYNTHESIZE(string, bill_stage, Bill_stage);
	// ����Ч
	CC_SYNTHESIZE(bool, is_effective, Is_effective);
	// �ѹر�
	CC_SYNTHESIZE(bool, is_closed, Is_closed);
	// ������
	CC_SYNTHESIZE(bool, is_voided, Is_voided);
	


public:
	// ��JSONת������
	friend void from_json(const json& j, AddPayDTO& t) {
		BIND_FROM_TO_NORMAL(j, t, id);
		BIND_FROM_TO_NORMAL(j, t, bill_no);
		BIND_FROM_TO_NORMAL(j, t, bill_date);
		BIND_FROM_TO_NORMAL(j, t, subject);
		BIND_FROM_TO_NORMAL(j, t, op);
		BIND_FROM_TO_NORMAL(j, t, op_dept);
		BIND_FROM_TO_NORMAL(j, t, supplier_id);
		BIND_FROM_TO_NORMAL(j, t, attachment);
		BIND_FROM_TO_OBJ(j, t, detail, std::list<AddPayDetailDTO>);

		BIND_FROM_TO_NORMAL(j, t, bill_stage);
		BIND_FROM_TO_B(j, t, is_effective);
		BIND_FROM_TO_B(j, t, is_closed);
		BIND_FROM_TO_B(j, t, is_voided);
	}; // NOLINT
	BIND_TO_JSON(AddPayDTO, id, bill_no, bill_date, subject, op, op_dept, supplier_id, remark, attachment, detail, bill_stage, is_effective, is_closed, is_voided);
};

#endif // !_SAMPLE_DTO_