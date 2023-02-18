#pragma once

#ifndef _AddQtrkBill_DTO_
#define _AddQtrkBill_DTO_
#include "../../GlobalInclude.h"
/**
 * ���������ⵥ�������
 */
class AddQtrkBillDTO
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
	friend void from_json(const json& j, AddQtrkBillDTO& t); // NOLINT
	BIND_TO_JSON(AddQtrkBillDTO, billDate, subject, supplierId, handler, remark, appFile);
};

#endif // !_AddQtrkBill_DTO_