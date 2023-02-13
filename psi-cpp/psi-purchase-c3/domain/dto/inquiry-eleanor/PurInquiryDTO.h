#pragma once

#ifndef _PURINQUIRY_DTO_
#define _PURINQUIRY_DTO_

#include "../../GlobalInclude.h"

/**
 * ������� ���� �ɹ�ѯ�۵��б�ָ��ѯ�۵���ϸ��Ϣ
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
};


//ָ��ѯ�۵���ϸ��Ϣ
class PurInquiryFindDetailBillDTO
{
//������Ϣ
	//���ݱ��
	CC_SYNTHESIZE(string, purInquiryBillNo, PurInquiryBillNo);   // ��Ӧmysql���ݿ���bill_no�ֶ�

public:
	// ��JSONת������
	friend void from_json(const json& j, PurInquiryFindDetailBillDTO& t); // NOLINT
};


//ָ��ѯ�۵�����ϸ��¼
class EntryPurInquiry
{
	//���ݱ��
	CC_SYNTHESIZE(string, purInquiryBillNo, PurInquiryBillNo);    // ��Ӧmysql���ݿ���bill_no�ֶ�

public:
	// ��from_json
	friend void from_json(const json& j, PurInquiryFindDetailBillQuery& t) { // NOLINT
		BIND_FROM_TO_ULL(j, t, purInquiryBillNo);
	}
};


#endif // !_PURINQUIRY_DTO_