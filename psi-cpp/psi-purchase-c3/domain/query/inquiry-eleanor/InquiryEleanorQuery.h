#pragma once

#ifndef _INQUIRYELEANOR_QUERY_
#define _INQUIRYELEANOR_QUERY_

#include "../PageQuery.h"

/**
 * ʾ����ҳ��ѯ����
 */
class InquiryEleanorQuery : public PageQuery
{
//��ѯ�Ķ�����Ϣ


public:
	// ��from_json
	friend void from_json(const json& j, InquiryEleanorQuery& t) { // NOLINT
	//BIND_FROM_TO_ULL(j, t, pageIndex);
	//BIND_FROM_TO_ULL(j, t, pageSize);
	//BIND_FROM_TO_NORMAL(j, t, name);
	//BIND_FROM_TO_NORMAL(j, t, sex);
	}
	}
};

class AssignInquiryEleanorQuery
{
//��ѯ��ָ��������Ϣ

public:
	// ��from_json
	friend void from_json(const json& j, InquiryEleanorQuery& t) { // NOLINT
	//BIND_FROM_TO_ULL(j, t, pageIndex);
	//BIND_FROM_TO_ULL(j, t, pageSize);
	//BIND_FROM_TO_NORMAL(j, t, name);
	//BIND_FROM_TO_NORMAL(j, t, sex);
	}

};

#endif // !_INQUIRYELEANOR_QUERY_