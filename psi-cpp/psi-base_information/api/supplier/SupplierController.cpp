#include "stdafx.h"
#include "SupplierController.h"

JsonVO<PageVO<AdvancedQueryVO>>  SupplierController::execAdvancedQuerySupplier(const AdvancedQuery& query)//1֪����
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

//���ﷵ��ֵ���ˣ�ͷ�ļ��ķ���ֵҲ���ˣ�����Щ��ok�ȵ�����һ��
JsonVO<PageVO<SpecifiedSupplierDataQueryVO>> SupplierController::execSpecifiedQuerySupplier(const SpecifiedSupplierDataQuery& query)
{



	JsonVO<PageVO<SpecifiedSupplierDataQueryVO>> result;   //����okokл��
	return result;
}


JsonVO<uint64_t> SupplierController::execAddSupplier(const AddSupplierDTO& dto)
{


	JsonVO<uint64_t> result;
	return result;

}

JsonVO<uint64_t> SupplierController::execModifySupplier(const ModifySupplierDTO& dto)
{


	JsonVO<uint64_t> result;
	return result;

}

JsonVO<uint64_t> SupplierController::execDeleteSupplier(const DeleteSupplierDTO& dto)
{



	JsonVO<uint64_t> result;
	return result;

}


