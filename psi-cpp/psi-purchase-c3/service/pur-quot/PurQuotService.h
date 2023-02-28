#pragma once

#ifndef _PUR_QUOT_SERVICE_H_
#define _PUR_QUOT_SERVICE_H_
#include <list>
#include "../../domain/vo/PageVO.h"

//vo
#include "../../domain/vo/pur-quot/PurQuotFindBillVO.h"
#include "../../domain/vo/pur-quot/PurQuotListVO.h"
#include "../../domain/vo/pur-quot/PurQuotDividedListVO.h"
#include "../../domain/vo/pur-quot/PurQuotFindDetailBillVO.h"
#include "../../domain/vo/pur-quot/PurQuotDetailVO.h"
#include "../../domain/vo/pur-quot/PurQuotBaseVO.h"

//query
#include "../../domain/query/pur-quot/PurQuotFindBillQuery.h"
#include "../../domain/query/pur-quot/PurQuotListQuery.h"
#include "../../domain/query/pur-quot/PurQuotDividedListQuery.h"
#include "../../domain/query/pur-quot/PurQuotFindDetailBillQuery.h"

//dto

#include "../../domain/dto/pur-quot/AddPurQuotDTO.h"
#include "../../domain/dto/pur-quot/ModPurQuotDTO.h"
#include "../../domain/dto/pur-quot/DelPurQuotDTO.h"
#include "../../domain/dto/pur-quot/PurQuotModBillStatusDTO.h"
#include "../../domain/dto/pur-quot/PurQuotDetailDTO.h"
#include "../lib-http/include/JWTUtil.h"
//vo
#include "../../domain/vo/pur-quot/PurQuotFindBillVO.h"
#include "../../domain/vo/pur-quot/PurQuotListVO.h"
#include "../../domain/vo/pur-quot/PurQuotDividedListVO.h"
#include "../../domain/vo/pur-quot/PurQuotFindDetailBillVO.h"
#include "../../domain/vo/pur-quot/PurQuotDetailVO.h"
#include "../../domain/vo/pur-quot/PurQuotBaseVO.h"
#include "../../domain/vo/pur-quot/PurQuotExportVO.h"

//query
#include "../../domain/query/pur-quot/PurQuotFindBillQuery.h"
#include "../../domain/query/pur-quot/PurQuotListQuery.h"
#include "../../domain/query/pur-quot/PurQuotDividedListQuery.h"
#include "../../domain/query/pur-quot/PurQuotFindDetailBillQuery.h"
#include "../../domain/query/pur-quot/PurQuotExportQuery.h"

//dto
#include "../../domain/dto/pur-quot/PurQuotIntoDTO.h"
#include "../../domain/dto/pur-quot/AddPurQuotDTO.h"
#include "../../domain/dto/pur-quot/ModPurQuotDTO.h"
#include "../../domain/dto/pur-quot/DelPurQuotDTO.h"
#include "../../domain/dto/pur-quot/PurQuotModBillStatusDTO.h"
#include "../../domain/dto/pur-quot/PurQuotDetailDTO.h"
#include "../lib-http/include/JWTUtil.h"

/**
 * ʾ������ʵ�֣���ʾ������ʾ������ʵ��
 */
class PurQuotService
{
public:
	//��ȡ���PurQuotFindBillVO����
	PageVO<PurQuotFindBillVO> listPurQuotFindBillVO(const PurQuotFindBillQuery& query);

	//��ȡ���PurQuotList����
	list<PurQuotListVO> listPurQuotListVO(const PurQuotListQuery& query);

	//��ȡ���PurQuotDividedListVO����
	list<PurQuotDividedListVO> listPurQuotDividedListVO(const PurQuotDividedListQuery& query);

	PurQuotFindDetailBillVO getPurQuotFindDetailBillVO(const PurQuotFindDetailBillQuery& query);

	//����
	PurQuotExportVO listPurQuotExportVO(const PurQuotExportQuery& query);
	//����
	uint64_t updatePurQuotInto(const PurQuotIntoDTO& dto);

	// ��ҳ��ѯ��������
	//PageVO<SampleVO> listAll(const SampleQuery& query);
	// ��������
	uint64_t saveData(const AddPurQuotDTO& dto, const PayloadDTO& payload);
	// �޸�����
	bool updateData(const ModPurQuotDTO& dto, const PayloadDTO& payload);
	// ͨ��bill_noɾ������
	bool removeData(const DelPurQuotDTO& dto);
	// ͨ��bill_no�޸ı���״̬
	bool UpdateDataBillStatus(const PurQuotModBillStatusDTO& dto);
	// ͨ��IDɾ������
	//bool removeData(uint64_t id);				//sample����

};

#endif // !_SAMPLE_SERVICE_

