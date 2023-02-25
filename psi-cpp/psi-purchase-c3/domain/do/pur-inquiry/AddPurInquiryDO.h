/*
 Copyright Zero One Star. All rights reserved.

 @Author: huilai
 @Date: 2023/02/19 14:42:15

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

	  https://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
*/
#ifndef _ADD_PUR_INQUIRY_DO_H_
#define _ADD_PUR_INQUIRY_DO_H_
#include "../../GlobalInclude.h"
#include <list>

//�޸ĺ�ɾ��DO
class AddPurInquiryDO
{
	//1ID
	CC_SYNTHESIZE(string, id, Id);
	//2���ݱ��
	CC_SYNTHESIZE(string, bill_no, Bill_no);
	//3��������
	CC_SYNTHESIZE(string, subject, Subject);
	//4���ʽ
	CC_SYNTHESIZE(string, payment_method, Payment_method);
	//5�����ص�
	CC_SYNTHESIZE(string, delivery_place, Delivery_place);
	////6��ϵ��			;
	CC_SYNTHESIZE(string, contact, Contact);
	////7��ϵ�绰	   ;
	CC_SYNTHESIZE(string, phone, Phone);
	////8����			 ;
	CC_SYNTHESIZE(string, fax, Fax);
	////9��������	   ;
	CC_SYNTHESIZE(string, email, Email);
	////10��ע			 ;
	CC_SYNTHESIZE(string, remark, Remark);
	//11���ֵ���(�Ƿ����)
	CC_SYNTHESIZE(int, is_rubric, Is_rubric);
	////12�Զ�����	   ;
	CC_SYNTHESIZE(int, is_auto, Is_auto);
	//13�޸�ʱ��		   ;
	CC_SYNTHESIZE(string, create_time, Create_time);
	//14�޸���			;
	CC_SYNTHESIZE(string, update_by, Update_by);
	////15��Чʱ��	   ;
	CC_SYNTHESIZE(string, effective_time, Effective_time);
	//16���ݽ׶�		   ;
	CC_SYNTHESIZE(string, bill_stage, Bill_stage);
	//17��������
	CC_SYNTHESIZE(string, bill_date, Bill_Date);
public:
	AddPurInquiryDO()
	{

	}

};

#endif // !_ADD_PUR_INQUIRY_DO_H_
