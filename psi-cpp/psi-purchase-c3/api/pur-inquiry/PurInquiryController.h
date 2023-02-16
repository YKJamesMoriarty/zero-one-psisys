



#pragma once
#ifndef _PUR_INQUIRY_CONTROLLER_
#define _PUR_INQUIRY_CONTROLLER_

//�����ӿ�
#include "stdafx.h"
#include "../../domain/vo/PageVO.h"
#include "../../domain/vo/JsonVO.h"
#include "../../domain/dto/IDDTO.h"
//dto
#include "../../domain/dto/pur-inquiry/AddPurInquiryDTO.h"
#include "../../domain/dto/pur-inquiry/PurInquiryIntoDTO.h"
#include "../../domain/dto/pur-inquiry/PurInquiryModBillStatusDTO.h"


//query
#include "../../domain/query/pur-inquiry/PurInquiryFindBillQuery.h"
#include "../../domain/query/pur-inquiry/PurInquiryFindDetailBillQuery.h"
#include "../../domain/query/pur-inquiry/PurInquiryExportQuery.h"
//vo
#include "../../domain/vo/pur-inquiry/PurInquiryFindBillVO.h"
#include "../../domain/vo/pur-inquiry/PurInquiryFindDetailBillVO.h"
#include "../../domain/vo/pur-inquiry/EntryPurInquiryVO.h"


//�������������
#include "../../domain/dto/pur-inquiry/PurInquiryRemoveDTO.h"
#include "../../domain/dto/pur-inquiry/PurInquiryIntoDTO.h"


#include "../../domain/vo/pur-inquiry/PurInquiryIntoVO.h"


#include "../../domain/vo/pur-inquiry/AddPurInquiryVO.h"

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
	CREATE_API_FUN_BODY_FILE(addPurInquiry, execAddPurInquiry, AddPurInquiryDTO);
	CREATE_API_FUN_BODY_FILE(modifyPurInquiry, execModifyPurInquiry, AddPurInquiryDTO);
	CREATE_API_FUN_BODY(removePurInquiry, execRemovePurInquiry, PurInquiryRemoveDTO);
	CREATE_API_FUN_BODY(modifyPurQuotModBillStatus,execModifyPurQuotModBillStatus,PurInquiryModBillStatusDTO)
	CREATE_API_FUN_BODY_FILE(PurInquiryInto, execPurInquiryInto, PurInquiryIntoDTO);
	CREATE_API_FUN_QUERY(PurInquiryExport, execPurInquiryExport, PurInquiryExportQuery);
private:
	//��ѯ�ɹ�ѯ�۵���ҳ�б�
	JsonVO<PageVO<PurInquiryFindBillVO>> execQueryPurInquiryFindBill(const PurInquiryFindBillQuery& query, const PayloadDTO& payload);
	//�鿴ָ��ѯ�۵���ϸ��Ϣ
	JsonVO<PurInquiryFindDetailBillVO> execQueryPurInquiryFindDetailBill(const PurInquiryFindDetailBillQuery& query, const PayloadDTO& payload);
	//�������
	JsonVO<AddPurInquiryVO> execAddPurInquiry(const AddPurInquiryDTO& dto);
	//�޸�����
	JsonVO<AddPurInquiryVO> execModifyPurInquiry(const AddPurInquiryDTO& dto);
	//ɾ������
	JsonVO<uint64_t> execRemovePurInquiry(const PurInquiryRemoveDTO& dto);
	//�޸ĵ���״̬
	JsonVO<uint64_t> execModifyPurQuotModBillStatus(const PurInquiryModBillStatusDTO& dto);
	//�ļ��ϴ�
	JsonVO<PurInquiryIntoVO> execPurInquiryInto(const PurInquiryIntoDTO& dto);
	//�ļ�����
	JsonVO<std::string> execPurInquiryExport(const PurInquiryExportQuery& qurry);


};

#endif 





