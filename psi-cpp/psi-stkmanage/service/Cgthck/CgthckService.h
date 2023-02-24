#pragma once
#ifndef _CGTHCK_SERVICE_
#define _CGTHCK_SERVICE_

#include "../../domain/vo/PageVO.h"
#include "../../dao/Cgthck/CgthckDAO.h"
#include "../../domain/do/Cgthck/CgthckDO.h"
#include "../../domain/vo/Cgthck/QueryCgthckBillVO.h"
#include "../../domain/query/Cgthck/QueryCgthckBillQuery.h"
#include "../../domain/dto/Cgthck/AddCgthckBillDTO.h"
#include "../../domain/dto/Cgthck/DeleteCgthckBillDTO.h"
#include "../../domain/dto/Cgthck/ExportCgthckFileDTO.h"
#include "../../domain/dto/Cgthck/ImportCgthckFileDTO.h"
#include "../../domain/dto/Cgthck/ModifyCgthckBillDTO.h"

class CgthckService
{
public:
	// ��ҳ��ѯ����
	PageVO<QueryCgthckBillVO> listAll(const QueryCgthckBillQuery& query);
	// ��Ӳɹ��˻����ⵥ(����/�ύ)
	uint64_t saveData(const AddCgthckBillDTO& dto);
	// �޸Ĳɹ��˻����ⵥ������/�ύ/��ˣ�
	int updateData(const AddCgthckBillDTO& dto);
	// ��˵���
	bool updateApproval(const ModifyCgthckBillDTO& dto);
	// ɾ���ɹ��˻����ⵥ
	bool removeData(uint64_t id);
	// �޸ĵ���״̬���ر�/����/���رգ�
	bool closed(const ModifyCgthckBillDTO& dto);
	bool unclosed(const ModifyCgthckBillDTO& dto);
	bool voided(const ModifyCgthckBillDTO& dto);
	// ����
	// ����
};


#endif // !_CGTHCK_SERVICE_


