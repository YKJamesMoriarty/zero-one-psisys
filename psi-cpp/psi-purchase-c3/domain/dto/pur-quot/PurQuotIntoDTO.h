#pragma once
#ifndef _PUR_QUOT_INTO_DTO_H_
#define _PUR_QUOT_INTO_DTO_H_
#include "../FileDTO.h"

class PurQuotIntoDTO : public FileDTO {

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
//-----------------��ϸ��ʼ
//Դ����¼��
	CC_SYNTHESIZE(string, entry_src_no, Entry_src_no);
	//����
	CC_SYNTHESIZE(string, entry_material_id,Entry_material_id);
	//����ͺ�
	//��λ
	CC_SYNTHESIZE(string, entry_unit_id, Entry_unit_id);
	//����
	CC_SYNTHESIZE(string, entry_qty, Entry_qty);
	//˰��
	CC_SYNTHESIZE(string, entry_tax_rate, Entry_tax_rate);
	//��˰����
	CC_SYNTHESIZE(string, entry_price, Entry_price);
	//�ۿ���
	CC_SYNTHESIZE(string, entry_discount_rate, Entry_discount_rate);
	//��˰���
	CC_SYNTHESIZE(string, entry_amt, Entry_amt);
	//��ע
	CC_SYNTHESIZE(string, entry_remark, Entry_remark);
	//�Զ���1
	CC_SYNTHESIZE(string, entry_custom1, Entry_custom1);
	//�Զ���2
	CC_SYNTHESIZE(string, entry_custom2, Entry_custom2);
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
		BIND_FROM_TO_NORMAL(j, t, attachment);
		BIND_FROM_TO_NORMAL(j, t, entry_src_no);
		BIND_FROM_TO_NORMAL(j, t, entry_material_id);
		BIND_FROM_TO_NORMAL(j, t, entry_unit_id);
		BIND_FROM_TO_NORMAL(j, t, entry_qty);
		BIND_FROM_TO_NORMAL(j, t, entry_tax_rate);
		BIND_FROM_TO_NORMAL(j, t, entry_price);
		BIND_FROM_TO_NORMAL(j, t, entry_discount_rate);
		BIND_FROM_TO_NORMAL(j, t, entry_amt);
		BIND_FROM_TO_NORMAL(j, t, entry_remark);
		BIND_FROM_TO_NORMAL(j, t, entry_custom1);
		BIND_FROM_TO_NORMAL(j, t, entry_custom2);
	}
};

#endif // !
