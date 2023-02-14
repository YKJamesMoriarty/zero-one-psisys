#include "stdafx.h"
#include "PurReqIntoDTO.h"

void from_json(const json& j, PurReqIntoDTO& t) { // NOLINT
	
	BIND_FROM_TO_ULL (j, t, purReqSubject);

	// �ɹ�����	�������ӿڣ�
	// ������	�������ӿڣ�
	// ������	��ѡ���û������ӿڣ�

	BIND_FROM_TO_ULL(j, t, purReqRequestTime);
	BIND_FROM_TO_ULL(j, t, purReqSrcEntryNo);
	BIND_FROM_TO_ULL(j, t, purReqMaterialId);

	// ����ͺţ������ӿڣ�

	BIND_FROM_TO_ULL(j, t, purReqUnitId);
	BIND_FROM_TO_D(j, t, purReqQty);
	BIND_FROM_TO_D(j, t, purReqTaxRate);
	BIND_FROM_TO_D(j, t, purReqPrice);
	BIND_FROM_TO_D(j, t, purReqAmt);

	// ���鹩Ӧ�̣������ӿڣ�

	BIND_FROM_TO_ULL(j, t, purReqRemark);
	BIND_FROM_TO_ULL(j, t, purReqCustom1);
	BIND_FROM_TO_ULL(j, t, purReqCustom2);

}