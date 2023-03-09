#include "stdafx.h"
#include "DepartNameService.h"
#include "../../dao/public-interface/DepartNameDAO.h"


std::list<DepartVO> DepartNameService::listAll(const DepartNameQuery& query)
{
	//�������ض���
	list<DepartVO> rs;
	//������ѯ����
	DepartQueryDO obj;
	obj.setDepartName(query.getDepartName());
	obj.setId(query.getId());

	//����dao�����
	DepartNameDAO dao;
	list<DepartReturnDO> result = dao.selectDepartName(obj);
	for (DepartReturnDO sub : result)
	{
		DepartVO vo;
		vo.setDepartName(sub.getDepartName());
		vo.setId(sub.getId());
		rs.push_back(vo);
	}
	return rs;
}
