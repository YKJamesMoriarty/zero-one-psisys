#pragma once

#ifndef __ADD_PUR_INQUIRY_DTO_H__
#define __ADD_PUR_INQUIRY_DTO_H__
#include "../../GlobalInclude.h"
#include "../FileDTO.h"
#include "../IDDTO.h"
#include <list>
#include "AddPurInquiryEntryDTO.h"
//���Ӻ��޸�DTO
class AddPurInquiryDTO : public FileDTO
{
	//ID
	CC_SYNTHESIZE(std::string, id, Id);
	//���ݱ��
	CC_SYNTHESIZE(string, bill_no, Bill_no);
	//��������
	CC_SYNTHESIZE(string, subject, Subject);
	//���ʽ
	CC_SYNTHESIZE(string, payment_method, Payment_method);
	//�����ص�
	CC_SYNTHESIZE(string, delivery_place, Delivery_place);
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
	////��Чʱ��	   ;
	CC_SYNTHESIZE(string, effective_time, Effective_time);
	//�Ƶ�ʱ��
	CC_SYNTHESIZE(string, create_time, Create_time);
	//�Ƶ�����
	CC_SYNTHESIZE(string, sys_org_code, Sys_org_code);
	//���ݽ׶�		   ;
	CC_SYNTHESIZE(string, bill_stage, Bill_stage);
	//��������
	CC_SYNTHESIZE(string, bill_date, Bill_Date);
	//��ϸ
	CC_SYNTHESIZE(list<AddPurInquiryEntryDTO>, detail, Detail);

	/*�޸�ר��*/
	//����Ƿ�ͨ��
	CC_SYNTHESIZE(string, approval_result_type, Approval_result_type);
	//������
	CC_SYNTHESIZE(string, approval_remark, Approval_remark);
	//�޸�ʱ��		   ;
	CC_SYNTHESIZE(string, update_time, Update_time);
	//�޸���			;
	CC_SYNTHESIZE(string, update_by, Update_by);
	//������
	CC_SYNTHESIZE(string, approver, Approver);

public:
	friend void from_json(const json& j, AddPurInquiryDTO& t)
	{
		BIND_FROM_TO_NORMAL(j, t, id);
		BIND_FROM_TO_NORMAL(j, t, bill_no);
		BIND_FROM_TO_NORMAL(j, t, subject);
		BIND_FROM_TO_NORMAL(j, t, payment_method);
		BIND_FROM_TO_NORMAL(j, t, delivery_place);
		BIND_FROM_TO_NORMAL(j, t, contact);
		BIND_FROM_TO_NORMAL(j, t, phone);
		BIND_FROM_TO_NORMAL(j, t, fax);
		BIND_FROM_TO_NORMAL(j, t, email);
		BIND_FROM_TO_NORMAL(j, t, remark);
		BIND_FROM_TO_I(j, t, is_rubric);
		BIND_FROM_TO_I(j, t, is_auto);
		BIND_FROM_TO_NORMAL(j, t, update_time);
		BIND_FROM_TO_NORMAL(j, t, update_by);
		BIND_FROM_TO_NORMAL(j, t, effective_time);
		BIND_FROM_TO_NORMAL(j, t, approver);
		BIND_FROM_TO_NORMAL(j, t, create_time);
		BIND_FROM_TO_NORMAL(j, t, sys_org_code);
		BIND_FROM_TO_NORMAL(j, t, bill_stage);
		BIND_FROM_TO_NORMAL(j, t, bill_date);
		BIND_FROM_TO_NORMAL(j, t, approval_result_type);
		BIND_FROM_TO_NORMAL(j, t, approval_remark);
		BIND_FROM_TO_OBJ(j, t, detail,list<AddPurInquiryEntryDTO>);
	}


};


#endif  //__ADDPURINQUIRYDTO_H__


