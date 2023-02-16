//����ͷ�ļ�
#include "stdafx.h"
#include "domain/dto/IDDTO.h"
#include "../../domain/vo/JsonVO.h"
#include "../../domain/vo/PageVO.h"

//query
#include "../../domain/query/pur-quot/PurQuotExportQuery.h"
//dto
#include "../../domain/dto/pur-quot/PurQuotIntoDTO.h"
#include "../../domain/dto/pur-quot/AddPurQuotDTO.h"
#include "../../domain/dto/pur-quot/DelPurQuotDTO.h"
#include "../../domain/dto/pur-quot/ModPurQuotDTO.h"
#include "../../domain/dto/pur-quot/PurQuotModBillStatusDTO.h"
//vo

#include "../../domain/vo/pur-quot/PurQuotExportVO.h"


#ifndef _PUR_QUOT_CONTROLLER_
#define _PUR_QUOT_CONTROLLER_



class PurQuotController
{
public:
	//��ӱ���
	//����ӱ����У����滹��һ����ѯ�ɹ�ѯ�۵���ѡ����ڲ�ѯ�ɹ�ѯ�۵�
	//��ϸ���ܻ���Ҫ����Ĵ���������һ�����ݣ����Ǻܶ���
	//CREATE_API_FUN_BODY_PAYLOAD(addPurQuot, execAddPurQuot, PurQuotDTO);
	CREATE_API_FUN_BODY(addPurQuot, execAddPurQuot, AddPurQuotDTO);
	//�޸ı���
	//CREATE_API_FUN_BODY_PAYLOAD(modPurQuot, execModPurQuot, PurQuotDTO);
	CREATE_API_FUN_BODY(modPurQuot, execModPurQuot, ModPurQuotDTO);
	//ɾ������
	CREATE_API_FUN_BODY(delPurQuot, execDelPurQuot, DelPurQuotDTO);
	//�޸ı���״̬���رա����ϡ����رգ�
	CREATE_API_FUN_BODY(purQuotModBillStatus, execPurQuotModBillStatus, PurQuotModBillStatusDTO);
	//����
	CREATE_API_FUN_BODY_PAYLOAD(queryPurQuotExport, execPurQuotExport, PurQuotExportQuery);
	//����
	CREATE_API_FUN_BODY_FILE(modifyPurQuotInto, execPurQuotInto, PurQuotIntoDTO);

private:
	//��������
	JsonVO<uint64_t> execAddPurQuot(const AddPurQuotDTO& dto);
	//�޸ı���
	JsonVO<uint64_t> execModPurQuot(const ModPurQuotDTO& dto);
	//ɾ������
	JsonVO<uint64_t> execDelPurQuot(const DelPurQuotDTO& dto);
	//�޸ı���״̬���رա����ϡ����رգ�
	JsonVO<uint64_t> execPurQuotModBillStatus(const PurQuotModBillStatusDTO& dto);
	//����
	nlohmann::json execPurQuotExport(const PurQuotExportQuery& dto, const PayloadDTO& payload);
	//����
	JsonVO<uint64_t> execPurQuotInto(const PurQuotIntoDTO& dto);


};

#endif // _PUI_QUOT_CONTROLLER_