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

JsonVO<PurComFindDetailBillVO> PurCompareController::execQueryPurComFindDetailBill(const string& query, const PayloadDTO& payload)
{
	////����һ��Service
	//SampleService service;
	////��ѯ����
	//PageVO<SampleVO> result = service.listAll(query);
	////��Ӧ���
	PurComFindDetailBillVO result;
	return JsonVO<PurComFindDetailBillVO>(result, RS_SUCCESS);
}

JsonVO<PageVO<PurComListVO>> PurCompareController::execQueryPurComList(const string& query, const PayloadDTO& payload)
{
	////����һ��Service
	//SampleService service;
	////��ѯ����
	//PageVO<SampleVO> result = service.listAll(query);
	////��Ӧ���
	PageVO<PurComListVO> result;
	return JsonVO<PageVO<PurComListVO>>(result, RS_SUCCESS);
}

JsonVO<PageVO<PurComDividedListVO>> PurCompareController::execQueryPurComDividedList(const string& query, const PayloadDTO& payload)
{
	////����һ��Service
	//SampleService service;
	////��ѯ����
	//PageVO<SampleVO> result = service.listAll(query);
	////��Ӧ���
	PageVO<PurComDividedListVO> result;
	return JsonVO<PageVO<PurComDividedListVO>>(result, RS_SUCCESS);
}


