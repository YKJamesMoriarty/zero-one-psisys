#include "stdafx.h"
#include "InquiryEleanorController.h"
#include "../../service/inquiry-eleanor/InquiryEleanorService.h"
#include "nlohmann/json.hpp"
using json = nlohmann::json;

//��ѯ�ɹ�ѯ�۵���ҳ�б�
json InquiryEleanorController::execQueryInquiryEleanor(const InquiryEleanorQuery& query, const PayloadDTO& payload)
{
	return JsonVO<PageVO<InquiryEleanorVO>>();
}

//�鿴ָ��ѯ�۵���ϸ��Ϣ
json execQueryAssignInquiryEleanor(const AssignInquiryEleanorQuery& query, const PayloadDTO& payload)
{
	return JsonVO<PageVO<AssignInquiryEleanorVO>>();
}

//��ʾJSON�ύ
json InquiryEleanorController::execJsonInquiryEleanor(const InquiryEleanorDTO& dto)
{
	return JsonVO<InquiryEleanorVO>();
}


