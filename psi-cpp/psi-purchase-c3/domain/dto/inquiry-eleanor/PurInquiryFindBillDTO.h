#pragma once

#ifndef _PURINQUIRYFINDBILL_DTO_
#define _PURINQUIRYFINDBILL_DTO_

#include "../../GlobalInclude.h"

/**
 * ������� ���� �ɹ�ѯ�۵���ѯ��Ϣ�б�
 */

//�ɹ�ѯ�۵��б�
class PurInquiryFindBillDTO
{
//���������� - ������Ϣstring
	//���ݱ��
	CC_SYNTHESIZE(string, purInquiryBillNo, PurInquiryBillNo);
	//��������
	CC_SYNTHESIZE(string, purInquiryBillDate, purInquiryBillDate);
	//��������
	CC_SYNTHESIZE(string, purInquirySubject, PurInquirySubject);
//����״̬
	//�Ƿ���Чint
	CC_SYNTHESIZE(int, purInquiryIsEffective, PurInquiryIsEffective);
	//�Ƿ�ر�
	CC_SYNTHESIZE(int, purInquiryIsClosed, PurInquiryIsClosed);
	//�Ƿ�����
	CC_SYNTHESIZE(int, purInquiryIsVoided, PurInquiryIsVoided);

public:
	// ��JSONת������
	friend void from_json(const json& j, PurInquiryFindBillDTO& t); // NOLINT
	BIND_TO_JSON(PurInquiryFindBillDTO, purInquiryBillNo, purInquiryBillDate, purInquirySubject,
		purInquiryIsEffective, purInquiryIsClosed, purInquiryIsVoided);
};

#endif // !_PURINQUIRYFINDBILL_DTO_