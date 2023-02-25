#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: QZP
 @Date: 2023/02/20 12:54:13

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
#ifndef _PUR_COMPARE_DAO_
#define _PUR_COMPARE_DAO_
#include "BaseDAO.h"
#include "../../domain/do/pur-compare/PurCompareDO.h"
#include "../../domain/do/pur-compare/PurCompareEntryDO.h"
#include "../../domain/do/pur-compare/PurComQuotEntryDO.h"
#include "../../domain/do/pur-compare/PurComQuotDO.h"
#include "../../domain/do/pur-compare/AddPurComDO.h"
#include "../../domain/do/pur-compare/ModPurComDO.h"
#include "../../domain/do/pur-compare/DelPurComDO.h"
#include "../../domain/do/pur-compare/PurComModBillStatusDO.h"


/**
 * ʾ�������ݿ����ʵ��
 */
class PurCompareDAO : public BaseDAO
{
public:
	// ͳ����������
	uint64_t count(const PurCompareDO& iObj);
	// ��ҳ��ѯ�ȼ۵������б�
	list<PurCompareDO> selectPurComFindBill(const PurCompareDO& obj, uint64_t pageIndex, uint64_t pageSize);
	// ��ѯָ���ȼ۵���ϸ��Ϣ���ȼ۵�
	list<PurCompareDO> selectPurComFindDetailBill(const PurCompareDO& obj);
	// ��ѯָ���ȼ۵���ϸ��Ϣ���ȼ۵���ϸ
	list<PurCompareEntryDO> selectPurComFindDetailBillEntry(const PurCompareEntryDO& obj);
	// ��ѯ��ѡ���۵�
	list<PurCompareDO> selectCandidateQuot(const PurCompareDO& obj);
	// ��ѯ���۵��б�
	list<PurComQuotDO> selectPurComList(const PurCompareDO& obj);
	// ��ѯ���۵���¼�б�
	list<PurComQuotEntryDO> selectPurComDividedList(const PurComQuotEntryDO& obj);
	// ��������
	uint64_t insertPurCom(const AddPurComDO& iObj);
	// �޸�����
	int updatePurCom(const ModPurComDO& uObj);
	// ɾ������
	int deletePurCom(const DelPurComDO& dObj);
	// �޸ĵ���״̬
	int updatePurComBillStatus(const ModPurComBillStatusDO& uObj);


};
#endif // !_SAMPLE_DAO_

