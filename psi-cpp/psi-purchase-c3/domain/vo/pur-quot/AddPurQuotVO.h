#ifndef _PUR_QUOT_VO_
#define _PUR_QUOT_VO_

#include "stdafx.h"
#include "../../GlobalInclude.h"




//������Ӧ���۵���
class AddPurQuotVO
{
	// ����id
	CC_SYNTHESIZE(long, id, Id);
	//���ݱ��
	CC_SYNTHESIZE(string, billNo, BillNo);
	//��������
	CC_SYNTHESIZE(string, billDate, BillDate);
	//��������
	CC_SYNTHESIZE(string, subject, Subject);
	//Դ����
	CC_SYNTHESIZE(string, srcNo, SrcNo);
	//�Ƿ���ʱ��Ӧ��
	CC_SYNTHESIZE(int, isTempSupplier, IsTempSupplier);
	//��Ӧ��
	CC_SYNTHESIZE(long, supplierId, SupplierId);
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
	CC_SYNTHESIZE(string, tax, Tax);
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
	//���ݽ׶�
	CC_SYNTHESIZE(int, billStage, BillStage);
	//�����
	CC_SYNTHESIZE(string, approver, Approver);
	//�����������
	CC_SYNTHESIZE(int, approvalResultType, ApprovalResultType);
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
	CC_SYNTHESIZE(string, updateTime, updateTime);
public:
	// ��JSONת������
	BIND_TO_JSON(AddPurQuotVO, 
		id, billNo, billDate, subject,
		srcNo, isTempSupplier, supplierId, tempSupplierName,
		deliveryMethod, deliveryDate, deliveryAddress, contact,
		phone, tax, email, qty,
		amt, attachment, remark, billStage,
		approver, approvalResultType, approvalRemark, isEffective,
		effectiveTime, isClosed, isVoided, sysOrdCode,
		createBy, createTime, updateBy, updateTime);
};


#endif // !_PUR_QUOT_VO_