#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: QZP
 @Date: 2023/2/15 17:57:54

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
#ifndef _PUR_COMPARE_CONTROLLER_
#define _PUR_COMPARE_CONTROLLER_
//�����ӿ�
#include "../../domain/dto/IDDTO.h"
#include "../../domain/vo/PageVO.h"
#include "../../domain/vo/JsonVO.h"

//query
#include "../../domain/query/pur-compare/PurComFindBillQuery.h"
#include "../../domain/query/pur-compare/PurComFindDetailBillQuery.h"
#include "../../domain/query/pur-compare/PurComDividedListQuery.h"
#include "../../domain/query/pur-compare/PurComListQuery.h"
#include "../../domain/query/pur-compare/PurComExportQuery.h"
//dto
#include "../../domain/dto/pur-compare/PurComIntoDTO.h"
#include "../../domain/dto/pur-compare/AddPurComDTO.h"
#include "../../domain/dto/pur-compare/ModPurComDTO.h"
#include "../../domain/dto/pur-compare/PurComModBillStatusDTO.h"
#include "../../domain/dto/pur-compare/DelPurComDTO.h"

//vo
#include "../../domain/vo/pur-compare/PurComFindBillVO.h"
#include "../../domain/vo/pur-compare/PurComFindDetailBillVO.h"
#include "../../domain/vo/pur-compare/PurComListVO.h"
#include "../../domain/vo/pur-compare/PurComDividedListVO.h"
/**
 * �ȼ۵�������
 */
class PurCompareController
{
public:
	// �����ȼ�
	CREATE_API_FUN_JSON_PAYLOAD(addPurCom, execAddPurCom, AddPurComDTO);

	// �޸ıȼ�
	CREATE_API_FUN_JSON_PAYLOAD(modifyPurCom, execModifyPurCom, ModPurComDTO);
	// ɾ���ȼ�
	CREATE_API_FUN_BODY(removePurCom, execRemovePurCom, DelPurComDTO);
	// �޸ĵ���״̬
	CREATE_API_FUN_BODY_PAYLOAD(purComModBillStatus, execPurComModBillStatus, PurComModBillStatusDTO);
	CREATE_API_FUN_QUERY_PAYLOAD(queryPurComFindBill, execQueryPurComFindBill, PurComFindBillQuery);
	CREATE_API_FUN_QUERY_PAYLOAD(queryPurComFindDetailBill, execQueryPurComFindDetailBill, PurComFindDetailBillQuery);
	CREATE_API_FUN_QUERY_PAYLOAD(queryPurComList, execQueryPurComList, PurComListQuery);
	CREATE_API_FUN_QUERY_PAYLOAD(queryPurComDividedList, execQueryPurComDividedList, PurComDividedListQuery);
	CREATE_API_FUN_JSON_PAYLOAD(queryPurComExport, execPurComExport, PurComExportQuery);
	CREATE_API_FUN_BODY_PAYLOAD_FILE(addPurComInto, execPurComInto, PurComIntoDTO);
private:
	//��ʾ�����ȼ�
	JsonVO<uint64_t> execAddPurCom(const AddPurComDTO& dto, PayloadDTO payload);
	//��ʾ�޸ıȼ�
	JsonVO<uint64_t> execModifyPurCom(const ModPurComDTO& dto, PayloadDTO payload);
	//��ʾɾ���ȼ�
	JsonVO<uint64_t> execRemovePurCom(const DelPurComDTO& dto);
	//��ʾ�޸ĵ���״̬
	JsonVO<uint64_t> execPurComModBillStatus(const PurComModBillStatusDTO& dto, PayloadDTO payload);
	// ��ѯ�ȼ۵������б�
	JsonVO<PageVO<PurComFindBillVO>> execQueryPurComFindBill(const PurComFindBillQuery& query, const PayloadDTO& payload);
	// ��ѯָ���ȼ۵�������ϸ��Ϣ
	JsonVO<PurComFindDetailBillVO> execQueryPurComFindDetailBill(const PurComFindDetailBillQuery& query, const PayloadDTO& payload);
	// ��ѯ���۵��б�
	JsonVO<list<PurComListVO>> execQueryPurComList(const PurComListQuery& query, const PayloadDTO& payload);
	// ��ѯ���۵���¼�б�
	JsonVO<list<PurComDividedListVO>> execQueryPurComDividedList(const PurComDividedListQuery& query, const PayloadDTO& payload);
	// ����
	JsonVO<std::string> execPurComExport(const PurComExportQuery& query, const PayloadDTO& payload);
	// ����
	JsonVO<uint64_t> execPurComInto(const PurComIntoDTO& dto, const PayloadDTO& payload);
};

#endif // _SAMPLE_CONTROLLER_#pragma once
