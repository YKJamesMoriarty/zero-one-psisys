
#include "stdafx.h"
#include "QtrkController.h"
#include"service/Qtrk/QtrkService.h"
//#include "../../service/sample/SampleService.h"

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

JsonVO<uint64_t> QtrkController::execAddQtrk(const AddQtrkBillDTO& dto)
{
	JsonVO<uint64_t> result;
	//SampleService service;
	//ִ����������
	uint64_t id=1; //= service.saveData(dto);
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
	QtrkService cs;
	JsonVO<uint64_t> result;

	if (cs.updataBillStatus(dto)) {
		result.success(1);
	}
	else
	{
		result.fail(0);
	}
	return result;
}

JsonVO<uint64_t> QtrkController::execRemoveQtrk(const DeleteQtrkBillDTO& dto)
{
	JsonVO<uint64_t> result;
	//ִ������ɾ��
	QtrkService cs;

	if (cs.deleteBill(dto)) {
		result.success(1);
	}
	else
	{
		result.fail(0);
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
