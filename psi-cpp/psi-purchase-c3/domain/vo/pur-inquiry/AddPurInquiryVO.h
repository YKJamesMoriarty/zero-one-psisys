#include "stdafx.h"
#include <vector>
#include "../../GlobalInclude.h"
#ifndef __ADDPURINQUIRYVO_H__
#define __ADDPURINQUIRYVO_H__


//���ʽ
class AddPurInquiryVO
{
	CC_SYNTHESIZE(std::vector<string>, payment, Payment);

public:
	BIND_TO_JSON(AddPurInquiryVO, payment);
	AddPurInquiryVO()
	{
		payment.push_back(u8"ȫ�����");
		payment.push_back(u8"������ȫ��");
		payment.push_back(u8"��Ʊ����ȫ��");
		payment.push_back(u8"��Ʊ������� ");
	}
};


#endif  //__ADDPURINQUIRYVO_H__
