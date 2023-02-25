#pragma once
#ifndef _PUR_COM_QUOT_DO_H_
#define _PUR_COM_QUOT_DO_H_
#include "../../GlobalInclude.h"
//���ݿ��pur_quot��ʵ��
class PurComQuotDO {
    //ID
    CC_SYNTHESIZE(string, id, Id);
    //���ݱ��
    CC_SYNTHESIZE(string, billNo, BillNo);
    //��������
    CC_SYNTHESIZE(string, billDate, BillDate);
    //Դ������
    CC_SYNTHESIZE(string, srcBillType, SrcBillType);
    //Դ��ID
    CC_SYNTHESIZE(string, srcBillId, SrcBillId);
    //Դ����
    CC_SYNTHESIZE(string, srcNo, SrcNo);
    //����
    CC_SYNTHESIZE(string, subject, Subject);
    //�Ƿ����
    CC_SYNTHESIZE(string, isRubric, IsRubric);
    //�Ƿ���ʱ��Ӧ��
    CC_SYNTHESIZE(string, isTempSupplier, IsTempSupplier);
    //��Ӧ��
    CC_SYNTHESIZE(string, supplierId, SupplierId);
    //��Ӧ������
    CC_SYNTHESIZE(string, supplierName, SupplierName);
    //���ʽ
    CC_SYNTHESIZE(string, paymentMethod, PaymentMethod);
    //����ʱ��
    CC_SYNTHESIZE(string, deliveryTime, DeliveryTime);
    //�����ص�
    CC_SYNTHESIZE(string, deliveryPlace, DeliveryPlace);
    //��ϵ��
    CC_SYNTHESIZE(string, contact, Contact);
    //��ϵ�绰
    CC_SYNTHESIZE(string, phone, Phone);
    //����
    CC_SYNTHESIZE(string, fax, Fax);
    //�����ʼ�
    CC_SYNTHESIZE(string, email, Email);
    //����
    CC_SYNTHESIZE(string, qty, Qty);
    //���
    CC_SYNTHESIZE(string, amt, Amt);
    //����
    CC_SYNTHESIZE(string, attachment, Attachment);
    //��ע
    CC_SYNTHESIZE(string, remark, Remark);
    //�Ƿ��Զ�����
    CC_SYNTHESIZE(string, isAuto, IsAuto);
    //���ݽ׶�
    CC_SYNTHESIZE(string, billStage, BillStage);
    //�����
    CC_SYNTHESIZE(string, approver, Approver);
    //����ʵ��ID
    CC_SYNTHESIZE(string, bpmiInstanceId, BpmiInstanceId);
    //�����������
    CC_SYNTHESIZE(string, approvalResultType, ApprovalResultType);
    //�������
    CC_SYNTHESIZE(string, approvalRemark, ApprovalRemark);
    //�Ƿ���Ч
    CC_SYNTHESIZE(string, isEffective, IsEffective);
    //��Чʱ��
    CC_SYNTHESIZE(string, effectiveTime, EffectiveTime);
    //�ѹر�
    CC_SYNTHESIZE(string, isClosed, IsClosed);
    //�Ƿ�����
    CC_SYNTHESIZE(string, isVoided, IsVoided);
    //��������
    CC_SYNTHESIZE(string, sysOrgCode, SysOrgCode);
    //������
    CC_SYNTHESIZE(string, createBy, CreateBy);
    //����ʱ��
    CC_SYNTHESIZE(string, createTime, CreateTime);
    //�޸���
    CC_SYNTHESIZE(string, updateBy, UpdateBy);
    //�޸�ʱ��
    CC_SYNTHESIZE(string, updateTime, UpdateTime);
    //�汾
    CC_SYNTHESIZE(string, version, Version);
public:
    //���ݿ������ʼ��
    PurComQuotDO() {
        billNo = "";
    }
};

#endif // !_PUR_COM_QUOT_DO_H_
