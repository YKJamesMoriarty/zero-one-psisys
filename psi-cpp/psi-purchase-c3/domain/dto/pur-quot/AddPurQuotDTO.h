#pragma once
#ifndef _ADD_PUR_QUOT_DTO_
#define _ADD_PUR_QUOT_DTO_


#include "../../GlobalInclude.h"
#include "../FileDTO.h"
#include "PurQuotDetailDTO.h"
#include <list>
#include <vector>
#include "cinatra.hpp"
#include "JWTUtil.h"
using namespace cinatra;
using namespace nlohmann;


class AddPurQuotDTO :public FileDTO{

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
	//��JSONת������
	friend void from_json(const json& j, AddPurQuotDTO& t) {

		BIND_FROM_TO_D(j, t, qty);
		BIND_FROM_TO_D(j, t, amt);

		BIND_FROM_TO_I(j, t, isRubric);
		BIND_FROM_TO_I(j, t, version);
		BIND_FROM_TO_I(j, t, isAuto);
		BIND_FROM_TO_I(j, t, isTempSupplier);
		BIND_FROM_TO_I(j, t, isEffective);
		BIND_FROM_TO_I(j, t, isClosed);
		BIND_FROM_TO_I(j, t, isVoided);

		BIND_FROM_TO_NORMAL(j, t, supplierId);
		BIND_FROM_TO_NORMAL(j, t, srcNo);
		BIND_FROM_TO_NORMAL(j, t, srcBillId);
		BIND_FROM_TO_NORMAL(j, t, srcBillType);
		BIND_FROM_TO_NORMAL(j, t, bpmi_instance_id);
		BIND_FROM_TO_NORMAL(j, t, id);
		BIND_FROM_TO_NORMAL(j, t, billNo);
		BIND_FROM_TO_NORMAL(j, t, billDate);
		BIND_FROM_TO_NORMAL(j, t, subject);
		BIND_FROM_TO_NORMAL(j, t, tempSupplierName);
		BIND_FROM_TO_NORMAL(j, t, deliveryMethod);
		BIND_FROM_TO_NORMAL(j, t, deliveryDate);
		BIND_FROM_TO_NORMAL(j, t, deliveryAddress);
		BIND_FROM_TO_NORMAL(j, t, contact);
		BIND_FROM_TO_NORMAL(j, t, phone);
		BIND_FROM_TO_NORMAL(j, t, fax);
		BIND_FROM_TO_NORMAL(j, t, email);
		BIND_FROM_TO_NORMAL(j, t, attachment);
		BIND_FROM_TO_NORMAL(j, t, remark);
		BIND_FROM_TO_NORMAL(j, t, approver);
		BIND_FROM_TO_NORMAL(j, t, approvalResultType);
		BIND_FROM_TO_NORMAL(j, t, billStage);

		BIND_FROM_TO_NORMAL(j, t, approvalRemark);
		BIND_FROM_TO_NORMAL(j, t, effectiveTime);
		BIND_FROM_TO_NORMAL(j, t, sysOrdCode);
		BIND_FROM_TO_NORMAL(j, t, createBy);
		BIND_FROM_TO_NORMAL(j, t, createTime);
		BIND_FROM_TO_NORMAL(j, t, updateBy);
		BIND_FROM_TO_NORMAL(j, t, updateTime);

		BIND_FROM_TO_OBJ(j, t, detail, list<PurQuotDetailDTO>);
	}
};

#endif // !_ADD_PUR_QUOT_DTO_