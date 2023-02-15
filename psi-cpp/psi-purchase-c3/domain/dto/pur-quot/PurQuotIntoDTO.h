#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: akun
 @Date: 2023/2/14 00:15:01

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
#ifndef _PUR_QUOT_INTO_DTO_
#define _PUR_QUOT_INTO_DTO_
#include "../FileDTO.h"
class PurQuotIntoDTO : public FileDTO {

	//���ݱ��
	CC_SYNTHESIZE(string, bill_no, bill_no);
	//��������
	CC_SYNTHESIZE(string, bill_date, bill_date);
	//����Ч
	CC_SYNTHESIZE(int, is_effective, Is_effective);
	//�ѹر�
	CC_SYNTHESIZE(int, is_closed, Is_closed);
	//������
	CC_SYNTHESIZE(int, is_voided, Ss_voided);
	//��������
	CC_SYNTHESIZE(string, subject, subject);
	//���ʽ
	CC_SYNTHESIZE(string, payment_method, payment_method);
	//�����ص�
	CC_SYNTHESIZE(string, delivery_place, delivery_place);
	//��ϵ��
	CC_SYNTHESIZE(string, contact,contact);
	//��ϵ�绰
	CC_SYNTHESIZE(string, phone, phone);
	//����
	CC_SYNTHESIZE(string, fax, fax);
	//�����ʼ�
	CC_SYNTHESIZE(string, email, email);
	//��ע
	CC_SYNTHESIZE(string, remark, remark);
	//����
	CC_SYNTHESIZE(string, attachment, attachment);
public:
	friend void from_json(const json& j, PurQuotIntoDTO& t) { // NOLINT
		BIND_FROM_TO_ULL(j, t, bill_no);
		BIND_FROM_TO_ULL(j, t, bill_date);
		BIND_FROM_TO_I(j, t, is_effective);
		BIND_FROM_TO_I(j, t, is_closed);
		BIND_FROM_TO_I(j, t, is_voided);
		BIND_FROM_TO_ULL(j, t, payment_method);
		BIND_FROM_TO_ULL(j, t, delivery_place);
		BIND_FROM_TO_ULL(j, t, contact);
		BIND_FROM_TO_ULL(j, t, fax);
		BIND_FROM_TO_ULL(j, t, email);
		BIND_FROM_TO_ULL(j, t, remark);
		BIND_FROM_TO_ULL(j, t, attachment);
	}
};

#endif // !




