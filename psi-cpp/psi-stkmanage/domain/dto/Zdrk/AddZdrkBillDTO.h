#pragma once
#ifndef _ADDZDRKBILL_DTO_
#define _ADDZDRKBILL_DTO_

#include "../../GlobalInclude.h"
#include "../../dto/Zdrk/ZdrkBillDetailDTO.h"
#include "../FileDTO.h"
/**
 * ��ӵ��ݴ������
 */
class AddZdrkBillDTO : public FileDTO
{
	// ���ݱ��
	CC_SYNTHESIZE(string, billNo, BillNo);
	// ��������
	CC_SYNTHESIZE(string, billDate, BillDate);
	// ��������
	CC_SYNTHESIZE(string, subject, Subject);
	// ��Ӧ��
	CC_SYNTHESIZE(string, supplier, Supplier);
	// �̵㾭��
	CC_SYNTHESIZE(string, handler, Handler);
	// ��ע
	CC_SYNTHESIZE(string, remark, Remark);
	// ����or�ύ(0:����, 1:�ύ)
	CC_SYNTHESIZE(int, save, Save);
	// ��ϸ
	CC_SYNTHESIZE(list<ZdrkBillDetailDTO>, detail, Detail);

public:
	// ��JSONת������
	friend void from_json(const json& j, AddZdrkBillDTO& t); // NOLINT
};

#endif // !_ADDZDRKBILL_DTO