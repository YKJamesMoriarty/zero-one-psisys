#ifndef _MOD_PUR_QUOT_DTO_
#define _MOD_PUR_QUOT_DTO_
#include "stdafx.h"
#include "../../GlobalInclude.h"
#include "../FileDTO.h"



class ModPurQuotDTO :public FileDTO
{
	//������һЩ�ֶΣ��Ҳ�ȷ���Ƿ���Ļ��õ������֮��д���룬���ֻ���Ҫ�����ֶΣ��������ȥ������Ҫ��ɾ����
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
	//��JSONת������
	friend void from_json(const json& j, ModPurQuotDTO& t) {
		BIND_FROM_TO_L(j, t, id);
		BIND_FROM_TO_L(j, t, supplierId);

		BIND_FROM_TO_I(j, t, isTempSupplier);
		BIND_FROM_TO_I(j, t, isEffective);
		BIND_FROM_TO_I(j, t, isClosed);
		BIND_FROM_TO_I(j, t, isVoided);
		BIND_FROM_TO_I(j, t, approvalResultType);
		BIND_FROM_TO_I(j, t, billStage);

		BIND_FROM_TO_D(j, t, qty);
		BIND_FROM_TO_D(j, t, amt);

		BIND_FROM_TO_NORMAL(j, t, billNo);
		BIND_FROM_TO_NORMAL(j, t, billDate);
		BIND_FROM_TO_NORMAL(j, t, subject);
		BIND_FROM_TO_NORMAL(j, t, srcNo);
		BIND_FROM_TO_NORMAL(j, t, tempSupplierName);
		BIND_FROM_TO_NORMAL(j, t, deliveryMethod);
		BIND_FROM_TO_NORMAL(j, t, deliveryDate);
		BIND_FROM_TO_NORMAL(j, t, deliveryAddress);
		BIND_FROM_TO_NORMAL(j, t, contact);
		BIND_FROM_TO_NORMAL(j, t, phone);
		BIND_FROM_TO_NORMAL(j, t, tax);
		BIND_FROM_TO_NORMAL(j, t, email);
		BIND_FROM_TO_NORMAL(j, t, attachment);
		BIND_FROM_TO_NORMAL(j, t, remark);
		BIND_FROM_TO_NORMAL(j, t, approver);

		BIND_FROM_TO_NORMAL(j, t, approvalRemark);
		BIND_FROM_TO_NORMAL(j, t, effectiveTime);
		BIND_FROM_TO_NORMAL(j, t, sysOrdCode);
		BIND_FROM_TO_NORMAL(j, t, createBy);
		BIND_FROM_TO_NORMAL(j, t, createTime);
		BIND_FROM_TO_NORMAL(j, t, updateBy);
		BIND_FROM_TO_NORMAL(j, t, updateTime);
	}
};

#endif // !_MOD_PUR_QUOT_DTO_