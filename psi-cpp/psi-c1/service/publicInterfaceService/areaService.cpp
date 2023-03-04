#include"stdafx.h"
#include "areaService.h"
#include "../../dao/publicInterfaceDao/areaDAO.h"


std::list<AreaVO> AreaService::listAll(const AreaQuery& query)
{
	//�������ض���
	list<AreaVO> vr;
	//������ѯ����
	AreaQueryDO obj;
	obj.setAreaName(query.getAreaName());
	obj.setType(query.getType());
	//����dao��
	AreaDAO dao;
	list<AreaReturnDO> result  = dao.selectArea(obj);
	for (AreaReturnDO sub : result)
	{
		AreaVO vo;
		vo.setName(sub.getAreaName());
		vr.push_back(vo);
	}
	return vr;
}
