/*
 Copyright Zero One Star. All rights reserved.

 @Author: renqing
 @Date: 2023/2/15 16:58:10

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
#pragma once
#ifndef _PUR_COMPARE_DTO_
#define _PUR_COMPARE_DTO_

#include "../../GlobalInclude.h"
#include "../FileDTO.h"

//�����ȼ�
class AddPurComDTO : public FileDTO
{
	// ���ݱ��
	CC_SYNTHESIZE(string, billId, BillId);
	// ��������
	CC_SYNTHESIZE(string, billDate, BillDate);
	// ����Ч
	CC_SYNTHESIZE(int, isEffect, IsEffect);
	// �ѹر�
	CC_SYNTHESIZE(int, isClose, Isclose);
	// ������
	CC_SYNTHESIZE(int, isCancelled, IsCancelled);
	// ��Чʱ��
	CC_SYNTHESIZE(string, effectDate, EffectDate);
	// ������
	CC_SYNTHESIZE(string, approver, Approver);
	// ����ʵ��
	// �Ƶ�ʱ��
	CC_SYNTHESIZE(string, makeBillDate, MakeBillDate);
	// �Ƶ�����
	CC_SYNTHESIZE(string, makeBillDept, MakeBillDept);
	// �Ƶ���
	CC_SYNTHESIZE(string, makeBillPerson, MakeBillPerson);
	// �޸�ʱ��
	CC_SYNTHESIZE(string, updateDate, UdpateDate);
	// �޸���
	CC_SYNTHESIZE(string, updatePerson, UdpatePerson);
	// �Զ�����
	CC_SYNTHESIZE(int, autoBill, AutoBill);
	// ���ֵ���
	CC_SYNTHESIZE(int, redBill, RedBill);
	// Դ������
	CC_SYNTHESIZE(string, billType, BillType);
	// ��������
	CC_SYNTHESIZE(string, billTheme, BillTheme);
	// ���ݽ׶�
	CC_SYNTHESIZE(string, billStatus, BillStatus);
	// �ɹ�ѯ�۵������ݱ�ţ�
	CC_SYNTHESIZE(string, inquiryBill, InquiryBill);
	// ���ʽ
	CC_SYNTHESIZE(string, payMethod, PayMethod);
	// ��������
	CC_SYNTHESIZE(string, deliveryDate, DeliveryDate);
	// �����ص�
	CC_SYNTHESIZE(string, deliveryPlace, DeliveryPlace);
	// ��ע
	CC_SYNTHESIZE(string, remark, Remark);
	
public:
	// ��JSONת������
	friend void from_json(const json& j, AddPurComDTO& t);// NOLINT	
};

// �޸ıȼ�
class ModPurComDTO : public FileDTO
{
	// ���ݱ��
	CC_SYNTHESIZE(string, billId, BillId);
	// ��������
	CC_SYNTHESIZE(string, billDate, BillDate);
	// ����Ч
	CC_SYNTHESIZE(int, isEffect, IsEffect);
	// �ѹر�
	CC_SYNTHESIZE(int, isClose, Isclose);
	// ������
	CC_SYNTHESIZE(int, isCancelled, IsCancelled);
	// ��Чʱ��
	CC_SYNTHESIZE(string, effectDate, EffectDate);
	// ������
	CC_SYNTHESIZE(string, approver, Approver);
	// ����ʵ��
	// �Ƶ�ʱ��
	CC_SYNTHESIZE(string, makeBillDate, MakeBillDate);
	// �Ƶ�����
	CC_SYNTHESIZE(string, makeBillDept, MakeBillDept);
	// �Ƶ���
	CC_SYNTHESIZE(string, makeBillPerson, MakeBillPerson);
	// �޸�ʱ��
	CC_SYNTHESIZE(string, updateDate, UdpateDate);
	// �޸���
	CC_SYNTHESIZE(string, updatePerson, UdpatePerson);
	// �Զ�����
	CC_SYNTHESIZE(int, autoBill, AutoBill);
	// ���ֵ���
	CC_SYNTHESIZE(int, redBill, RedBill);
	// Դ������
	CC_SYNTHESIZE(string, billType, BillType);
	// ��������
	CC_SYNTHESIZE(string, billTheme, BillTheme);
	// ���ݽ׶�
	CC_SYNTHESIZE(string, billStatus, BillStatus);
	// �ɹ�ѯ�۵������ݱ�ţ�
	CC_SYNTHESIZE(string, inquiryBill, InquiryBill);
	// ���ʽ
	CC_SYNTHESIZE(string, payMethod, PayMethod);
	// ��������
	CC_SYNTHESIZE(string, deliveryDate, DeliveryDate);
	// �����ص�
	CC_SYNTHESIZE(string, deliveryPlace, DeliveryPlace);
	// ��ע
	CC_SYNTHESIZE(string, remark, Remark);

public:
	// ��JSONת������
	friend void from_json(const json& j, ModPurComDTO& t);// NOLINT	
};

// ɾ���ȼۣ�ǰ�˴��ݵ��ݱ�ţ���˽���ɾ��
class DelPurComDTO
{
	// ���ݱ��
	CC_SYNTHESIZE(string, billId, BillId);

public:
	// ��JSONת������
	friend void from_json(const json& j, DelPurComDTO& t);// NOLINT	
};

// �޸ĵ��ݵ�״̬��ǰ�˴��ݱ���Լ��仯��״̬
class PurComModBillStatusDTO
{
	// ���ݱ��
	CC_SYNTHESIZE(string, billId, BillId);
	// ����Ч
	CC_SYNTHESIZE(int, isEffect, IsEffect);
	// �ѹر�
	CC_SYNTHESIZE(int, isClose, Isclose);
	// ������
	CC_SYNTHESIZE(int, isCancelled, IsCancelled);

public:
	// ��JSONת������
	friend void from_json(const json& j, PurComModBillStatusDTO& t);// NOLINT	
};
#endif // !_PUR_COMPARE_DTO_