/*
 Copyright Zero One Star. All rights reserved.

 @Author: QZP
 @Date: 2023/2/15 17:57:26

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

	  https://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
*/
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


