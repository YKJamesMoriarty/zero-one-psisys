#pragma once

#ifndef _QTRK_CONTROLLER_
#define _QTRK_CONTROLLER_

#include "../../domain/query/Qtrk/QueryBillListQuery.h"
#include "../../domain/query/Qtrk/QueryDetailMessageQuery.h"
#include "../../domain/dto/Qtrk/QueryBillListDTO.h"
#include "../../domain/dto/Qtrk/AddListDTO.h"
#include "../../domain/dto/Qtrk/DeleteBillDTO.h"
#include "../../domain/dto/Qtrk/QueryDetailMessageDTO.h"
#include "../../domain/dto/IDDTO.h"

#include "../../domain/vo/Qtrk/QueryBillListVO.h"
#include "../../domain/vo/Qtrk/QueryDetailMessageVO.h"
#include "../../domain/vo/PageVO.h"
#include "../../domain/vo/JsonVO.h"
//#include "../../domain/dto/user/UserDTO.h"
//#include "../../domain/vo/user/UserVO.h"

/**
 * ����������������ʾ�����ӿڵ�ʹ��
 */
class QtrkController
{
public:
	CREATE_API_FUN_QUERY_PAYLOAD(queryQtrk, execQueryQtrk, QueryBillListQuery);
	//CREATE_API_FUN_QUERY_PAYLOAD(querydetailQtrk, execQuerydetailQtrk, QueryDetailMessageQuery);
	CREATE_API_FUN_BODY(addQtrk, execAddQtrk, AddListDTO);
	CREATE_API_FUN_BODY(modifyQtrk, execModifyQtrk, AddListDTO);
	CREATE_API_FUN_BODY(removeQtrk, execRemoveQtrk, DeleteBillDTO);
	//CREATE_API_FUN_BODY(removeById, execRemoveById, IntID);
	//CREATE_API_FUN_JSON(jsonQtrk, execJsonQtrk, QueryBillListDTO);
	CREATE_API_FUN_BODY_FILE(uploadFile, execUploadFile, QueryDetailMessageDTO);
	//API_BODY_PARAM_FILE(uploadFile, execUploadFile, QueryDetailMessageDTO);
private:
	//��ѯ������ⵥ���б�
	JsonVO<PageVO<QueryBillListVO>> execQueryQtrk(const QueryBillListQuery& query, const PayloadDTO& payload);
	//��ѯ������ⵥ���б�
	//JsonVO<PageVO<QueryDetailMessageVO>> execQuerydetailQtrk(const QueryDetailMessageQuery& query, const PayloadDTO& payload);
	//���������ⵥ������/�ύ��
	JsonVO<uint64_t> execAddQtrk(const AddListDTO& dto);
	//��ʾ�޸�����
	JsonVO<uint64_t> execModifyQtrk(const AddListDTO& dto);
	//��ʾɾ������
	JsonVO<uint64_t> execRemoveQtrk(const DeleteBillDTO& dto);
	//JsonVO<uint64_t> execRemoveById(const IntID& id);
	////��ʾJSON�ύ
	//JsonVO<SampleVO> execJsonSample(const SampleDTO& dto);
	////��ʾ�ļ��ϴ�
	JsonVO<QueryDetailMessageVO> execUploadFile(const QueryDetailMessageDTO& dto);
};

#endif // _Qtrk_CONTROLLER_