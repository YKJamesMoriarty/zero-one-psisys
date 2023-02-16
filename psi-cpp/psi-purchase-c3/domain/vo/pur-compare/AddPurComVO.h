#pragma once

#ifndef _ADD_PUR_COM_VO_
#define _ADD_PUR_COM_VO_
#include "../../GlobalInclude.h"
#include "stdafx.h"

class AddPurComVO
{
	// 单据编号
	CC_SYNTHESIZE(string, billId, BillId);
	// 单据日期
	CC_SYNTHESIZE(string, billDate, BillDate);
	// 已生效
	CC_SYNTHESIZE(string, isEffect, IsEffect);
	// 已关闭
	CC_SYNTHESIZE(string, isClose, Isclose);
	// 已作废
	CC_SYNTHESIZE(string, isCancelled, IsCancelled);
	// 生效时间
	CC_SYNTHESIZE(string, effectDate, EffectDate);
	// 核批人
	CC_SYNTHESIZE(string, approver, Approver);
	// 审批实例
	// 制单时间
	CC_SYNTHESIZE(string, makeBillDate, MakeBillDate);
	// 制单部门
	CC_SYNTHESIZE(string, makeBillDept, MakeBillDept);
	// 制单人
	CC_SYNTHESIZE(string, makeBillPerson, MakeBillPerson);
	// 修改时间
	CC_SYNTHESIZE(string, updateDate, UdpateDate);
	// 修改人
	CC_SYNTHESIZE(string, updatePerson, UdpatePerson);
	// 自动单据
	CC_SYNTHESIZE(string, autoBill, AutoBill);
	// 红字单据
	CC_SYNTHESIZE(string, redBill, RedBill);
	// 源单类型
	CC_SYNTHESIZE(string, billType, BillType);
	// 单据主题
	CC_SYNTHESIZE(string, billTheme, BillTheme);
	// 单据阶段
	CC_SYNTHESIZE(string, billStatus, BillStatus);
	// 采购询价单（单据编号）
	CC_SYNTHESIZE(string, inqueryBill, InqueryBill);
	// 付款方式
	CC_SYNTHESIZE(string, payMethod, PayMethod);
	// 交货日期
	CC_SYNTHESIZE(string, deliveryDate, DeliveryDate);
	// 交货地点
	CC_SYNTHESIZE(string, deliveryPlace, DeliveryPlace);
	// 备注
	CC_SYNTHESIZE(string, remark, Remark);

public:
	// 绑定JSON转换方法
	BIND_TO_JSON(AddPurComVO, billId, billDate, isEffect, isClose, isCancelled,
		effectDate, approver, makeBillDate, makeBillDept, makeBillPerson,
		updateDate, updatePerson, autoBill, redBill, billType, billTheme, billStatus,
		inqueryBill, payMethod, deliveryDate, deliveryPlace, remark);

};
#endif