#include "stdafx.h"
#include "SupplierController.h"

JsonVO<PageVO<AdvancedQueryVO>>  SupplierController::execAdvancedQuerySupplier(const AdvancedQuery& query)
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
JsonVO<SpecifiedSupplierDataQueryVO> SupplierController::execSpecifiedQuerySupplier(const SpecifiedSupplierDataQuery& query)
{
	


	JsonVO<SpecifiedSupplierDataQueryVO> result;  
	return result;
}


JsonVO<uint64_t> SupplierController::execAddSupplier(const AddSupplierDTO& dto)
{
	int code = dto.getCode();
	string name = dto.getName();
	string alias = dto.getAlias();
	string enable = dto.getEnable();
	string accessibleName = dto.getAccessibleName();
	if (code == NULL||name==NULL|| alias==NULL||enable==NULL||accessibleName==NULL)
	{
		JsonVO<uint64_t> result; 
		result.fail(code);//ʹ��״̬��
		return result;
	}
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


