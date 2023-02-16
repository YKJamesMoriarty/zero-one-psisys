#pragma once

#ifndef _PUR_QUOT_INTO_DTO_
#define _PUR_QUOT_INTO_DTO_
#include "../FileDTO.h"
class PurQuotIntoDTO : public FileDTO {

	//���ݱ��
	CC_SYNTHESIZE(string, bill_no, bill_no);
	//��������
	CC_SYNTHESIZE(string, bill_date, bill_date);
	//����Ч
	CC_SYNTHESIZE(int, is_effective, Is_effective);
	//�ѹر�
	CC_SYNTHESIZE(int, is_closed, Is_closed);
	//������
	CC_SYNTHESIZE(int, is_voided, Ss_voided);
	//��������
	CC_SYNTHESIZE(string, subject, subject);
	//���ʽ
	CC_SYNTHESIZE(string, payment_method, payment_method);
	//�����ص�
	CC_SYNTHESIZE(string, delivery_place, delivery_place);
	//��ϵ��
	CC_SYNTHESIZE(string, contact,contact);
	//��ϵ�绰
	CC_SYNTHESIZE(string, phone, phone);
	//����
	CC_SYNTHESIZE(string, fax, fax);
	//�����ʼ�
	CC_SYNTHESIZE(string, email, email);
	//��ע
	CC_SYNTHESIZE(string, remark, remark);
	//����
	CC_SYNTHESIZE(string, attachment, attachment);
public:
	friend void from_json(const json& j, PurQuotIntoDTO& t) { // NOLINT
		BIND_FROM_TO_ULL(j, t, bill_no);
		BIND_FROM_TO_ULL(j, t, bill_date);
		BIND_FROM_TO_I(j, t, is_effective);
		BIND_FROM_TO_I(j, t, is_closed);
		BIND_FROM_TO_I(j, t, is_voided);
		BIND_FROM_TO_ULL(j, t, payment_method);
		BIND_FROM_TO_ULL(j, t, delivery_place);
		BIND_FROM_TO_ULL(j, t, contact);
		BIND_FROM_TO_ULL(j, t, fax);
		BIND_FROM_TO_ULL(j, t, email);
		BIND_FROM_TO_ULL(j, t, remark);
		BIND_FROM_TO_ULL(j, t, attachment);
	}
};

#endif // !




