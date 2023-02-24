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
#include "DepotService.h"
#include "../../../lib-common/include/SnowFlake.h"

const int datacenterId = 1;
const int machineId = 2;

PageVO<DepotVO> DepotService::listAll(const DepotQuery& query)
{
	//�������ض���
	PageVO<DepotVO> pages;
	pages.setPageIndex(query.getPageIndex());
	pages.setPageSize(query.getPageSize());

	//��ѯ����������
	DepotDO obj;
	obj.setName(query.getName());
	obj.setCode(query.getCode());
	
	DepotDAO dao;
	uint64_t count = dao.count(obj);
	if (count <= 0)
	{
		return pages;
	}

	//��ҳ��ѯ����
	obj.setPid("0");
	pages.setTotal(dao.count(obj));
	pages.calcPages();
	//��Ϊ�û�δ�����κ���Ϣ����������һ����Ϣ�Ĳ���
	if (obj.getName() == "" && obj.getCode() == "")
	{
		obj.setPid("0");
		//DO���ս����
		list<DepotDO> result = dao.selectWithPage(obj, query.getPageIndex(), query.getPageSize());
		list<DepotVO> vr;
		for (DepotDO sub : result)
		{
			DepotVO vo;
			vo.setName(sub.getName());
			vo.setCode(sub.getCode());
			vo.setAuxName(sub.getAuxName());
			vo.setCreationPeo(sub.getCreationPeo());
			vo.setCreationTime(sub.getCreationTime());
			vo.setId(sub.getId());
			vo.setModiPeo(sub.getModiPeo());
			vo.setModiTime(sub.getModiTime());
			vo.setRemarks(sub.getRemarks());
			vo.setStart(sub.getStart());
			vo.setPhone(sub.getPhone());
			vr.push_back(vo);
		}
		pages.setRows(vr);
	}
	else
	{
		//DO���ս����
		obj.setPid("");
		list<DepotDO> result = dao.selectWithPage(obj, query.getPageIndex(), query.getPageSize());
		//VO���ؽ����
		list<DepotVO> vr;
		//������ӽڵ㣬�ҵ����ĸ��ڵ�
		DepotDO sub = result.front();
		while (sub.getPid() != "0")
		{
			obj.setId(sub.getPid());
			obj.setPid("");
			obj.setCode("");
			obj.setName("");
			result = dao.selectWithPage(obj, query.getPageIndex(), query.getPageSize());
			sub = result.front();
			obj.setPid(sub.getPid());
		}
		//ת����vo
		DepotVO vo;
		vo.setName(sub.getName());
		vo.setCode(sub.getCode());
		vo.setAuxName(sub.getAuxName());
		vo.setCreationPeo(sub.getCreationPeo());
		vo.setCreationTime(sub.getCreationTime());
		vo.setId(sub.getId());
		vo.setModiPeo(sub.getModiPeo());
		vo.setModiTime(sub.getModiTime());
		vo.setRemarks(sub.getRemarks());
		vo.setStart(sub.getStart());
		vo.setPhone(sub.getPhone());
		vr.push_back(vo);
		
		pages.setRows(vr);
	}
	return pages;
}

std::list<DepotVO> DepotService::getKid(const OnlyValueQuery& query)
{
	// ��ȡ����id
	DepotDO id;
	id.setPid(query.getId());
	// ��ȡ�Ӽ��ֿ�DO
	DepotDAO dao;
	std::list<DepotDO> result =  dao.selectKid(id);
	std::list<DepotVO> vr;
	for (DepotDO sub : result)
	{
		DepotVO vo;
		vo.setName(sub.getName());
		vo.setCode(sub.getCode());
		// ʣ�µ�����
		vr.push_back(vo);
	}
	return vr;
}

DepotDetailVO DepotService::listDetail(const OnlyValueQuery& query)
{
	//������ѯ����
	DepotDO obj;
	obj.setName("");
	obj.setCode(query.getCode());

	DepotDAO dao;
	std::list<DepotDO> result = dao.selectDetail(obj);
	//��ѯ���ڵ�����
	DepotDO sub = result.front();
	obj.setCode("");
	DepotDetailVO vo;
	if (sub.getPid() != "0")
	{
		obj.setId(sub.getPid());
		result = dao.selectDetail(obj);
		DepotDO psub = result.front();
		vo.setPid(psub.getName());
	}
	//ת��Ϊvo
	vo.setNext(sub.getHasChild());
	vo.setCode(sub.getCode());
	vo.setName(sub.getName());
	vo.setAuxName(sub.getAuxName());
	vo.setPhone(sub.getPhone());
	vo.setStart(sub.getStart() + "0");
	vo.setRemarks(sub.getRemarks());
	return vo;
}

DepotActionInfoVO DepotService::listInfo(const OnlyValueQuery& query)
{
	//������ѯ����
	DepotDO obj;
	obj.setName("");
	obj.setCode(query.getCode());

	DepotDAO dao;
	std::list<DepotDO> result = dao.selectDetail(obj);

	DepotDO sub = result.front();
	obj.setCode("");
	DepotActionInfoVO vo;

	vo.setCreationTime(sub.getCreationTime());
	vo.setCreationPeo(sub.getCreationPeo());
	vo.setModiTime(sub.getModiTime());
	vo.setModiPeo(sub.getModiPeo());

	return vo;
}

bool DepotService::getData(const DepotQuery& query, vector<vector<string>>& data)
{
	//��ѯ����������
	DepotDO obj;
	obj.setName(query.getName());
	obj.setCode(query.getCode());
	DepotDAO dao;
	uint64_t count = dao.count(obj);
	if (count <= 0)
	{
		return false;
	}

	//����ҳ��ѯ����
	list<DepotDO> result = dao.selectWithPage(obj, -1, -1);
	for (DepotDO sub : result)
	{
		vector<string> row;
		row.emplace_back(sub.getName());
		row.emplace_back(sub.getCode());
		// ʣ�µ�����
		data.emplace_back(row);
	}
	return true;
}

int DepotService::saveData(const DepotDTO& dto)
{
	//��װ����
	DepotDO data;
	SnowFlake sf(datacenterId, machineId);
	data.setId(to_string(sf.nextId()));
	// ���pid��Ϊ�գ���Ҫ�޸ĸ�����has_child
	data.setPid(dto.getPid().empty() ? "0" : dto.getPid());
	data.setName(dto.getName());
	data.setCode(dto.getCode());
	data.setAuxName(dto.getAuxName());
	data.setPhone(dto.getPhone());
	data.setStart(dto.getStart());
	//ִ���������
	DepotDAO dao;
	return dao.insertDepot(data);
}

int DepotService::saveKidData(const DepotDTO& dto)
{
	//��װ����
	DepotDO data;
	SnowFlake sf(datacenterId, machineId);
	data.setId(to_string(sf.nextId()));
	data.setPid(dto.getPid());
	data.setName(dto.getName());
	data.setCode(dto.getCode());
	data.setAuxName(dto.getAuxName());
	data.setPhone(dto.getPhone());
	data.setStart(dto.getStart());
	//ִ���������
	DepotDAO dao;
	return dao.insertKidDepot(data);
}

bool DepotService::removeData(const OnlyValueQuery& query)
{
	DepotDO id;
	id.setId(query.getId());
	DepotDAO dao;

	return dao.deleteDepot(id);
}

int DepotService::modifyDepot(const DepotDTO& dto)
{
	//��װ����
	DepotDO data;
	data.setId(dto.getId());
	data.setName(dto.getName());
	data.setCode(dto.getCode());
	data.setAuxName(dto.getAuxName());
	data.setPhone(dto.getPhone());
	data.setStart(dto.getStart());
	data.setRemarks(dto.getRemarks());
	//ִ���������
	DepotDAO dao;
	return dao.update(data);
}

bool DepotService::saveFile(const std::list<DepotDTO>& dto)
{
	bool saveSucceed = true;
	for (auto d : dto) {
		saveSucceed = saveSucceed && saveData(d);
	}
	return saveSucceed;
}
