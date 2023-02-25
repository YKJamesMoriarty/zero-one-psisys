#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: qingyu
 @Date: 2023/02/16 0:23:02

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

#ifndef _PUR_ORDER_CONTROLLER_
#define _PUR_ORDER_CONTROLLER_

#include "../../domain/query/PurOrder/PurOrderQuery.h"
#include "../../domain/dto/PurOrder/PurOrderDTO.h"
#include "../../domain/dto/IDDTO.h"
#include "../../domain/vo/PurOrder/PurOrderVO.h"
#include "../../domain/vo/PageVO.h"
#include "../../domain/vo/JsonVO.h"

/**
 * �ɹ��������������ɹ������ӿڵ�ʹ��
 */
class PurOrderController
{
public:
	// ��ҳ����
	CREATE_API_FUN_QUERY_PAYLOAD(querylistPurOrder, execQueryListPurOrder, PurOrderQuery);
	// ��������
	CREATE_API_FUN_BODY(getPurOrder, execGetPurOrder, PurOrderDTO);
	// ��������
	CREATE_API_FUN_JSON(addPurOrder, execAddPurOrder, PurOrderDTO);
	// �޸�����
	CREATE_API_FUN_BODY(modifyPurOrder, execModifyPurOrder, PurOrderDTO);
	// �޸�״̬
	CREATE_API_FUN_BODY(statusPurOrder, execStatusPurOrder, PurOrderDTO);
	// ɾ������
	CREATE_API_FUN_BODY(removePurOrder, execRemovePurOrder, PurOrderDTO);
	// ɾ��ById
	CREATE_API_FUN_BODY(removeById, execRemoveById, IntID);

private:
	// �����ҳ����
	JsonVO<PageVO<PurOrderVO>> execQueryListPurOrder(const PurOrderQuery& query, const PayloadDTO& payload);
	// ��ѯ��������
	JsonVO<PurOrderVO> execGetPurOrder(const PurOrderDTO& dto);
	// ��������
	JsonVO<uint64_t> execAddPurOrder(const PurOrderDTO& dto);
	// �޸�����
	JsonVO<uint64_t> execModifyPurOrder(const PurOrderDTO& dto);
	// �޸�״̬
	JsonVO<uint64_t> execStatusPurOrder(const PurOrderDTO& dto);
	//ɾ������
	JsonVO<uint64_t> execRemovePurOrder(const PurOrderDTO& dto);
	// ɾ������-ID
	JsonVO<uint64_t> execRemoveById(const IntID& id);

};

#endif // _PUR_ORDER_CONTROLLER_