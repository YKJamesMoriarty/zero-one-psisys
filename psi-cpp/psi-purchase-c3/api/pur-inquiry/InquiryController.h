#include "stdafx.h"
#include "domain/vo/JsonVO.h"
#include "domain/dto/pur-inquiry/InquiryDTO.h"
#include "domain/vo/pur-inquiry/InquiryVO.h"
#include "domain/query/pur-inquiry/InquiryQuery.h"
#ifndef __INQUIRYCONTROLLER_H__
#define __INQUIRYCONTROLLER_H__


class InquiryController
{
public:
	CREATE_API_FUN_BODY(addPurInquiry, execAddPurInquiry, InquiryDTO);
	CREATE_API_FUN_BODY(modifyPurInquiry, execModifyPurInquiry, InquiryDTO);
	CREATE_API_FUN_BODY(removePurInquiry, execRemovePurInquiry, InquiryDTO);
	CREATE_API_FUN_BODY_FILE(PurInquiryInto, execPurInquiryInto, PurInquiryDTO);
	CREATE_API_FUN_QUERY(PurInquiryExport, execPurInquiryExport, PurInquiryQurey);

private:
	//�������
	JsonVO<uint64_t> execAddPurInquiry(const InquiryDTO& dto);

	//�޸�����
	JsonVO<uint64_t> execModifyPurInquiry(const InquiryDTO& dto);

	//ɾ������
	JsonVO<uint64_t> execRemovePurInquiry(const InquiryDTO& dto);

	//�ļ��ϴ�
	JsonVO<InquiryVO> execPurInquiryInto(const PurInquiryDTO& dto);

	//�ļ�����
	JsonVO<std::string> execPurInquiryExport(const PurInquiryQurey& qurry);


};

#endif  //__INQUIRYCONTROLLER_H__
