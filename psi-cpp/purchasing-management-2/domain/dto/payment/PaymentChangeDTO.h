#pragma once
#ifndef __PAYMENT_CHANGE_DTO_
#define __PAYMENT_CHANGE_DTO_
#include "../../GlobalInclude.h"
#include "../FileDTO.h"

//�޸Ķ���״̬��DTO ǰ����Ҫ����һ�����ݱ���Լ�״̬�޸���Ϣ
class PaymentChangeDTO {
	// ���
	CC_SYNTHESIZE(string, id, Id);
	// ��������(�ر�/���ر�/����)
	CC_SYNTHESIZE(int, opType, OpType);
	// ���ݱ��
	CC_SYNTHESIZE(string, bill_no, Bill_no);
	// �Ƿ���Ч
	//CC_SYNTHESIZE(bool, is_effective, Is_effective);
	// ��Чʱ��
	//CC_SYNTHESIZE(string, effective_time, effective_time);
	// �Ƿ�ر�
	CC_SYNTHESIZE(bool, is_closed, Is_closed);
	// �Ƿ�����
	CC_SYNTHESIZE(bool, is_voided, Is_voided);
public:
	enum OPS { CLOSE, UNCLOSE, CANCEL }; // ��������ö����
	//��JSONת������
	friend void from_json(const json& j, PaymentChangeDTO& t);
};
#endif // !_PUR_REQ_MOD_BILL_STATUS_DTO_