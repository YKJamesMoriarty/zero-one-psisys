#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: qingyu
 @Date: 2023/02/26 14:21:55

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

	  https://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
*/
#ifndef _PUR_INQUIRY_ENTRY_MAPPER_
#define _PUR_INQUIRY_ENTRY_MAPPER_

#include "Mapper.h"
#include "../../domain/do/PurInquiry/PurInquiryEntryDO.h"

/**
 * �ɹ�����entry���ֶ�ƥ��ӳ��
 */
class PurInquiryEntryMapper : public Mapper<PurInquiryEntryDO>
{
public:
	PurInquiryEntryDO mapper(ResultSet* resultSet) const override
	{
		PurInquiryEntryDO data;
		data.setId(resultSet->getString(1));
		data.setMid(resultSet->getString(2));
		data.setBill_no(resultSet->getString(3));
		data.setEntry_no(resultSet->getInt(4));
		data.setSrc_bill_type(resultSet->getString(5));
		data.setSrc_bill_id(resultSet->getString(6));
		data.setSrc_entry_id(resultSet->getString(7));
		data.setSrc_no(resultSet->getString(8));
		data.setMaterial_id(resultSet->getString(9));
		data.setUnit_id(resultSet->getString(10));
		data.setQty(resultSet->getDouble(11));
		data.setTax_rate(resultSet->getDouble(12));
		data.setPrice(resultSet->getDouble(13));
		data.setAmt(resultSet->getDouble(14));
		data.setRemark(resultSet->getString(15));
		data.setCustom1(resultSet->getString(16));
		data.setCustom2(resultSet->getString(17));
		data.setVersion(resultSet->getInt(18));
		return data;
	}
};

#endif //_PUR_COMPARE_ENTRY_MAPPER_