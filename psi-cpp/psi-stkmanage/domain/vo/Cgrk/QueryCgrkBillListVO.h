#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 11:34:14

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
#ifndef _QUERY_CGRK_BILL_LIST_VO_
#define _QUERY_CGRK_BILL_LIST_VO_

#include "../../GlobalInclude.h"

/**
 * ʾ����ʾ����
 */
class QueryCgrkBillListVO
{	
	//��ע
	CC_SYNTHESIZE(string, remark, Remark);
	//���ݱ��
	CC_SYNTHESIZE(string, billNo, BillNo);
	//�����������
	CC_SYNTHESIZE(string, approvalResultType, ApprovalResultType);
	//�޸���
	CC_SYNTHESIZE(string, updateBy, UpdateBy);
	//����Ч
	CC_SYNTHESIZE(int, isEffective, IsEffective); 
	//������
	CC_SYNTHESIZE(int, isVoided, IsVoided);
	//��������
	CC_SYNTHESIZE(int, billType, BillType);
	//������
	CC_SYNTHESIZE(string, approver, Approver);
	//��������
	CC_SYNTHESIZE(string, billDate, BillDate);
	//Դ������
	CC_SYNTHESIZE(string, srcBillType, SrcBillType);
	//�������
	CC_SYNTHESIZE(string, approvalRemark, ApprovalRemark );
	//Դ����
	CC_SYNTHESIZE(string, srcNo, SrcNo);
	//�޸�ʱ��
	CC_SYNTHESIZE(string, updateTime, UpdateTime);
	//�Ƿ��Զ�����
	CC_SYNTHESIZE(int, isAuto, IsAuto);
	//���ֵ���
	CC_SYNTHESIZE(int, isRubric, IsRubric);
	//�Ƶ�����
	CC_SYNTHESIZE(string, sysOrgCode, SysOrgCode);
	//�Ƶ�ʱ��
	CC_SYNTHESIZE(string, createTime, CreateTime);
	//�Ƶ���
	CC_SYNTHESIZE(string, createBy, CreateBy);
	//Դ��id
	CC_SYNTHESIZE(string, srcBillId, SrcBillId);
	//��Чʱ��
	CC_SYNTHESIZE(string, effectiveTime, EffectiveTime);
	//���ݽ׶�
	CC_SYNTHESIZE(string, billStage, BillStage);
	//�汾
	CC_SYNTHESIZE(string, version, Version);
	//����
	CC_SYNTHESIZE(string, attachment, Attachment);
	//��������
	CC_SYNTHESIZE(string, sudject, Subject);
	//ID
	CC_SYNTHESIZE(string, id, Id);
	//�ѹر�
	CC_SYNTHESIZE(int, isClosed, IsClosed);
	//����ʵ��id
	CC_SYNTHESIZE(string, bpmiInstanceId, BpmiInstanceId);
	//���������
	CC_SYNTHESIZE(string, stockIoType, StockIoType);
	//������
	CC_SYNTHESIZE(int, hasRp, HasRp);
	//�Ƿ����Ƕ�
	CC_SYNTHESIZE(int, hasSwell, HasSwell);
	//��Ӧ��
	CC_SYNTHESIZE(string, supplierId, SupplierId); 
	//�ͻ�
	CC_SYNTHESIZE(string, customerId, CustomerId);
	//��Ʊ����
	CC_SYNTHESIZE(string,invoiceType, InvoiceType );
	//ҵ����
	CC_SYNTHESIZE(string, opDept, OpDept);
	//ҵ��Ա
	CC_SYNTHESIZE(string, operator1, Operator1);
	//����⾭��
	CC_SYNTHESIZE(string, handler, Handler);
	//�ɱ�
	CC_SYNTHESIZE(double, cost, Cost);
	//������
	CC_SYNTHESIZE(double, settleAmt, SettleAmt);
	//�ѽ�����
	CC_SYNTHESIZE(double, settledAmt, SettledAmt);
	//�ѿ�Ʊ���
	CC_SYNTHESIZE(double, invoicedAmt, InvoicedAmt );
	//�Ƿ��˻���Ʊ
	CC_SYNTHESIZE(int, isReturned, IsReturned );

	CC_SYNTHESIZE(string, stockIoTypeDictText, StockIoTypeDictText);
	CC_SYNTHESIZE(string, hasRpDictText, HasRpDictText);
	CC_SYNTHESIZE(string, hasSwellDictText, HasSwellDictText);
	CC_SYNTHESIZE(string, invoiceTypeDictTex, InvoiceTypeDictTex);
	CC_SYNTHESIZE(string, opDeptDictText, OpDeptDictText);
	CC_SYNTHESIZE(string, operatorDictText, OperatorDictText);
	CC_SYNTHESIZE(string, handlerDictText, HandlerDictText);
	CC_SYNTHESIZE(string, updateByDictText, UpdateByDictText);
	CC_SYNTHESIZE(string, isEffectiveDictText, IsEffectiveDictText);
	CC_SYNTHESIZE(string, isVoidedDictText, IsVoidedDictText);
	CC_SYNTHESIZE(string, srcBillTypeDictText, SrcBillTypeDictText);
	CC_SYNTHESIZE(string, isAutoDictText, IsAutoDictText);
	CC_SYNTHESIZE(string, isRubricDictText, IsRubricDictText);
	CC_SYNTHESIZE(string, sysOrgCodeDictText, SysOrgCodeDictText);
	CC_SYNTHESIZE(string, createByDictText, CreateByDictText);
	CC_SYNTHESIZE(string, billStageDictText, BillStageDictText);
	CC_SYNTHESIZE(string, isClosedDictText, IsClosedDictText);

public:
	QueryCgrkBillListVO() {
		billNo = "CGRK-230101-001";
		approvalResultType = "123";
	}
	// ��JSONת������
	BIND_TO_JSON(QueryCgrkBillListVO, remark, billNo, approvalResultType, updateBy, isEffective, isVoided, billType, approver, billDate, srcBillType, approvalRemark, srcNo, updateTime, isAuto,
		isRubric, sysOrgCode, createTime, createBy, srcBillId, effectiveTime, billStage, version, attachment, sudject, id, isClosed, bpmiInstanceId, stockIoType, hasRp, hasSwell, supplierId, customerId,
		invoiceType, opDept, operator1, handler, cost, settleAmt, settledAmt, invoicedAmt, isReturned, stockIoTypeDictText, hasRpDictText, hasSwellDictText, invoiceTypeDictTex, opDeptDictText, operatorDictText,
		handlerDictText, updateByDictText, isEffectiveDictText, isVoidedDictText, srcBillTypeDictText, isAutoDictText, isRubricDictText, sysOrgCodeDictText, createByDictText, billStageDictText, isClosedDictText );
};

#endif // !_QUERY_CGRK_BILL_LIST_VO_
