/**
 *Author c1-ruizi
 * 2023/2/22 17:46
 * �ӿڣ���Ʊ����
 */

#pragma once
#ifndef _InvoiceType_DO_
#define _InvoiceType_DO_
#include "../DoInclude.h"

 /**
  * ���ݿ�ʵ����
  */
class InvoiceTypeDO
{
	// ���
	CC_SYNTHESIZE(uint64_t, id, Id);
	// ������
	CC_SYNTHESIZE(string, name, Name);
public:
	InvoiceTypeDO() {
		id = 0;
		name = "";
	}
};

#endif // !_InvoiceType_DO_