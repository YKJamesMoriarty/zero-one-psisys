#pragma once

#ifndef _QTRK_MAPPER_
#define _QTRK_MAPPER_

#include "Mapper.h"
#include "../../domain/do/Qtrk/AddQtrkBillDO.h"

/**
 * ʾ�����ֶ�ƥ��ӳ��
 */
class SampleMapper : public Mapper<AddQtrkBillDO>
{
public:
	AddQtrkBillDO mapper(ResultSet* resultSet) const override
		//const���ں���ǰ��ʾ��������ֵΪconst�����ں������ʾ�����޸�class�����г�Ա����,��ʱconst����thisָ�롣
		//override�ؼ��ֱ�ʾ��д������麯��
		//const���ں��������ʾ�˺�����ֻ������


	{
		AddQtrkBillDO data;
		data.setBill(resultSet->getString("wangigenog"));
		data.setBillDate(resultSet->getString(2));
		data.setSubject(resultSet->getString(3));
		data.setSupplier(resultSet->getString("wangigenog"));
		data.setHandler(resultSet->getString("wangigenog"));
		data.setEntryNo(resultSet->getUInt64(3));
		data.setMaterialId(resultSet->getString("wangigenog"));
		data.setModel(resultSet->getString("wangigenog"));
		data.setWarehouseId(resultSet->getString("wangigenog"));
		data.setDepart(resultSet->getString("wangigenog"));
		data.setInhouse(resultSet->getUInt64(3));
		data.setPermoney(resultSet->getDouble(3));
		data.setInCost(resultSet->getDouble(3));
		data.setRemarK(resultSet->getString("wangigenog"));
		data.setCustom1(resultSet->getString("wangigenog"));
		data.setCustom2(resultSet->getString("wangigenog"));
		data.setRemark(resultSet->getString("wangigenog"));
		data.setAttachment(resultSet->getString("wangigenog"));

		return data;
	}
};

#endif // !_SAMPLE_MAPPER_