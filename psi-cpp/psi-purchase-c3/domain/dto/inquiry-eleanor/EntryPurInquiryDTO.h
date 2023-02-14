#pragma once
#ifndef _ENTRYPURINQUIRY_DTO_
#define _ENTRYPURINQUIRY_DTO_

#include "../../GlobalInclude.h"

/**
 * ������� ���� ���ݱ�ţ����ݵ��ݱ��ƥ���Ӧ����ϸ�б�
 */

//ָ��ѯ�۵�����ϸ��¼ 
class EntryPurInquiryDTO
{
	//���ݱ��
	CC_SYNTHESIZE(string, purInquiryBillNo, PurInquiryBillNo);    // ��Ӧmysql���ݿ���bill_no�ֶ�

public:
	// ��from_json
	friend void from_json(const json& j, EntryPurInquiryDTO& t);  // NOLINT
	BIND_TO_JSON(EntryPurInquiryDTO, purInquiryBillNo);
};

#endif // !_ENTRYPURINQUIRYDTO_