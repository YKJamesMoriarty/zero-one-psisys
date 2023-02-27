#pragma once

#ifndef _PUR_REQ_SERVICE_
#define _PUR_REQ_SERVICE_

#include "../../domain/vo/PageVO.h"
#include "../../domain/dto/pur-req/AddPurReqDTO.h"
#include "../../domain/dto/pur-req/ModifyPurReqDTO.h"
#include "../../domain/dto/pur-req/PurReqModBillStatusDTO.h"
#include "../../domain/vo/pur-req/PurReqFindBillVO.h"
#include "../../domain/vo/pur-req/PurReqFindDetailBillVO.h"
#include "../../domain/query/pur-req/PurReqFindBillQuery.h"
#include "../../domain/query/pur-req/PurReqFindDetailBillQuery.h"

/**
 * ʾ������ʵ��
 */
class PurReqService
{
public:
	//��������
	uint64_t saveData(const AddPurReqDTO& dto, const PayloadDTO& payload);

	//�޸�����
	uint64_t updateData(const ModifyPurReqDTO& dto, const PayloadDTO& payload);

	//�޸�����״̬
	uint64_t updateBillStatus(const PurReqModBillStatusDTO& dto, const PayloadDTO& payload);

	// ͨ����Ŀ¼billNoɾ������
	bool removeData(string billNo);

	//���д�execlת�������ݸ�ʽ
	uint64_t getFromExecl(string fieldName, const PayloadDTO& payload);

	//ͨ��bill_no�б���execl���
	string getToExecl(list<string> billNoList);

	// ��ҳ��ѯ��������
	PageVO<PurReqFindBillVO> listAll(const PurReqFindBillQuery& query);
	//��ѯָ��������ϸ��Ϣ
	PurReqFindDetailBillVO detailsOne(const PurReqFindDetailBillQuery& query);

};

#endif // !_PUR_REQ_SERVICE_