#pragma once

#ifndef _AddQtrkBill_DTO_
#define _AddQtrkBill_DTO_

#include "../../GlobalInclude.h"
#include "../FileDTO.h"
#include "QtrkBillDetailDTO.h"

/**
 * ���������ⵥ�������
 */
class AddQtrkBillDTO : public FileDTO
{
	// ���ݱ��
	CC_SYNTHESIZE(string, billNo, BillNo);
	// ��������
	CC_SYNTHESIZE(string, billDate, BillDate);
	// ��������
	CC_SYNTHESIZE(string, subject, Subject);
	// �̵㾭��
	CC_SYNTHESIZE(string, handler, Handler);
	// ��ע
	CC_SYNTHESIZE(string, remark, Remark);
	// ����or�ύ(0:����, 1:�ύ)
	CC_SYNTHESIZE(int, save, Save);
	// ��ϸ
	CC_SYNTHESIZE(list<QtrkBillDetailDTO>, detail, Detail);
public:
	// ��JSONת������
	friend void from_json(const json& j, AddQtrkBillDTO& t); // NOLINT
};

#endif // !_AddQtrkBill_DTO_