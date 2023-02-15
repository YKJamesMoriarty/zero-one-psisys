#include "stdafx.h"

#include "../../GlobalInclude.h"
#include "../arch-demo/domain/query/PageQuery.h"

#ifndef __PURINQUIRYQUERY_H__
#define __PURINQUIRYQUERY_H__

//�ļ��ϴ�Query
class PurInquiryQurey : public PageQuery
{
	//���ݱ��
	CC_SYNTHESIZE(string, bill_no, Bill_no);
	//��������
	CC_SYNTHESIZE(string, bill_date, Bill_Date);
	//��������
	CC_SYNTHESIZE(string, subject, Subject);
	//Դ����			;
	CC_SYNTHESIZE(string, src_no, Src_no);
	//��������		   ;
	CC_SYNTHESIZE(string, delivery_time, Delivery_time);
	//����			 ;
	CC_SYNTHESIZE(double, qty, Qty);
	//�ο����		   ;
	CC_SYNTHESIZE(double, amt, Amt);
	//���۵���		   ;
	CC_SYNTHESIZE(int, quot_count, Quot_count);
	//���ݽ׶�		   ;
	CC_SYNTHESIZE(string, bill_stage, Bill_stage);
	//����Ч			;
	CC_SYNTHESIZE(int, is_effective, Is_effective)
		//�ѹر�			;
	CC_SYNTHESIZE(int, is_close, Is_close);
	//������			;
	CC_SYNTHESIZE(int, is_voided, Is_voided);
	//�����ص�		   ;
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
	////�Զ�����	   ;
	CC_SYNTHESIZE(int, is_auto, Is_auto);
	////��Чʱ��	   ;
	CC_SYNTHESIZE(string, effective_time, Effective_time);
	//�޸�ʱ��		   ;
	CC_SYNTHESIZE(string, create_time, Create_time);
	//�޸���			;
	CC_SYNTHESIZE(string, update_by, Update_by);

public:

	friend void from_json(const json& j, PurInquiryQurey& t)
	{
		BIND_FROM_TO_NORMAL(j, t, bill_no);
		BIND_FROM_TO_NORMAL(j, t, bill_date);
		BIND_FROM_TO_NORMAL(j, t, subject);
		BIND_FROM_TO_NORMAL(j, t, src_no);
		BIND_FROM_TO_NORMAL(j, t, delivery_time);
		BIND_FROM_TO_D(j, t, qty);
		BIND_FROM_TO_D(j, t, amt);
		BIND_FROM_TO_I(j, t, quot_count);
		BIND_FROM_TO_NORMAL(j, t, bill_stage);
		BIND_FROM_TO_I(j, t, is_effective);
		BIND_FROM_TO_I(j, t, is_close);
		BIND_FROM_TO_I(j, t, is_voided);
		BIND_FROM_TO_NORMAL(j, t, deliver_place);
		BIND_FROM_TO_NORMAL(j, t, contact);
		BIND_FROM_TO_NORMAL(j, t, phone);
		BIND_FROM_TO_NORMAL(j, t, fax);
		BIND_FROM_TO_NORMAL(j, t, email);
		BIND_FROM_TO_NORMAL(j, t, remark);
		BIND_FROM_TO_I(j, t, is_auto);
		BIND_FROM_TO_NORMAL(j, t, effective_time);
		BIND_FROM_TO_NORMAL(j, t, create_time);
		BIND_FROM_TO_NORMAL(j, t, update_by);
	}
};


#endif  //__PURINQUIRYQUERY_H__

