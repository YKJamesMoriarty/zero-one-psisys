/*
 Copyright Zero One Star. All rights reserved.

 @Author: renqing
 @Date: 2023/2/15 16:58:10

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
#pragma once
#ifndef _PUR_COMPARE_CONTROLLER_H
#define _PUR_COMPARE_CONTROLLER_H

#include "../../domain/dto/pur-compare/PurCompareDTO.h"
#include "../../domain/dto/IDDTO.h"
#include "../../domain/vo/pur-compare/PurCompareVO.h"
#include "../../domain/vo/PageVO.h"
#include "../../domain/vo/JsonVO.h"


/**
 * ʾ������������ʾ�����ӿڵ�ʹ��
 */
class PurCompareController
{
public:
	// �����ȼ�
	CREATE_API_FUN_BODY(addPurCom, execAddPurCom, AddPurComDTO);
	// �޸ıȼ�
	CREATE_API_FUN_BODY(modifyPurCom, execModifyPurCom, ModPurComDTO);
	// ɾ���ȼ�
	CREATE_API_FUN_BODY(removePurCom, execRemovePurCom, DelPurComDTO);
	// �޸ĵ���״̬
	CREATE_API_FUN_BODY(purComModBillStatus, execPurComModBillStatus, PurComModBillStatusDTO);
private:
	//��ʾ�����ȼ�
	JsonVO<uint64_t> execAddPurCom(const AddPurComDTO& dto);
	//��ʾ�޸ıȼ�
	JsonVO<uint64_t> execModifyPurCom(const ModPurComDTO& dto);
	//��ʾɾ���ȼ�
	JsonVO<uint64_t> execRemovePurCom(const DelPurComDTO& dto);
	//��ʾ�޸ĵ���״̬
	JsonVO<uint64_t> execPurComModBillStatus(const PurComModBillStatusDTO& dto);
	
};

#endif // _PUR_COMPARE_CONTROLLER_H