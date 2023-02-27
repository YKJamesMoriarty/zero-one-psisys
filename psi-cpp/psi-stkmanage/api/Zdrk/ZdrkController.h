#pragma once
#ifndef _QUERYDOCLIST_CONTROLLER_
#define _QUERYDOCLIST_CONTROLLER_

#include "../../domain/query/Zdrk/QueryZdrkBillListQuery.h"
#include "../../domain/query//Zdrk/QueryZdrkDBillDetailsQuery.h"
#include "../../domain/vo/Zdrk/QueryZdrkBillListVO.h"
#include "../../domain/vo/Zdrk/QueryZdrkBillDetailsVO.h"
#include "../../domain/dto/Zdrk/AddZdrkBillDTO.h"
#include "../../domain/dto/Zdrk/ModifyZdrkBillDTO.h"
#include "../../domain/dto/Zdrk/ModifyZdrkBillStateDTO.h"
#include "../../domain/dto/Zdrk/ImportZdrkFileDTO.h"
#include "../../domain/dto/FileDTO.h"
#include "../../domain/vo/PageVO.h"
#include "../../domain/vo/JsonVO.h"
#include "../../domain/dto/IDDTO.h"
#include "../../domain/dto/Zdrk/ApprovalDTO.h"
/**
 * �Ƕ���������
 */
class ZdrkController
{
public:
	CREATE_API_FUN_QUERY(queryZdrkBillDetails, execQueryZdrkBillDetails, QueryZdrkBillDetailsQuery);
	CREATE_API_FUN_QUERY(queryZdrkBillList, execQueryZdrkBillList, QueryZdrkBillListQuery);

	//��ӵ���
	CREATE_API_FUN_JSON_PAYLOAD(addZdrkrkBill, execAddZdrkBill, AddZdrkBillDTO);
	// ��˵���
	CREATE_API_FUN_BODY_PAYLOAD(modifyBillApproval, execModifyBillApproval, ApprovalDTO);
	//�޸ĵ���
	CREATE_API_FUN_JSON_PAYLOAD(modifyZdrkBill, execModifyZdrkBill, ModifyZdrkBillDTO);
	//ɾ������
	CREATE_API_FUN_BODY(removeZdrkBill, execRemoveZdrkBill, StringID);

	//�޸ĵ���״̬ �رշ��ر�����
	CREATE_API_FUN_BODY(modifyZdrkBillState, execModifyZdrkBillState, ModifyZdrkBillStateDTO);
	CREATE_API_FUN_BODY_PAYLOAD(modifyZdrkBillStateToClose, execModifyZdrkBillStateToClose, StringID);
	CREATE_API_FUN_BODY_PAYLOAD(modifyZdrkBillStateToUnclose, execModifyZdrkBillStateToUnclose, StringID);
	CREATE_API_FUN_BODY_PAYLOAD(modifyZdrkBillStateToVoid, execModifyZdrkBillStateToVoid, StringID);

	//���뵼��
	CREATE_API_FUN_BODY_FILE(ImportZdrkFile, execImportZdrkFile, ImportZdrkFileDTO);
	CREATE_API_FUN_QUERY3(EmportZdrkFile, execEmportZdrkFile);
private:
	//��ѯ������ϸ��Ϣ
	JsonVO<PageVO<QueryZdrkBillDetailsVO>> execQueryZdrkBillDetails(const QueryZdrkBillDetailsQuery& query);
	//��ѯ�����б�
	JsonVO<PageVO<QueryZdrkBillListVO>> execQueryZdrkBillList(const QueryZdrkBillListQuery& query);//**?������Ϣ
	//��ӵ���
	JsonVO<uint64_t> execAddZdrkBill(const AddZdrkBillDTO& dto,const PayloadDTO& payload);
	//��˵���
	JsonVO<int> execModifyBillApproval(const ApprovalDTO& approval, const PayloadDTO& payload);
	//�޸ĵ���
	JsonVO<int> execModifyZdrkBill(const ModifyZdrkBillDTO& dto, const PayloadDTO& payload);
	//ɾ������
	JsonVO<int> execRemoveZdrkBill(const StringID& dto);
	//�޸ĵ���״̬
	JsonVO<uint64_t> execModifyZdrkBillState(const ModifyZdrkBillStateDTO& dto);
	// �ر�
	JsonVO<int> execModifyZdrkBillStateToClose(const StringID& id, const PayloadDTO& payload);
	// ���ر�
	JsonVO<int> execModifyZdrkBillStateToUnclose(const StringID& id, const PayloadDTO& payload);
	// ����
	JsonVO<int> execModifyZdrkBillStateToVoid(const StringID& id, const PayloadDTO& payload);
	//����
	JsonVO<uint64_t> execImportZdrkFile(const ImportZdrkFileDTO& dto);
	//����
	JsonVO<std::string>  execEmportZdrkFile();
};

#endif // _QUERYDOCLIST_CONTROLLER_
