#include"stdafx.h"
#include "areaService.h"
#include "../../dao/publicInterfaceDAO/areaDAO.h"


std::list<AreaVO> AreaService::listAll(const AreaQuery& query)
{
	//�������ض���
	list<AreaVO>rs;
	//������ѯ����
	AreaDO obj;
	obj.setAreaName(query.getAreaName());
	obj.setId(query.getId());
	obj.setCityName(query.getCityName());
	obj.setProvinceName(query.getProvinceName());

	AreaDAO dao;
	list<AreaDO> result  = dao.selectArea(obj);
	list<AreaVO> vr;
	for (AreaDO sub : result)
	{
		AreaVO vo;
		vo.setId(sub.getId());
		vo.setName(sub.getName());
		vr.push_back(vo);
	}
	return vr;
}
