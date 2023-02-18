/*Author:Satan*/
#pragma once
#ifndef _SUPPLIER_CONTROLLER_
#define _SUPPLIER_CONTROLLER_

#include "../../domain/dto/supplierDTO/AddSupplierDTO.h"
#include "../../domain/dto/supplierDTO/DeleteSupplierDTO.h"
#include "../../domain/dto/supplierDTO/ModifySupplierDTO.h"
#include "../../domain/dto/IDDTO.h"
#include "../../domain/dto/FileDTO.h"
#include "../../domain/vo/supplierVO/AdvancedQueryVO.h"
#include "../../domain/vo/supplierVO/SpecifiedSupplierDataQueryVO.h"
#include "../../domain/vo/PageVO.h"
#include "../../domain/vo/JsonVO.h"
#include "../../domain/query/PageQuery.h"
#include "../../domain/query/supplierQuery/AdvancedQuery.h"
#include "../../domain/query/supplierQuery/SpecifiedSupplierDataQuery.h"


class SupplierController
{
	public:                                                                                
	CREATE_API_FUN_QUERY(advancedquerySupplier,execAdvancedQuerySupplier,AdvancedQuery);//AdvancedQuery�ǲ�ѯʱҪ����Ķ���
	/*��Ҳ�Ƕ��庯�����������涨��ĺ���querySample�����executeXXX�����ҹ涨�������ͣ�Ȼ��궨��ĺ���querySample��Router����*/
	CREATE_API_FUN_QUERY(specifiedquerySupplier,execSpecifiedQuerySupplier,SpecifiedSupplierDataQuery);//�����е��µı���
	//��ӹ�Ӧ�̲��ϴ��ļ�
	CREATE_API_FUN_BODY_FILE(addSupplier, execAddSupplier, AddSupplierDTO);
	CREATE_API_FUN_BODY(modifySupplier, execModifySupplier, ModifySupplierDTO);
	CREATE_API_FUN_BODY(deleteSupplier, execDeleteSupplier, DeleteSupplierDTO);

private:
	//�߼���ѯ����--��ҳ��ѯ
	JsonVO<PageVO<AdvancedQueryVO>> execAdvancedQuerySupplier(const AdvancedQuery& query);
	//��ѯָ����Ӧ������--���Ƿ�ҳ��ѯ
	JsonVO<SpecifiedSupplierDataQueryVO> execSpecifiedQuerySupplier(const SpecifiedSupplierDataQuery& query);//������һ��
	//��������
	JsonVO<uint64_t> execAddSupplier(const AddSupplierDTO& dto);
	//�޸�����
	JsonVO<uint64_t> execModifySupplier(const ModifySupplierDTO& dto);
	//ɾ������
	JsonVO<uint64_t> execDeleteSupplier(const DeleteSupplierDTO& dto);

};

#endif // _SUPPLIER_CONTROLLER_