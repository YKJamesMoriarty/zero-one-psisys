#include "stdafx.h"
#ifndef __INQUIRYHUILAICONTROLLER_H__
#define __INQUIRYHUILAICONTROLLER_H__
#include "domain/vo/JsonVO.h"
#include "domain/dto/inquiry-huilai/InquiryHuilaiDTO.h"
#include "domain/vo/inquiry-huilai/InquiryHuilaiVO.h"



class InquiryHuilaiController
{
public:
	CREATE_API_FUN_BODY(addPurInquiry, execAddPurInquiry, InquiryHuilaiDTO);
	CREATE_API_FUN_BODY(modifyPurInquiry, execModifyPurInquiry, InquiryHuilaiDTO);
	CREATE_API_FUN_BODY(removePurInquiry, execRemovePurInquiry, InquiryHuilaiDTO);
	CREATE_API_FUN_BODY_FILE(modifyPurInquiryInfo, execModifyPurInquiryInfo, InquiryHuilaiDTO);
	CREATE_API_FUN_BODY_FILE(modifyPurInquiryIn, execModifyPurInquiryIn, InquiryHuilaiDTO);

private:
	//�������
	JsonVO<uint64_t> execAddPurInquiry(const InquiryHuilaiDTO& dto);

	//�޸�����
	JsonVO<uint64_t> execModifyPurInquiry(const InquiryHuilaiDTO& dto);

	//ɾ������
	JsonVO<uint64_t> execRemovePurInquiry(const InquiryHuilaiDTO& dto);

	//�ļ��ϴ�
	JsonVO<InquiryHuilaiVO> execModifyPurInquiryInfo(const InquiryHuilaiDTO& dto);

	//�ļ�����
	JsonVO<InquiryHuilaiVO> execModifyPurInquiryIn(const InquiryHuilaiDTO& dto);


};

#endif  //__INQUIRYHUILAICONTROLLER_H__
