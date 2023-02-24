#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 11:52:32

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
#ifndef _PUR_QUOT_NAI_GUAN_DO_H_
#define _PUR_QUOT_NAI_GUNA_DO_H_
#include "../DoInclude.h"
#include "../../dto/pur-quot/PurQuotDetailDTO.h"
/**
 * ʾ�����ݿ�ʵ����
 */
class PurQuotNaiGuanDO
{
	// ����id
	CC_SYNTHESIZE(string, id, Id);
	//���ݱ��
	CC_SYNTHESIZE(string, billNo, BillNo);
	//��������
	CC_SYNTHESIZE(string, billDate, BillDate);
	//Դ������
	CC_SYNTHESIZE(string, srcBillType, SrcBillType);
	//Դ��id
	CC_SYNTHESIZE(string, srcBillId, SrcBillId);
	//Դ����
	CC_SYNTHESIZE(string, srcNo, SrcNo);
	//��������
	CC_SYNTHESIZE(string, subject, Subject);
	//�Ƿ����
	CC_SYNTHESIZE(int, isRubric, IsRubric);
	//�Ƿ���ʱ��Ӧ��
	CC_SYNTHESIZE(int, isTempSupplier, IsTempSupplier);
	//��Ӧ��
	CC_SYNTHESIZE(string, supplierId, SupplierId);
	//��ʱ��Ӧ������
	CC_SYNTHESIZE(string, tempSupplierName, TempSupplierName);
	//���ʽ
	CC_SYNTHESIZE(string, deliveryMethod, DeliveryMethod);
	//��������
	CC_SYNTHESIZE(string, deliveryDate, DeliveryDate);
	//�����ص�
	CC_SYNTHESIZE(string, deliveryAddress, DeliveryAddress);
	//��ϵ��
	CC_SYNTHESIZE(string, contact, Contact);
	//��ϵ�绰
	CC_SYNTHESIZE(string, phone, Phone);
	//����
	CC_SYNTHESIZE(string, fax, Fax);
	//�����ʼ�
	CC_SYNTHESIZE(string, email, Email);
	//����
	CC_SYNTHESIZE(double, qty, Qty);
	//���
	CC_SYNTHESIZE(double, amt, Amt);
	//����
	CC_SYNTHESIZE(string, attachment, Attachment);
	//��ע
	CC_SYNTHESIZE(string, remark, Remark);
	//�Ƿ��Զ�����
	CC_SYNTHESIZE(int, isAuto, IsAuto);
	//���ݽ׶�
	CC_SYNTHESIZE(string, billStage, BillStage);
	//�����
	CC_SYNTHESIZE(string, approver, Approver);
	//ʾ��id
	CC_SYNTHESIZE(string, bpmi_instance_id, Bpmi_instance_id);
	//�����������
	CC_SYNTHESIZE(string, approvalResultType, ApprovalResultType);
	//�������
	CC_SYNTHESIZE(string, approvalRemark, ApprovalRemark);
	//�Ƿ���Ч
	CC_SYNTHESIZE(int, isEffective, IsEffective);
	//��Чʱ��
	CC_SYNTHESIZE(string, effectiveTime, EffectiveTime);
	//�Ƿ��ѹر�
	CC_SYNTHESIZE(int, isClosed, IsClosed);
	//�Ƿ�����
	CC_SYNTHESIZE(int, isVoided, IsVoided);
	//��������
	CC_SYNTHESIZE(string, sysOrdCode, SysOrdCode);
	//������
	CC_SYNTHESIZE(string, createBy, CreateBy);
	//����ʱ��
	CC_SYNTHESIZE(string, createTime, CreateTime);
	//�޸���
	CC_SYNTHESIZE(string, updateBy, UpdateBy);

	//�޸�ʱ��
	CC_SYNTHESIZE(string, updateTime, UpdateTime);
	//�汾
	CC_SYNTHESIZE(int, version, Version);
	//������ϸ
	CC_SYNTHESIZE(list<PurQuotDetailDTO>, detail, Detail);
public:
	
};

#endif // !_PUR_QUOT_DO_H_
