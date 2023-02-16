#pragma once
#ifndef _PYRK_CONTROLLER_
#define _PYRK_CONTROLLER_

#include "../../domain/dto/IDDTO.h"
#include "../../domain/vo/JsonVO.h"
#include "../../domain/dto/Pyrk/ImportPyrkFileDTO.h"
#include "../../domain/vo/Pyrk/ImportPyrkFileVO.h"

/**
* ��ӯ��������
*/
class PyrkController
{
public:
	CREATE_API_FUN_BODY(removePyrkBillById, execRemovePyrkBillById, StringID);
	CREATE_API_FUN_BODY_PAYLOAD(modifyPyrkBillStateToClose, execModifyPyrkBillStateToClose, StringID);
	CREATE_API_FUN_BODY_PAYLOAD(modifyPyrkBillStateToUnclose, execModifyPyrkBillStateToUnclose, StringID);
	CREATE_API_FUN_BODY_PAYLOAD(modifyPyrkBillStateToVoid, execModifyPyrkBillStateToVoid, StringID);
	CREATE_API_FUN_BODY_PAYLOAD_FILE(importPyrkFile, execImportPyrkFile, ImportPyrkFileDTO);
	CREATE_API_FUN_QUERY(exportPyrkFile, execExportPyrkFile, StringIDs);
private:
	//ɾ������
	JsonVO<uint64_t> execRemovePyrkBillById(const StringID& id);
	//�޸ĵ���״̬
		// �ر�
	JsonVO<uint64_t> execModifyPyrkBillStateToClose(const StringID& id, const PayloadDTO& payload);
		// ���ر�
	JsonVO<uint64_t> execModifyPyrkBillStateToUnclose(const StringID& id, const PayloadDTO& payload);
		// ����
	JsonVO<uint64_t> execModifyPyrkBillStateToVoid(const StringID& id, const PayloadDTO& payload);
	// ����
	JsonVO<ImportPyrkFileVO> execImportPyrkFile(const ImportPyrkFileDTO& dto, const PayloadDTO& payload);
	// ����
	JsonVO<string> execExportPyrkFile(const StringIDs& ids);
};

#endif // !_PYRK_CONTROLLER_