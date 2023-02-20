#pragma once
#ifndef _P_B_D_DTO_
#define _P_B_D_DTO_

#include "../../GlobalInclude.h"
#include "../FileDTO.h"
#include "DetailDTO.h"

/*
* ǰ�˴��뵥����ϸ��Ϣ
*/
class PyrkBillDetailDTO : public FileDTO {
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
	CC_SYNTHESIZE(list<DetailDTO>, detail, Detail);
public:
	// ��JSONת������
	friend void from_json(const json& j, PyrkBillDetailDTO& t); // NOLINT
};

#endif // !_P_B_D_DTO_