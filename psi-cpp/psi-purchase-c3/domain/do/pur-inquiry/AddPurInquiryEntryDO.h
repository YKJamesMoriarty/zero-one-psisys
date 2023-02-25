#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: huilai
 @Date: 2023/02/20 16:48:09

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
#ifndef _ADDPURINQUIRYENTRYDO_H_
#define _ADDPURINQUIRYENTRYDO_H_
#include "../../GlobalInclude.h"


class AddPurInquiryEntryDO
{
	//Ӧ��������ĵ��ݱ��
	CC_SYNTHESIZE(string, bill_no, Bill_no);
	//��¼��
	CC_SYNTHESIZE(int, entry_no, Entry_no);
	//����
	CC_SYNTHESIZE(std::string, mid, Mid);
	//ID
	CC_SYNTHESIZE(std::string, id, Id);
	//Դ������
	CC_SYNTHESIZE(std::string, src_bill_type, Src_bill_type);
	//Դ����¼��
	CC_SYNTHESIZE(std::string, src_no, Src_no);
	//����
	CC_SYNTHESIZE(std::string, material_id, Material_id);
	//����ͺ�
	//CC_SYNTHESIZE(std::string, model, Model);
	//��λ
	CC_SYNTHESIZE(std::string, unit_id, Unit_id);
	//����
	CC_SYNTHESIZE(double, qty, Qty);
	//˰��
	CC_SYNTHESIZE(double, tax_rate, Tax_rate);
	//�ο���˰����
	CC_SYNTHESIZE(double, price, Price);
	//�ο���˰���
	CC_SYNTHESIZE(double, amt, Amt);
	//��ע
	CC_SYNTHESIZE(std::string, remark, Remark);
	//�Զ���1
	CC_SYNTHESIZE(std::string, custom1, Custom1);
	//�Զ���2
	CC_SYNTHESIZE(std::string, custom2, Custom2);

public:

	AddPurInquiryEntryDO()
	{

	}

};

#endif // !_ADDPURINQUIRYENTRYDO_H_