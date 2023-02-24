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
#include<ctime>

//����vo����Ҫ�ָ�������


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

	//��ҳ��ѯ���� #���ܻ�ҪŪ������ҳ�ģ�����Ū�����б�
	pages.setTotal(count);
	pages.calcPages();
	list<MaterialClassificationDO> result = dao.selectWithPage(obj, query.getPageIndex(), query.getPageSize());
	list<MaterialClassificationBaseVO> vr;
	for (MaterialClassificationDO sub : result)
	{
		MaterialClassificationBaseVO vo;
		vo.setId(sub.getId());
		vo.setName(sub.getName());
		vo.setCode(sub.getCode());
		vo.setFullname(sub.getFullname());
		vo.setIsEnabled(sub.getIsEnabled());
		vo.setCreateTime(sub.getCreateTime());
		vo.setCreateBy(sub.getCreateBy());
		vo.setUpdateTime(sub.getUpdateTime());
		vo.setUpdateBy(sub.getUpdateBy());

		vr.push_back(vo);
	}
	pages.setRows(vr);
	return pages;
}

//��ѯ�����б�
list<MaterialClassificationChildVO> MaterialClassificationService::listChildren(const MaterialClassificationQuery& query) {
	MaterialClassificationDO obj;
	obj.setCode(query.getCode());//�������
	MaterialClassificationDAO dao;
	list<MaterialClassificationDO> father = dao.selectByCode(obj.getCode());//���ص���list
	MaterialClassificationDO f;
	for (MaterialClassificationDO sub : father) {
		f.setId(sub.getId());
	}
	list<MaterialClassificationDO> result = dao.selectByPid(f.getId());
	list<MaterialClassificationChildVO> vr;
	for (MaterialClassificationDO sub : result)
	{
		MaterialClassificationChildVO vo;
		vo.setId(sub.getId());
		vo.setName(sub.getName());
		vo.setCode(sub.getCode());
		vo.setFullname(sub.getFullname());
		vo.setIsEnabled(sub.getIsEnabled());
		vo.setCreateTime(sub.getCreateTime());
		vo.setCreateBy(sub.getCreateBy());
		vo.setUpdateTime(sub.getUpdateTime());
		vo.setUpdateBy(sub.getUpdateBy());

		vr.push_back(vo);

	}

	return vr;

}


list<MaterialClassificationDetailVO> MaterialClassificationService::listDetail(const MaterialClassificationQuery& query) {
	MaterialClassificationDO obj;
	obj.setCode(query.getCode());
	MaterialClassificationDAO dao;
	list<MaterialClassificationDO> result = dao.selectByCode(obj.getCode());
	list<MaterialClassificationDetailVO> vr;
	for (MaterialClassificationDO sub : result)
	{
		MaterialClassificationDetailVO vo;
		vo.setId(sub.getId());
		vo.setPid(sub.getPid());
		vo.setHasChild(sub.getHasChild());
		vo.setName(sub.getName());
		vo.setCode(sub.getCode());
		vo.setFullname(sub.getFullname());
		vo.setIsEnabled(sub.getIsEnabled());
		vo.setCreateTime(sub.getCreateTime());
		vo.setCreateBy(sub.getCreateBy());
		vo.setUpdateTime(sub.getUpdateTime());
		vo.setUpdateBy(sub.getUpdateBy());

		vr.push_back(vo);
	}

	return  vr;
}

int MaterialClassificationService::saveData(const MaterialClassificationDTO& dto, const PayloadDTO& payload)
{
	//��������Ӧ�ò��ù��޸���ص���Ϣ

	//��װ����
	MaterialClassificationDO data;
	//Ӧ��������������id
	SnowFlake sf(1, 2);
	data.setId(to_string(sf.nextId()));

	//����¼���ʱ��Ҫ���pid�����pid�ĸ���һ��ʼû���¼�����Ҫ�޸ĸ����has_child
	data.setPid(dto.getPid()==""? "0":dto.getPid());
	data.setHasChild(dto.getHasChild()==""? "0":dto.getHasChild());
	data.setName(dto.getName());
	data.setCode(dto.getCode());
	data.setFullname(dto.getFullname());
	data.setIsEnabled(dto.getIsEnabled());
	data.setCreateBy(payload.getUsername());

	//����ʱ��
	time_t nowtime;
	time(&nowtime); //��ȡ1900��1��1��0��0��0�뵽���ھ���������
	tm p;
	localtime_s(&p,&nowtime); //������ת��Ϊ����ʱ��,���1900����,��Ҫ+1900,��Ϊ0-11,����Ҫ+1
	//printf("%04d:%02d:%02d %02d:%02d:%02d\n", p.tm_year + 1900, p.tm_mon + 1, p.tm_mday,p.tm_hour,p.tm_min,p.tm_sec);
	string nowTime = to_string(p.tm_year+1900) + "-" +to_string(p.tm_mon+1)+"-"+to_string(p.tm_mday) + " " + to_string(p.tm_hour)+":"+to_string(p.tm_min) +":"+to_string(p.tm_sec);

	data.setCreateTime(nowTime);
	data.setVersion(dto.getVersion());
	//ִ���������
	MaterialClassificationDAO dao;

	int modify = 1;
	if (dto.getPid() != "") {//�и��ڵ�
		modify = dao.updateById(dto.getPid());//ͨ��id�޸ĸ��ڵ��has_child
	}

	return (modify * dao.insert(data))==1;
}

int MaterialClassificationService::updateData(const MaterialClassificationDTO& dto, const PayloadDTO& payload)
{

	//�޸�����Ҫ���õ�id,�޸�����Ӧ�ò��ùܴ�����ص���Ϣ

	//��װ��������
	MaterialClassificationDO data;
	data.setId(dto.getId());
	data.setPid(dto.getPid());
	data.setHasChild(dto.getHasChild());
	data.setName(dto.getName());
	data.setCode(dto.getCode());
	data.setFullname(dto.getFullname());
	data.setIsEnabled(dto.getIsEnabled());

	time_t nowtime;
	time(&nowtime); //��ȡ1900��1��1��0��0��0�뵽���ھ���������
	tm p;
	localtime_s(&p, &nowtime); //������ת��Ϊ����ʱ��,���1900����,��Ҫ+1900,��Ϊ0-11,����Ҫ+1
	string nowTime = to_string(p.tm_year + 1900) + "-" + to_string(p.tm_mon + 1) + "-" + to_string(p.tm_mday) + " " + to_string(p.tm_hour) + ":" + to_string(p.tm_min) + ":" + to_string(p.tm_sec);

	data.setUpdateBy(payload.getUsername());
	data.setUpdateTime(nowTime);
	data.setVersion(dto.getVersion());
	//ִ�������޸�
	MaterialClassificationDAO dao;
	return dao.update(data) == 1;
}

int MaterialClassificationService::removeData(const MaterialClassificationDTO& dto)
{
	MaterialClassificationDAO dao;

	int d = 1;
	if (dto.getHasChild()=="1") {//������Ӽ��ڵ���ɾ��
		d = dao.deleteByPid(dto.getId());
	}
	

	return (d*dao.deleteById(dto.getId())) == 1;
}
