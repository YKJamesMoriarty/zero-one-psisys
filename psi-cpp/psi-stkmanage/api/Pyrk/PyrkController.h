#pragma once
#ifndef _PYRK_CONTROLLER_
#define _PYRK_CONTROLLER_

#include "../psi-stkmanage/domain/vo/JsonVO.h"
#include "../psi-stkmanage/domain/vo/Message.h"
#include "../psi-stkmanage/domain/vo/PageVO.h"
#include "../../domain/dto/IDDTO.h"
#include "../psi-stkmanage/domain/vo/Pyrk/QueryPyrkBillListVO.h"
#include "../psi-stkmanage/domain/vo/Pyrk/QueryPyrkDetailedBillVO.h"
#include"../psi-stkmanage/domain/query/Pyrk/QueryPyrkBillListQuery.h"
#include"../psi-stkmanage/domain/dto/Pyrk/PyrkBillDetailDTO.h"
#include "../../domain/dto/Pyrk/ImportPyrkFileDTO.h"
#include "../../domain/vo/Pyrk/ImportPyrkFileVO.h"
#include "../../domain/dto/Pyrk/ApprovalDTO.h"

class PyrkController {
public:
	// ��ѯ�����б�
	CREATE_API_FUN_QUERY(queryQueryBillList, execQueryBillList, QueryPyrkBillListQuery);
	// ��ѯ������ϸ��Ϣ
	CREATE_API_FUN_QUERY(queryQueryBillDetailed, exeQueryBillDetailed, QueryPyrkBillListQuery);
	// ����������ϸ��Ϣ
	CREATE_API_FUN_JSON_PAYLOAD(addBillDetailed, execAddBillDetailed, PyrkBillDetailDTO);
	// ��˵���
	CREATE_API_FUN_BODY_PAYLOAD(modifyBillApproval, execModifyBillApproval, ApprovalDTO);
	// �޸ĵ�����ϸ��Ϣ
	CREATE_API_FUN_JSON_PAYLOAD(updateBillDetailed, execUpdateBillDetailed, PyrkBillDetailDTO);

	CREATE_API_FUN_BODY(removePyrkBillById, execRemovePyrkBillById, StringID);
	CREATE_API_FUN_BODY_PAYLOAD(modifyPyrkBillStateToClose, execModifyPyrkBillStateToClose, StringID);
	CREATE_API_FUN_BODY_PAYLOAD(modifyPyrkBillStateToUnclose, execModifyPyrkBillStateToUnclose, StringID);
	CREATE_API_FUN_BODY_PAYLOAD(modifyPyrkBillStateToVoid, execModifyPyrkBillStateToVoid, StringID);
	CREATE_API_FUN_BODY_PAYLOAD_FILE(importPyrkFile, execImportPyrkFile, ImportPyrkFileDTO);
	CREATE_API_FUN_JSON(exportPyrkFile, execExportPyrkFile, StringIDs);
private:
	// ��ѯ�����б�
	JsonVO<PageVO<QueryPyrkBillListVO>> execQueryBillList(const QueryPyrkBillListQuery& query);
	// ��ѯ������ϸ��Ϣ
	JsonVO<QueryPyrkDetailedBillVO> exeQueryBillDetailed(const QueryPyrkBillListQuery& query);
	// ����������ϸ��Ϣ
	JsonVO<int> execAddBillDetailed(const PyrkBillDetailDTO& addMessage, const PayloadDTO& payload);
	// ��˵���
	JsonVO<int> execModifyBillApproval(const ApprovalDTO& approval, const PayloadDTO& payload);
	// �޸ĵ�����ϸ��Ϣ
	JsonVO<int> execUpdateBillDetailed(const PyrkBillDetailDTO& updateMessage, const PayloadDTO& payload);
	//ɾ������
	JsonVO<int> execRemovePyrkBillById(const StringID& id);
	//�޸ĵ���״̬
		// �ر�
	JsonVO<int> execModifyPyrkBillStateToClose(const StringID& id, const PayloadDTO& payload);
	// ���ر�
	JsonVO<int> execModifyPyrkBillStateToUnclose(const StringID& id, const PayloadDTO& payload);
	// ����
	JsonVO<int> execModifyPyrkBillStateToVoid(const StringID& id, const PayloadDTO& payload);
	// ����
	JsonVO<ImportPyrkFileVO> execImportPyrkFile(const ImportPyrkFileDTO& dto, const PayloadDTO& payload);
	// ����
	JsonVO<string> execExportPyrkFile(const StringIDs& ids);
};

#endif // !_PYRK_CONTROLLER_

