#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 0:27:04

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
#ifndef _QUERYBILLLIST_CONTROLLER_
#define _QUERYBILLLIST_CONTROLLER_

#include "../../domain/query/QueryBillList/QueryBillListQuery.h"
#include "../../domain/dto/QueryBillListDTO/QueryBillListDTO.h"
#include "../../domain/dto/IDDTO.h"
#include "../../domain/vo/QueryBillList/QueryBillListVO.h"
#include "../../domain/vo/PageVO.h"
#include "../../domain/vo/JsonVO.h"
//#include "../../domain/dto/user/UserDTO.h"
//#include "../../domain/vo/user/UserVO.h"

/**
 * ��ѯ�����б����������ʾ�����ӿڵ�ʹ��
 */
class QueryBillListController
{
public:
	CREATE_API_FUN_QUERY_PAYLOAD(queryQueryBillList,execQueryQueryBillList, QueryBillListQuery);
	/*CREATE_API_FUN_BODY(addQueryBillList, execAddQueryBillList, QueryBillListDTO);
	CREATE_API_FUN_BODY(modifyQueryBillList, execModifyQueryBillList, QueryBillListDTO);
	CREATE_API_FUN_BODY(removeQueryBillList, execRemoveQueryBillList, QueryBillListDTO);
	CREATE_API_FUN_BODY(removeById, execRemoveById, IntID);
	CREATE_API_FUN_JSON(jsonQueryBillList, execJsonQueryBillList, QueryBillListDTO);
	CREATE_API_FUN_BODY_FILE(modifyUserInfo, execModifyUserInfo, UserDTO);*/
private:
	//��ʾ��ѯ����
	JsonVO<PageVO<QueryBillListVO>> execQueryQueryBillList(const QueryBillListQuery& query, const PayloadDTO& payload);
	////��ʾ��������
	//JsonVO<uint64_t> execAddQueryBillList(const QueryBillListDTO& dto);
	////��ʾ�޸�����
	//JsonVO<uint64_t> execModifyQueryBillList(const QueryBillListDTO& dto);
	////��ʾɾ������
	//JsonVO<uint64_t> execRemoveQueryBillList(const QueryBillListDTO& dto);
	//JsonVO<uint64_t> execRemoveById(const IntID& id);
	////��ʾJSON�ύ
	//JsonVO<QueryBillListVO> execJsonSample(const QueryBillListDTO& dto);
	////��ʾ�ļ��ϴ�
	////JsonVO<UserVO> execModifyUserInfo(const UserDTO& dto);
};

#endif // _QUERYBILLLIST_CONTROLLER_