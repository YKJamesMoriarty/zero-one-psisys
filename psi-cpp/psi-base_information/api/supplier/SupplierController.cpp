#include "stdafx.h"
#include "SupplierController.h"

JsonVO<PageVO<AdvancedQueryVO>> execAdvancedQuerySupplier(const AdvancedQuery& query)
{
	//����һ��Service
	//SampleService service;
	//��ѯ����
	//PageVO<SampleVO> result = service.listAll(query);
	//��Ӧ���
	PageVO< AdvancedQueryVO> data;

	JsonVO<PageVO<AdvancedQueryVO>> result;
	result.success(data);
	return result;

}


JsonVO<SpecifiedSupplierDataQuery> exeSpecifiedexecQuerySupplier(const SpecifiedSupplierDataQuery& query)
{



	JsonVO<SpecifiedSupplierDataQuery> result;
	return result;
}


JsonVO<uint64_t> execAddSupplier(const AddSupplierDTO& dto)
{


	JsonVO<uint64_t> result;
	return result;

}

JsonVO<uint64_t> execModifySupplier(const ModifySupplierDTO& dto)
{


	JsonVO<uint64_t> result;
	return result;

}

JsonVO<uint64_t> execDeleteSupplier(const DeleteSupplierDTO& dto)
{



	JsonVO<uint64_t> result;
	return result;

}


