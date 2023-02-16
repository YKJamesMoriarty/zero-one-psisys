#include "stdafx.h"
#include "domain/vo/JsonVO.h"
#include "domain/dto/pur-inquiry/AddPurInquiryDTO.h"
#include "domain/dto/pur-inquiry/PurInquiryRemoveDTO.h"
#include "domain/dto/pur-inquiry/PurInquiryIntoDTO.h"
#include "domain/vo/pur-inquiry/PurInquiryIntoVO.h"
#include "domain/query/pur-inquiry/PurInquiryExportQuery.h"
#include "domain/dto/pur-inquiry/PurInquiryModBillStatusDTO.h"
#include "domain/vo/pur-inquiry/AddPurInquiryVO.h"
#ifndef __PURINQUIRYCONTROLLER_H__
#define __PURINQUIRYCONTROLLER_H__

class PurInquiryController
{
public:
	CREATE_API_FUN_BODY_FILE(addPurInquiry, execAddPurInquiry, AddPurInquiryDTO);
	CREATE_API_FUN_BODY_FILE(modifyPurInquiry, execModifyPurInquiry, AddPurInquiryDTO);
	CREATE_API_FUN_BODY(removePurInquiry, execRemovePurInquiry, PurInquiryRemoveDTO);
	CREATE_API_FUN_BODY(modifyPurQuotModBillStatus,execModifyPurQuotModBillStatus,PurInquiryModBillStatusDTO)
	CREATE_API_FUN_BODY_FILE(PurInquiryInto, execPurInquiryInto, PurInquiryIntoDTO);
	CREATE_API_FUN_QUERY(PurInquiryExport, execPurInquiryExport, PurInquiryExportQuery);

private:
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

#endif  //__PURINQUIRYCONTROLLER_H__
