/**
 *Author c1-ruizi
 * 2023/2/22 17:46
 * �ӿڣ���Ʊ��ʽ
 */

#pragma once
#ifndef _INVOICEMETHOD_DO_
#define _INVOICEMETHOD_DO_
#include "../DoInclude.h"

 /**
  * ���ݿ�ʵ����
  */
class InvoiceMethodDO
{
	// ���
	CC_SYNTHESIZE(uint64_t, id, Id);
	// ������
	CC_SYNTHESIZE(string, name, Name);
public:
	InvoiceMethodDO() {
		id = 0;
		name = "";
	}
};

#endif // !_INVOICEMETHOD_DO_