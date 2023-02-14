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
#ifndef _CGRK_QUERY_VO_
#define _CGRK_QUERY_VO_

#include "../../GlobalInclude.h"

/**
 * ʾ����ʾ����
 */
class CgrkQueryVO
{	
	//��ע
	CC_SYNTHESIZE(string, remark, Remark);
	//���ݱ��
	CC_SYNTHESIZE(string, bill_no, Bill_no);
	//�����������
	CC_SYNTHESIZE(string, approval_result_type, Approval_result_type);
	//�޸���
	CC_SYNTHESIZE(string, update_by, Update_by);
	//����Ч
	CC_SYNTHESIZE(int, is_effective, Is_effective); 
	//������
	CC_SYNTHESIZE(int, is_voided, Is_voided);
	//��������
	CC_SYNTHESIZE(int, bill_type, Bill_type);
	//������
	CC_SYNTHESIZE(string, approver, Approver);
	//��������
	CC_SYNTHESIZE(string, bill_date, Bill_date);
	//Դ������
	CC_SYNTHESIZE(string, src_bill_type, Src_bill_type);
	//�������
	CC_SYNTHESIZE(string, approval_remark, Approval_remark );
	//Դ����
	CC_SYNTHESIZE(string, src_no, Src_no);
	//�޸�ʱ��
	CC_SYNTHESIZE(string, update_time, Update_time);
	//�Ƿ��Զ�����
	CC_SYNTHESIZE(int, is_auto, Is_auto);
	//���ֵ���
	CC_SYNTHESIZE(int, is_rubric, Is_rubric);
	//�Ƶ�����
	CC_SYNTHESIZE(string, sys_org_code, Sys_org_code);
	//�Ƶ�ʱ��
	CC_SYNTHESIZE(string, create_time, Create_time);
	//�Ƶ���
	CC_SYNTHESIZE(string, create_by, Create_by);
	//Դ��id
	CC_SYNTHESIZE(string, src_bill_id, Src_bill_id);
	//��Чʱ��
	CC_SYNTHESIZE(string, effective_time, Effective_time);
	//���ݽ׶�
	CC_SYNTHESIZE(string, bill_stage, Bill_stage);
	//�汾
	CC_SYNTHESIZE(string, version, Version);
	//����
	CC_SYNTHESIZE(string, attachment, Attachment);
	//��������
	CC_SYNTHESIZE(string, sudject, Subject);
	//ID
	CC_SYNTHESIZE(string, id, Id);
	//�ѹر�
	CC_SYNTHESIZE(int, is_closed, Is_closed);
	//����ʵ��id
	CC_SYNTHESIZE(string, bpmi_instance_id, Bpmi_instance_id);
	//���������
	CC_SYNTHESIZE(string, stock_io_type, Stock_io_type);
	//������
	CC_SYNTHESIZE(int, has_rp, Has_rp);
	//�Ƿ����Ƕ�
	CC_SYNTHESIZE(int, has_swell, Has_swell);
	//��Ӧ��
	CC_SYNTHESIZE(string, supplier_id, Supplier_id); 
	//�ͻ�
	CC_SYNTHESIZE(string, customer_id, Customer_id);
	//��Ʊ����
	CC_SYNTHESIZE(string,invoice_type, Invoice_type );
	//ҵ����
	CC_SYNTHESIZE(string, op_dept, Op_dept);
	//ҵ��Ա
	CC_SYNTHESIZE(string, operator1, Operator1);
	//����⾭��
	CC_SYNTHESIZE(string, handler, Handler);
	//�ɱ�
	CC_SYNTHESIZE(double, cost, Cost);
	//������
	CC_SYNTHESIZE(double, settle_amt, Settle_amt);
	//�ѽ�����
	CC_SYNTHESIZE(double, settled_amt, Settled_amt);
	//�ѿ�Ʊ���
	CC_SYNTHESIZE(double, invoiced_amt, Invoiced_amt );
	//�Ƿ��˻���Ʊ
	CC_SYNTHESIZE(int, is_returned, Is_returned );

	CC_SYNTHESIZE(string, stockIoType_dictText, StockIoType_dictText);
	CC_SYNTHESIZE(string, hasRp_dictText, HasRp_dictText);
	CC_SYNTHESIZE(string, hasSwell_dictText, HasSwell_dictText);
	CC_SYNTHESIZE(string, invoiceType_dictTex, InvoiceType_dictTex);
	CC_SYNTHESIZE(string, opDept_dictText, OpDept_dictText);
	CC_SYNTHESIZE(string, operator_dictText, Operator_dictText);
	CC_SYNTHESIZE(string, handler_dictText, Handler_dictText);
	CC_SYNTHESIZE(string, updateBy_dictText, UpdateBy_dictText);
	CC_SYNTHESIZE(string, isEffective_dictText, IsEffective_dictText);
	CC_SYNTHESIZE(string, isVoided_dictText, IsVoided_dictText);
	CC_SYNTHESIZE(string, srcBillType_dictText, SrcBillType_dictText);
	CC_SYNTHESIZE(string, isAuto_dictText, IsAuto_dictText);
	CC_SYNTHESIZE(string, isRubric_dictText, IsRubric_dictText);
	CC_SYNTHESIZE(string, sysOrgCode_dictText, SysOrgCode_dictText);
	CC_SYNTHESIZE(string, createBy_dictText, CreateBy_dictText);
	CC_SYNTHESIZE(string, billStage_dictText, BillStage_dictText);
	CC_SYNTHESIZE(string, isClosed_dictText, IsClosed_dictText);

public:
	// ��JSONת������
	BIND_TO_JSON(CgrkQueryVO, remark, bill_no, approval_result_type, update_by, is_effective, is_voided, bill_type, approver, bill_date, src_bill_type, approval_remark, src_no, update_time, is_auto,
		is_rubric, sys_org_code, create_time, create_by, src_bill_id, effective_time, bill_stage, version, attachment, sudject, id, is_closed, bpmi_instance_id, stock_io_type, has_rp, has_swell, supplier_id, customer_id,
		invoice_type, op_dept, operator1, handler, cost, settle_amt, settled_amt, invoiced_amt, is_returned, stockIoType_dictText, hasRp_dictText, hasSwell_dictText, invoiceType_dictTex, opDept_dictText, operator_dictText,
		handler_dictText, updateBy_dictText, isEffective_dictText, isVoided_dictText, srcBillType_dictText, isAuto_dictText, isRubric_dictText, sysOrgCode_dictText, createBy_dictText, billStage_dictText, isClosed_dictText );
};

#endif // !_CGRK_QUERY_VO_
