#include "stdafx.h"
#include "CurrencyTypeService.h"
#include "../../dao/public-interface/CurrencyTypeDAO.h"

list<CurrencyTypeVO> CurrencyTypeService::listAll()
{
    CurrencyTypeDAO dao;
    list<CurrencyTypeDO> result = dao.selectCurrencyType();
    list<CurrencyTypeVO> vr;
    //��DO����ת��ΪVO
    for (CurrencyTypeDO sub : result)
    {
        CurrencyTypeVO vo;
        vo.setId(sub.getId());
        vo.setName(sub.getName());
        vr.push_back(vo);
    }
    return vr;
}
