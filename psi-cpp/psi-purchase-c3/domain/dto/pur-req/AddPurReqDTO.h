#pragma once
#ifndef _ADD_PUR_REQ_DTO_
#define _ADD_PUR_REQ_DTO_

#include "../../GlobalInclude.h"
#include "../FileDTO.h"

//���ǵ��޸ĺ���Ӳɹ������Ĳ����������Ժϲ�Ϊһ��DTO
//��Ӷ�����DTO(��������ϸ����),ͬʱ�����и������ݿ������,���Լ̳�FileDTO
class AddPurReqDTO :public FileDTO
{
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
	//�ɹ�����
	CC_SYNTHESIZE(string, purType, PurType);
	//������
	CC_SYNTHESIZE(string, requester, Requester);
	//����ʱ��
	CC_SYNTHESIZE(string, requestTime, RequestTime);
	//����
	CC_SYNTHESIZE(double, qty, Qty);
	//�ο����
	CC_SYNTHESIZE(double, amt, Amt);
	//�Ѷ�����
	CC_SYNTHESIZE(double, orderedQty, OrderedQty);
	//��ע
	CC_SYNTHESIZE(string, remark, Remark);
	//�Ƿ��Զ�����
	CC_SYNTHESIZE(int, isAuto, IsAuto);
	//���ݽ׶�
	CC_SYNTHESIZE(string, billStage, BillStage);
	//�Ƿ���Ч
	CC_SYNTHESIZE(int, isEffective, IsEffective);
	//��Чʱ��
	CC_SYNTHESIZE(string, effectiveTime, EffectiveTime);
	//�Ƿ��ѹر�
	CC_SYNTHESIZE(int, isClosed, IsClosed);
	//�Ƿ�����
	CC_SYNTHESIZE(int, isVoided, IsVoided);
public:
	//��JSONת������
	friend void from_json(const json& j, AddPurReqDTO& t);
};

#endif // !_ADD_PUR_REQ_DTO_