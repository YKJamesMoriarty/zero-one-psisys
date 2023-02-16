#ifndef _INVOICETYPE_VO_
#define _INVOICETYPE_VO_

#include "../../GlobalInclude.h"

/**
 *Author c1-ruizi
 * 2023/2/13  15:46
 * �ӿڣ���Ʊ����
 */

class InvoiceTypeVO
{
	// ��ʽ���
	CC_SYNTHESIZE(int, id, Id);
	// ��ʽ����
	CC_SYNTHESIZE(string, name, Name);

public:
	// ��JSONת������
	BIND_TO_JSON(InvoiceTypeVO, id, name);
};

#endif //_INVOICETYPE_VO_