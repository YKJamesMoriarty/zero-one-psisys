#pragma once
#ifndef _QTRK_SERVICE_
#define _QTRK_SERVICE_

#include "../../domain/dto/Qtrk/AddQtrkBillDTO.h"
#include "../../domain/dto/Pyrk/ApprovalDTO.h"
#include <list>
#include "../../domain/query/Qtrk/QueryQtrkBillListQuery.h"
#include "../../domain/query/Qtrk/QueryQtrkBillDetailsQuery.h"
#include "../../domain/dto/IDDTO.h"
#include "../../domain/vo/Qtrk/QueryQtrkBillListVO.h"
#include "../../domain/vo/Qtrk/QueryQtrkBillDetailsVO.h"
#include "../../domain/vo/PageVO.h"
#include "../../domain/vo/JsonVO.h"
#include"domain/dto/Qtrk/ModifyQtrkBillDTO.h"
#include"domain/do/Qtrk/ModifyQtrkBillStatusDO.h"
#include"domain/dto/Qtrk/DeleteQtrkBillDTO.h"
#include"domain/do/Qtrk/DeleteBill.h"

/*
* ����������
*/
class QtrkService {
public:
	// ������������
	int saveBillData(const AddQtrkBillDTO& dto, const PayloadDTO& payload);
	// �޸ĵ�������
	int updateBillDate(const AddQtrkBillDTO& dto, const PayloadDTO& payload);
	// ��˵���
	int updateApproval(const ApprovalDTO& dto, const PayloadDTO& payload);
	
	// ��ҳ��ѯ��������
	PageVO<QueryQtrkBillListVO> listQtrkBillList(const QueryQtrkBillListQuery& query);

	//��ѯ������ϸ��Ϣ
	QueryQtrkBillDetailsVO getQtrkBillDetails(const QueryQtrkBillDetailsQuery& query);

	//�޸ĵ���״̬
	bool updataBillStatus(const ModifyQtrkBillDTO& dto, const PayloadDTO& payload);

	//ɾ������
	bool deleteBill(const DeleteQtrkBillDTO& dto);
};

#endif // !_QTRK_SERVICE_
