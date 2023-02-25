#pragma once
#include "stdafx.h"
#ifndef __PUR_REQ_DO_H__
#define __PUR_REQ_DO_H__

#include "../DoInclude.h"


/*
* �����ݿ� pur_req ��Ӧ
*/

class PurReqDO
{
	// ID
	CC_SYNTHESIZE(string, id, Id);
	// ���ݱ��  
	CC_SYNTHESIZE(string, bill_no, Bill_no);
	// ��������
	CC_SYNTHESIZE(string, bill_date, Bill_date);
	// Դ������
	CC_SYNTHESIZE(string, src_bill_type, Src_bill_type);
	// Դ��id
	CC_SYNTHESIZE(string, src_bill_id, Src_bill_id);
	// Դ����
	CC_SYNTHESIZE(string, src_no, Src_no);
	// �������� 
	CC_SYNTHESIZE(string, subject, Subject);
	// �Ƿ����
	CC_SYNTHESIZE(int, is_rubric, Is_rubric);
	// �ɹ�����
	CC_SYNTHESIZE(string, pur_type, Pur_type);
	// ������
	CC_SYNTHESIZE(string, request_dept, Request_dept);
	// ������
	CC_SYNTHESIZE(string, requester, Requester);
	// ����ʱ��
	CC_SYNTHESIZE(string, request_time, Request_time);
	// ����
	CC_SYNTHESIZE(double, qty, Qty);
	// �ο����
	CC_SYNTHESIZE(double, amt, Amt);
	// �Ѷ�����
	CC_SYNTHESIZE(double, ordered_qty, Ordered_qty);
	// ����
	CC_SYNTHESIZE(string, attachment, Attachment);
	// ��ע
	CC_SYNTHESIZE(string, remark, Remark);
	// �Ƿ��Զ�����
	CC_SYNTHESIZE(int, is_auto, Is_auto);
	// ���ݽ׶Σ������ӿڣ�
	CC_SYNTHESIZE(string, bill_stage, Bill_stage);
	// ������
	CC_SYNTHESIZE(string, approver, Approver);
	// ����ʵ��id
	CC_SYNTHESIZE(string, bpmi_instance_id, Bpmi_instance_id);
	// �����������
	CC_SYNTHESIZE(string, approval_result_type, Approval_result_type);
	// �������
	CC_SYNTHESIZE(string, approval_remark, Approval_remark);
	// �Ƿ���Ч
	CC_SYNTHESIZE(int, is_effective, Is_effective);
	// ��Чʱ��
	CC_SYNTHESIZE(string, effective_time, Effective_time);
	// �Ƿ�ر�
	CC_SYNTHESIZE(int, is_closed, Is_closed);
	// �Ƿ�����
	CC_SYNTHESIZE(int, is_voided, Is_voided);
	// ��������
	CC_SYNTHESIZE(string, sys_org_code, Sys_org_code);
	// ������
	CC_SYNTHESIZE(string, create_by, Create_by);
	// ����ʱ��
	CC_SYNTHESIZE(string, create_time, Create_time);
	// �޸���
	CC_SYNTHESIZE(string, update_by, Update_by);
	// �޸�ʱ��
	CC_SYNTHESIZE(string, update_time, Update_time);
	// �汾
	CC_SYNTHESIZE(int, version, Version);

public:
	PurReqDO()
	{



	}




};


#endif //__PUR_REQ_DO_H__