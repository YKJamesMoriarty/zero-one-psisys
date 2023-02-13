#pragma once
#ifndef _QUERYDOC_DO_
#define __QUERYDOC_DO_
#include "../DoInclude.h"

/**
 * �Ƕ���⣬��ѯ������ϸ���ݿ�ʵ����
 */
class QueryDocDO
{
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
	//��Чʱ��
	CC_SYNTHESIZE(string, effective_time, Effective_time);
    //������ 
	CC_SYNTHESIZE(string, approver, Approver);
	//����ʵ��***
	CC_SYNTHESIZE(string, bpmi_instance_id, Bpmi_instance_id);
	//�Ƶ���*******
	CC_SYNTHESIZE(string, create_by, Create_by);
	//�Ƶ�ʱ��
	CC_SYNTHESIZE(string, create_time, Create_time);
	//�Ƶ�����
	CC_SYNTHESIZE(string, sys_org_code, Sys_org_code);
	//�޸�ʱ��
	CC_SYNTHESIZE(string, update_time, Update_time);
	//�޸���
	CC_SYNTHESIZE(string, update_by, Update_by);
	//�Զ�����
	CC_SYNTHESIZE(int, is_auto, Is_auto);
	//���ֵ���
	CC_SYNTHESIZE(int, is_rubric, Is_rubric);
	//��Ӧ��
	CC_SYNTHESIZE(int,has_rp, Has_rp);
	//��������
	CC_SYNTHESIZE(string, subject, Subject);
	//ҵ����
	CC_SYNTHESIZE(string, op_dept, op_dept);
	//ҵ��Ա
	CC_SYNTHESIZE(string, operatoR, Operator);
	//��⾭��
	CC_SYNTHESIZE(string, handler, Handler);
	//��¼��
	CC_SYNTHESIZE(int, entry_no, Entry_no);
	//����
	CC_SYNTHESIZE(string, material_id, Material_id);
	//����ͺ�
	CC_SYNTHESIZE(string, model, Model);
	//�ֿ�
	CC_SYNTHESIZE(string,warehouse_id, Warehouse_id);
	//��λ
	CC_SYNTHESIZE(string, unit_id, Unit_id);
	//�Ƕ�����
	CC_SYNTHESIZE(double, swell_qty, Swell_qty);
	//�����
	CC_SYNTHESIZE(double, in_cost, In_cost);
	//��ϸ����ע
	CC_SYNTHESIZE(string, remarK, RemarK);
	//�Զ���1
	CC_SYNTHESIZE(string, custom1, Custom1);
	//�Զ���2
	CC_SYNTHESIZE(string, custom2, Custom2);
	//��ע
	CC_SYNTHESIZE(string, remark, Remark);
	//�������
	CC_SYNTHESIZE(string, approval_remark, Approval_remark);
	//�������
	CC_SYNTHESIZE(string, approval_result_type, Approval_result_type);

	
	
	
public:
	QueryDocDO() {
		bill_no = "";
		bill_date = "";
		bill_stage = "";
		is_effective = -1;
		is_closed = -1;
		is_voided = -1;
		effective_time = "";
		approver = "";
		bpmi_instance_id = "";
		create_by = "";
		create_time = "";
		sys_org_code = "";
		update_time = "";
		update_by = "";
		is_auto = -1;
		is_rubric = -1;
		has_rp = -1;
		subject = "";
		op_dept = "";
		operatoR = "";
		handler = "";
		entry_no = 0;
		material_id = "";
		model = "";
		warehouse_id = "";
		unit_id = "";
		swell_qty = 0;
		in_cost = 0;
		remarK = "";
		approval_remark = "";
		custom1 = "";
		custom2 = "";
		remark = "";
		approval_remark = "";
		approval_result_type = "";
	}
};

#endif // __QUERYDOC_DO_