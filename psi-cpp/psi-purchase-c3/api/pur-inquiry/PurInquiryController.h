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

#ifndef _PUR_INQUIRY_CONTROLLER_
#define _PUR_INQUIRY_CONTROLLER_

#include "../../domain/query/pur-inquiry/PurInquiryFindBillQuery.h"
#include "../../domain/query/pur-inquiry/PurInquiryFindDetailBillQuery.h"
//#include "../../domain/dto/pur-inquiry/PurInquiryFindBillDTO.h"
//#include "../../domain/dto/pur-inquiry/PurInquiryFindDetailBillDTO.h"
#include "../../domain/dto/IDDTO.h"
#include "../../domain/vo/pur-inquiry/PurInquiryFindBillVO.h"
#include "../../domain/vo/pur-inquiry/PurInquiryFindDetailBillVO.h"
#include "../../domain/vo/pur-inquiry/EntryPurInquiryVO.h"
#include "../../domain/vo/PageVO.h"
#include "../../domain/vo/JsonVO.h"


/**
 * ʾ������������ʾ�ӿڵ�ʹ��
 */
class PurInquiryController
{
public:
	//�ӿ�1 ��ѯ�ɹ�ѯ�۵���ҳ�б�
	CREATE_API_FUN_QUERY_PAYLOAD(queryPurInquiryFindBill, execQueryPurInquiryFindBill, PurInquiryFindBillQuery);
	//�ӿ�2 �鿴ָ��ѯ�۵���ϸ��Ϣ
	CREATE_API_FUN_QUERY_PAYLOAD(queryPurInquiryFindDetailBill, execQueryPurInquiryFindDetailBill, PurInquiryFindDetailBillQuery);

private:
	//��ѯ�ɹ�ѯ�۵���ҳ�б�
	JsonVO<PageVO<PurInquiryFindBillVO>> execQueryPurInquiryFindBill(const PurInquiryFindBillQuery& query, const PayloadDTO& payload);
	//�鿴ָ��ѯ�۵���ϸ��Ϣ
	JsonVO<PurInquiryFindDetailBillVO> execQueryPurInquiryFindDetailBill(const PurInquiryFindDetailBillQuery& query, const PayloadDTO& payload);

};

#endif // _PUR_INQUIRY__CONTROLLER_
