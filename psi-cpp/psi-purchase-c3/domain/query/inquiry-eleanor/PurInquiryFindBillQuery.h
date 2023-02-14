#pragma once

#ifndef _PURINQUIRYFINDBILL_QUERY_
#define _PURINQUIRYFINDBILL_QUERY_

#include "../PageQuery.h"

/**
 * ʾ����ҳ��ѯ���� ���� �ɹ�ѯ�۵��б�
 */

//�ɹ�ѯ�۵���ѯ�б�
class PurInquiryFindBillQuery : public PageQuery
{
	//���ݱ��
	CC_SYNTHESIZE(string, purInquiryBillNo, PurInquiryBillNo);
	//��������
	CC_SYNTHESIZE(string, purInquiryBillDate, purInquiryBillDate);
	//��������
	CC_SYNTHESIZE(string, purInquirySubject, PurInquirySubject);
//����״̬
	//�Ƿ���Ч
	CC_SYNTHESIZE(int, purInquiryIsEffective, PurInquiryIsEffective);
	//�Ƿ�ر�
	CC_SYNTHESIZE(int, purInquiryIsClosed, PurInquiryIsClosed);
	//�Ƿ�����
	CC_SYNTHESIZE(int, purInquiryIsVoided, PurInquiryIsVoided);

public:
	// ��from_json
	friend void from_json(const json& j, PurInquiryFindBillQuery& t) { // NOLINT
		BIND_FROM_TO_ULL(j, t, purInquiryBillNo);
		BIND_FROM_TO_ULL(j, t, purInquiryBillDate);
		BIND_FROM_TO_ULL(j, t, purInquirySubject);
		BIND_FROM_TO_I(j, t, purInquiryIsEffective);
		BIND_FROM_TO_I(j, t, purInquiryIsClosed);
		BIND_FROM_TO_I(j, t, purInquiryIsVoided);
	}
};

#endif // !_PURINQUIRYFINDBILL_QUERY_