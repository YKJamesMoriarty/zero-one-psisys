#include "stdafx.h"
#include "PurCompareDTO.h"

// �����ȼ�
void from_json(const json& j, AddPurComDTO& t) { 
	BIND_FROM_TO_NORMAL(j, t, billId);
	BIND_FROM_TO_NORMAL(j, t, billDate);
	BIND_FROM_TO_I(j, t, isEffect);
	BIND_FROM_TO_I(j, t, isClose);
	BIND_FROM_TO_I(j, t, isCancelled);
	BIND_FROM_TO_NORMAL(j, t, effectDate);
	BIND_FROM_TO_NORMAL(j, t, approver);
	BIND_FROM_TO_NORMAL(j, t, makeBillDate);
	BIND_FROM_TO_NORMAL(j, t, makeBillDept);
	BIND_FROM_TO_NORMAL(j, t, makeBillPerson);
	BIND_FROM_TO_NORMAL(j, t, updateDate);
	BIND_FROM_TO_NORMAL(j, t, updatePerson);
	BIND_FROM_TO_I(j, t, autoBill);
	BIND_FROM_TO_I(j, t, redBill);
	BIND_FROM_TO_NORMAL(j, t, billTheme);
	BIND_FROM_TO_NORMAL(j, t, billStatus);
	BIND_FROM_TO_NORMAL(j, t, inquiryBill);
	BIND_FROM_TO_NORMAL(j, t, payMethod);
	BIND_FROM_TO_NORMAL(j, t, deliveryDate);
	BIND_FROM_TO_NORMAL(j, t, deliveryPlace);
	BIND_FROM_TO_NORMAL(j, t, remark);
}

// �޸ıȼ�
void from_json(const json& j, ModPurComDTO& t) {
	BIND_FROM_TO_NORMAL(j, t, billId);
	BIND_FROM_TO_NORMAL(j, t, billDate);
	BIND_FROM_TO_I(j, t, isEffect);
	BIND_FROM_TO_I(j, t, isClose);
	BIND_FROM_TO_I(j, t, isCancelled);
	BIND_FROM_TO_NORMAL(j, t, effectDate);
	BIND_FROM_TO_NORMAL(j, t, approver);
	BIND_FROM_TO_NORMAL(j, t, makeBillDate);
	BIND_FROM_TO_NORMAL(j, t, makeBillDept);
	BIND_FROM_TO_NORMAL(j, t, makeBillPerson);
	BIND_FROM_TO_NORMAL(j, t, updateDate);
	BIND_FROM_TO_NORMAL(j, t, updatePerson);
	BIND_FROM_TO_I(j, t, autoBill);
	BIND_FROM_TO_I(j, t, redBill);
	BIND_FROM_TO_NORMAL(j, t, billTheme);
	BIND_FROM_TO_NORMAL(j, t, billStatus);
	BIND_FROM_TO_NORMAL(j, t, inquiryBill);
	BIND_FROM_TO_NORMAL(j, t, payMethod);
	BIND_FROM_TO_NORMAL(j, t, deliveryDate);
	BIND_FROM_TO_NORMAL(j, t, deliveryPlace);
	BIND_FROM_TO_NORMAL(j, t, remark);
}

// ɾ���ȼ�
void from_json(const json& j, DelPurComDTO& t) {
	BIND_FROM_TO_NORMAL(j, t, billId);
}

// �޸ĵ���״̬
void from_json(const json& j, PurComModBillStatusDTO& t) {
	BIND_FROM_TO_NORMAL(j, t, billId);
	BIND_FROM_TO_I(j, t, isEffect);
	BIND_FROM_TO_I(j, t, isClose);
	BIND_FROM_TO_I(j, t, isCancelled);
}