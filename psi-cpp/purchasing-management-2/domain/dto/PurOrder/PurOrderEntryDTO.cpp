/*
 Copyright Zero One Star. All rights reserved.

 @Author: qingyu
 @Date: 2023/02/15 11:59:38

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
#include "PurOrderEntryDTO.h"
void from_json(const json& j, PurOrderEntryDTO& t) { // NOLINT
	//ID
	BIND_FROM_TO_NORMAL(j, t, id);
	//����
	BIND_FROM_TO_NORMAL(j, t, mid);
	//���ݺ�
	BIND_FROM_TO_NORMAL(j, t, bill_no);
	//��¼��
	BIND_FROM_TO_I(j, t, entry_no);
	//Դ������
	BIND_FROM_TO_NORMAL(j, t, src_bill_type);
	//srcBillId
	BIND_FROM_TO_NORMAL(j, t, src_bill_id);
	//Դ����¼id
	BIND_FROM_TO_NORMAL(j, t, src_entry_id);
	//Դ����¼��
	BIND_FROM_TO_NORMAL(j, t, src_no);
	//����
	BIND_FROM_TO_NORMAL(j, t, material_id);
	//������λ
	BIND_FROM_TO_NORMAL(j, t, unit_id);
	//����
	BIND_FROM_TO_D(j, t, qty);
	//˰��%
	BIND_FROM_TO_D(j, t, tax_rate);
	//��˰����
	BIND_FROM_TO_D(j, t, price);
	//�ۿ���%
	BIND_FROM_TO_D(j, t, discount_rate);
	//˰��
	BIND_FROM_TO_D(j, t, tax);
	//��˰���
	BIND_FROM_TO_D(j, t, amt);
	//���������
	BIND_FROM_TO_D(j, t, in_qty);
	//�����ɱ�
	BIND_FROM_TO_D(j, t, in_cost);
	//��������
	BIND_FROM_TO_D(j, t, settle_qty);
	//������
	BIND_FROM_TO_D(j, t, settle_amt);
	//�ѿ�Ʊ����
	BIND_FROM_TO_D(j, t, invoiced_qty);
	//�ѿ�Ʊ���
	BIND_FROM_TO_D(j, t, invoiced_amt);
	//��ע
	BIND_FROM_TO_NORMAL(j, t, remark);
	//�Զ���1
	BIND_FROM_TO_NORMAL(j, t, custom1);
	//�Զ���2
	BIND_FROM_TO_NORMAL(j, t, custom2);
	//�汾
	BIND_FROM_TO_I(j, t, version);
}