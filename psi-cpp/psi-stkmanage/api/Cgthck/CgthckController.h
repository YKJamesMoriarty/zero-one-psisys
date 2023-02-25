#ifndef _CGTHCK_CONTROLLER_
#define _CGTHCK_CONTROLLER_

#include "../psi-stkmanage/domain/vo/JsonVO.h"
#include "../psi-stkmanage/domain/vo/Message.h"
#include "../psi-stkmanage/domain/vo/PageVO.h"
#include "../../service/Cgthck/CgthckService.h"
#include "../psi-stkmanage/domain/query/Cgthck/QueryCgthckBillQuery.h"
#include "../psi-stkmanage/domain/query/Cgthck/QueryCgrkBillQuery.h"
#include "../psi-stkmanage/domain/dto/Cgthck//AddCgthckBillDTO.h"
#include "../psi-stkmanage/domain/dto/Cgthck/DeleteCgthckBillDTO.h"
#include "../psi-stkmanage/domain/dto/Cgthck/ExportCgthckFileDTO.h"
#include "../psi-stkmanage/domain/dto/Cgthck/ModifyCgthckBillDTO.h"
#include "../psi-stkmanage/domain/dto/Cgthck/ImportCgthckFileDTO.h"
#include "../psi-stkmanage/domain/vo/Cgthck/QueryCgthckBillVO.h"
#include "../psi-stkmanage/domain/vo/Cgthck/QueryCgrkBillListsVO.h"
/**
* ������, �ɹ��˻�����ӿڵ�ʹ��
*/
class CgthckController
{
public:
	// ��ѯ�ɹ��˻�����(����)���ݽӿ�
	// CREATE_API_FUN_QUERY(queryCgthcBillk, execQueryCgthckBill, QueryCgthckBillQuery);
	// ��ѯ�ɹ��˻�����(����)������ϸ�ӿ�
	// CREATE_API_FUN_QUERY(queryCgthckBillDetail, execQueryCgthckBillDetail, QueryCgthckBillQuery);
	
	// ��ѯ�ɹ���ⵥ�ݷ�¼�б�
	CREATE_API_FUN_QUERY(queryCgrkBillList, execQueryCgrkBillList, QueryCgrkBillQuery);
	// ��Ӳɹ��˻�����(����)���ݽӿ�
	CREATE_API_FUN_JSON(addCgthckBill, execAddCgthckBill, AddCgthckBillDTO);
	// �޸Ĳɹ��˻�����(����)���ݽӿ�
	CREATE_API_FUN_JSON(modifyCgthckBill, execModifyCgthckBill, AddCgthckBillDTO);
	// �޸Ĳɹ��˻�����(����)����
	CREATE_API_FUN_BODY_PAYLOAD(modifyCgthckApproval, execModifyCgthckApproval, ModifyCgthckBillDTO);
	// �޸Ĳɹ��˻�����(����)����״̬�ӿ�
	// �ر�
	CREATE_API_FUN_BODY_PAYLOAD(modifyCgthckBillStatusToClosed, execModifyCgthcStatusToClose, ModifyCgthckBillDTO);
	// ���ر�
	CREATE_API_FUN_BODY_PAYLOAD(modifyCgthckBillStatusToUnclosed, execModifyCgthcStatusToUnclose, ModifyCgthckBillDTO);
	// ����
	CREATE_API_FUN_BODY_PAYLOAD(modifyCgthckBillStatusToVoided, execModifyCgthcStatusToVoided, ModifyCgthckBillDTO);
	// ɾ���ɹ��˻�����(����)���ݽӿ�
	CREATE_API_FUN_BODY(deleteCgthckBill, execDeleteCgthckBill, DeleteCgthckBillDTO);
	// ɾ���ɹ��˻�����(����)����ϸ�ӿ�
	CREATE_API_FUN_JSON(deleteCgthckBillDetail, execDeleteCgthckBillDetail, DeleteCgthckBillDTO);
	// ����
	CREATE_API_FUN_BODY(importCgthckFile, execImportCgthckFile, ImportCgthckFileDTO);
	// ����
	CREATE_API_FUN_BODY(exportCgthckFile, execExportCgthckFile, ExportCgthckFileDTO);
private:
	//// ���Բ�ѯ����
	//JsonVO<PageVO<QueryCgthckBillVO>> execQueryCgthckBill(const QueryCgthckBillQuery& query);
	//// ���Բ�ѯ��ϸ����
	//JsonVO<PageVO<QueryCgthckBillDetailVO>> execQueryCgthckBillDetail(const QueryCgthckBillQuery& query);
	// ���Է�¼��ѯ�ɹ���ⵥ�б�	
	JsonVO<PageVO<QueryCgrkBillListsVO>> execQueryCgrkBillList(const QueryCgrkBillQuery& query);
	// �����������
	JsonVO<uint64_t> execAddCgthckBill(const AddCgthckBillDTO& dto);
	// �����޸�����
	JsonVO<uint64_t> execModifyCgthckBill(const AddCgthckBillDTO& dto);
	// ��������
	JsonVO<uint64_t> execModifyCgthckApproval(const ModifyCgthckBillDTO& dto, const PayloadDTO& payload);
	// �޸ĵ���״̬
	// �ر�
	JsonVO<uint64_t> execModifyCgthcStatusToClose (const ModifyCgthckBillDTO& dto, const PayloadDTO& payload);
	// ���ر�
	JsonVO<uint64_t> execModifyCgthcStatusToUnclose(const ModifyCgthckBillDTO& dto, const PayloadDTO& payload);
	// ����
	JsonVO<uint64_t> execModifyCgthcStatusToVoided(const ModifyCgthckBillDTO& dto, const PayloadDTO& payload);
	// ����ɾ������
	JsonVO<uint64_t> execDeleteCgthckBill(const DeleteCgthckBillDTO& dto);
	// ����ɾ����ϸ
	JsonVO<uint64_t> execDeleteCgthckBillDetail(const DeleteCgthckBillDTO& dto);
	// �����ύJSON
	// �����ļ�����
	JsonVO<uint64_t> execImportCgthckFile(const ImportCgthckFileDTO& dto);
	// �����ļ�����
	JsonVO<uint64_t> execExportCgthckFile(const ExportCgthckFileDTO& dto);
};


#endif // !_CGTHCK_CONTROLLER_

