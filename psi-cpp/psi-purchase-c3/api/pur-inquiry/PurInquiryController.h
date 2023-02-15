#include "stdafx.h"
#include "domain/vo/JsonVO.h"
#include "domain/dto/pur-inquiry/PurInquiryDTO.h"
#include "domain/query/pur-inquiry/PurInquiryQuery.h"
#include "domain/vo/pur-inquiry/PurInquiryVO.h"
#ifndef __PURINQUIRYCONTROLLER_H__
#define __PURINQUIRYCONTROLLER_H__

class PurInquiryController
{
public:
	CREATE_API_FUN_BODY(addPurInquiry, execAddPurInquiry, InquiryDTO);
	CREATE_API_FUN_BODY(modifyPurInquiry, execModifyPurInquiry, InquiryDTO);
	CREATE_API_FUN_BODY(removePurInquiry, execRemovePurInquiry, PurInquiryRemoveDTO);
	CREATE_API_FUN_BODY_FILE(PurInquiryInto, execPurInquiryInto, PurInquiryDTO);
	CREATE_API_FUN_QUERY(PurInquiryExport, execPurInquiryExport, PurInquiryQurey);

private:
	//�������
	JsonVO<uint64_t> execAddPurInquiry(const InquiryDTO& dto);

	//�޸�����
	JsonVO<uint64_t> execModifyPurInquiry(const InquiryDTO& dto);

	//ɾ������
	JsonVO<uint64_t> execRemovePurInquiry(const PurInquiryRemoveDTO& dto);

	//�ļ��ϴ�
	JsonVO<PurInquiryVO> execPurInquiryInto(const PurInquiryDTO& dto);

	//�ļ�����
	JsonVO<std::string> execPurInquiryExport(const PurInquiryQurey& qurry);


};

#endif  //__PURINQUIRYCONTROLLER_H__
