﻿#pragma once
#ifndef _PUR_REQ_CONTROLLER_H_
#define _PUR_REQ_CONTROLLER_H_

#include"api/ApiHelper.h"

#include "../../domain/vo/PageVO.h"
#include "../../domain/vo/JsonVO.h"

//查询单据列表
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
 * 采购申请功能点
 */
class PurReqController
{
public:
	//导出
	CREATE_API_FUN_JSON_PAYLOAD(queryPurReqExport, execPurReqExport, PurReqExportDTO);
	//导入
	CREATE_API_FUN_BODY_PAYLOAD_FILE(modifyPurReqInto, execPurReqInto, PurReqIntoDTO);
	//查询单据列表
	CREATE_API_FUN_QUERY_PAYLOAD(queryPurReqFindBill, execQueryPurReqFindBill, PurReqFindBillQuery);
	//查询指定单据详细信息
	CREATE_API_FUN_QUERY_PAYLOAD(queryPurReqFindDetailBill, execQueryPurReqFindDetailBill, PurReqFindDetailBillQuery);
	//添加申请(保存/提交)
	CREATE_API_FUN_JSON_PAYLOAD(addPurReq, execAddPurReq, AddPurReqDTO);
	//修改申请(保存/提交/审核)
	CREATE_API_FUN_JSON_PAYLOAD(modifyPurReq, execModifyPurReq, ModifyPurReqDTO);
	//删除申请
	CREATE_API_FUN_BODY(removePurReqById, execRemovePurReqById, DeletePurReqDTO);
	//修改单据状态(关闭、作废、反关闭)
	CREATE_API_FUN_BODY_PAYLOAD(modifyPurReqBillStatus, execModifyPurReqBillStatus, PurReqModBillStatusDTO);
private:
	//查询单据列表
	JsonVO<PageVO<PurReqFindBillVO>> execQueryPurReqFindBill(const PurReqFindBillQuery& query, const PayloadDTO& payload);
	//查询指定单据详细信息
	JsonVO<PurReqFindDetailBillVO> execQueryPurReqFindDetailBill(const PurReqFindDetailBillQuery& query, const PayloadDTO& payload);
	//添加申请(保存/提交)
	JsonVO<uint64_t> execAddPurReq(const AddPurReqDTO& dto, const PayloadDTO& payload);
	//修改申请
	JsonVO<uint64_t> execModifyPurReq(const ModifyPurReqDTO& dto, const PayloadDTO& payload);
	//删除申请
	JsonVO<uint64_t> execRemovePurReqById(const DeletePurReqDTO& id);
	//修改单据状态(关闭、作废、反关闭)
	JsonVO<uint64_t> execModifyPurReqBillStatus(const PurReqModBillStatusDTO& dto, const PayloadDTO& payload);
	//导入
	JsonVO<uint64_t> execPurReqInto(const PurReqIntoDTO& dto, const PayloadDTO& payload);
	//导出
	JsonVO<string> execPurReqExport(const PurReqExportDTO& dto, const PayloadDTO &payload);
};
#endif 


