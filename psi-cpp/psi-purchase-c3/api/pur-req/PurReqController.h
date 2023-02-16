#pragma once


#ifndef _PUR_REQ_CONTROLLER_
#define _PUR_REQ_CONTROLLER_

#include"api/ApiHelper.h"




#include "../../domain/vo/PageVO.h"
#include "../../domain/vo/JsonVO.h"
#include "../../domain/dto/IDDTO.h"

//��ѯ�����б�
#include "../../domain/query/pur-req/PurReqFindBillQuery.h"
#include "../../domain/query/pur-req/PurReqFindDetailBillQuery.h"


//query
#include "../../domain/query/pur-req/PurReqExportQuery.h"

//vo
#include "../../domain/vo/pur-req/PurReqIntoVO.h"
#include "../../domain/vo/pur-req/PurReqFindDetailBillVO.h"
#include "../../domain/vo/pur-req/PurReqFindBillVO.h"

//dto
#include "../../domain/dto/pur-req/AddPurReqDTO.h"
#include "../../domain/dto/pur-req/DeletePurReqDTO.h"
#include "../../domain/dto/pur-req/ModifyPurReqDTO.h"
#include "../../domain/dto/pur-req/PurReqModBillStatusDTO.h"

#include "../../domain/dto/pur-req/PurReqIntoDTO.h"



/**
 * �ɹ����빦�ܵ�
 */
class PurReqController
{
public:
	//�ӿ�1 �������뵥

	CREATE_API_FUN_BODY_PAYLOAD(queryPurReqExport, execPurReqExport, PurReqExportQuery);

	//�ӿ�2 �������뵥

	CREATE_API_FUN_BODY_FILE(modifyPurReqInto, execPurReqInto, PurReqIntoDTO);
	CREATE_API_FUN_QUERY_PAYLOAD(queryPurReqFindBill, execQueryPurReqFindBill,PurReqFindBillQuery);
	CREATE_API_FUN_QUERY_PAYLOAD(queryPurReqFindDetailBill, execQueryPurReqFindDetailBill, PurReqFindDetailBillQuery);
	//����޸�ɾ����Ҫ�޸��˺������˵���Ϣ,��������û���Ϣ����
	
//��Ӷ���
	CREATE_API_FUN_BODY_PAYLOAD_FILE(addPurReq, execAddPurReq, AddPurReqDTO);
	//�޸Ķ���
	CREATE_API_FUN_BODY_PAYLOAD_FILE(modifyPurReq, execModifyPurReq, ModifyPurReqDTO);
	//ɾ������
	CREATE_API_FUN_BODY(removePurReqById, execRemovePurReqById, DeletePurReqDTO);
	//�޸Ķ���״̬���رա����ϡ����رգ�
	CREATE_API_FUN_BODY_PAYLOAD(modifyPurReqBillStatus, execModifyPurReqBillStatus, PurReqModBillStatusDTO);
	
private:

	//��ѯ�����б�
	JsonVO<PageVO<PurReqFindBillVO>> execQueryPurReqFindBill(const PurReqFindBillQuery& query, const PayloadDTO& payload);
	//��ѯָ��������ϸ��Ϣ
	JsonVO<PurReqFindDetailBillVO> execQueryPurReqFindDetailBill(const PurReqFindDetailBillQuery& query, const PayloadDTO& payload);
		//ִ�з���������

	//ִ�з���������
	JsonVO<std::string> execPurReqExport(const PurReqExportQuery&query, const PayloadDTO &payload);

	//ִ�з���������
	JsonVO<PurReqIntoVO> execPurReqInto(const PurReqIntoDTO& dto);
	
//��������
	JsonVO<uint64_t> execAddPurReq(const AddPurReqDTO& dto, const PayloadDTO& payload);
	//�޸Ķ���
	JsonVO<uint64_t> execModifyPurReq(const ModifyPurReqDTO& dto, const PayloadDTO& payload);
	//�޸Ķ���״̬
	JsonVO<uint64_t> execModifyPurReqBillStatus(const PurReqModBillStatusDTO& dto, const PayloadDTO& payload);
	//ɾ������
	JsonVO<uint64_t> execRemovePurReqById(const DeletePurReqDTO& id);

};
#endif 


