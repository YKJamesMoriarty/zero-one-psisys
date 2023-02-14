#pragma once
#ifndef _PUR_COMPARE_CONTROLLER_H
#define _PUR_COMPARE_CONTROLLER_H

#include "../../domain/dto/pur-compare/PurCompareDTO.h"
#include "../../domain/dto/IDDTO.h"
#include "../../domain/vo/pur-compare/PurCompareVO.h"
#include "../../domain/vo/PageVO.h"
#include "../../domain/vo/JsonVO.h"


/**
 * ʾ������������ʾ�����ӿڵ�ʹ��
 */
class PurComRenqingController
{
public:
	// �����ȼ�
	CREATE_API_FUN_BODY(addPurCom, execAddPurCom, AddPurComDTO);
	// �޸ıȼ�
	CREATE_API_FUN_BODY(modifyPurCom, execModifyPurCom, ModPurComDTO);
	// ɾ���ȼ�
	CREATE_API_FUN_BODY(removePurCom, execRemovePurCom, DelPurComDTO);
	// �޸ĵ���״̬
	CREATE_API_FUN_JSON(purComModBillStatus, execPurComModBillStatus, PurComModBillStatusDTO);
private:
	//��ʾ�����ȼ�
	JsonVO<uint64_t> execAddPurCom(const AddPurComDTO& dto);
	//��ʾ�޸ıȼ�
	JsonVO<uint64_t> execModifyPurCom(const ModPurComDTO& dto);
	//��ʾɾ���ȼ�
	JsonVO<uint64_t> execRemovePurCom(const DelPurComDTO& dto);
	//��ʾ�޸ĵ���״̬
	JsonVO<uint64_t> execPurComModBillStatus(const PurComModBillStatusDTO& dto);
	
};

#endif // _PUR_COMPARE_CONTROLLER_H