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
#include "../../domain/dto/purOrder/PurOrderDTO.h"
#include "../../domain/dto/IDDTO.h"
#include "../../domain/vo/purOrder/PurOrderVO.h"
#include "../../domain/vo/purOrder/PurOrderDetailVO.h"
#include "../../domain/vo/PageVO.h"
#include "../../domain/vo/JsonVO.h"

/**
 * �ɹ��������������ɹ������ӿڵ�ʹ��
 */
class PurOrderController
{
public:
	// ɾ���ɹ�����
	// �����ˣ�Andrew
	CREATE_API_FUN_BODY(removeById, execRemoveById, StringID);
	// �޸ĵ���״̬(�ر�/���ر�/����)
	// �����ˣ�Andrew
	CREATE_API_FUN_BODY_PAYLOAD(statusPurOrder, execStatusPurOrder, PurOrderDTO);

	// ��ҳ����
	// �����ˣ�����
	CREATE_API_FUN_QUERY_PAYLOAD(querylistPurOrder, execQueryListPurOrder, PurOrderQuery);
	// ��������
	// �����ˣ�����
	CREATE_API_FUN_QUERY(getPurOrder, execGetPurOrder, PurOrderQuery);
	// ��������
	// �����ˣ�����
	CREATE_API_FUN_JSON_PAYLOAD(addPurOrder, execAddPurOrder, PurOrderDTO);
	// �޸�����
	// �����ˣ�����
	CREATE_API_FUN_JSON_PAYLOAD(modifyPurOrder, execModifyPurOrder, PurOrderDTO);
private:
	// ɾ���ɹ�����
	// �����ˣ�Andrew
	JsonVO<string> execRemoveById(const StringID& id);
	// �޸ĵ���״̬(�ر�/���ر�/����)
	// �����ˣ�Andrew
	JsonVO<string> execStatusPurOrder(const PurOrderDTO& dto, const PayloadDTO& payload);

	// �����ҳ����
	// �����ˣ�����
	JsonVO<PageVO<PurOrderVO>> execQueryListPurOrder(const PurOrderQuery& query, const PayloadDTO& payload);
	// ��ѯ��������
	// �����ˣ�����
	JsonVO<PurOrderDetailVO> execGetPurOrder(const PurOrderQuery& query);
	// ��������
	// �����ˣ�����
	JsonVO<uint64_t> execAddPurOrder(const PurOrderDTO& dto, const PayloadDTO& payload);
	// �޸�����
	// �����ˣ�����
	JsonVO<uint64_t> execModifyPurOrder(const PurOrderDTO& dto, const PayloadDTO& payload);

};

#endif // _PUR_ORDER_CONTROLLER_