#include "stdafx.h"
#include "PurOrderService.h"
#include "../../dao/PurOrder/PurOrderDAO.h"
#include <list>


list<PurOrderDividedListVO> PurOrderService::listPurOrderDividedListDO(const PurOrderDividedListQuery& query) {
	//���ò�ѯ����
	PurOrderDividedListDO obj;
	obj.setBillNo(query.getBillNo());
	//���ղ�ѯ����DO
	PurOrderDAO dao;
	list<PurOrderDividedListDO> result = dao.selectPurOrderDividedListDO(obj);
	
	//�������ض���vo
	list<PurOrderDividedListVO> vr;
	if (!result.empty()) {
		for (PurOrderDividedListDO sub : result) {
			PurOrderDividedListVO vo;
			vo.setBillNo(sub.getBillNo());
			vo.setEntryNo(sub.getEntryNo());
			vo.setMaterialId(sub.getMaterialId());
			vo.setUnitId(sub.getUnitId());
			vo.setQty(sub.getQty());
			vo.setOrderedQty(sub.getOrderedQty());
			vo.setTaxRate(sub.getTaxRate());
			vo.setPrice(sub.getPrice());
			vo.setAmt(sub.getAmt());
			vo.setSuggestSupplierId(sub.getSuggestSupplierId());
			vo.setRemark(sub.getRemark());
			vo.setCustom1(sub.getCustom1());
			vo.setCustom2(sub.getCustom2());
			vr.push_back(vo);
		}
	}
	return vr;
}
