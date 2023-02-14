#pragma once

#ifndef _PUR_COMPARE_CONTROLLER_
#define _PUR_COMPARE_CONTROLLER_

#include "../../domain/query/pur-compare/PurComFindBillQuery.h"
#include "../../domain/dto/IDDTO.h"
#include "../../domain/vo/pur-compare/PurComFindBillVO.h"
#include "../../domain/vo/pur-compare/PurComFindDetailBillVO.h"
#include "../../domain/vo/pur-compare/PurComListVO.h"
#include "../../domain/vo/pur-compare/PurComDividedListVO.h"
#include "../../domain/vo/PageVO.h"
#include "../../domain/vo/JsonVO.h"
//#include "../../domain/dto/sample/SampleDTO.h"
//#include "../../domain/dto/user/UserDTO.h"
//#include "../../domain/vo/user/UserVO.h"

/**
 * �ȼ۵�������
 */
class PurCompareController
{
public:
	CREATE_API_FUN_QUERY_PAYLOAD(queryPurComFindBill, execQueryPurComFindBill, PurComFindBillQuery);
	CREATE_API_FUN_QUERY_PAYLOAD(queryPurComFindDetailBill, execQueryPurComFindDetailBill, string);
	CREATE_API_FUN_QUERY_PAYLOAD(queryPurComList, execQueryPurComList, string);
	CREATE_API_FUN_QUERY_PAYLOAD(queryPurComDividedList, execQueryPurComDividedList, string);
private:
	// ��ѯ�ȼ۵������б�
	JsonVO<PageVO<PurComFindBillVO>> execQueryPurComFindBill(const PurComFindBillQuery& query, const PayloadDTO& payload);
	// ��ѯָ���ȼ۵�������ϸ��Ϣ
	JsonVO<PurComFindDetailBillVO> execQueryPurComFindDetailBill(const string& query, const PayloadDTO& payload);
	// ��ѯ���۵��б�
	JsonVO<PageVO<PurComListVO>> execQueryPurComList(const string& query, const PayloadDTO& payload);
	// ��ѯ���۵���¼�б�
	JsonVO<PageVO<PurComDividedListVO>> execQueryPurComDividedList(const string& query, const PayloadDTO& payload);
};

#endif // _SAMPLE_CONTROLLER_#pragma once
