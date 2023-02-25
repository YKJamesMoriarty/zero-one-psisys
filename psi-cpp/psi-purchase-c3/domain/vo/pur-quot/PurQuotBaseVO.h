
//���VO��Ϊ����������VO�Ļ�������
//PurQuotFindDetailBillVO
//PurQuotListVO
//PurQuotDividedListVO
#pragma once
#ifndef _PUR_QUOT_BASE_VO_H_
#define _PUR_QUOT_BASE_VO_H_

#include "../../GlobalInclude.h"
class PurQuotBaseVO {

	//���ݱ��
	CC_SYNTHESIZE(string, bill_no, Bill_no);
	//��������
	CC_SYNTHESIZE(string, bill_date, Bill_date);
	//���ݽ׶�
	CC_SYNTHESIZE(string, bill_stage, Bill_stage);
	//����Ч
	CC_SYNTHESIZE(int, is_effective, Is_effective);
	//�ѹر�
	CC_SYNTHESIZE(int, is_closed, Is_closed);
	//������
	CC_SYNTHESIZE(int, is_voided, Is_voided);
	//��������
	CC_SYNTHESIZE(string, subject, Subject);
	//�ɹ�ѯ�۵�

	//�Ƿ���ʱ��Ӧ��
	CC_SYNTHESIZE(int, is_temp_supplier, Is_temp_supplier);
	//��Ӧ��
	CC_SYNTHESIZE(string, supplier_id, Supplier_id);
	//��ʱ��Ӧ������
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
	//�������
	CC_SYNTHESIZE(string, approval_remark, Approval_remark);
	//����---------------����
	CC_SYNTHESIZE(string, attachment, Attachment);
	//�������
	CC_SYNTHESIZE(string, approval_result_type, Approval_result_type);

	//------------ǰ����Ҫ�����ť��չ���Ĳ���
		//��Чʱ��
	CC_SYNTHESIZE(string, effective_time, Effective_time);
	//������
	CC_SYNTHESIZE(string, approver, Approver);
	//����ʵ��
	CC_SYNTHESIZE(string, bpmi_instance_id, Bpmi_instance_id);
	//�Ƶ�ʱ��
	CC_SYNTHESIZE(string, create_time, Create_time);
	//�Ƶ�����
	CC_SYNTHESIZE(string, sys_org_code, Sys_org_code);
	//�Ƶ���
	CC_SYNTHESIZE(string, create_by, Create_by);
	//�޸�ʱ��
	CC_SYNTHESIZE(string, update_time, Update_time);
	//�޸���
	CC_SYNTHESIZE(string, update_by, Update_by);
	//�Զ�����
	CC_SYNTHESIZE(int, is_auto, Is_auto);
	//���ֵ���
	CC_SYNTHESIZE(int, is_rubric, Is_rubric);
	//Դ������
	CC_SYNTHESIZE(string, src_bill_type, Src_bill_type);
public:
	BIND_TO_JSON(PurQuotBaseVO, bill_no, bill_date, bill_stage, is_effective, is_closed, is_voided,
		subject, is_temp_supplier, supplier_id, supplier_name, payment_method, delivery_time, delivery_place,
		contact, phone, fax, email, remark, approval_remark, attachment, approval_result_type, effective_time,
		approver, bpmi_instance_id, bpmi_instance_id, sys_org_code, create_by, update_time, update_by, is_auto, is_rubric, src_bill_type);
};
#endif