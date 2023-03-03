
#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 10:59:38

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
#ifndef _MODIFY_CGRK_BILL_DTO_
#define _MODIFY_CGRK_BILL_DTO_

#include "../../GlobalInclude.h"
#include "CgrkBillEntryDTO.h"
#include "../FileDTO.h"

/**
 * �޸Ĳɹ���ⵥ������/���/�ύ��
 */
class ModifyCgrkBillDTO : public FileDTO
{

	//����
	//���ݱ��
	CC_SYNTHESIZE(string, billNo, BillNo);//�Զ�����
	//��������
	CC_SYNTHESIZE(string, billDate, BillDate);
	//��Ӧ��
	CC_SYNTHESIZE(string, supplierId, SupplierId);
	//��Ʊ����
	CC_SYNTHESIZE(string, invoiceType, InvoiceType);

	//ѡ��############
	//Դ����
	CC_SYNTHESIZE(string, srcNo, SrcNo);
	//��������
	CC_SYNTHESIZE(string, subject, Subject);
	//ҵ��Ա
	CC_SYNTHESIZE(string, operator1, Operator1);
	//ҵ����
	CC_SYNTHESIZE(string, opDept, OpDept);
	//��⾭��
	CC_SYNTHESIZE(string, handler, Handler);
	//��ע
	CC_SYNTHESIZE(string, remark, Remark);
	//����
	CC_SYNTHESIZE(string, attachment, Attachment);
	//�Ƿ��Ƕ�
	CC_SYNTHESIZE(int, hasSwell, HasSwell);
	//�Զ�����
	CC_SYNTHESIZE(int, isAuto, IsAuto);
	//������ϸ
	CC_SYNTHESIZE(list<CgrkBillEntryDTO>, entry, Entry);


	// ����or�ύ(0:����, 1:�ύ)
	CC_SYNTHESIZE(int, save, Save);

	//���
	CC_SYNTHESIZE(int, approve, Approve);
	//�����������
	CC_SYNTHESIZE(string, approvalResultType, ApprovalResultType);
	//�������
	CC_SYNTHESIZE(string, approvalRemark, ApprovalRemark);

public:
	// ��JSONת������
	friend void from_json(const json& j, ModifyCgrkBillDTO& t); // NOLINT

};

#endif // !_ADD_CGRK_BILL_DTO_