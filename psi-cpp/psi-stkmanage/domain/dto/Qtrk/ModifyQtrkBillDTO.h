#pragma once

#ifndef _ModifyQtrkBill_DTO_
#define _ModifyQtrkBill_DTO_
#include "../../GlobalInclude.h"
/**
 * �޸�������ⵥ�������
 */
class ModifyQtrkBillDTO
{
	// ���ݱ��
	//CC_SYNTHESIZE(uint64_t, id, Id);
	// ��������
	CC_SYNTHESIZE(string, billDate, BillDate);
	// ��������
	CC_SYNTHESIZE(string, subject, Subject);
	// ��Ӧ��
	CC_SYNTHESIZE(string, supplierId, SupplierId);
	//��⾭��
	CC_SYNTHESIZE(string, handler, Handler);
	//��ע
	CC_SYNTHESIZE(string, remark, Remark);
	//�ϴ�����
	CC_SYNTHESIZE(string, appFile, AppFile);


public:
	// ��JSONת������
	friend void from_json(const json& j, ModifyQtrkBillDTO& t); // NOLINT
	BIND_TO_JSON(ModifyQtrkBillDTO, billDate, subject, supplierId, handler, remark, appFile);
};

#endif // !_ModifyQtrkBill_DTO_