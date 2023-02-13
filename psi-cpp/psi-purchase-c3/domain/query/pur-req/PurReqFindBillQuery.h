#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: akun
 @Date: 2023/2/14 00:36:01

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
#ifndef _PUR_RER_FIND_BILL_Query_
#define _PUR_RER_FIND_BILL_Query_

#include "../../GlobalInclude.h"

/*
��ѯ�����б���ʾ����
*/
//��ע
// 1. ��ĺ�������ֶ�������Ҫ����
// 2. from_json������δʵ��
class PurReqFindBillQuery {
	//���ݱ��
	CC_SYNTHESIZE(string, bill_no, Bill_no);
	//��������
	CC_SYNTHESIZE(string, bill_date, Bill_date);
	//��������
	CC_SYNTHESIZE(string, subject, Subject);
	//���ݽ׶�
	CC_SYNTHESIZE(string, bill_stage, Bill_stage);
	//����Ч			
	CC_SYNTHESIZE(int, is_effective, Is_effective);
	//�ѹر�			
	CC_SYNTHESIZE(int, is_close, Is_close);
	//������			
	CC_SYNTHESIZE(int, is_voided, Is_voided);
public:
	// ��JSONת������
	friend void from_json(const json& j, PurReqFindBillQuery& t) {
		//��ʱ��δʵ��
		//BIND_FROM_TO_ULL(j, t, id);
		//BIND_FROM_TO_NORMAL(j, t, name);
		//BIND_FROM_TO_I(j, t, age);
		//BIND_FROM_TO_NORMAL(j, t, sex);
	}
};
#endif // !




