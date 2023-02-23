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
	// ��ѯ���ݽӿ�
	CREATE_API_FUN_QUERY(queryCgthcBillk, execQueryCgthckBill, QueryCgthckBillQuery);
	// ��ѯָ��������ϸ�ӿ�
	CREATE_API_FUN_QUERY(queryCgthckBillDetail, execQueryCgthckBillDetail, QueryCgthckBillQuery);
	// ��Ӳɹ��˻�����(����)���ݽӿ�
	CREATE_API_FUN_JSON(addCgthckBill, execAddCgthckBill, AddCgthckBillDTO);
	// �޸Ĳɹ��˻�����(����)���ݽӿ�
	CREATE_API_FUN_BODY(modifyCgthckBill, execModifyCgthckBill, ModifyCgthckBillDTO);
	// ɾ���ɹ��˻�����(����)���ݽӿ�
	CREATE_API_FUN_BODY(deleteCgthckBill, execDeleteCgthckBill, DeleteCgthckBillDTO);
	// ����
	CREATE_API_FUN_BODY(importCgthckFile, execImportCgthckFile, ImportCgthckFileDTO);
	// ����
	CREATE_API_FUN_BODY(exportCgthckFile, execExportCgthckFile, ExportCgthckFileDTO);
private:
	// ���Բ�ѯ����
	JsonVO<PageVO<QueryCgthckBillVO>> execQueryCgthckBill(const QueryCgthckBillQuery& query);
	// ���Բ�ѯ��ϸ����
	JsonVO<PageVO<QueryCgthckBillDetailVO>> execQueryCgthckBillDetail(const QueryCgthckBillQuery& query);
	// ���Է�¼��ѯ�ɹ���ⵥ�б�	
	JsonVO<PageVO<QueryCgrkBillListsVO>> execQueryCgrkBillList(const QueryCgrkBillQuery& query);
	// �����������
	JsonVO<uint64_t> execAddCgthckBill(const AddCgthckBillDTO& dto);
	// �����޸�����
	JsonVO<uint64_t> execModifyCgthckBill(const ModifyCgthckBillDTO& dto);
	// ����ɾ������
	JsonVO<uint64_t> execDeleteCgthckBill(const DeleteCgthckBillDTO& dto);
	// �����ύJSON
	// �����ļ�����
	JsonVO<uint64_t> execImportCgthckFile(const ImportCgthckFileDTO& dto);
	// �����ļ�����
	JsonVO<uint64_t> execExportCgthckFile(const ExportCgthckFileDTO& dto);
};


#endif // !_CGTHCK_CONTROLLER_

