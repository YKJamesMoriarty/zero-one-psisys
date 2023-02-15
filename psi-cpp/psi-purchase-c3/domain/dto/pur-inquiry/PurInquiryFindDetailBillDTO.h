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
#ifndef _PUR_INQUIRY_FIND_DETAIL_BILL_DTO_
#define _PUR_INQUIRY_FIND_DETAIL_BILL_DTO_

#include "../../GlobalInclude.h"


//�鿴ָ��ѯ�۵���ϸ��Ϣ
class PurInquiryFindDetailBillDTO
{
	//���ݱ��
	CC_SYNTHESIZE(string, purInquiryBillNo, PurInquiryBillNo);   // ��Ӧmysql���ݿ���bill_no�ֶ�

public:
	// ��JSONת������
	friend void from_json(const json& j, PurInquiryFindDetailBillDTO& t); // NOLINT
};


#endif  // !_PUR_INQUIRY_FIND_DETAIL_BILL__DTO_