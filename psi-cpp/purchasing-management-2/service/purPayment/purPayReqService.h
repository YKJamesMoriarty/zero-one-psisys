#pragma once

#ifndef _PUR_PAY_REQ_SERVICE_
#define _PUR_PAY_REQ_SERVICE_

#include "SnowFlake.h"
#include "FastDfsClient.h"
#include "ExcelComponent.h"
#include "CharsetConvertHepler.h"
#include <time.h>
#include <cstdio> 

#include "../../domain/vo/PageVO.h"
#include "../../domain/dto/PaymentBillImpl/AddPayApplyDTO.h"
#include "../../domain/dto/PaymentBillImpl/ModPayApplyDTO.h"
#include"../../domain/vo/PaymentBillImpl/PaymentBillVO.h"
#include"../../domain/vo/PaymentBillImpl/PaymentBillDetailVO.h"
#include"../../domain/query/PaymentBillImpl/PaymentBillQuery.h"
#include"../../domain/query/PaymentBillImpl/PaymentBillDetailQuery.h"


class PurPayReqService
{
public:
	//��������
	uint64_t addData(const AddPayApplyDTO& dto, const PayloadDTO& payload);

	//��������
	uint64_t updateData(const ModPayApplyDTO& dto, const PayloadDTO& payload);
	
	// ��ҳ��ѯ��������
	PageVO<PaymentBillVO> queryList(const PaymentBillQuery& query);
	//��ѯָ��������ϸ��Ϣ
	PaymentBillDetailVO detailDate(const PaymentBillDetailQuery& query);
	
};


#endif // _PUR_PAY_REQ_SERVICE_