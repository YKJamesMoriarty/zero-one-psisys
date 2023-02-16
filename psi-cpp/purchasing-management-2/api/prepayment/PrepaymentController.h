#pragma once
#ifndef _SAMPLE_CONTROLLER_
#define _SAMPLE_CONTROLLER_

#include "../../domain/query/prepaymentbill/PrepaymentBillQuery.h"
#include "../../domain/query/prepaymentbill/PrepaymentDetailBillQuery.h"
#include "../../domain/dto/prepayment/PrepaymentDTO.h"
#include "../../domain/dto/IDDTO.h"
#include "../../domain/vo/prepayment/PrepaymentVO.h"
#include "../../domain/vo/PageVO.h"
#include "../../domain/vo/JsonVO.h"
#include "../../domain/dto/prepayment/"
#include "../../domain/vo/user/UserVO.h"

/**
 * ʾ������������ʾ�����ӿڵ�ʹ��
 */
class PrepaymentController
{
public:
	CREATE_API_FUN_QUERY_PAYLOAD(queryPrepayment, execQueryPrepayment, PrepaymentQuery);
	CREATE_API_FUN_BODY(addPrepayment, execAddPrepayment, PrepaymentDTO);
	CREATE_API_FUN_BODY(modifyPrepayment, execModifyPrepayment, PrepaymentDTO);
	CREATE_API_FUN_BODY(removePrepayment, execRemovePrepayment, PrepaymentDTO);
	CREATE_API_FUN_BODY(removeById, execRemoveById, IntID);
	CREATE_API_FUN_JSON(jsonPrepayment, execJsonPrepayment, PrepaymentDTO);
	CREATE_API_FUN_BODY_FILE(modifyUserInfo, execModifyUserInfo, UserDTO);
private:
	//��ʾ��ѯ����
	JsonVO<PageVO<PrepaymentVO>> execQueryPrepayment(const PrepaymentBillQuery& query, const PayloadDTO& payload);
	//��ʾ��������
	JsonVO<uint64_t> execAddPrepayment(const PrepaymentDTO& dto);
	//��ʾ�޸�����
	JsonVO<uint64_t> execModifyPrepayment(const PrepaymentDTO& dto);
	//��ʾɾ������
	JsonVO<uint64_t> execRemovePrepayment(const PrepaymentDTO& dto);
	JsonVO<uint64_t> execRemoveById(const IntID& id);
	//��ʾJSON�ύ
	JsonVO<PrepaymentVO> execJsonPrepayment(const PrepaymentDTO& dto);
	//��ʾ�ļ��ϴ�
	JsonVO<UserVO> execModifyUserInfo(const UserDTO& dto);
};

#endif // _SAMPLE_CONTROLLER_