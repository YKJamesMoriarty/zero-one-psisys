
#pragma once


#ifndef _PUR_INQUIRY_CONTROLLER_
#define _PUR_INQUIRY_CONTROLLER_

//�����ӿ�
#include "../../domain/vo/PageVO.h"
#include "../../domain/vo/JsonVO.h"
#include "../../domain/dto/IDDTO.h"
//dto
//#include "../../domain/dto/pur-inquiry/PurInquiryDTO.h"
#include "../../domain/dto/pur-inquiry/PurInquiryFindBillDTO.h"
#include "../../domain/dto/pur-inquiry/PurInquiryFindDetailBillDTO.h"

//query
//#include "../../domain/query/pur-inquiry/PurInquiryQuery.h"
#include "../../domain/query/pur-inquiry/PurInquiryFindBillQuery.h"
#include "../../domain/query/pur-inquiry/PurInquiryFindDetailBillQuery.h"

//vo
//#include "../../domain/vo/pur-inquiry/PurInquiryVO.h"
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
	//CREATE_API_FUN_BODY(addPurInquiry, execAddPurInquiry, InquiryDTO);
	//CREATE_API_FUN_BODY(modifyPurInquiry, execModifyPurInquiry, InquiryDTO);
	//CREATE_API_FUN_BODY(removePurInquiry, execRemovePurInquiry, PurInquiryRemoveDTO);
	//CREATE_API_FUN_BODY_FILE(PurInquiryInto, execPurInquiryInto, PurInquiryDTO);
	//CREATE_API_FUN_QUERY(PurInquiryExport, execPurInquiryExport, PurInquiryQurey);
private:
	//��ѯ�ɹ�ѯ�۵���ҳ�б�
	JsonVO<PageVO<PurInquiryFindBillVO>> execQueryPurInquiryFindBill(const PurInquiryFindBillQuery& query, const PayloadDTO& payload);
	//�鿴ָ��ѯ�۵���ϸ��Ϣ
	JsonVO<PurInquiryFindDetailBillVO> execQueryPurInquiryFindDetailBill(const PurInquiryFindDetailBillQuery& query, const PayloadDTO& payload);
	//�������
	//JsonVO<uint64_t> execAddPurInquiry(const InquiryDTO& dto);
	////�޸�����
	//JsonVO<uint64_t> execModifyPurInquiry(const InquiryDTO& dto);
	////ɾ������
	//JsonVO<uint64_t> execRemovePurInquiry(const PurInquiryRemoveDTO& dto);
	////�ļ��ϴ�
	//JsonVO<PurInquiryVO> execPurInquiryInto(const PurInquiryDTO& dto);
	////�ļ�����
	//JsonVO<std::string> execPurInquiryExport(const PurInquiryQurey& qurry);

};

#endif 





