#pragma once

#ifndef _PURINQUIRY_QUERY_
#define _PURINQUIRY_QUERY_

#include "../PageQuery.h"

/**
 * ʾ����ҳ��ѯ����
 */
class PurInquiryFindBillQuery : public PageQuery
{
//��ѯ�Ķ�����Ϣ
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



//ָ��ѯ�۵���ϸ��Ϣ
class PurInquiryFindDetailBillQuery : public PageQuery
{
//��ѯ��ָ��������Ϣ
	//���ݱ��
	CC_SYNTHESIZE(string, purInquiryBillNo, PurInquiryBillNo);    // ��Ӧmysql���ݿ���bill_no�ֶ�

public:
	// ��from_json
	friend void from_json(const json& j, PurInquiryFindDetailBillQuery& t) { // NOLINT
		BIND_FROM_TO_ULL(j, t, purInquiryBillNo);
	}
};

#endif // !_PURINQUIRY_QUERY_