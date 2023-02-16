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
	//��ѯ�����б�
	CREATE_API_FUN_QUERY_PAYLOAD(queryPurReqFindBill, execQueryPurReqFindBill, PurReqFindBillQuery);
	//��ѯָ��������ϸ��Ϣ
	CREATE_API_FUN_QUERY_PAYLOAD(queryPurReqFindDetailBill, execQueryPurReqFindDetailBill, PurReqFindDetailBillQuery);
	//�������(����/�ύ)
	CREATE_API_FUN_BODY_PAYLOAD_FILE(addPurReq, execAddPurReq, AddPurReqDTO);
	//�޸�����(����/�ύ/���)
	CREATE_API_FUN_BODY_PAYLOAD_FILE(modifyPurReq, execModifyPurReq, ModifyPurReqDTO);
	//ɾ������
	CREATE_API_FUN_BODY(removePurReqById, execRemovePurReqById, DeletePurReqDTO);
	//�޸ĵ���״̬(�رա����ϡ����ر�)
	CREATE_API_FUN_BODY_PAYLOAD(modifyPurReqBillStatus, execModifyPurReqBillStatus, PurReqModBillStatusDTO);
	
private:
	//��ѯ�����б�
	JsonVO<PageVO<PurReqFindBillVO>> execQueryPurReqFindBill(const PurReqFindBillQuery& query, const PayloadDTO& payload);
	//��ѯָ��������ϸ��Ϣ
	JsonVO<PurReqFindDetailBillVO> execQueryPurReqFindDetailBill(const PurReqFindDetailBillQuery& query, const PayloadDTO& payload);
  //�������(����/�ύ)
	JsonVO<uint64_t> execAddPurReq(const AddPurReqDTO& dto, const PayloadDTO& payload);
	//�޸�����
	JsonVO<uint64_t> execModifyPurReq(const ModifyPurReqDTO& dto, const PayloadDTO& payload);
	//ɾ������
	JsonVO<uint64_t> execRemovePurReqById(const DeletePurReqDTO& id);
	//�޸ĵ���״̬(�رա����ϡ����ر�)
	JsonVO<uint64_t> execModifyPurReqBillStatus(const PurReqModBillStatusDTO& dto, const PayloadDTO& payload);
	//����
	JsonVO<uint64_t> execPurReqInto(const PurReqIntoDTO& dto);
	//����
	JsonVO<std::string> execPurReqExport(const PurReqExportQuery& query, const PayloadDTO& payload);


};
#endif 


