#pragma once
#pragma once
#ifndef _QUERYDOCLIST_DO_
#define _QUERYDOCLIST_DO_
#include "../DoInclude.h"

/**
 * �Ƕ���⣬��ѯ������ϸ���ݿ�ʵ����
 */
class QueryDocListDO
{
	//���ݱ��
	CC_SYNTHESIZE(string, bill_no, Bill_no);
	//��������
	CC_SYNTHESIZE(string, bill_date, Bill_date);
	//ҵ����
	CC_SYNTHESIZE(string, op_dept, op_dept);
	//ҵ��Ա
	CC_SYNTHESIZE(string, operatoR, Operator);
	//���ݽ׶�
	CC_SYNTHESIZE(string, bill_stage, Bill_stage);
	//����Ч
	CC_SYNTHESIZE(int, is_effective, Is_effective);
	//�ѹر�
	CC_SYNTHESIZE(int, is_closed, Is_closed);
	//������
	CC_SYNTHESIZE(int, is_voided, Is_voided);
	//��ע
	CC_SYNTHESIZE(string, remark, Remark);
	//��ע
	CC_SYNTHESIZE(int,is_auto, Is_auto);
	//��Чʱ��
	CC_SYNTHESIZE(string, effective_time, Effective_time);
	//������ 
	CC_SYNTHESIZE(string, approver, Approver);
	//�Ƶ���
	CC_SYNTHESIZE(string, create_by, Create_by);
	//�Ƶ�ʱ��
	CC_SYNTHESIZE(string, create_time, Create_time);
	//�Ƶ�����
	CC_SYNTHESIZE(string, sys_org_code, Sys_org_code);
	//�޸�ʱ��
	CC_SYNTHESIZE(string, update_time, Update_time);
	//�޸���
	CC_SYNTHESIZE(string, update_by, Update_by);

public:
	QueryDocListDO() {
		bill_no = "";
		bill_date = "";
		op_dept = "";
		operatoR = "";
		bill_stage = "";
		is_effective = -1;
		is_closed = 1;
		is_voided = -1;
		remark = "";
		is_auto = -1;
		effective_time = "";
		approver = "";
		create_by = "";
		create_time = "";
		sys_org_code = "";
		update_time = "";
		update_by = "";


	}
};

#endif // __QUERYDOC_DO_
