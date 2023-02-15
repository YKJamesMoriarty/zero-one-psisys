#pragma once
#ifndef _QUERYZDRKBILLLIST_VO_
#define _QUERYZDRKBILLLIST_VO_

#include "../../GlobalInclude.h"

/**
 * ��ѯ�����б���ʾ����
 */
class QueryZdrkBillListVO
{
	//���ݱ��     
	CC_SYNTHESIZE(string, billNo, BillNo);
	//��������    
	CC_SYNTHESIZE(string, billDate, BillDate);
	//ҵ����   
	CC_SYNTHESIZE(string, opDept, OpDept);
	//ҵ��Ա   
	CC_SYNTHESIZE(string, operatoR, Operator);
	//���ݽ׶�   
	CC_SYNTHESIZE(string, billStage, BillStage);
	//����Ч   
	CC_SYNTHESIZE(int, isEffective, IsEffective);
	//�ѹر�   
	CC_SYNTHESIZE(int, isClosed, IsClosed);
	//������   
	CC_SYNTHESIZE(int, isVoided, IsVoided);
	//��ע    
	CC_SYNTHESIZE(string, remark, Remark);
	//�Զ�     
	CC_SYNTHESIZE(int, isAuto, IsAuto);
	//��Чʱ��   
	CC_SYNTHESIZE(string, effectiveTime, EffectiveTime);
	//������    
	CC_SYNTHESIZE(string, approver, Approver);
	//�Ƶ���   
	CC_SYNTHESIZE(string, createBy, CreateBy);
	//�Ƶ�ʱ��    
	CC_SYNTHESIZE(string, createTime, CreateTime);
	//�Ƶ�����   
	CC_SYNTHESIZE(string, sysOrgCode, SysOrgCode);
	//�޸�ʱ��  
	CC_SYNTHESIZE(string, updateTime, UpdateTime);
	//�޸���     
	CC_SYNTHESIZE(string, updateBy, UpdateBy);
public:
	// ��JSONת������    
	BIND_TO_JSON(QueryZdrkBillListVO, billNo, billDate, billStage, isEffective, isClosed, isVoided, effectiveTime, approver, createBy, createTime, sysOrgCode, updateTime, updateBy, isAuto, opDept, operatoR, remark);
};

#endif // !QueryZdrkBillListVO
