#pragma once
#ifndef _CGTHCK_SERVICE_
#define _CGTHCK_SERVICE_

#include "ExcelComponent.h"
#include "FastDfsClient.h"
#include "CharsetConvertHepler.h"
#include "../../domain/vo/PageVO.h"
#include "../../dao/Cgthck/CgthckDAO.h"
#include "../../domain/do/Cgthck/CgthckDO.h"
#include "../../domain/vo/Cgthck/QueryCgrkBillListsVO.h"
#include "../../domain/vo/Cgthck/QueryCgthckBillVO.h"
#include "../../domain/query/Cgthck/QueryCgrkBillQuery.h"
#include "../../domain/query/Cgthck/QueryCgthckBillQuery.h"
#include "../../domain/dto/Cgthck/AddCgthckBillDTO.h"
#include "../../domain/dto/Cgthck/DeleteCgthckBillDTO.h"
#include "../../domain/dto/Cgthck/ExportCgthckFileDTO.h"
#include "../../domain/dto/Cgthck/ImportCgthckFileDTO.h"
#include "../../domain/dto/Cgthck/ModifyCgthckBillDTO.h"

class CgthckService
{
public:
	// �ɹ���ⵥ��¼��ѯ����
	std::list<QueryCgrkBillListsVO> listAll(const QueryCgrkBillQuery& query);
	// ��Ӳɹ��˻����ⵥ(����/�ύ)
	int saveData(const AddCgthckBillDTO& dto);
	// �޸Ĳɹ��˻����ⵥ������/�ύ/��ˣ�
	int updateData(const AddCgthckBillDTO& dto);
	// ��˵���
	int updateApproval(const ModifyCgthckBillDTO& dto, const PayloadDTO& payload);
	// ɾ���ɹ��˻����ⵥ
	int removeData(const DeleteCgthckBillDTO& dto);
	// ɾ���ɹ��˻�����ϸ
	int removeEntry(const DeleteCgthckBillDTO& dto);
	// �޸ĵ���״̬���ر�/����/���رգ�
	// �ر�
	int closed(const ModifyCgthckBillDTO& dto, const PayloadDTO& payload);
	// ���ر�
	int unclosed(const ModifyCgthckBillDTO& dto, const PayloadDTO& payload);
	// ����
	int voided(const ModifyCgthckBillDTO& dto, const PayloadDTO& payload);
	// ����
	int importData(const ImportCgthckFileDTO& dto);
	// ����
	int exportData(const ExportCgthckFileDTO& dto);
};


#endif // !_CGTHCK_SERVICE_


