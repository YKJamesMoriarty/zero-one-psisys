#pragma once
#ifndef _PUR_QUOT_INTO_VO_H_
#define _PUR_QUOT_INTO_VO_H_
#include "../../GlobalInclude.h"
class PurQuotIntoVO
{
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
	CC_SYNTHESIZE(string, entry_material_id, Entry_material_id);
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
	// ��JSONת������
	BIND_TO_JSON(PurQuotIntoVO, bill_date, subject, pur_inquiry_bill_no, is_temp_supplier, supplier_name, payment_method, 
		delivery_time, delivery_place, contact, phone, fax,email, remark, attachment,
		entry_src_no, entry_material_id, entry_unit_id, entry_qty, entry_tax_rate, entry_price, entry_discount_rate, entry_amt, entry_remark,
		entry_custom1, entry_custom2);
};
#endif

