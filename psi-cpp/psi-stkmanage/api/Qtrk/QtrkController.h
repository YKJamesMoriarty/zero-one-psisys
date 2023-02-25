#pragma once

#ifndef _QTRK_CONTROLLER_
#define _QTRK_CONTROLLER_

#include "../../domain/query/Qtrk/QueryQtrkBillListQuery.h"
#include "../../domain/query/Qtrk/QueryQtrkBillDetailsQuery.h"
//#include "../../domain/dto/Qtrk/QueryBillListDTO.h"
#include "../../domain/dto/Qtrk/AddQtrkBillDTO.h"
#include "../../domain/dto/Pyrk/ApprovalDTO.h"
#include "../../domain/dto/Qtrk/DeleteQtrkBillDTO.h"
#include "../../domain/dto/Qtrk/ImportQtrkFileDTO.h"
#include "../../domain/dto/Qtrk/ExportQtrkFileDTO.h"
//#include "../../domain/dto/Qtrk/QueryQtrkBillDetailsDTO.h"
#include "../../domain/dto/IDDTO.h"

#include "../../domain/vo/Qtrk/QueryQtrkBillListVO.h"
#include "../../domain/vo/Qtrk/ImportQtrkFileVO.h"
#include "../../domain/vo/Qtrk/ExportQtrkFileVO.h"
#include "../../domain/vo/Qtrk/QueryQtrkBillDetailsVO.h"
#include "../../domain/vo/PageVO.h"
#include "../../domain/vo/JsonVO.h"
//#include "../../domain/dto/user/UserDTO.h"
//#include "../../domain/vo/user/UserVO.h"

/**
 * �������������������ӿڵ�ʹ��
 */
class QtrkController
{
public:
	CREATE_API_FUN_QUERY_PAYLOAD(queryQtrk, execQueryQtrk, QueryQtrkBillListQuery);
	CREATE_API_FUN_QUERY_PAYLOAD(querydetailsQtrk, execQueryDetailsQtrk, QueryQtrkBillDetailsQuery);
	CREATE_API_FUN_JSON_PAYLOAD(addQtrk, execAddQtrk, AddQtrkBillDTO);
	CREATE_API_FUN_JSON_PAYLOAD(modifyQtrk, execModifyQtrk, AddQtrkBillDTO);
	CREATE_API_FUN_BODY_PAYLOAD(modifyQtrkApproval, execModifyQtrkApproval, ApprovalDTO);
	CREATE_API_FUN_BODY(removeQtrk, execRemoveQtrk, DeleteQtrkBillDTO);
	//CREATE_API_FUN_BODY(removeById, execRemoveById, IntID);
	//CREATE_API_FUN_JSON(jsonQtrk, execJsonQtrk, QueryBillListDTO);
	CREATE_API_FUN_BODY_FILE(importFileQtrk, execImportFileQtrk, ImportQtrkFileDTO);
	CREATE_API_FUN_QUERY3(exportFileQtrk, execExportFileQtrk);
	//API_BODY_PARAM_FILE(uploadFile, execUploadFile, QueryDetailMessageDTO);
private:
	//��ѯ������ⵥ���б�
	JsonVO<PageVO<QueryQtrkBillListVO>> execQueryQtrk(const QueryQtrkBillListQuery& query, const PayloadDTO& payload);
	//��ѯ���������ϸ��Ϣ�����б�
	JsonVO<PageVO<QueryQtrkBillDetailsVO>> execQueryDetailsQtrk(const QueryQtrkBillDetailsQuery& query, const PayloadDTO& payload);
	//���������ⵥ������/�ύ��
	JsonVO<int> execAddQtrk(const AddQtrkBillDTO& dto, const PayloadDTO& payload);
	//�޸�������ⵥ����
	JsonVO<int> execModifyQtrk(const AddQtrkBillDTO& dto, const PayloadDTO& payload);
	// ���������ⵥ
	JsonVO<int> execModifyQtrkApproval(const ApprovalDTO& dto, const PayloadDTO& payload);
	//��ʾɾ������
	JsonVO<uint64_t> execRemoveQtrk(const DeleteQtrkBillDTO& dto);
	//JsonVO<uint64_t> execRemoveById(const IntID& id);
	////��ʾJSON�ύ
	//JsonVO<SampleVO> execJsonSample(const SampleDTO& dto);
	
	//��ʾ�ļ�����
	//JsonVO<QueryDetailMessageVO> execUploadFile(const QueryDetailMessageDTO& dto);
	JsonVO<uint64_t> execImportFileQtrk(const ImportQtrkFileDTO& dto);
	//��ʾ�ļ�����
	JsonVO<std::string> execExportFileQtrk();
};

#endif // _Qtrk_CONTROLLER_