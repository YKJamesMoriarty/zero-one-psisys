#ifndef _BILLSTAGE_VO_
#define _BILLSTAGE_VO_

#include "../GlobalInclude.h"

/*
���ݽ׶������б�
Author C1-��ľ
2023.2.11 18��11��
*/
	class BillStageVO
{
	// �׶α��
	CC_SYNTHESIZE(int, id, Id);
	// �׶�����
	CC_SYNTHESIZE(string, name, Name);
public:
	// ��JSONת������
	BIND_TO_JSON(BillStageVO, id, name);
};

#endif //_BILLSTAGE_VO_