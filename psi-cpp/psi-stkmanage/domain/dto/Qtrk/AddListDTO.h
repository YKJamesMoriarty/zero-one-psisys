#pragma once

#ifndef _AddList_DTO_
#define _AddList_DTO_
#include "../../GlobalInclude.h"
/**
 * ���������ⵥ�������
 */
class AddListDTO
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
	friend void from_json(const json& j, AddListDTO& t); // NOLINT
	BIND_TO_JSON(AddListDTO, billDate, subject, supplierId, handler, remark, appFile);
};

#endif // !_AddList_DTO_