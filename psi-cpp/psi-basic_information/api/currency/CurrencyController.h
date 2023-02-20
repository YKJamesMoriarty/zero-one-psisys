#pragma once
/*
 Copyright Zero One Star. All rights reserved.
 @Author: Linsky
 @Date: 2023/2/13 20:31:04
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
#ifndef _Currency_CONTROLLER_
#define _Currency_CONTROLLER_

#include "../../domain/query/currency/CurrencyQuery.h"
#include "../../domain/dto/currency/CurrencyDTO.h"
#include "../../domain/dto/IDDTO.h"
#include "../../domain/vo/currency/CurrencyVO.h"
#include "../../domain/vo/PageVO.h"
#include "../../domain/vo/JsonVO.h"
// #include "../../domain/dto/FileDTO.h"

/**
 * �������ϲֿ�ģ��ӿ�
 */
class CurrencyController
{
public:
	CREATE_API_FUN_QUERY_PAYLOAD(queryCurrency, execQueryCurrency, CurrencyQuery);
	//CREATE_API_FUN_QUERY_PAYLOAD(queryKidCurrency, execQueryKidCurrency, OnlyValueQuery);
	CREATE_API_FUN_QUERY_PAYLOAD(queryDetailCurrency, execQueryDetail, OnlyValueQuery);
	CREATE_API_FUN_QUERY_PAYLOAD(queryActionInfolCurrency, execQueryActionInfo, OnlyValueQuery);
	CREATE_API_FUN_BODY(addCurrency, execAddCurrency, CurrencyDTO);
	CREATE_API_FUN_BODY(modifyCurrency, execModifyCurrency, CurrencyDTO);
	CREATE_API_FUN_BODY(removeCurrency, execRemoveCurrency, OnlyValueQuery);
	// ����ֱ����FileDTO����
	CREATE_API_FUN_BODY_FILE(addCurrencys, execAddCurrencys, CurrencyDTO);
	CREATE_API_FUN_QUERY_PAYLOAD(exportExecl, execExportExecl, CurrencyQuery);
	CREATE_API_FUN_QUERY_PAYLOAD(exportExeclOnly, execExportExeclOnly, OnlyValueQuery);
private:
	//Ĭ�ϲ�ѯ����
	JsonVO<PageVO<CurrencyVO>> execQueryCurrency(const CurrencyQuery& query, const PayloadDTO& payload);
	//��ѯ�Ӽ��б�
	//JsonVO<CurrencyVO> execQueryKidCurrency(const OnlyValueQuery& query, const PayloadDTO& payload);
	// ��ѯ����
	JsonVO<CurrencyDetailVO> execQueryDetail(const OnlyValueQuery& query, const PayloadDTO& payload);
	JsonVO<CurrencyActionInfoVO> execQueryActionInfo(const OnlyValueQuery& query, const PayloadDTO& payload);
	//�����ֿ�
	JsonVO<PageVO<CurrencyVO>> execAddCurrency(const CurrencyDTO& dto);
	//�޸Ĳֿ�
	JsonVO<PageVO<CurrencyVO>> execModifyCurrency(const CurrencyDTO& dto);
	//ɾ���ֿ� 
	JsonVO<PageVO<CurrencyVO>> execRemoveCurrency(const OnlyValueQuery& query);
	//�ļ�����
	JsonVO<PageVO<CurrencyVO>> execAddCurrencys(const CurrencyDTO& dto);
	//�ļ�����
	JsonVO<string> execExportExecl(const CurrencyQuery& query, const PayloadDTO& payload);
	// ͨ��Ψһֵ��������
	JsonVO<string> execExportExeclOnly(const OnlyValueQuery& query, const PayloadDTO& payload);
};

#endif // _Currency_CONTROLLER_