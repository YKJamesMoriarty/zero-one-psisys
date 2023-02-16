
#pragma once


#ifndef _PUR_INQUIRY_CONTROLLER_
#define _PUR_INQUIRY_CONTROLLER_

//�����ӿ�
#include "../../domain/vo/PageVO.h"
#include "../../domain/vo/JsonVO.h"
#include "../../domain/dto/IDDTO.h"
//dto

//query
#include "../../domain/query/pur-inquiry/PurInquiryFindBillQuery.h"
#include "../../domain/query/pur-inquiry/PurInquiryFindDetailBillQuery.h"

//vo
#include "../../domain/vo/pur-inquiry/PurInquiryFindBillVO.h"
#include "../../domain/vo/pur-inquiry/PurInquiryFindDetailBillVO.h"
#include "../../domain/vo/pur-inquiry/EntryPurInquiryVO.h"


/**
 * ʾ������������ʾ�ӿڵ�ʹ��
 */
class PurInquiryController
{
public:
	//�ӿ�1 ��ѯ�ɹ�ѯ�۵���ҳ�б�
	CREATE_API_FUN_QUERY_PAYLOAD(queryPurInquiryFindBill, execQueryPurInquiryFindBill, PurInquiryFindBillQuery);
	//�ӿ�2 �鿴ָ��ѯ�۵���ϸ��Ϣ
	CREATE_API_FUN_QUERY_PAYLOAD(queryPurInquiryFindDetailBill, execQueryPurInquiryFindDetailBill, PurInquiryFindDetailBillQuery);

private:
	//��ѯ�ɹ�ѯ�۵���ҳ�б�
	JsonVO<PageVO<PurInquiryFindBillVO>> execQueryPurInquiryFindBill(const PurInquiryFindBillQuery& query, const PayloadDTO& payload);
	//�鿴ָ��ѯ�۵���ϸ��Ϣ
	JsonVO<PurInquiryFindDetailBillVO> execQueryPurInquiryFindDetailBill(const PurInquiryFindDetailBillQuery& query, const PayloadDTO& payload);


};

#endif 





