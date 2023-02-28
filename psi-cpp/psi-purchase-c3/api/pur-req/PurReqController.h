#pragma once
#ifndef _PUR_REQ_CONTROLLER_H_
#define _PUR_REQ_CONTROLLER_H_

#include"api/ApiHelper.h"

#include "../../domain/vo/PageVO.h"
#include "../../domain/vo/JsonVO.h"

//��ѯ�����б�
//query
#include "../../domain/query/pur-req/PurReqFindBillQuery.h"
#include "../../domain/query/pur-req/PurReqFindDetailBillQuery.h"
//vo
#include "../../domain/vo/pur-req/PurReqFindDetailBillVO.h"
#include "../../domain/vo/pur-req/PurReqFindBillVO.h"
#include "../../domain/vo/pur-req/PurReqExportVO.h"

//dto
#include "../../domain/dto/pur-req/AddPurReqDTO.h"
#include "../../domain/dto/pur-req/DeletePurReqDTO.h"
#include "../../domain/dto/pur-req/ModifyPurReqDTO.h"
#include "../../domain/dto/pur-req/PurReqModBillStatusDTO.h"
#include "../../domain/dto/pur-req/PurReqIntoDTO.h"
#include "../../domain/dto/pur-req/PurReqExportDTO.h"

/**
 * �ɹ����빦�ܵ�
 */
class PurReqController
{
public:
	//����
	CREATE_API_FUN_JSON_PAYLOAD(queryPurReqExport, execPurReqExport, PurReqExportDTO);
	//����
	CREATE_API_FUN_BODY_PAYLOAD_FILE(modifyPurReqInto, execPurReqInto, PurReqIntoDTO);
	//��ѯ�����б�
	CREATE_API_FUN_QUERY_PAYLOAD(queryPurReqFindBill, execQueryPurReqFindBill, PurReqFindBillQuery);
	//��ѯָ��������ϸ��Ϣ
	CREATE_API_FUN_QUERY_PAYLOAD(queryPurReqFindDetailBill, execQueryPurReqFindDetailBill, PurReqFindDetailBillQuery);
	//�������(����/�ύ)
	CREATE_API_FUN_JSON_PAYLOAD(addPurReq, execAddPurReq, AddPurReqDTO);
	//�޸�����(����/�ύ/���)
	CREATE_API_FUN_JSON_PAYLOAD(modifyPurReq, execModifyPurReq, ModifyPurReqDTO);
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
	JsonVO<uint64_t> execPurReqInto(const PurReqIntoDTO& dto, const PayloadDTO& payload);
	//����
	JsonVO<string> execPurReqExport(const PurReqExportDTO& dto, const PayloadDTO &payload);
};
#endif 


