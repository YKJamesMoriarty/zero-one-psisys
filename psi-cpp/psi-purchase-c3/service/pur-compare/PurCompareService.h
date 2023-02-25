#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: QZP
 @Date: 2023/02/20 12:37:10

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
#ifndef _PUR_COMPARE_SERVICE_
#define _PUR_COMPARE_SERVICE_
#include <list>
#include "../../domain/vo/PageVO.h"
#include "../../domain/vo/pur-compare/PurComDetailsVO.h"
#include "../../domain/vo/pur-compare/PurComDividedListVO.h"
#include "../../domain/vo/pur-compare/PurComFindBillVO.h"
#include "../../domain/vo/pur-compare/PurComFindDetailBillVO.h"
#include "../../domain/vo/pur-compare/PurComListVO.h"
#include "../../domain/query/pur-compare/PurComDividedListQuery.h"
#include "../../domain/query/pur-compare/PurComFindBillQuery.h"
#include "../../domain/query/pur-compare/PurComFindDetailBillQuery.h"
#include "../../domain/query/pur-compare/PurComListQuery.h"

//dto
#include "../../domain/dto/pur-compare/AddPurComDTO.h"
#include "../../domain/dto/pur-compare/ModPurComDTO.h"
#include "../../domain/dto/pur-compare/DelPurComDTO.h"
#include "../../domain/dto/pur-compare/PurComModBillStatusDTO.h"

/**
 * ʾ������ʵ�֣���ʾ������ʾ������ʵ��
 */
class PurCompareService
{
public:
	// ��ҳ��ѯ�ȼ۵������б�
	PageVO<PurComFindBillVO> listPurComFindBill(const PurComFindBillQuery& query);
	// ��ѯָ���ȼ۵���ϸ��Ϣ
	PurComFindDetailBillVO getPurComFindDetailBill(const PurComFindDetailBillQuery& query);
	// ���۵��б�
	std::list<PurComListVO> listPurComList(const PurComListQuery& query);
	// ���۵���¼�б�
	std::list<PurComDividedListVO> listPurComDividedList(const PurComDividedListQuery& query);

	// ��������
	uint64_t savePurCom(const AddPurComDTO& dto, PayloadDTO payload);
	// �޸�����
	bool updatePurCom(const ModPurComDTO& dto, PayloadDTO payload);
	// ɾ������
	bool removePurCom(const DelPurComDTO& dto);
	// �޸ĵ���״̬
	bool updatePurComBillStatus(const PurComModBillStatusDTO& dto, PayloadDTO payload);
};

#endif // !_SAMPLE_SERVICE_

