#ifndef _BILLSTAGE_VO_
#define _BILLSTAGE_VO_

#include "../GlobalInclude.h"

	class BillStageVO
{
	// �׶α��
	CC_SYNTHESIZE(uint64_t, id, Id);
	// �׶�����
	CC_SYNTHESIZE(string, name, Name);
public:
	// ��JSONת������
	BIND_TO_JSON(BillStageVO, id, name);
};

#endif // !_SAMPLE_VO_