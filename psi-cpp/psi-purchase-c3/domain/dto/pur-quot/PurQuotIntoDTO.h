#pragma once
#ifndef _PUR_QUOT_INTO_DTO_H_
#define _PUR_QUOT_INTO_DTO_H_
#include "../FileDTO.h"
class PurQuotIntoDTO : public FileDTO {

	//���ݱ��,����Ч, �ѹر�,������---�������Զ�����, ���ɸ���
	//��������, �Ƿ���ʱ��Ӧ��---�������Զ�����, ���Ը���

	//��������
	CC_SYNTHESIZE(string, bill_date, Bill_date);
	//��������
	CC_SYNTHESIZE(string, subject, Subject)
	//�ɹ�ѯ�۵����--pur-inquiry������ֶ�
		CC_SYNTHESIZE(string, pur_inquiry_bill_no, Pur_inquiry_bill_no)
	//�Ƿ���ʱ��Ӧ��
	CC_SYNTHESIZE(string, is_temp_supplier, Is_temp_supplier);
	//��Ӧ��/��ʱ��Ӧ����
	CC_SYNTHESIZE(string, supplier_name, Supplier_name);
	//���ʽ
	CC_SYNTHESIZE(string, payment_method, Payment_method);
	//��������
	CC_SYNTHESIZE(string, delivery_time, Delivery_time);
	//�����ص�
	CC_SYNTHESIZE(string, delivery_place, Delivery_place);
	//��ϵ��
	CC_SYNTHESIZE(string, contact, Contact);
	//��ϵ�绰
	CC_SYNTHESIZE(string, phone, Phone);
	//����
	CC_SYNTHESIZE(string, fax, Fax);
	//�����ʼ�
	CC_SYNTHESIZE(string, email, Email);
	//��ע
	CC_SYNTHESIZE(string, remark, Remark);
	//����
	CC_SYNTHESIZE(string, attachment, Attachment);
public:
	friend void from_json(const json& j, PurQuotIntoDTO& t) { // NOLINT
		BIND_FROM_TO_NORMAL(j, t, bill_date);
		BIND_FROM_TO_NORMAL(j, t, subject);
		BIND_FROM_TO_NORMAL(j, t, pur_inquiry_bill_no);
		BIND_FROM_TO_NORMAL(j, t, is_temp_supplier);
		BIND_FROM_TO_NORMAL(j, t, supplier_name);
		BIND_FROM_TO_NORMAL(j, t, payment_method);
		BIND_FROM_TO_NORMAL(j, t, delivery_time);
		BIND_FROM_TO_NORMAL(j, t, delivery_place);
		BIND_FROM_TO_NORMAL(j, t, contact);
		BIND_FROM_TO_NORMAL(j, t, phone);
		BIND_FROM_TO_NORMAL(j, t, fax);
		BIND_FROM_TO_NORMAL(j, t, email);
		BIND_FROM_TO_NORMAL(j, t, remark);
		BIND_FROM_TO_NORMAL(j, t, remark);


	}
};

#endif // !
