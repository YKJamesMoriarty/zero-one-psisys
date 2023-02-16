#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: Adam
 @Date: 2023��2��15��

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
#ifndef _PUR_REQ_MOD_BILL_STATUS_VO_
#define _PUR_REQ_MOD_BILL_STATUS_VO_

#include "../../GlobalInclude.h"

//���ǵ��޸ĺ���Ӳɹ������Ĳ����������Ժϲ�Ϊһ��DTO
//��Ӷ�����DTO(��������ϸ����),ͬʱ�����и������ݿ������,���Լ̳�FileDTO
class PurReqModBillStatusVO
{
	//���ݱ��
	CC_SYNTHESIZE(string, billNo, BillNo);
public:

	//��JSONת������
	BIND_TO_JSON(PurReqModBillStatusVO, billNo);
};

#endif // !_PUR_REQ_MOD_BILL_STATUS_VO_