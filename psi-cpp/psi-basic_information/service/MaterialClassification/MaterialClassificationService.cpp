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
#include "MaterialClassificationService.h"
#include "../../dao/MaterialClassification/MaterialClassificationDAO.h"


//����vo����Ҫ�ָ�������...


PageVO<MaterialClassificationBaseVO> MaterialClassificationService::listAll(const MaterialClassificationQuery& query)
{
	//�������ض���
	PageVO<MaterialClassificationBaseVO> pages;
	pages.setPageIndex(query.getPageIndex());
	pages.setPageSize(query.getPageSize());

	//��ѯ����������
	MaterialClassificationDO obj;
	obj.setName(query.getName());
	obj.setCode(query.getCode());
	MaterialClassificationDAO dao;
	uint64_t count = dao.count(obj);
	if (count <= 0)
	{
		return pages;
	}

	//��ҳ��ѯ���� #Ӧ�û�ҪŪ������ҳ��
	pages.setTotal(count);
	pages.calcPages();
	list<MaterialClassificationDO> result = dao.selectWithPage(obj, query.getPageIndex(), query.getPageSize());
	list<MaterialClassificationBaseVO> vr;
	for (MaterialClassificationDO sub : result)
	{
		MaterialClassificationBaseVO vo;
		vo.setName(sub.getName());
		vo.setCode(sub.getCode());
		vo.setFullname(sub.getFullname());
		vo.setIsEnabled(sub.getIsEnabled());
		vo.setCreateBy(sub.getCreateBy());
		vo.setCreateTime(sub.getCreateTime());
		vo.setUpdateBy(sub.getUpdateBy());
		vo.setUpdateTime(sub.getUpdateTime());

		vr.push_back(vo);
	}
	pages.setRows(vr);
	return pages;
}

uint64_t MaterialClassificationService::saveData(const MaterialClassificationDTO& dto)
{
	//��װ����
	MaterialClassificationDO data;
	data.setPid(dto.getPid());
	data.setName(dto.getName());
	data.setCode(dto.getCode());
	data.setFullname(dto.getFullname());
	data.setIsEnabled(dto.getIsEnabled());
	data.setCreateBy(dto.getCreateBy());
	data.setCreateTime(dto.getCreateTime());
	data.setUpdateBy(dto.getUpdateBy());
	data.setUpdateTime(dto.getUpdateTime());
	
	//ִ���������
	MaterialClassificationDAO dao;
	return dao.insert(data);
}

bool MaterialClassificationService::updateData(const MaterialClassificationDTO& dto)
{
	//��װ��������
	MaterialClassificationDO data;
	data.setPid(dto.getPid());
	data.setName(dto.getName());
	data.setCode(dto.getCode());
	data.setFullname(dto.getFullname());
	data.setIsEnabled(dto.getIsEnabled());
	data.setCreateBy(dto.getCreateBy());
	data.setCreateTime(dto.getCreateTime());
	data.setUpdateBy(dto.getUpdateBy());
	data.setUpdateTime(dto.getUpdateTime());
	//ִ�������޸�
	MaterialClassificationDAO dao;
	return dao.update(data) == 1;
}

bool MaterialClassificationService::removeData(string id)
{
	MaterialClassificationDAO dao;
	return dao.deleteById(id) == 1;
}
