#ifndef _PUR_COM_EXPORT_DTO_
#define _PUR_COM_EXPORT_DTO_

#include "../../GlobalInclude.h"
#include "../FileDTO.h"

class PurComExportDTO{
	//���ݱ��(ʹ�õ��ݱ�Ų�ѯ)
	CC_SYNTHESIZE(string, bill_no, Bill_no);

public:
	// ��JSONת������
	friend void from_json(const json& j, PurComExportDTO& t) {
		BIND_FROM_TO_ULL(j, t, bill_no);
	}
};
#endif