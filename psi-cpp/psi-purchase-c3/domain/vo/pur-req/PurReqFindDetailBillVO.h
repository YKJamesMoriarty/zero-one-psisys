#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: akun
 @Date: 2023/2/14 10:54:03

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
#ifndef _PUR_RER_FIND_DETAIL_BILL_VO_H_
#define _PUR_RER_FIND_DETAIL_BILL_VO_H_

#include "../../GlobalInclude.h"
#include "PurReqFindBillVO.h"
#include "PurReqDetailBillVO.h"

/*
��ѯ�����б���ʾ����
*/
//��ע:��ĺ�������ֶ�������Ҫ����
class PurReqFindDetailBillVO : public PurReqFindBillVO {
	//��ϸ�б�
	CC_SYNTHESIZE(list<PurReqDetailBillVO>, detailBillsVO, DetailBillsVO);

public:
	// ��JSONת������
	BIND_TO_JSON(PurReqFindDetailBillVO, bill_no, bill_date, is_effective, is_closed,\
		is_voided,subject, pur_type, requester, request_dept, request_time, ordered_qty, detailBillsVO);
};
#endif // 
