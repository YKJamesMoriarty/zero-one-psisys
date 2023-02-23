#pragma once
#ifndef _PUR_QUOT_FIND_BILL_VO_H_
#define _PUR_QUOT_FIND_BILL_VO_H_
#include "../../GlobalInclude.h"
class PurQuotFindBillVO 
{
	//���ݱ��
	CC_SYNTHESIZE(string, bill_no, Bill_no);
	//��������
	CC_SYNTHESIZE(string, bill_date, Bill_date);
	//��������
	CC_SYNTHESIZE(string, subject, Subject);
	//Դ����
	CC_SYNTHESIZE(string, src_no, Src_no);
	//��Ӧ��
	CC_SYNTHESIZE(string, supplier_id, Supplier_id);
	//��ʱ��Ӧ������
	CC_SYNTHESIZE(string, supplier_name, Supplier_name);
	//��������
	CC_SYNTHESIZE(string, delivery_time, Delivery_time);
	//����
	CC_SYNTHESIZE(double, qty, Qty);
	//���
	CC_SYNTHESIZE(double, amt, Amt);
	//���ݽ׶�
	CC_SYNTHESIZE(string, bill_stage, Bill_stage);
	//����Ч
	CC_SYNTHESIZE(int, is_effective, Is_effective);
	//�ѹر�
	CC_SYNTHESIZE(int, is_closed, Is_closed);
	//������
	CC_SYNTHESIZE(int, is_voided, Is_voided);
	//���ʽ
	CC_SYNTHESIZE(string, payment_method, Payment_method);
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
	//�Զ�����
	CC_SYNTHESIZE(int, is_auto, Is_auto);
	//���ֵ���
	CC_SYNTHESIZE(int, is_rubric, Is_rubric);
	//��Чʱ��
	CC_SYNTHESIZE(string, effective_time, Effective_time);
	//������
	CC_SYNTHESIZE(string, approver, Approver);
	//�Ƶ�ʱ��
	CC_SYNTHESIZE(string, create_time, Create_time);
	//�Ƶ���
	CC_SYNTHESIZE(string, create_by, Create_by);
	//�Ƶ�����
	CC_SYNTHESIZE(string, sys_org_code, Sys_org_code);
	//�޸�ʱ��
	CC_SYNTHESIZE(string, update_time, Update_time);
	//�޸���
	CC_SYNTHESIZE(string, update_by, Update_by);
public:
	// ��JSONת������
	BIND_TO_JSON(PurQuotFindBillVO, bill_no, bill_date, subject, src_no, supplier_id,
		supplier_name, delivery_time, qty, amt, bill_stage, is_effective, is_closed, is_voided,
		payment_method, delivery_place, contact, phone, fax, email, remark, is_auto, is_rubric,
		effective_time, approver, create_time, create_by, sys_org_code, update_time, update_by);
};
#endif // !_PUR_QUOT_FIND_DETAIL_BILL_VO_H_
