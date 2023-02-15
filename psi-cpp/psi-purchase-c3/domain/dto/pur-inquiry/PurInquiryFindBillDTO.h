#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: Eleanor
 @Date: 2023/2/15 14:42

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
#ifndef _PUR_INQUIRY_FIND_BILL_DTO_
#define _PUR_INQUIRY_FIND_BILL_DTO_

#include "../../GlobalInclude.h"

/**
 * ������� ���� �ɹ�ѯ�۵���ѯ��Ϣ�б�
 */

//�ɹ�ѯ�۵��б�
class PurInquiryFindBillDTO: public PayloadDTO
{
//���������� - ������Ϣstring
	//���ݱ��
	CC_SYNTHESIZE(string, purInquiryBillNo, PurInquiryBillNo);
	//��������
	CC_SYNTHESIZE(string, purInquiryBillDate, PurInquiryBillDate);
	//��������
	CC_SYNTHESIZE(string, purInquirySubject, PurInquirySubject);
//����״̬
	//�Ƿ���Чint
	CC_SYNTHESIZE(int, purInquiryIsEffective, PurInquiryIsEffective);
	//�Ƿ�ر�
	CC_SYNTHESIZE(int, purInquiryIsClosed, PurInquiryIsClosed);
	//�Ƿ�����
	CC_SYNTHESIZE(int, purInquiryIsVoided, PurInquiryIsVoided);

public:
	// ��JSONת������
	friend void from_json(const json& j, PurInquiryFindBillDTO& t); // NOLINT
	BIND_TO_JSON(PurInquiryFindBillDTO, purInquiryBillNo, purInquiryBillDate, purInquirySubject,
		purInquiryIsEffective, purInquiryIsClosed, purInquiryIsVoided);

};

#endif // !_PUR_INQUIRY_FIND_BILL_DTO_