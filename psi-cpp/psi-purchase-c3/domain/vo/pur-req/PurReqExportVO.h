#pragma once

#ifndef _PURREQEXPORT_VO_
#define _PURREQEXPORT_VO_

#include "../../GlobalInclude.h"

//����
class PurReqExportVO
{
//�����������Ϣ
	// �ɹ�����	�������ӿڣ�
	CC_SYNTHESIZE(string, purReqType, PurReqType);
	// ������	�������ӿڣ�
	CC_SYNTHESIZE(string, purReqRequestDept, PurReqRequestDept);
	// ������	��ѡ���û������ӿڣ�
	CC_SYNTHESIZE(string, purReqRequester, PurReqRequester);
	// ����ʱ��	
	CC_SYNTHESIZE(string, purReqRequestTime, PurReqRequestTime);
	// ����	
	CC_SYNTHESIZE(double, purReqQty, PurReqQty);
	// �ο����	
	CC_SYNTHESIZE(double, purReqAmt, PurReqAmt);
	// �Ѷ�������
	CC_SYNTHESIZE(double, purReqOrderQty, PurReqOrderQty);
	// �Ƿ���Ч	
	CC_SYNTHESIZE(int, purReqIsEffective, PurReqIsEffective);
	// ����	
	CC_SYNTHESIZE(string, purReqAttachment, PurReqAttachment);
	// Դ��id	
	CC_SYNTHESIZE(string, purReqSrcBillId, PurReqSrcBillId);
	// ��������	
	CC_SYNTHESIZE(string, purReqSubject, PurReqSubject);
	// ���ݽ׶�	�������ӿڣ�
	CC_SYNTHESIZE(string, purReqStage, PurReqStage);
	// Դ����	
	CC_SYNTHESIZE(string, purReqSrcNo, PurReqSrcNo);
	// �Ƿ��Զ�����	
	CC_SYNTHESIZE(int, purReqIsAuto, PurReqIsAuto);
	// ��ע	
	CC_SYNTHESIZE(string, purReqRemark, PurReqReqRemark);
	// ����ʵ��id	
	CC_SYNTHESIZE(string, purReqBpmiInstenceId, PurReqBpmiInstenceId);
	// �Ƿ�����	
	CC_SYNTHESIZE(int, purReqIsVoided, PurReqIsVoided);
	// ���ݱ��	
	CC_SYNTHESIZE(string, purReqBillNo, PurReqBillNo);
	// �Ƿ����	
	CC_SYNTHESIZE(int, purReqIsRubric, PurReqIsRubric);
	// Դ������	
	CC_SYNTHESIZE(string, purReqSrcBillType, PurReqSrcBillType);
	// �Ƶ�ʱ��	
	CC_SYNTHESIZE(string, purReqCreateTime, PurReqCreateTime);
	// ��Чʱ��	
	CC_SYNTHESIZE(string, purReqEffectiveTime, PurReqEffectiveTime);
	// ������	
	CC_SYNTHESIZE(string, purReqApprover, PurReqApprover);
	// �޸���	
	CC_SYNTHESIZE(string, purReqUpdateBy, PurReqUpdateBy);
	// �Ƶ�����	
	CC_SYNTHESIZE(string, purReqSysOrgCode, PurReqSysOrgCode);
	// �Ƿ�ر�	
	CC_SYNTHESIZE(int, purReqIsClosed, PurReqIsClosed);
	// �����������	
	CC_SYNTHESIZE(string, purReqApprovalResultType, PurReqApprovalResultType);
	// ��������	
	CC_SYNTHESIZE(string, purReqBillDate, PurReqBillDate);
	// �Ƶ���	
	CC_SYNTHESIZE(string, purReqCreateBy, PurReqCreateBy);
	// �������
	CC_SYNTHESIZE(string, purReqApprovalRemark, PurReqApprovalRemark);
	
//��ϸ
	// ����	
	CC_SYNTHESIZE(string, purReqMaterialId, PurReqMaterialId);
	// ������λ	
	CC_SYNTHESIZE(string, purReqUnitId, PurReqUnitId);
	// ˰��% 
	CC_SYNTHESIZE(double, purReqTaxRate, PurReqTaxRate);
	//�ο���˰����
	CC_SYNTHESIZE(double, purReqPrice, PurReqPrice);
	// ���鹩Ӧ�̣������ӿڣ�
	CC_SYNTHESIZE(string, purReqSuggestSupplierId, PurReqSuggestSupplierId);
	// �Զ���1	
	CC_SYNTHESIZE(string,purReqCustom1, PurReqCustom1);
	// Դ����¼��	
	CC_SYNTHESIZE(string, purReqSrcEntryNo, PurReqSrcEntryNo);
	// ��¼��	
	CC_SYNTHESIZE(string, purReqEntryNo, PurReqEntryNo);
	// �Զ���2	
	CC_SYNTHESIZE(string, purReqCustom2, PurReqCustom2);
	// Դ����¼id	
	CC_SYNTHESIZE(string, purReqSrcEntryId, PurReqSrcEntryId);


public:
// ��JSONת������
	BIND_TO_JSON(PurReqExportVO, purReqType, purReqRequestDept, purReqRequester, purReqRequestTime, purReqQty, purReqAmt,
		purReqOrderQty, purReqIsEffective, purReqAttachment, purReqSrcBillId, purReqSubject, purReqStage, 
		purReqSrcNo, purReqIsAuto, purReqRemark, purReqBpmiInstenceId, purReqIsVoided, purReqBillNo,
		purReqIsRubric, purReqSrcBillType, purReqCreateTime, purReqEffectiveTime, purReqApprover, 
		purReqUpdateBy, purReqSysOrgCode, purReqIsClosed, purReqApprovalResultType, purReqBillDate,
		purReqCreateBy, purReqApprovalRemark, purReqMaterialId, purReqUnitId,purReqTaxRate,
		purReqPrice,purReqSuggestSupplierId, purReqCustom1, purReqSrcEntryNo, 
		purReqEntryNo);

};


#endif // !_PURREQEXPORT_VO_
