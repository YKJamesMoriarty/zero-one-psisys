#pragma once

#ifndef __ADD_PUR_INQUIRY_VO_H__
#define __ADD_PUR_INQUIRY_VO_H__
#include <vector>
#include "../../GlobalInclude.h"

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
