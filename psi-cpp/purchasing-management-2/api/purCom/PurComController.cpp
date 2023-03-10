/*
 Copyright Zero One Star. All rights reserved.

 @Author: qingyu
@Date: 2023/02/16 0:23:02

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
#include "PurComController.h"
#include "../../service/purCom/PurComService.h"

// ��ѯlist����
// �����ˣ�J4nnA
JsonVO<PageVO<PurComVO>> PurComController::execListPurCom(const PurComQuery& query, const PayloadDTO& payload) {
	// ����һ��Service
	PurComService service;
	// ��ѯ����
	PageVO<PurComVO> result = service.listAll(query);
	// ��Ӧ���
	return JsonVO<PageVO<PurComVO>>(result, RS_SUCCESS);
}


// ��ѯָ���ȼ۵�����ϸ�б�
// �����ˣ�J4nnA
JsonVO<PageVO<PurComEntryVO>> PurComController::execListPurComEntrys(const PurComEntryQuery& query, const PayloadDTO& payload)
{
	// ����һ��Service
	PurComService service;
	// ��ѯ����
	PageVO<PurComEntryVO> result = service.listEntry(query);

	// ��Ӧ���
	return JsonVO<PageVO<PurComEntryVO>>(result, RS_SUCCESS);
}

// ��ѯѯ�۵���¼�б�
// �����ˣ�c3����
JsonVO<list<PurOrderDividedListVO>> PurComController::execQueryPurOrderDividedList(const PurOrderDividedListQuery& query, const PayloadDTO& payload) {
	//�������ض���
	list<PurOrderDividedListVO> result;
	
	//����У��
	if (query.getBillNo() == "") return JsonVO<list<PurOrderDividedListVO>>(result, RS_PARAMS_INVALID);

	//����У��ɹ�,���ض�Ӧ�Ķ���
	PurComService service;
	result = service.listPurOrderDividedListDO(query);

	return JsonVO<list<PurOrderDividedListVO>>(result, RS_SUCCESS);
}