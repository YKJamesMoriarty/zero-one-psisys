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
#include "service/depot/DepotService.h"
#include "../lib-common/include/ExcelComponent.h"
// #include "../../domain/dto/FileDTO.h"

/**
 * �������ϲֿ�ģ��ӿ�
 */
class DepotController
{
public:
	CREATE_API_FUN_QUERY_PAYLOAD(queryDepot, execQueryDepot, DepotQuery);
	CREATE_API_FUN_QUERY_PAYLOAD(queryKidDepot, execQueryKidDepot, OnlyValueQuery);
	CREATE_API_FUN_QUERY_PAYLOAD(queryDetailDepot, execQueryDetail, OnlyValueQuery);
	CREATE_API_FUN_QUERY_PAYLOAD(queryActionInfolDepot, execQueryActionInfo, OnlyValueQuery);
	CREATE_API_FUN_BODY(addDepot, execAddDepot, DepotDTO);
	CREATE_API_FUN_BODY(addKidDepot, execAddKidDepot, DepotDTO);
	CREATE_API_FUN_BODY(modifyDepot, execModifyDepot, DepotDTO);
	CREATE_API_FUN_BODY(removeDepot, execRemoveDepot, OnlyValueQuery);
	// ����ֱ����FileDTO����
	CREATE_API_FUN_BODY_FILE(addDepots, execAddDepots, DepotDTO);
	CREATE_API_FUN_QUERY_PAYLOAD(exportExecl, execExportExecl, DepotQuery);
	CREATE_API_FUN_QUERY_PAYLOAD(exportExeclOnly, execExportExeclOnly, OnlyValueQuery);
private:
	//Ĭ�ϲ�ѯ����
	JsonVO<PageVO<DepotVO>> execQueryDepot(const DepotQuery& query, const PayloadDTO& payload);
	//��ѯ�Ӽ��б�
	JsonVO<std::list<DepotVO>> execQueryKidDepot(const OnlyValueQuery& query, const PayloadDTO& payload);
	// ��ѯ����
	JsonVO<DepotDetailVO> execQueryDetail(const OnlyValueQuery& query, const PayloadDTO& payload);
	JsonVO<DepotActionInfoVO> execQueryActionInfo(const OnlyValueQuery& query, const PayloadDTO& payload);
	// �����ֿ�
	JsonVO<bool> execAddDepot(const DepotDTO& dto);
	// �����Ӽ��ֿ�
	JsonVO<bool> execAddKidDepot(const DepotDTO& dto);
	//�޸Ĳֿ�
	JsonVO<bool> execModifyDepot(const DepotDTO& dto);
	//ɾ���ֿ� 
	JsonVO<bool> execRemoveDepot(const OnlyValueQuery& query);
	//�ļ�����
	JsonVO<bool> execAddDepots(const DepotDTO& dto);
	//�ļ�����
	JsonVO<string> execExportExecl(const DepotQuery& query, const PayloadDTO& payload);
	// ͨ��Ψһֵ��������
	JsonVO<string> execExportExeclOnly(const OnlyValueQuery& query, const PayloadDTO& payload);
};

#endif // _DEPOT_CONTROLLER_