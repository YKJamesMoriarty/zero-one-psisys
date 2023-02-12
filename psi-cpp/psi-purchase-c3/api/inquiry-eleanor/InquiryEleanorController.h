#pragma once


#ifndef _INQUIRYELEANOR_CONTROLLER_
#define _INQUIRYELEANOR_CONTROLLER_

#include "../../domain/query/inquiry-eleanor/InquiryEleanorQuery.h"
#include "../../domain/dto/inquiry-eleanor/InquiryEleanorDTO.h"
#include "../../domain/dto/IDDTO.h"
#include "../../domain/vo/inquiry-eleanor/InquiryEleanorVO.h"
#include "../../domain/vo/PageVO.h"
#include "../../domain/vo/JsonVO.h"
#include "../../domain/dto/user/UserDTO.h"
#include "../../domain/vo/user/UserVO.h"
using json = nlohmann::json;

/**
 * ʾ������������ʾ�ӿڵ�ʹ��
 */
class InquiryEleanorController
{
public:
	//�ӿ�1 ��ѯ�ɹ�ѯ�۵���ҳ�б�
	CREATE_API_FUN_QUERY_PAYLOAD(queryInquiryEleanor, execQueryInquiryEleanor, InquiryEleanorQuery);
	//�ӿ�2 �鿴ָ��ѯ�۵���ϸ��Ϣ
	CREATE_API_FUN_QUERY_PAYLOAD(queryAssignInquiryEleanor, execQueryAssignInquiryEleanor, InquiryEleanorQuery);

	//��ʾJSON�ύ
	CREATE_API_FUN_JSON(jsonInquiryEleanor, execJsonInquiryEleanor, InquiryEleanorDTO);

private:
	//��ѯ�ɹ�ѯ�۵���ҳ�б�
	json execQueryInquiryEleanor(const InquiryEleanorQuery& query, const PayloadDTO& payload);
	//�鿴ָ��ѯ�۵���ϸ��Ϣ
	json execQueryAssignInquiryEleanor(const InquiryEleanorQuery& query, const PayloadDTO& payload);

	//��ʾJSON�ύ
	json execJsonInquiryEleanor(const InquiryEleanorDTO& dto);
};

#endif // _INQUIRYELEANOR__CONTROLLER_
