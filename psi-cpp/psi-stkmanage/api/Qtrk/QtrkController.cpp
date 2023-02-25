#include "stdafx.h"
#include "QtrkController.h"
#include "../../service/Qtrk/QtrkService.h"

JsonVO<PageVO<QueryQtrkBillListVO>> QtrkController::execQueryQtrk(const QueryQtrkBillListQuery& query, const PayloadDTO& payload)
{
	//����һ��Service
	//SampleService service;
	//��ѯ����
	PageVO<QueryQtrkBillListVO> data;
	list<QueryQtrkBillListVO> rows;
	rows.push_back(QueryQtrkBillListVO());
	rows.push_back(QueryQtrkBillListVO());
	rows.push_back(QueryQtrkBillListVO());
	data.setRows(rows);
	//��Ӧ���
	return JsonVO<PageVO<QueryQtrkBillListVO>>(data, RS_SUCCESS);
}

JsonVO<PageVO<QueryQtrkBillDetailsVO>> QtrkController::execQueryDetailsQtrk(const QueryQtrkBillDetailsQuery& query, const PayloadDTO& payload)
{
	//����һ��Service
	//SampleService service;
	//��ѯ����
	PageVO<QueryQtrkBillDetailsVO> data;
	list<QueryQtrkBillDetailsVO> rows;
	rows.push_back(QueryQtrkBillDetailsVO());
	rows.push_back(QueryQtrkBillDetailsVO());
	rows.push_back(QueryQtrkBillDetailsVO());
	data.setRows(rows);
	//��Ӧ���
	return JsonVO<PageVO<QueryQtrkBillDetailsVO>>(data, RS_SUCCESS);
}

JsonVO<int> QtrkController::execAddQtrk(const AddQtrkBillDTO& dto, const PayloadDTO& payload)
{
	JsonVO<int> result;
	QtrkService service;
	//ִ����������
	int id = service.saveBillData(dto, payload);
	if (id > 0) {
		result.success(id);
	}
	else
	{
		result.fail(id);
	}
	//��Ӧ���
	return result;
}

JsonVO<uint64_t> QtrkController::execModifyQtrk(const ModifyQtrkBillDTO& dto)
{
	//SampleService service;
	JsonVO<uint64_t> result;
	if (1/*service.updateData(dto)*/) {
		result.success(1/*dto.getId()*/);
	}
	else
	{
		result.fail(1/*dto.getId()*/);
	}
	return result;
}

JsonVO<uint64_t> QtrkController::execRemoveQtrk(const DeleteQtrkBillDTO& dto)
{
	//SampleService service;
	JsonVO<uint64_t> result;
	//ִ������ɾ��
	if (1/*service.removeData(dto.getId())*/) {
		result.success(dto.getId());
	}
	else
	{
		result.fail(dto.getId());
	}
	//��Ӧ���
	return result;
}
//
//JsonVO<uint64_t> SampleController::execRemoveById(const IntID& id)
//{
//	SampleDTO dto;
//	dto.setId(id.getId());
//	return execRemoveSample(dto);
//}
//
//JsonVO<SampleVO> SampleController::execJsonSample(const SampleDTO& dto)
//{
//	//����һ������VO
//	SampleVO vo;
//	vo.setId(dto.getId());
//	vo.setName(dto.getName());
//	vo.setAge(dto.getAge());
//	vo.setSex(dto.getSex());
//
//	//��Ӧ���
//	return JsonVO<SampleVO>(vo, RS_API_UN_IMPL);
//}
//
JsonVO<uint64_t> QtrkController::execImportFileQtrk(const ImportQtrkFileDTO& dto)
{
	//JsonVO<string> result;
	//	//����һ������VO
	//	//��������ϴ��ļ�·���б�
	//	for (auto file : dto.getFiles()) {
	//		std::cout << "path " << file << std::endl;
	//	}

	//	
		//��Ӧ���
		return JsonVO<uint64_t>();
}
JsonVO<std::string> QtrkController::execExportFileQtrk()
{
	
	//return JsonVO<std::string>();
	


	//��Ӧ���

	return JsonVO<string>();
}
