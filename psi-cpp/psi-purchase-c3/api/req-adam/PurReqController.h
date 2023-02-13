#pragma once
#ifndef _REQADAM_CONTROLLER_
#define _REQADAM_CONTROLLER_

#include "../../domain/dto/req-adam/PurReqDTO.h"
#include "../../domain/dto/IDDTO.h"
#include "../../domain/vo/PageVO.h"
#include "../../domain/vo/JsonVO.h"


class ReqAdamController
{
public:
	//��Ӷ���
	CREATE_API_FUN_BODY(addPurReq, execAddPurReq, PurReqDTO);
	//�޸Ķ���
	CREATE_API_FUN_BODY(modifyPurReq, execModifyPurReq, PurReqDTO);
	//ɾ������
	CREATE_API_FUN_BODY(removePurReq, execRemovePurReq, PurReqDTO);
	CREATE_API_FUN_BODY(removeById, execRemoveById, IntID);

	//�޸Ķ���״̬���رա����ϡ����رգ�
	CREATE_API_FUN_BODY(modifyPurReqState, execModifyPurReqState, PurReqDTO);
private:
	//��ʾ��������
	JsonVO<uint64_t> execAddPurReq(const PurReqDTO& dto);
	//��ʾ�޸�����
	JsonVO<uint64_t> execModifyPurReq(const PurReqDTO& dto);
	//��ʾ�޸�״̬
	JsonVO<uint64_t> execModifyPurReqState(const PurReqDTO& dto);
	//��ʾɾ������
	JsonVO<uint64_t> execRemovePurReq(const PurReqDTO& dto);
	JsonVO<uint64_t> execRemoveById(const IntID& id);
};
#endif // _REQADAM_CONTROLLER_