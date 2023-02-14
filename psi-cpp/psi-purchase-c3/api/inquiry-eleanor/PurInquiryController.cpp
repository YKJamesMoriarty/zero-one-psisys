#include "stdafx.h"
#include "PurInquiryController.h"
#include "../../service/inquiry-eleanor/PurInquiryService.h"
#include "nlohmann/json.hpp"

//��ѯ�ɹ�ѯ�۵���ҳ�б�
JsonVO<PageVO<PurInquiryFindBillVO>> PurInquiryController::execQueryPurInquiryFindBill(const PurInquiryFindBillQuery& query, const PayloadDTO& payload)
{
	return JsonVO<PageVO<PurInquiryFindBillVO>>();
}

//�鿴ָ��ѯ�۵���ϸ��Ϣ
JsonVO<PurInquiryFindDetailBillVO> execQueryPurInquiryFindDetailBill(const PurInquiryFindDetailBillQuery& query, const PayloadDTO& payload)
{
	return JsonVO<PurInquiryFindDetailBillVO>();
}


