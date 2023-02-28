



#pragma once
#ifndef _PUR_INQUIRY_CONTROLLER_H_
#define _PUR_INQUIRY_CONTROLLER_H_

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
#include "../../domain/vo/pur-inquiry/PurInquiryExportVO.h"
#include "stdafx.h"
#include "../../domain/vo/PageVO.h"
#include "../../domain/vo/JsonVO.h"
#include "../../domain/dto/IDDTO.h"
//dto
#include "../../domain/dto/pur-inquiry/AddPurInquiryDTO.h"
#include "../../domain/dto/pur-inquiry/PurInquiryIntoDTO.h"
#include "../../domain/dto/pur-inquiry/PurInquiryModBillStatusDTO.h"
#include "../../domain/dto/pur-inquiry/PurInquiryRemoveDTO.h"
#include "../../domain/dto/pur-inquiry/PurInquiryIntoDTO.h"


//query
#include "../../domain/query/pur-inquiry/PurInquiryFindBillQuery.h"
#include "../../domain/query/pur-inquiry/PurInquiryFindDetailBillQuery.h"
#include "../../domain/query/pur-inquiry/PurInquiryExportQuery.h"
//vo
#include "../../domain/vo/pur-inquiry/PurInquiryFindBillVO.h"
#include "../../domain/vo/pur-inquiry/PurInquiryFindDetailBillVO.h"
#include "../../domain/vo/pur-inquiry/EntryPurInquiryVO.h"
#include "../../domain/vo/pur-inquiry/PurInquiryExportVO.h"
#include "../../domain/vo/pur-inquiry/PurInquiryIntoVO.h"


//�������������
#include "../../domain/dto/pur-inquiry/PurInquiryRemoveDTO.h"
//#include "../../domain/dto/pur-inquiry/PurInquiryIntoDTO.h"


#include "../../domain/vo/pur-inquiry/PurInquiryIntoVO.h"




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
	//����ѯ��
	CREATE_API_FUN_JSON_PAYLOAD(addPurInquiry, execAddPurInquiry, AddPurInquiryDTO);
	//�޸�ѯ��
	CREATE_API_FUN_JSON_PAYLOAD(modifyPurInquiry, execModifyPurInquiry, AddPurInquiryDTO);
	//ɾ��ѯ��
	CREATE_API_FUN_BODY(removePurInquiry, execRemovePurInquiry, PurInquiryRemoveDTO);
	//�޸�ѯ�۵���
	CREATE_API_FUN_BODY(modifyPurQuotModBillStatus, execModifyPurQuotModBillStatus, PurInquiryModBillStatusDTO);
	// ����
	CREATE_API_FUN_JSON_PAYLOAD(queryPurInquiryExport, execQueryPurInquiryExport, PurInquiryExportQuery);
	// ����
	CREATE_API_FUN_BODY_PAYLOAD_FILE(addPurInquiryInto, execaddPurInquiryInto, PurInquiryIntoDTO);
private:
	//��ѯ�ɹ�ѯ�۵���ҳ�б�
	JsonVO<PageVO<PurInquiryFindBillVO>> execQueryPurInquiryFindBill(const PurInquiryFindBillQuery& query, const PayloadDTO& payload);
	//�鿴ָ��ѯ�۵���ϸ��Ϣ
	JsonVO<PurInquiryFindDetailBillVO> execQueryPurInquiryFindDetailBill(const PurInquiryFindDetailBillQuery& query, const PayloadDTO& payload);
	//�������
	JsonVO<uint64_t> execAddPurInquiry(const AddPurInquiryDTO& dto, const PayloadDTO& payload);
	//�޸�����
	JsonVO<std::string> execModifyPurInquiry(const AddPurInquiryDTO& dto, const PayloadDTO& payload);
	//ɾ������
	JsonVO<string> execRemovePurInquiry(const PurInquiryRemoveDTO& dto);
	//�޸ĵ���״̬
	JsonVO<string> execModifyPurQuotModBillStatus(const PurInquiryModBillStatusDTO& dto);
	//�����������ݱ��������ѯ�󣬷���xml���������ļ���
	JsonVO<std::string> execQueryPurInquiryExport(const PurInquiryExportQuery& query,const PayloadDTO& payload);
	//���루�ϴ��ļ��󣬽�xml������json/cpp�������ݿ⣬�������ݣ�
	JsonVO<uint64_t> execaddPurInquiryInto(const PurInquiryIntoDTO& dto, const PayloadDTO& payload);
};

#endif 





