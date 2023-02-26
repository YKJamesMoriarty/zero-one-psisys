#pragma once
#ifndef _PUR_REQ_MOD_BILL_STATUS_DTO_
#define _PUR_REQ_MOD_BILL_STATUS_DTO_

#include "../../GlobalInclude.h"
#include "../FileDTO.h"

//�޸Ķ���״̬��DTO ǰ����Ҫ����һ�����ݱ���Լ�״̬�޸���Ϣ
class PayModBillStatusDTO {
	// ���
	CC_SYNTHESIZE(string, id, Id);
	// ���ݱ��
	CC_SYNTHESIZE(string, bill_no, Bill_no);
	// �Ƿ���Ч
	CC_SYNTHESIZE(int, is_effective, Is_effective);
	//��Чʱ��
	CC_SYNTHESIZE(string, effective_time, effective_time);
	// �Ƿ�ر�
	CC_SYNTHESIZE(int, is_closed, Is_closed);
	// �Ƿ�����
	CC_SYNTHESIZE(int, is_voided, Is_voided);
public:
	//��JSONת������
	friend void from_json(const json& j, PayModBillStatusDTO& t);
};
#endif // !_PUR_REQ_MOD_BILL_STATUS_DTO_