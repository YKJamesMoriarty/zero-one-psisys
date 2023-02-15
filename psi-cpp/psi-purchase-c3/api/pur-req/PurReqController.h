#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 0:27:04

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
#ifndef _PUR_REQ_CONTROLLER_
#define _PUR_REQ_CONTROLLER_

//�����ӿ�
#include "../../domain/vo/PageVO.h"
#include "../../domain/vo/JsonVO.h"
#include "../../domain/dto/IDDTO.h"

//��ѯ�����б�
#include "../../domain/query/pur-req/PurReqFindBillQuery.h"
#include "../../domain/vo/pur-req/PurReqFindBillVO.h"

//��ѯָ�������б�
#include "../../domain/query/pur-req/PurReqFindDetailBillQuery.h"
#include "../../domain/vo/pur-req/PurReqFindDetailBillVO.h"


/**
 * �ɹ����빦�ܵ�
 */
class PurReqController
{
public:
	CREATE_API_FUN_QUERY_PAYLOAD(queryPurReqFindBill, execQueryPurReqFindBill,PurReqFindBillQuery);
	CREATE_API_FUN_QUERY_PAYLOAD(queryPurReqFindDetailBill, execQueryPurReqFindDetailBill, PurReqFindDetailBillQuery);
private:
	//��ѯ�����б�
	JsonVO<PageVO<PurReqFindBillVO>> execQueryPurReqFindBill(const PurReqFindBillQuery& query, const PayloadDTO& payload);
	//��ѯָ��������ϸ��Ϣ
	JsonVO<PurReqFindDetailBillVO> execQueryPurReqFindDetailBill(const PurReqFindDetailBillQuery& query, const PayloadDTO& payload);
};


#endif 