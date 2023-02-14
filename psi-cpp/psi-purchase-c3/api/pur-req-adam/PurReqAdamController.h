#pragma once
#ifndef _PUR_REQ_ADAM_CONTROLLER_
#define _PUR_REQ_ADAM_CONTROLLER_

#include "../../domain/dto/pur-req-adam/PurReqAdamDTO.h"
#include "../../domain/vo/pur-req-adam/PurReqAdamVO.h"
#include "../../domain/dto/IDDTO.h"
#include "../../domain/vo/PageVO.h"
#include "../../domain/vo/JsonVO.h"


class PurReqAdamController
{
public:
	//��Ӷ���
	CREATE_API_FUN_BODY(addPurReq, execAddPurReq, AddAndModifyPurReqDTO);
	//�޸Ķ���
	CREATE_API_FUN_BODY(modifyPurReq, execModifyPurReq, AddAndModifyPurReqDTO);
	//ɾ������
	CREATE_API_FUN_BODY(removePurReqById, execRemovePurReqById, DeletePurDTO);
	//�޸Ķ���״̬���رա����ϡ����رգ�
	CREATE_API_FUN_BODY(modifyPurReqBillStatus, execModifyPurReqBillStatus, PurReqModBillStatusDTO);
private:
	//��������
	JsonVO<uint64_t> execAddPurReq(const AddAndModifyPurReqDTO& dto);
	//�޸Ķ���
	JsonVO<uint64_t> execModifyPurReq(const AddAndModifyPurReqDTO& dto);
	//�޸Ķ���״̬
	JsonVO<uint64_t> execModifyPurReqBillStatus(const PurReqModBillStatusDTO& dto);
	//ɾ������
	JsonVO<uint64_t> execRemovePurReqById(const DeletePurDTO& id);
};
#endif // _PUR_REQ_ADAM_CONTROLLER_