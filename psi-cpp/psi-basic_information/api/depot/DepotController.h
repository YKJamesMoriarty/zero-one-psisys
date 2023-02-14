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
#ifndef _DEPOT_CONTROLLER_
#define _DEPOT_CONTROLLER_

#include "../../domain/query/depot/DepotQuery.h"
#include "../../domain/dto/depot/DepotDTO.h"
#include "../../domain/dto/IDDTO.h"
#include "../../domain/vo/depot/DepotVO.h"
#include "../../domain/vo/PageVO.h"
#include "../../domain/vo/JsonVO.h"

/**
 * �������ϲֿ�ģ��ӿ�
 */
class SampleController
{
public:
	// �����æ��һ�£��������Ӧ������
	CREATE_API_FUN_QUERY_PAYLOAD(queryDepot, execQueryDepot, DepotQuery);
	CREATE_API_FUN_BODY(addDepot, execAddDepot, DepotDTO);
	CREATE_API_FUN_BODY(modifyDepot, execModifyDepot, DepotDTO);
	CREATE_API_FUN_BODY(removeDepot, execRemoveDepot, DepotDTO);
	CREATE_API_FUN_BODY_FILE(modifyDepots, execModifyDepots, DepotDTO);
	CREATE_API_FUN_QUERY_PAYLOAD(exportExecl, execExportExecl, DepotQuery);
private:
	//Ĭ�ϲ�ѯ����
	JsonVO<PageVO<DepotVO>> execQueryDepot(const DepotQuery& query, const PayloadDTO& payload);
	//��ѯ�Ӽ��б� # ����Ӧ�ô���Ψһֵ���� Ҫ��Ҫ��ҳ������֮���������˵
	JsonVO<DepotVO> execQueryKidDepot(const DepotQuery& query, const PayloadDTO& payload);
	// ��ѯ���� # ����Ӧ�ô���Ψһֵ����
	JsonVO<DepotDetailVO> execQueryDetail(const DepotQuery& query, const PayloadDTO& payload);
	JsonVO<DepotActionInfoVO> execQueryActionInfo(const DepotQuery& query, const PayloadDTO& payload);
	//�����ֿ� # ����¼�Ӧ�ÿ���ͨ�������ʵ�֣����Ȳ�д
	JsonVO<uint64_t> execAddDepot(const DepotDTO& dto);
	//�޸Ĳֿ�
	JsonVO<uint64_t> execModifyDepot(const DepotDTO& dto);
	//ɾ���ֿ� # ����Ӧ�ô���Ψһֵ���У������Ƕ�Ӧɾ����
	JsonVO<uint64_t> execRemoveDepot(const DepotDTO& dto);
	//�ļ�����
	JsonVO<DepotVO> execModifyDepots(const DepotDTO& dto);
	//�ļ�����
	JsonVO<string> execExportExecl(const DepotQuery& query, const PayloadDTO& payload);
};

#endif // _DEPOT_CONTROLLER_
