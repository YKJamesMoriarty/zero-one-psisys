#pragma once
#ifndef _QUERYDOCLIST_CONTROLLER_
#define _QUERYDOCLIST_CONTROLLER_

#include "../../domain/dto/IncreaseTon/DocStatDTO.h"
#include "../../domain/dto/IncreaseTon/DocFileDTO.h"
#include "../../domain/dto/IncreaseTon/DocNoDTO.h"
#include "../../domain/vo/IncreaseTon/SucVO.h"
#include "../../domain/dto/IncreaseTon/DocDTO.h"
#include "../../domain/vo/IncreaseTon/DocVO.h"
#include "../../domain/vo/IncreaseTon/QueryDocVO.h"
#include "../../domain\query\IncreaseTon\QueryDocQuery.h"
#include "../../domain/vo/IncreaseTon/DoclVO.h"
#include "../../domain\query\IncreaseTon\QueryDocListQuery.h"
#include "../../domain\dto\IncreaseTon\QueryDocDTO.h"
#include "../../domain/vo/PageVO.h"
#include "../../domain/vo/JsonVO.h"


/**
 * �Ƕ���������
 */
class IncreaseTonController
{
public:
	CREATE_API_FUN_QUERY_PAYLOAD(QueryDocIncreaseTon, execQueryDocIncreaseTon, QueryDocQuery);
	CREATE_API_FUN_QUERY_PAYLOAD(QueryDocListIncreaseTon, execQueryDocListIncreaseTon, QueryDocListQuery);
	CREATE_API_FUN_JSON(AddDocIncreaseTon, execAddDocIncreaseTon, DocDTO);
	CREATE_API_FUN_JSON(ModifyDocIncreaseTon, execModifyDocIncreaseTon, DocDTO);
	CREATE_API_FUN_BODY(RemoveDocIncreaseTon, execRemoveDocIncreaseTon, DocNoDTO);
	CREATE_API_FUN_BODY(ModifyDocStatIncreaseTon, execModifyDocStatIncreaseTon, DocStatDTO);
	CREATE_API_FUN_BODY_FILE(ImportDocFileIncreaseTon, execImportDocFileIncreaseTon, DocFileDTO);
	CREATE_API_FUN_QUERY3(EmportDocFileIncreaseTon, execEmportDocFileIncreaseTon);
private:
	//��ѯ������ϸ��Ϣ
	JsonVO<QueryDocVO> execQueryDocIncreaseTon(const QueryDocQuery& query, const PayloadDTO& payload);
	//��ѯ�����б�
	JsonVO<PageVO<DoclVO>> execQueryDocListIncreaseTon(const QueryDocListQuery& query, const PayloadDTO& payload);//**?������Ϣ
	//��ӵ���
	JsonVO<SucVO> execAddDocIncreaseTon(const DocDTO& dto);
	//�޸ĵ���
	JsonVO<SucVO> execModifyDocIncreaseTon(const DocDTO& dto);
	//ɾ������
	JsonVO<SucVO> execRemoveDocIncreaseTon(const DocNoDTO& dto);
	//�޸ĵ���״̬
	JsonVO<SucVO> execModifyDocStatIncreaseTon(const DocStatDTO& dto);
	//����
	JsonVO<SucVO> execImportDocFileIncreaseTon(const DocFileDTO& dto);
	//����
	JsonVO<std::string> execEmportDocFileIncreaseTon();
};

#endif // _QUERYDOCLIST_CONTROLLER_
