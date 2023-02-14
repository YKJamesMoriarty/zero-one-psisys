#pragma once

#ifndef _PUR_COM_FIND_BILL_VO_
#define _PUR_COM_FIND_BILL_VO_

#include "../../GlobalInclude.h"

/**
 * �ȼ۵��б���ʾ����
 */
class PurComFindBillVO
{
	// ���
	CC_SYNTHESIZE(uint64_t, id, Id);
	// ���ݱ��
	CC_SYNTHESIZE(string, billNo, BillNo);
	// ��������
	CC_SYNTHESIZE(string, billDate, BillDate);
	// ��������
	CC_SYNTHESIZE(string, subject, Subject);
	// Դ����
	CC_SYNTHESIZE(string, srcNo, SrcNo);
	// ���ʽ
	CC_SYNTHESIZE(string, paymentMethod, PaymentMethod);
	// ��������
	CC_SYNTHESIZE(string, deliveryTime, DeliveryTime);
	// ���ݽ׶�
	CC_SYNTHESIZE(string, billStage, BillStage);
	// ����Ч
	CC_SYNTHESIZE(string, isEffective, IsEffective);
	// �ѹر�
	CC_SYNTHESIZE(string, isClosed, IsClosed);
	// ������
	CC_SYNTHESIZE(string, isVoided, IsVoided);
	// �����ص�
	CC_SYNTHESIZE(string, deliveryPlace, DeliveryPlace);
	// ��ע
	CC_SYNTHESIZE(string, remark, Remark);
	// �Զ�����
	CC_SYNTHESIZE(string, isAuto, IsAuto);
	// ���ֵ���
	CC_SYNTHESIZE(string, isRubric, IsRubric);
	// ��Чʱ��
	CC_SYNTHESIZE(string, effectiveTime, EffectiveTime);
	// ������
	CC_SYNTHESIZE(string, approver, Approver);
	// �Ƶ�ʱ��
	CC_SYNTHESIZE(string, createTime, CreateTime);
	// �Ƶ���
	CC_SYNTHESIZE(string, createBy, CreateBy);
	// �Ƶ�����
	CC_SYNTHESIZE(string, sysOrgCode, SysOrgCode);
	// �޸�ʱ��
	CC_SYNTHESIZE(string, updateTime, UpdateTime);
	// �޸���
	CC_SYNTHESIZE(string, updateBy, UpdateBy);
public:
	// ��JSONת������
	BIND_TO_JSON(PurComFindBillVO, id, billNo, billDate, subject, srcNo, paymentMethod, deliveryTime, \
		billStage, isEffective, isClosed, isVoided, deliveryPlace, remark, isAuto, isRubric, \
		effectiveTime, approver, createTime, createBy, sysOrgCode, updateTime, updateBy);
	// ���ڲ�����
	PurComFindBillVO() {
		this->setId(100);
		this->setBillNo("CGBJ100QZP");
		this->setSubject("���Խӿ�");
	}
};


#endif 

