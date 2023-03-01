#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 11:08:56

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
#ifndef _PRE_PAY_CONTROLLER_
#define _PRE_PAY_CONTROLLER_

#include"api/ApiHelper.h"

#include "../../domain/vo/PageVO.h"
#include "../../domain/vo/JsonVO.h"
#include "../../domain/dto/IDDTO.h"

//ɾ��
#include "../../domain/dto/prepayment/DePayDTO.h"
#include "../../domain/vo/prepayment/PrepaymentVO.h"
// �ɹ������б�
#include "../../domain/query/PurOrder/PurOrderQuery.h"
#include "../../domain/vo/PurOrder/PurOrderVO.h"

/**
 * ʾ������������ʾ�����ӿڵ�ʹ��
 */
class PrePayController
{
public:

	//��ѯ
	CREATE_API_FUN_QUERY_PAYLOAD(queryPayFindBill, execQuerypayFindBill, PurOrderQuery);
	//��ѯָ��������ϸ��Ϣ
	CREATE_API_FUN_QUERY_PAYLOAD(queryPayFinDetailBill, execQueryPayDetailBill, PurOrderQuery);
	//ɾ������
	CREATE_API_FUN_BODY(removeDePayId, execRemoveDePayId, DePayDTO);
	


private:
	
	//��ѯ
	JsonVO<PageVO<PurOrderVO>> execQuerypayFindBill(const PurOrderQuery& query, const PayloadDTO& payload);
	//��ѯָ��������ϸ��Ϣ
	JsonVO<PurOrderVO> execQueryPayDetailBill(const PurOrderQuery& query, const PayloadDTO& payload);
	//ɾ������
	JsonVO<string> execRemoveDePayId(const DePayDTO& dto);
	

};

#endif // _SAMPLE_CONTROLLER_