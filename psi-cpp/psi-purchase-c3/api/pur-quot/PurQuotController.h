#include "stdafx.h"
#include "domain/dto/IDDTO.h"
#include "../../domain/vo/JsonVO.h"
#include "../../domain/vo/PageVO.h"
#include "../../domain/dto/pur-quot/AddPurQuotDTO.h"
#include "../../domain/dto/pur-quot/DelPurQuotDTO.h"
#include "../../domain/dto/pur-quot/ModPurQuotDTO.h"
#include "../../domain/dto/pur-quot/PurQuotModBillStatusDTO.h"
#include "../../domain/vo/pur-quot/AddPurQuotVO.h"
#include "../../domain/vo/pur-quot/DelPurQuotVO.h"
#include "../../domain/vo/pur-quot/ModPurQuotVO.h"
#include "../../domain/vo/pur-quot/PurQuotModBillStatusVO.h"

#ifndef _PUR_QUOT_CONTROLLER_
#define _PUR_QUOT_CONTROLLER_



class PurQuotController
{
public:
	//��ӱ���
	//CREATE_API_FUN_BODY_PAYLOAD(addPurQuot, execAddPurQuot, PurQuotDTO);
	CREATE_API_FUN_BODY(addPurQuot, execAddPurQuot, AddPurQuotDTO);
	//�޸ı���
	//CREATE_API_FUN_BODY_PAYLOAD(modPurQuot, execModPurQuot, PurQuotDTO);
	CREATE_API_FUN_BODY(modPurQuot, execModPurQuot, ModPurQuotDTO);
	//ɾ������
	CREATE_API_FUN_BODY(delPurQuot, execDelPurQuot, DelPurQuotDTO);
	//�޸ı���״̬���رա����ϡ����رգ�
	CREATE_API_FUN_BODY(purQuotModBillStatus, execPurQuotModBillStatus, PurQuotModBillStatusDTO);


private:
	//��ʾ��������
	JsonVO<uint64_t> execAddPurQuot(const AddPurQuotDTO& dto);
	//��ʾ�޸ı���
	JsonVO<uint64_t> execModPurQuot(const ModPurQuotDTO& dto);
	//��ʾɾ������
	JsonVO<uint64_t> execDelPurQuot(const DelPurQuotDTO& dto);
	//�޸ı���״̬���رա����ϡ����رգ�
	JsonVO<uint64_t> execPurQuotModBillStatus(const PurQuotModBillStatusDTO& dto);
};

#endif // _PUI_QUOT_CONTROLLER_