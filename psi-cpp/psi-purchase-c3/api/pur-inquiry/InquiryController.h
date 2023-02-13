#include "stdafx.h"
#include "domain/vo/JsonVO.h"
#include "domain/dto/pur-inquiry/InquiryDTO.h"
#include "domain/vo/pur-inquiry/InquiryVO.h"
#ifndef __INQUIRYCONTROLLER_H__
#define __INQUIRYCONTROLLER_H__


class InquiryHuilaiController
{
public:
	CREATE_API_FUN_BODY(addPurInquiry, execAddPurInquiry, InquiryDTO);
	CREATE_API_FUN_BODY(modifyPurInquiry, execModifyPurInquiry, InquiryDTO);
	CREATE_API_FUN_BODY(removePurInquiry, execRemovePurInquiry, InquiryDTO);
	CREATE_API_FUN_BODY_FILE(modifyPurInquiryInfo, execModifyPurInquiryInfo, InquiryDTO);
	CREATE_API_FUN_BODY_FILE(modifyPurInquiryIn, execModifyPurInquiryIn, InquiryDTO);

private:
	//�������
	JsonVO<uint64_t> execAddPurInquiry(const InquiryDTO& dto);

	//�޸�����
	JsonVO<uint64_t> execModifyPurInquiry(const InquiryDTO& dto);

	//ɾ������
	JsonVO<uint64_t> execRemovePurInquiry(const InquiryDTO& dto);

	//�ļ��ϴ�
	JsonVO<InquiryVO> execModifyPurInquiryInfo(const InquiryDTO& dto);

	//�ļ�����
	JsonVO<InquiryVO> execModifyPurInquiryIn(const InquiryDTO& dto);


};

#endif  //__INQUIRYCONTROLLER_H__
