#pragma once
#ifndef _SUPPLIER_CONTROLLER_
#define _SUPPLIER_CONTROLLER_



#include "../../domain/dto/supplier/AddSupplierDTO.h"
#include "../../domain/dto/supplier/DeleteSupplierDTO.h"
#include "../../domain/dto/supplier/ModifySupplierDTO.h"
#include "../../domain/dto/IDDTO.h"
#include "../../domain/dto/FileDTO.h"
#include "../../domain/vo/supplier/AdvancedQueryVO.h"
#include "../../domain/vo/supplier/SpecifiedSupplierDataQueryVO.h"
#include "../../domain/vo/PageVO.h"
#include "../../domain/vo/JsonVO.h"
#include "../../domain/query/PageQuery.h"
#include "../../domain/query/supplier/AdvancedQuery.h"
#include "../../domain/query/supplier/SpecifiedSupplierDataQuery.h"

//
//class SupplierController
//{
//	public:
//	CREATE_API_FUN_QUERY_PAYLOAD(advancedquerySupplier, execAdvancedQuerySupplier, AdvancedQuery);
//	CREATE_API_FUN_QUERY_PAYLOAD(specifiedquerySupplier, SpecifiedexecQuerySupplier, SpecifiedSupplierDataQuery);
//	CREATE_API_FUN_BODY(addSupplier, execAddSupplier, AddSupplierDTO);
//	CREATE_API_FUN_BODY(modifySupplier, execModifySupplier, ModifySupplierDTO);
//	CREATE_API_FUN_BODY(deleteSupplier, execDeleteSupplier, DeleteSupplierDTO);
//	//CREATE_API_FUN_BODY(removeById, execRemoveById, IntID);
//	//CREATE_API_FUN_JSON(jsonSample, execJsonSample, SampleDTO);
//
//private:
//	//��ʾ�߼���ѯ����
//	JsonVO<PageVO<AdvancedQueryVO>> execAdvancedQuerySupplier(const AdvancedQuery& query);
//	//��ʾ��ѯָ����Ӧ������
//	JsonVO<PageVO<SpecifiedSupplierDataQuery>> SpecifiedexecQuerySupplier(const SpecifiedSupplierDataQuery& query);
//	//��ʾ��������
//	JsonVO<uint64_t> execAddSupplier(const AddSupplierDTO& dto);
//	//��ʾ�޸�����
//	JsonVO<uint64_t> execModifySupplier(const ModifySupplierDTO& dto);
//	//��ʾɾ������
//	JsonVO<uint64_t> execDeleteSupplier(const DeleteSupplierDTO& dto);
//	//JsonVO<uint64_t> execRemoveById(const IntID& id);
//
//};
//
#endif // _SUPPLIER_CONTROLLER_