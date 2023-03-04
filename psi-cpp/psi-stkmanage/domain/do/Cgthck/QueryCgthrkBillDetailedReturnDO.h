#pragma once
#ifndef _Q_C_B_D_R_DO
#define _Q_C_B_D_R_DO

#include "../../GlobalInclude.h"
#include"domain/vo/Cgthck/BillEntryDetailedVO.h"
class QueryCgthrkBillDetailedReturnDO {
	// ���ݱ��
	CC_SYNTHESIZE(std::string, billNo, BillNo);
	// ��������
	CC_SYNTHESIZE(std::string, billDate, BillDate);
	// ��������
	CC_SYNTHESIZE(std::string, subject, Subject);
	// Դ����
	CC_SYNTHESIZE(std::string, srcNo, SrcNo);
	// ��Ӧ��
	CC_SYNTHESIZE(std::string, supplierId, SupplierId);
	// ҵ����
	CC_SYNTHESIZE(std::string, optDept, OptDept);
	// ҵ��Ա
	CC_SYNTHESIZE(std::string, srcOperator, SrcOperator);
	// �����
	CC_SYNTHESIZE(double, inAmt, InAmt);
	// ������
	CC_SYNTHESIZE(double, settleAmt, SettleAmt);
	// �ѽ�����
	CC_SYNTHESIZE(double, settledAmt, SettledAmt);
	// �ѿ�Ʊ���
	CC_SYNTHESIZE(double, invoicedAmt, InvoicedAmt);
	// ��Ʊ����
	CC_SYNTHESIZE(std::string, invoiceType, InvoiceType);
	// ���⾭��
	CC_SYNTHESIZE(std::string, handler, Handler);
	// ���ݽ׶�
	CC_SYNTHESIZE(std::string, billStage, BillStage);
	// �Ƿ���Ч
	CC_SYNTHESIZE(int, isEff, IsEff);
	// �Ƿ�ر�
	CC_SYNTHESIZE(int, isClosed, IsClosed);
	// �Ƿ�����
	CC_SYNTHESIZE(int, isVoided, IsVoided);
	// �Զ�����
	CC_SYNTHESIZE(int, isAuto, IsAuto);
	// ���ֵ���
	CC_SYNTHESIZE(int, isRubric, IsRubric);
	// ��ע
	CC_SYNTHESIZE(std::string, remark, Remark);
	// ��Чʱ��
	CC_SYNTHESIZE(std::string, effTime, EffTime);
	// ������
	CC_SYNTHESIZE(std::string, approver, Approver);
	// �Ƶ�ʱ��
	CC_SYNTHESIZE(std::string, createTime, CreateTime);
	// �Ƶ���
	CC_SYNTHESIZE(std::string, createBy, CreateBy);
	// �Ƶ�����
	CC_SYNTHESIZE(std::string, sysOrgCode, SysOrgCode);
	// �޸�ʱ��
	CC_SYNTHESIZE(std::string, updateTime, UpdateTime);
	// �޸���
	CC_SYNTHESIZE(std::string, updateBy, UpdateBy);
	//��ϸ��Ϣ
	CC_SYNTHESIZE(list<BillEntryDetailedVO>, detail, Detail);
};













#endif