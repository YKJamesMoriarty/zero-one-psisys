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
#ifndef _PUR_RER_FIND_DETAIL_BILL_VO_
#define _PUR_RER_FIND_DETAIL_BILL_VO_

#include "../../GlobalInclude.h"
#include "PurReqFindBillVO.h"

/*
��ѯ�����б���ʾ����
*/
//��ע:��ĺ�������ֶ�������Ҫ����
class PurReqFindDetailBillVO : public PurReqFindBillVO {
	//Դ����¼��
	CC_SYNTHESIZE(string, src_no, Src_no);
	//����
	CC_SYNTHESIZE(string, material_id, Material_id);
	//�����ͺ�---------->�����ͺ�ʹ�õ�pur_req_entry���е�Դ������
	CC_SYNTHESIZE(string, src_bill_type, Src_bill_type);
	//��λ
	CC_SYNTHESIZE(string, unit_id, Unit_id);
	//����
	CC_SYNTHESIZE(string, qty, Qty);
	//�Ѷ�����
	CC_SYNTHESIZE(double, ordered_qty, Ordered_qty);
	//˰��
	CC_SYNTHESIZE(double, tax_rate, Tax_rate);
	//�ο���˰����
	CC_SYNTHESIZE(double, price, Price);
	//�ο���˰���
	CC_SYNTHESIZE(double, amt, Amt);
	//���鹩Ӧ��
	CC_SYNTHESIZE(string, suggest_supplier_id, Suggest_supplier_id);
	//��ע
	CC_SYNTHESIZE(string, remark, Remark);
	//�Զ���1
	CC_SYNTHESIZE(string, custom1, Custom1);
	//�Զ���2
	CC_SYNTHESIZE(string, custom2, Custom2);

public:
	// ��JSONת������
	BIND_TO_JSON(PurReqFindDetailBillVO, bill_no, bill_date, subject, src_no, pur_type,
		request_dept, requester, request_time, qty, ordered_qty, amt, bill_stage,
		is_effective, is_closed, is_voided, remark, is_auto, is_rubric, effective_time,
		approver, create_time, create_by, sys_org_code, update_time, update_by,
		src_no, material_id, src_bill_type, unit_id, qty, ordered_qty, tax_rate,
		price, amt, suggest_supplier_id, remark, custom1, custom2);
};
#endif // !
