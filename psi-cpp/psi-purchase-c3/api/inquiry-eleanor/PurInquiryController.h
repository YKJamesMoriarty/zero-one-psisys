#pragma once


#ifndef _PURINQUIRY_CONTROLLER_
#define _PURINQUIRY_CONTROLLER_

#include "../../domain/query/inquiry-eleanor/PurInquiryQuery.h"
#include "../../domain/dto/inquiry-eleanor/PurInquiryDTO.h"
#include "../../domain/dto/IDDTO.h"
#include "../../domain/vo/inquiry-eleanor/PurInquiryVO.h"
#include "../../domain/vo/PageVO.h"
#include "../../domain/vo/JsonVO.h"
#include "../../domain/dto/user/UserDTO.h"
#include "../../domain/vo/user/UserVO.h"

/**
 * ʾ������������ʾ�ӿڵ�ʹ��
 */
class PurInquiryController
{
public:
	//�ӿ�1 ��ѯ�ɹ�ѯ�۵���ҳ�б�
	CREATE_API_FUN_QUERY_PAYLOAD(queryPurInquiry, execQueryPurInquiryFindBill, PurInquiryFindBillQuery);
	//�ӿ�2 �鿴ָ��ѯ�۵���ϸ��Ϣ
	CREATE_API_FUN_QUERY_PAYLOAD(queryAssignPurInquiry, execQueryPurInquiryFindDetailBill, PurInquiryFindDetailBillQuery);


private:
	//��ѯ�ɹ�ѯ�۵���ҳ�б�
	JsonVO<PageVO<PurInquiryFindBillVO>> execQueryPurInquiryFindBill(const PurInquiryFindBillQuery& query, const PayloadDTO& payload);
	//�鿴ָ��ѯ�۵���ϸ��Ϣ
	JsonVO<PurInquiryFindDetailBillVO> execQueryPurInquiryFindDetailBill(const PurInquiryFindDetailBillQuery& query, const PayloadDTO& payload);

};

#endif // _PURINQUIRY__CONTROLLER_
