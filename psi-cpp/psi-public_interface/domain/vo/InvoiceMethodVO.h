#ifndef _INVOICEMETHOD_VO_
#define _INVOICEMETHOD_VO_

#include "../GlobalInclude.h"

/**
 *Author c1-ruizi
 * 2023/2/12  17:46
 * �ӿڣ���Ʊ��ʽ
 */

class InvoiceMethodVO
{
	// ��ʽ���
	CC_SYNTHESIZE(int, id, Id);
	// ��ʽ����
	CC_SYNTHESIZE(string, name, Name);
	
public:
	// ��JSONת������
	BIND_TO_JSON(InvoiceMethodVO, id, name);
};

#endif //_INVOICEMETHOD_VO_