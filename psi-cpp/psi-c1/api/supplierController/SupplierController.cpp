#include "stdafx.h"
#include "SupplierController.h"
#include "../../service/supplierService/service-supplier-satan/SupplierServiceSatan.h"
//�߼���ѯ
JsonVO<PageVO<AdvancedQueryVO>>  SupplierController::execAdvancedQuerySupplier(const AdvancedQuery & query, const PayloadDTO& payload)
{
	//����һ��Service
	SupplierService service;
	//��ѯ����
	PageVO<AdvancedQueryVO> result = service.advancedListSupplierData(query);
	//��Ӧ���
	return JsonVO<PageVO<AdvancedQueryVO>>(result, RS_SUCCESS);

}

//��ѯָ����Ӧ��
JsonVO<SpecifiedSupplierDataQueryVO> SupplierController::execSpecifiedQuerySupplier(const SpecifiedSupplierDataQuery& query)
{
	//����һ��Service
	SupplierService service;
	//��ѯ����
	SpecifiedSupplierDataQueryVO result = service.specifiedListSupplierData(query);
	//���ؽ��
	return JsonVO<SpecifiedSupplierDataQueryVO>(result, RS_SUCCESS);
}

//��ӹ�Ӧ��
JsonVO<string> SupplierController::execAddSupplier(const AddSupplierDTO& dto)//����string��������Ϊcode��string����
{
	JsonVO<string> result;//�����ļ������·��
	SupplierService service;
	//��������ϴ��ļ�·���б�
	for (auto file : dto.getFiles()) {
		std::cout << "path " << file << std::endl;
	}
	//���ݿ���Ҫ��ǿ����ݵļ��
	if (dto.getCode() == NULL || dto.getName() == NULL || dto.getAux_Name() == NULL || dto.getIs_Enabled() == NULL)
	{
		
		JsonVO<string> result;
		result.fail(dto.getCode());//ʹ��״̬��
		return result;
	}
	//ִ�����ݲ������ݿ�
	uint64_t id =service.addSupplierData(dto);
	//�жϲ����Ƿ�ɹ�
	if (id > 0) 
	{
		
		string file_router;
		for (auto file_segment : dto.getFiles())
		{
			file_router = file_router + file_segment;
		}
		result.success(file_router);
	}
	else
	{
		result.fail(dto.getCode());
	}
	return result;
}

JsonVO<string> SupplierController::execModifySupplier(const ModifySupplierDTO& dto)//����string��������Ϊcode��string����
{
	JsonVO<string> result;//�����ļ������·��
	SupplierService service;

	//��������ϴ��ļ�·���б�
	for (auto file : dto.getFiles()) {
		std::cout << "path " << file << std::endl;
	}
	//���ݿ���Ҫ��ǿ����ݵļ��
	if (dto.getCode() == NULL || dto.getName() == NULL || dto.getAux_Name() == NULL || dto.getIs_Enabled() == NULL)
	{

		JsonVO<string> result;
		result.fail(dto.getCode());//ʹ��״̬��
		return result;
	}
	//ִ�����ݲ������ݿ�
	uint64_t id = service.modifySupplierData(dto);
	//�жϲ����Ƿ�ɹ�
	if (id > 0)
	{

		string file_router;
		for (auto file_segment : dto.getFiles())
		{
			file_router = file_router + file_segment;
		}
		result.success(file_router);
	}
	else
	{
		result.fail(dto.getCode());
	}
	return result;

}

JsonVO<string> SupplierController::execDeleteSupplier(const DeleteSupplierDTO& dto)//����string��������Ϊcode��string����
{
	SupplierService service;
	JsonVO<string> result;
	//ִ������ɾ��
	DeleteSupplierDTO delete_supplier_code;
	delete_supplier_code.setCode(dto.getCode());
	if (service.deleteSupplierData(delete_supplier_code) )
	{
		result.success(dto.getCode());
	}
	else
	{
		result.fail(dto.getCode());
	}
	return result;
}








