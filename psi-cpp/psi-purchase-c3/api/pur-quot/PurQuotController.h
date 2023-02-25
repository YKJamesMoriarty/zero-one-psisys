
//����ͷ�ļ�
#pragma once
#ifndef _PUR_QUOT_CONTROLLER_H_
#define _PUR_QUOT_CONTROLLER_H_
#include "domain/dto/IDDTO.h"
#include "../../domain/vo/JsonVO.h"
#include "../../domain/vo/PageVO.h"

//query
#include "../../domain/query/pur-quot/PurQuotExportQuery.h"
#include "../../domain/query/pur-quot/PurQuotFindBillQuery.h"
#include "../../domain/query/pur-quot/PurQuotFindDetailBillQuery.h"
#include "../../domain/query/pur-quot/PurQuotDividedListQuery.h"
#include "../../domain/query/pur-quot/PurQuotListQuery.h"


//dto
#include "../../domain/dto/pur-quot/PurQuotIntoDTO.h"
#include "../../domain/dto/pur-quot/AddPurQuotDTO.h"
#include "../../domain/dto/pur-quot/DelPurQuotDTO.h"
#include "../../domain/dto/pur-quot/ModPurQuotDTO.h"
#include "../../domain/dto/pur-quot/PurQuotModBillStatusDTO.h"
//vo

#include "../../domain/vo/pur-quot/PurQuotIntoVO.h"
#include "../../domain/vo/pur-quot/PurQuotExportVO.h"
#include "../../domain/vo/pur-quot/PurQuotDividedListVO.h"
#include "../../domain/vo/pur-quot/PurQuotFindBillVO.h"
#include "../../domain/vo/pur-quot/PurQuotFindDetailBillVO.h"
#include "../../domain/vo/pur-quot/PurQuotListVO.h"

#include "cinatra.hpp"
#include "JWTUtil.h"
using namespace cinatra;
using namespace nlohmann;
using namespace std;

class PurQuotController
{
public:
	// ��ӱ���
	// CREATE_API_FUN_BODY_PAYLOAD_FILE(addPurQuot, execAddPurQuot, AddPurQuotDTO);
	// ��body����˳������APIPost����body��ʽ�������ݣ����ǵ���Ϊjson-raw��ʽ����������raw�з��ͣ�ȴ�޷�����
	// ��ˣ�Ԥ�Ƹ�ΪJSON_PAYLOAD_FILE�����Կ���������������豻��֤�ǶԵģ���������ModҲ���Դ�BODY��ΪJSON��
	CREATE_API_FUN_JSON_PAYLOAD(addPurQuot, execAddPurQuot, AddPurQuotDTO);
	//�޸ı���
	CREATE_API_FUN_JSON_PAYLOAD(modPurQuot, execModPurQuot, ModPurQuotDTO);
	//ɾ������
	CREATE_API_FUN_BODY(delPurQuotById, execDelPurQuot, DelPurQuotDTO);
	//�޸ı���״̬���رա����ϡ����رգ�
	CREATE_API_FUN_BODY_PAYLOAD(purQuotModBillStatus, execPurQuotModBillStatus, PurQuotModBillStatusDTO);

	//����
	CREATE_API_FUN_BODY_PAYLOAD(queryPurQuotExport, execPurQuotExport, PurQuotExportQuery);
	//����
	CREATE_API_FUN_BODY_FILE(modifyPurQuotInto, execPurQuotInto, PurQuotIntoDTO);
	//ѯ�۵��б�
	CREATE_API_FUN_QUERY_PAYLOAD(queryPurQuotList, execQueryPurQuotList, PurQuotListQuery);
	//ѯ�۵���¼�б�
	CREATE_API_FUN_QUERY_PAYLOAD(queryPurQuotDividedList, execQueryPurQuotDividedList, PurQuotDividedListQuery);
	//��ѯ�����б�
	CREATE_API_FUN_QUERY_PAYLOAD(queryPurInquiryFindBill, execQueryPurQuotFindBill, PurQuotFindBillQuery);
	//��ѯָ��������ϸ��Ϣ
	CREATE_API_FUN_QUERY_PAYLOAD(queryPurInquiryFindDetailBill, execQueryPurQuotFindDetailBill, PurQuotFindDetailBillQuery);
private:

	//��������
	JsonVO<uint64_t> execAddPurQuot(const AddPurQuotDTO& dto, const PayloadDTO& payload);
	//�޸ı���
	JsonVO<uint64_t> execModPurQuot(const ModPurQuotDTO& dto, const PayloadDTO& payload);
	//ɾ������
	JsonVO<uint64_t> execDelPurQuot(const DelPurQuotDTO& dto);
	//�޸ı���״̬���رա����ϡ����رգ�
	JsonVO<uint64_t> execPurQuotModBillStatus(const PurQuotModBillStatusDTO& dto, const PayloadDTO& payload);

	//��ѯ�����б�
	JsonVO<PageVO<PurQuotFindBillVO>> execQueryPurQuotFindBill(const PurQuotFindBillQuery& query, const PayloadDTO& payload);
	//��ѯָ�������б�
	JsonVO<PurQuotFindDetailBillVO> execQueryPurQuotFindDetailBill(const PurQuotFindDetailBillQuery& query, const PayloadDTO& payload);
	// ��ѯѯ�۵��б�
	JsonVO<list<PurQuotListVO>> execQueryPurQuotList(const PurQuotListQuery& query, const PayloadDTO& payload);
	// ��ѯѯ�۵���¼�б�
	JsonVO<list<PurQuotDividedListVO>> execQueryPurQuotDividedList(const PurQuotDividedListQuery& query, const PayloadDTO& payload);
	//����
	JsonVO<PurQuotExportVO> execPurQuotExport(const PurQuotExportQuery& dto, const PayloadDTO& payload);
	//����
	JsonVO<PurQuotIntoVO> execPurQuotInto(const PurQuotIntoDTO& dto);

};


#endif // _PUI_QUOT_CONTROLLER_




