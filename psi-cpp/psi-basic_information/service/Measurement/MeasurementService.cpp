/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 11:13:11

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
#include "stdafx.h"
#include "../../domain/do/Measurement/MeasurementDO.h"
#include "MeasurementService.h"
#include "../../dao/Measurement/MeasurementDao.h"

PageVO<MeasurementVO> MeasurementService::listAll(const MeasurementQuery& query)
{
	//�������ض���
	PageVO<MeasurementVO> pages;
	pages.setPageIndex(query.getPageIndex());
	pages.setPageSize(query.getPageSize());

	//��ѯ����������
	MeasurementDO obj;
	obj.setName(query.getName());
	//obj.setSex(query.getSex());
	MeasurementDAO dao;
	uint64_t count = dao.count(obj);
	if (count <= 0)
	{
		return pages;
	}

	//��ҳ��ѯ����
	pages.setTotal(count);
	pages.calcPages();
	list<MeasurementDO> result = dao.selectWithPage(obj, query.getPageIndex(), query.getPageSize());
	list<MeasurementVO> vr;
	for (MeasurementDO sub : result)
	{
		MeasurementVO vo;
		vo.setId(sub.getId());
		vo.setName(sub.getName());
		vo.setSex(sub.getSex());
		vo.setAge(sub.getAge());
		vr.push_back(vo);
	}
	pages.setRows(vr);
	return pages;
}

uint64_t MeasurementService::saveData(const MeasurementDTO& dto)
{
	//��װ����
	MeasurementDO data;
	data.setName(dto.getName());
	data.setSex(dto.getSex());
	data.setAge(dto.getAge());
	//ִ���������
	MeasurementDAO dao;
	return dao.insert(data);
}

bool MeasurementService::updateData(const MeasurementDTO& dto)
{
	//��װ��������
	MeasurementDO data;
	data.setId(dto.getId());
	data.setAge(dto.getAge());
	data.setName(dto.getName());
	data.setSex(dto.getSex());
	//ִ�������޸�
	MeasurementDAO dao;
	return dao.update(data) == 1;
}

/*
bool MeasurementService::removeData(uint64_t id)
{
	MeasurementDAO dao;
	return dao.deleteById(id) == 1;
}
*/
