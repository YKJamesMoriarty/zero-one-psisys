#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: Eleanor
 @Date: 2023/2/15 14:42

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
#ifndef _ENTRY_PUR_INQUIRY_VO_
#define _ENTRY_PUR_INQUIRY_VO_
#include "../../GlobalInclude.h"

/**
 * ��ʾ���� ���� �ɹ�ѯ�۵���ϸ�б������ɹ����뵥��Ϣ
 */


//�ɹ�ѯ�۵���ϸ���ɹ����뵥
class EntryPurInquiryVO
{
	//Դ������
	CC_SYNTHESIZE(string, purReqSrcBillType, PurReqSrcBillType);
	//Դ����¼��
	CC_SYNTHESIZE(string, purReqSrcEntryNo, PurReqSrcEntryNo);
	//����
	CC_SYNTHESIZE(string, purReqMaterialId, PurReqMaterialId);


	//����ͺţ������ӿڣ�


	//��λ
	CC_SYNTHESIZE(string, purReqUnitId, PurReqUnitId);
	//����
	CC_SYNTHESIZE(double, purReqQty, PurReqQty);
	//˰��%
	CC_SYNTHESIZE(double, purReqTaxRate, PurReqTaxRate);
	//�ο���˰����
	CC_SYNTHESIZE(double, purReqPrice, PurReqPrice);
	//�ο���˰���
	CC_SYNTHESIZE(double, purReqAmt, PurReqAmt);
	//��ע
	CC_SYNTHESIZE(string, purReqRemark, PurReqRemark);
	//�Զ���1
	CC_SYNTHESIZE(string, purReqCustom1, PurReqCustom1);
	//�Զ���2
	CC_SYNTHESIZE(string, purReqCustom2, PurReqCustom2);

public:
	// ��JSONת������
	BIND_TO_JSON(EntryPurInquiryVO, purReqSrcBillType, purReqSrcEntryNo, purReqMaterialId, purReqUnitId,
					purReqQty, purReqTaxRate, purReqPrice, purReqAmt, purReqRemark, purReqCustom1, purReqCustom2);
};


#endif // !_ENTRY_PUR_INQUIRY_VO_