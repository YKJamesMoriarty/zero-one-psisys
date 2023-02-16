#include "stdafx.h"
#include "../../GlobalInclude.h"
#ifndef __ADDPURINQUIRYDTO_H__
#define __ADDPURINQUIRYDTO_H__
//���Ӻ��޸�DTO
class AddPurInquiryDTO
{
	//���ݱ��
	CC_SYNTHESIZE(string, bill_no, Bill_no);
	//��������
	CC_SYNTHESIZE(string, subject, Subject);
	//���ʽ
	CC_SYNTHESIZE(string, payment_method, Payment_method);
	//�����ص�
	CC_SYNTHESIZE(string, deliver_place, Deliver_place);
	////��ϵ��			;
	CC_SYNTHESIZE(string, contact, Contact);
	////��ϵ�绰	   ;
	CC_SYNTHESIZE(string, phone, Phone);
	////����			 ;
	CC_SYNTHESIZE(string, fax, Fax);
	////��������	   ;
	CC_SYNTHESIZE(string, email, Email);
	////��ע			 ;
	CC_SYNTHESIZE(string, remark, Remark);
	//���ֵ���(�Ƿ����)
	CC_SYNTHESIZE(int, is_rubric, Is_rubric);
	////�Զ�����	   ;
	CC_SYNTHESIZE(int, is_auto, Is_auto);
	//�޸�ʱ��		   ;
	CC_SYNTHESIZE(string, create_time, Create_time);
	//�޸���			;
	CC_SYNTHESIZE(string, update_by, Update_by);
	////��Чʱ��	   ;
	CC_SYNTHESIZE(string, effective_time, Effective_time);
	//���ݽ׶�		   ;
	CC_SYNTHESIZE(string, bill_stage, Bill_stage);
	//��������
	CC_SYNTHESIZE(string, bill_date, Bill_Date);
public:
	friend void from_json(const json& j, AddPurInquiryDTO& t)
	{
		BIND_FROM_TO_NORMAL(j, t, subject);
		BIND_FROM_TO_NORMAL(j, t, payment_method);
		BIND_FROM_TO_NORMAL(j, t, deliver_place);
		BIND_FROM_TO_NORMAL(j, t, contact);
		BIND_FROM_TO_NORMAL(j, t, phone);
		BIND_FROM_TO_NORMAL(j, t, fax);
		BIND_FROM_TO_NORMAL(j, t, email);
		BIND_FROM_TO_NORMAL(j, t, remark);
		BIND_FROM_TO_I(j, t, is_rubric);
		BIND_FROM_TO_I(j, t, is_auto);
		BIND_FROM_TO_NORMAL(j, t, create_time);
		BIND_FROM_TO_NORMAL(j, t, update_by);
		BIND_FROM_TO_NORMAL(j, t, effective_time);
		BIND_FROM_TO_NORMAL(j, t, bill_stage);
		BIND_FROM_TO_NORMAL(j, t, bill_date);
	}


};


#endif  //__ADDPURINQUIRYDTO_H__


