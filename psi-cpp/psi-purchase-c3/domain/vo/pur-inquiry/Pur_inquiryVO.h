#include "stdafx.h"
#include "../../GlobalInclude.h"
#include <vector>
#ifndef __PUR_INQUIRYVO_H__
#define __PUR_INQUIRYVO_H__

//չʾvo
 //   class Pur_inquiryVO
 //   {
 //       //���ݱ��
	//		CC_SYNTHESIZE(string, bill_no, Bill_no);
 //       //��������
	//		CC_SYNTHESIZE(string,bill_date,Bill_Date);
 //       //��������
	//		CC_SYNTHESIZE(string,subject,Subject);
 //       //Դ����			;
	//		CC_SYNTHESIZE(string,src_no,Src_no);
	//	//��������		   ;
	//		CC_SYNTHESIZE(string,delivery_time,Delivery_time);
	//	//����			 ;
	//		CC_SYNTHESIZE(double,qty,Qty);
	//	//�ο����		   ;
	//		CC_SYNTHESIZE(double,amt,Amt);
	//	//���۵���		   ;
	//		CC_SYNTHESIZE(int,quot_count,Quot_count);
	//	//���ݽ׶�		   ;
	//		CC_SYNTHESIZE(string,bill_stage,Bill_stage);
	//	//����Ч			;
	//		CC_SYNTHESIZE(int,is_effective,Is_effective)
	//	//�ѹر�			;
	//		CC_SYNTHESIZE(int,is_close,Is_close);
	//	//������			;
	//		CC_SYNTHESIZE(int,is_voided,Is_voided);
	//	//�����ص�		   ;
	//		CC_SYNTHESIZE(string,deliver_place,Deliver_place);
	//	////��ϵ��			;
	//		CC_SYNTHESIZE(string,contact,Contact);
	//	////��ϵ�绰	   ;
	//		CC_SYNTHESIZE(string,phone,Phone);
	//	////����			 ;
	//		CC_SYNTHESIZE(string,fax,Fax);
	//	////��������	   ;
	//		CC_SYNTHESIZE(string,email,Email);
	//	////��ע			 ;
	//		CC_SYNTHESIZE(string,remark,Remark);
	//	////�Զ�����	   ;
	//		CC_SYNTHESIZE(int,is_auto,Is_auto);
	//	////��Чʱ��	   ;
	//		CC_SYNTHESIZE(string,effective_time,Effective_time);
	//	//�޸�ʱ��		   ;
	//		CC_SYNTHESIZE(string,create_time,Create_time);
	//	//�޸���			;
	//		CC_SYNTHESIZE(string,update_by,Update_by);

	//public:
	//	BIND_TO_JSON(Pur_inquiryVO, bill_no, bill_date, subject, src_no, 
	//		delivery_time, qty, amt, quot_count, bill_stage, is_effective
	//		, is_close, is_voided, deliver_place, contact, phone, fax, email
	//		, remark, is_auto, effective_time, create_time, update_by
	//	);
 //   };


	//���ʽ
	class PaymentVO
	{
		CC_SYNTHESIZE(std::vector<string>, payment, Payment);

	public:
		BIND_TO_JSON(PaymentVO, payment);
		PaymentVO()
		{
			payment.push_back(u8"ȫ�����");
			payment.push_back(u8"������ȫ��");
			payment.push_back(u8"��Ʊ����ȫ��");
			payment.push_back(u8"��Ʊ������� ");
		}
	};


#endif  //__PUR_INQUIRYVO_H__
