
#include "stdafx.h"
#include "PurCompareController.h"
//#include "../../service/sample/SampleService.h"
JsonVO<PageVO<PurComFindBillVO>> PurCompareController::execQueryPurComFindBill(const PurComFindBillQuery& query, const PayloadDTO& payload)
{
	////����һ��Service
	//SampleService service;
	////��ѯ����
	//PageVO<SampleVO> result = service.listAll(query);
	////��Ӧ���
	//�����������ڲ���Apipost
	PurComFindBillVO test1;
	list<PurComFindBillVO> ls; ls.push_back(test1);
	PageVO<PurComFindBillVO> result(1,2,0,0,ls);
	//PageVO<PurComFindBillVO> result;
	return JsonVO<PageVO<PurComFindBillVO>>(result, RS_SUCCESS);
}

JsonVO<PurComFindDetailBillVO> PurCompareController::execQueryPurComFindDetailBill(const PurComFindDetailBillQuery& query, const PayloadDTO& payload)
{
	////����һ��Service
	//SampleService service;
	////��ѯ����
	//PageVO<SampleVO> result = service.listAll(query);
	////��Ӧ���

	PurComFindDetailBillVO result;
	return JsonVO<PurComFindDetailBillVO>(result, RS_SUCCESS);
}

JsonVO<PageVO<PurComListVO>> PurCompareController::execQueryPurComList(const PurComListQuery& query, const PayloadDTO& payload)
{
	////����һ��Service
	//SampleService service;
	////��ѯ����
	//PageVO<SampleVO> result = service.listAll(query);
	////��Ӧ���
	PageVO<PurComListVO> result;
	return JsonVO<PageVO<PurComListVO>>(result, RS_SUCCESS);
}

JsonVO<PageVO<PurComDividedListVO>> PurCompareController::execQueryPurComDividedList(const PurComDividedListQuery& query, const PayloadDTO& payload)
{
	////����һ��Service
	//SampleService service;
	////��ѯ����
	//PageVO<SampleVO> result = service.listAll(query);
	////��Ӧ���
	PageVO<PurComDividedListVO> result;
	return JsonVO<PageVO<PurComDividedListVO>>(result, RS_SUCCESS);
}

//��ʾ�����ȼ�
JsonVO<uint64_t> PurCompareController::execAddPurCom(const AddPurComDTO& dto)
{
	JsonVO<uint64_t> result;
	// �ӿڲ���
	/*result.success(1);*/
	return result;
}
//��ʾ�޸ıȼ�
JsonVO<uint64_t> PurCompareController::execModifyPurCom(const ModPurComDTO& dto) {
	JsonVO<uint64_t> result;
	return result;
}
//��ʾɾ���ȼ�
JsonVO<uint64_t> PurCompareController::execRemovePurCom(const DelPurComDTO& dto) {
	JsonVO<uint64_t> result;
	return result;
}
//��ʾ�޸ĵ���״̬
JsonVO<uint64_t> PurCompareController::execPurComModBillStatus(const PurComModBillStatusDTO& dto) {
	JsonVO<uint64_t> result;
	return result;
}


//����
nlohmann::json PurCompareController::execPurComExport(const PurComExportQuery& dto, const PayloadDTO& payload)
{
	//��Ӧ���
	return nlohmann::json(JsonVO<std::string>());
}

//����
JsonVO<uint64_t> PurCompareController::execPurComInto(const PurComIntoDTO& dto)
{
	//��Ӧ���
	return JsonVO<uint64_t>();
}