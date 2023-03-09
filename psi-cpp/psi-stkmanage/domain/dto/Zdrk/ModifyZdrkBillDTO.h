#pragma once
#ifndef _MODIFYZDRKBILL_DTO_
#define _MODIFYZDRKBILL_DTO_

#include "../../GlobalInclude.h"
#include "../Zdrk/ZdrkBillDetailDTO.h"
#include "../FileDTO.h"
/**
 * ��ӵ��ݴ������
 */
class ModifyZdrkBillDTO :public FileDTO
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
	friend void from_json(const json& j, ModifyZdrkBillDTO& t); // NOLINT
};

#endif // !_DOC_DTO_

