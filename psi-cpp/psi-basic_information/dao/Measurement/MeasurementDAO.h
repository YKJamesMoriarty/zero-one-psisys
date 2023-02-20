#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 14:23:49

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
#ifndef _Measurement_DAO_
#define _Measurement_DAO_
#include "BaseDAO.h"
#include "../../domain/do/Measurement/MeasurementDO.h"

/**
 * ���ݿ����ʵ��
 */
class MeasurementDAO : public BaseDAO
{
public:
	// ͳ����������
	uint64_t count(const MeasurementDO& iObj);
	// ��ҳ��ѯ����
	list<MeasurementDO> selectWithPage(const MeasurementDO& obj, uint64_t pageIndex, uint64_t pageSize);
	// ͨ��������ѯ����
	list<MeasurementDO> selectByName(const string& name);
	// ��������
	uint64_t insert(const MeasurementDO& iObj);
	// �޸�����
	int update(const MeasurementDO& uObj);
	// ͨ��IDɾ������
	int deleteById(uint64_t id);
};
#endif // !_Measurement_DAO_
