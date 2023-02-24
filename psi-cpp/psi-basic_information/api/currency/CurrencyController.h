#pragma once
/*
 Copyright Zero One Star. All rights reserved.
 @Author: douhao
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

/**
 * �������ϱ���ģ��ӿ�
 */
class CurrencyController
{
public:
	CREATE_API_FUN_QUERY_PAYLOAD(queryCurrency, execQueryCurrency, CurrencyQuery);
	CREATE_API_FUN_QUERY_PAYLOAD(queryDetailCurrency, execQueryDetail, OnlyValueCurrencyQuery);

	CREATE_API_FUN_BODY_PAYLOAD(addCurrency, execAddCurrency, CurrencyDTO);
	CREATE_API_FUN_BODY_PAYLOAD(modifyCurrency, execModifyCurrency, CurrencyDTO);
	CREATE_API_FUN_BODY(removeCurrency, execRemoveCurrency, CurrencyDTO);
	
	CREATE_API_FUN_BODY_FILE(addCurrencys, execAddCurrencys, CurrencyDTO);
	CREATE_API_FUN_QUERY_PAYLOAD(exportExecl, execExportExecl, CurrencyQuery);
	CREATE_API_FUN_QUERY_PAYLOAD(exportExeclOnly, execExportExeclOnly, OnlyValueCurrencyQuery);
private:
	//Ĭ�ϲ�ѯ����
	JsonVO<PageVO<CurrencyVO>> execQueryCurrency(const CurrencyQuery& query, const PayloadDTO& payload);
	// ��ѯ����
	JsonVO<CurrencyVO> execQueryDetail(const OnlyValueCurrencyQuery& query, const PayloadDTO& payload);
	//��������
	JsonVO<uint64_t> execAddCurrency(const CurrencyDTO& dto, const PayloadDTO& payload);
	//JsonVO<PageVO<CurrencyVO>> execAddCurrency(const CurrencyDTO& dto);
	//�޸ı���
	JsonVO<uint64_t> execModifyCurrency(const CurrencyDTO& dto, const PayloadDTO& payload);
	//ɾ������ 
	JsonVO<uint64_t>  execRemoveCurrency(const CurrencyDTO& dto);
	//�ļ�����
	JsonVO<PageVO<CurrencyVO>> execAddCurrencys(const CurrencyDTO& dto);
	//�ļ�����
	JsonVO<string> execExportExecl(const CurrencyQuery& query, const PayloadDTO& payload);
	// ͨ��Ψһֵ��������
	JsonVO<string> execExportExeclOnly(const OnlyValueCurrencyQuery& query, const PayloadDTO& payload);
};

#endif // _Currency_CONTROLLER_