#include "stdafx.h"
#include "../../GlobalInclude.h"
#ifndef __PURINQUIRYDO_H__
#define __PURINQUIRYDO_H__
class PurInquiryDO
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
	PurInquiryDO()
	{

	}

};

#endif  //__PURINQUIRYDO_H__