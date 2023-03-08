#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: Andrew
 @Date: 2023/02/15 22:00:00

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
#ifndef __MATERIAL_VO__
#define __MATERIAL_VO__

#include "../../GlobalInclude.h"

class MaterialVO
{
	CC_SYNTHESIZE(uint64_t, id, Id); // ID
	CC_SYNTHESIZE(uint64_t, material, Material); // ����ID
	CC_SYNTHESIZE(std::string, materialCode, MaterialCode); // ���ϱ���
	CC_SYNTHESIZE(std::string, materialName, MaterialName); // ������
	CC_SYNTHESIZE(std::string, materialModel, MaterialModel); // ����ͺ�
	CC_SYNTHESIZE(uint16_t, year, Year); // ���
	CC_SYNTHESIZE(uint16_t, month, Month); // �·�
	CC_SYNTHESIZE(std::string, unit, Unit); // ��λ
	CC_SYNTHESIZE(uint16_t, quantity, Quantity); // �ɹ�����
	CC_SYNTHESIZE(double, price, Price); // �ɹ����
	CC_SYNTHESIZE(uint16_t, outQty, OUtQty); // ��������
	CC_SYNTHESIZE(double, outcost, Outcost); // ������
	CC_SYNTHESIZE(uint16_t, settleQty, SettleQty); // ��������
	CC_SYNTHESIZE(double, settlePrice, SettlePrice); // ������
private:
	friend void to_json(json& j, const MaterialVO& mv)
	{
		j = json{
			{"id", mv.id},
			{"material", mv.material},
			{"materialCode", mv.materialCode},
			{"materialName", mv.materialName},
			{"materialModel", mv.materialModel},
			{"year", mv.year},
			{"month", mv.month},
			{"unit", mv.unit},
			{"quantity", mv.quantity},
			{"price", mv.price},
			{"outQty", mv.outQty},
			{"outCost", mv.outcost},
			{"settleQty", mv.settleQty},
			{"settlePrice", mv.settlePrice}
		};
	}
};

#endif // !__MATERIAL_VO__
