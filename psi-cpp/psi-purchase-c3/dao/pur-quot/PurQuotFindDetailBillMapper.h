#pragma once
#ifndef _PUR_QUOT_FIND_DETAIL_BILL_MAPPER_H_
#define _PUR_QUOT_FIND_DETAIL_BILL_MAPPER_H_

#include "Mapper.h"
#include "../../domain/do/pur-quot/PurQuotDO.h"
#include "../../domain/do/pur-quot/PurQuotEntryDO.h"

/**
 * ʾ�����ֶ�ƥ��ӳ��
 */
class PurQuotFindDetailBillMapper : public Mapper<PurQuotDO>
{
public:
	PurQuotDO mapper(ResultSet* resultSet) const override
	{
		PurQuotDO data;
		data.setBill_no(resultSet->getString(1));
		data.setBill_date(resultSet->getString(2));
		data.setBill_stage(resultSet->getString(3));
		data.setIs_effective(resultSet->getInt(4));
		data.setIs_closed(resultSet->getInt(5));
		data.setIs_voided(resultSet->getInt(6));
		data.setSubject(resultSet->getString(7));
		data.setIs_temp_supplier(resultSet->getInt(8));
		data.setSupplier_id(resultSet->getString(9));
		data.setPayment_method(resultSet->getString(10));
		data.setDelivery_time(resultSet->getString(11));
		data.setDelivery_place(resultSet->getString(12));
		data.setContact(resultSet->getString(13));
		data.setPhone(resultSet->getString(14));
		data.setFax(resultSet->getString(15));
		data.setEmail(resultSet->getString(16));
		data.setRemark(resultSet->getString(17));
		data.setApproval_remark(resultSet->getString(18));
		data.setAttachment(resultSet->getString(19));
		data.setApproval_result_type(resultSet->getString(20));
//��ϸ�ֶ�
		//data.setEntry_src_no(resultSet->getString(21));
		//data.setEntry_material_id(resultSet->getString(22));
		//data.setEntry_unit_id(resultSet->getString(23));
		//data.setEntry_qty(resultSet->getString(24));
		//data.setEntry_tax_rate(resultSet->getString(25));
		//data.setEntry_price(resultSet->getString(26));
		//data.setEntry_discount_rate(resultSet->getString(27));
		//data.setEntry_amt(resultSet->getString(28));
		//data.setEntry_remark(resultSet->getString(29));
		//data.setEntry_custom1(resultSet->getString(30));
		//data.setEntry_custom2(resultSet->getString(31));
		return data;
	}
};

#endif
