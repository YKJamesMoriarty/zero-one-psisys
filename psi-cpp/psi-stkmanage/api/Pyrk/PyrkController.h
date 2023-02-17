#pragma once
#ifndef _PYRK_CONTROLLER_
#define _PYRK_CONTROLLER_
#include "../psi-stkmanage/domain/vo/JsonVO.h"
#include "../psi-stkmanage/domain/vo/Message.h"
#include "../psi-stkmanage/domain/vo/PageVO.h"
#include "../psi-stkmanage/domain/vo/Pyrk/QueryPyrkBillListVO.h"
#include "../psi-stkmanage/domain/vo/Pyrk/QueryPyrkDetailedBillVO.h"
#include"../psi-stkmanage/domain/query/Pyrk/QueryPyrkBillListQuery.h"
#include"../psi-stkmanage/domain/dto/Pyrk/PyrkBillDetailDTO.h"
class PyrkController {
public:
	// ��ѯ�����б�
	CREATE_API_FUN_QUERY(queryQueryBillList, execQueryBillList, QueryPyrkBillListQuery);
	// ��ѯ������ϸ��Ϣ
	CREATE_API_FUN_QUERY(queryQueryBillDetailed, exeQueryBillDetailed, QueryPyrkBillListQuery);
	// ����������ϸ��Ϣ
	CREATE_API_FUN_BODY(addBillDetailed, exeAddBillDetailed, PyrkBillDetailDTO);
	// �޸ĵ�����ϸ��Ϣ
	CREATE_API_FUN_BODY(updateBillDetailed, exeUpdateBillDetailed, PyrkBillDetailDTO);
private:
	// ��ѯ�����б�
	JsonVO<PageVO<QueryPyrkBillListVO>> execQueryBillList(const QueryPyrkBillListQuery& query);
	// ��ѯ������ϸ��Ϣ
	JsonVO<QueryPyrkBillListVO> exeQueryBillDetailed(const QueryPyrkBillListQuery& query);
	// ����������ϸ��Ϣ
	JsonVO<int> exeAddBillDetailed(const PyrkBillDetailDTO& addMessage);
	// �޸ĵ�����ϸ��Ϣ
	JsonVO<int> exeUpdateBillDetailed(const PyrkBillDetailDTO& updateMessage);
};










#endif