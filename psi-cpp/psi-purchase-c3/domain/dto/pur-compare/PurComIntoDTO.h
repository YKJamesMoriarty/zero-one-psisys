#pragma once

#ifndef _PUR_COM_INTO_DTO_
#define _PUR_COM_INTO_DTO_

#include "../FileDTO.h"

class PurComIntoDTO :public FileDTO {
	//���ݱ��
	CC_SYNTHESIZE(string, bill_no, Bill_no);
	////��������
	//CC_SYNTHESIZE(string, bill_date, Bill_date);
	////����Ч
	//CC_SYNTHESIZE(int, is_effective, Is_effective);
	////�ѹر�
	//CC_SYNTHESIZE(int, is_closed, Is_closed);
	////������
	//CC_SYNTHESIZE(int, is_voided, Ss_voided);
	////��������
	//CC_SYNTHESIZE(string, subject, Subject);
	////�ɹ�ѯ�۵����
	//CC_SYNTHESIZE(string, bill_no, Bill_no);
	////���ʽ
	//CC_SYNTHESIZE(string, payment_method, Payment_method);
	////��������
	//CC_SYNTHESIZE(string, delivery_time, Delivery_time);
	////����ص�
	//CC_SYNTHESIZE(string, delivery_place, Delivery_place);
	////��ע
	//CC_SYNTHESIZE(string, remark, Remark);
	////����
	//CC_SYNTHESIZE(string, attachment, Attachment);
public:
	// ��JSONת������
	friend void from_json(const json& j, PurComIntoDTO& t) { // NOLINT
		BIND_FROM_TO_ULL(j, t, bill_no);
		//BIND_FROM_TO_ULL(j, t, bill_date);
		//BIND_FROM_TO_ULL(j, t, is_effective);
		//BIND_FROM_TO_I(j, t, is_closed);
		//BIND_FROM_TO_I(j, t, is_voided);
		//BIND_FROM_TO_I(j, t, subject);
		//BIND_FROM_TO_ULL(j, t, bill_no);
		//BIND_FROM_TO_ULL(j, t, payment_method);
		//BIND_FROM_TO_ULL(j, t, delivery_time);
		//BIND_FROM_TO_ULL(j, t, delivery_place);
		//BIND_FROM_TO_ULL(j, t, remark);
		//BIND_FROM_TO_ULL(j, t, attachment);
	}
};

#endif // !




