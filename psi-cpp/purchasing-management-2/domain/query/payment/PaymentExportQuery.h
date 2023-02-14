#pragma once

#ifndef _PAYMENTEXPORTQUERY_H_
#define _PAYMENTEXPORTQUERY_H_

#include "../../GlobalInclude.h"
#include <list>

/**
 * ����
 */
	class PaymentExportQuery
{
protected:
	// һ����Ҫ������ID(�ݶ�����uint64_t)����û����Ĭ��ȫ��
	CC_SYNTHESIZE(std::list<uint64_t>, exportPayment, ExportPayment);
public:
	//��JSONת������
	friend void from_json(const json& j, PaymentExportQuery& t) {
		BIND_FROM_TO_OBJ(j, t, exportPayment, std::list<uint64_t>);
	}
};


#endif // _PAYMENTEXPORTQUERY_H_