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
	//��ѯ���ݣ����ģ�
	SpecifiedSupplierDataQueryVO result = service.specifiedListSupplierData(query);
	//���ؽ��
	return JsonVO<SpecifiedSupplierDataQueryVO>(result, RS_SUCCESS);
}

//��ӹ�Ӧ��
JsonVO<string> SupplierController::execAddSupplier(const AddSupplierDTO& dto, const PayloadDTO& payload)//����string��������Ϊcode��string����
{
	JsonVO<string> result;//�����ļ������·��
	SupplierService service;
	//��������ϴ��ļ�·���б�
	for (auto file : dto.getFiles()) {
		std::cout << "path " << file << std::endl;
	}
	//���ݿ���Ҫ��ǿ����ݵļ��
	if (dto.getCode().empty()|| dto.getName().empty() || dto.getAux_Name().empty() || dto.getIs_Enabled() == -2)
	{
		result.fail(dto.getID());//ʹ��״̬��
		return result;
	}
	//ִ�����ݲ������ݿ�    (����)
	uint64_t id =service.addSupplierData(dto, payload);
	cout <<"user_name"<< payload.getUsername() << endl;
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
		result.fail(dto.getID());
	}
	return result;
}
//�޸�
JsonVO<string> SupplierController::execModifySupplier(const ModifySupplierDTO& dto, const PayloadDTO& payload)//����string��������Ϊcode��string����
{
	JsonVO<string> result;//�����ļ������·��
	SupplierService service;

	//��������ϴ��ļ�·���б�
	for (auto file : dto.getFiles()) {
		std::cout << "path " << file << std::endl;
	}
	//���ݿ���Ҫ��ǿ����ݵļ��
	if (dto.getCode().empty()|| dto.getName().empty()|| dto.getAux_Name().empty() || dto.getIs_Enabled() == -2)
	{

		JsonVO<string> result;
		result.fail(dto.getID());//ʹ��״̬��
		return result;
	}
	//ִ�����ݲ������ݿ�
	uint64_t id = service.modifySupplierData(dto, payload);
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
		result.fail(dto.getID());
	}
	return result;

}

JsonVO<string> SupplierController::execDeleteSupplier(const DeleteSupplierDTO& dto)//����string��������Ϊcode��string����
{
	SupplierService service;
	JsonVO<string> result;
	//ִ������ɾ��
	DeleteSupplierDTO delete_supplier_code;
	delete_supplier_code.setID(dto.getID());
	if (service.deleteSupplierData(delete_supplier_code) )
	{
		result.success(dto.getID());
	}
	else
	{
		result.fail(dto.getID());
	}
	return result;
}








