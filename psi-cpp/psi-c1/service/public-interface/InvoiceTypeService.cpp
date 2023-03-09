/**
 *Author c1-ruizi
 * 2023/2/22 17:46
 * �ӿڣ���Ʊ����
 */

#include "stdafx.h"
#include "InvoiceTypeService.h"
#include "../../dao/public-interface/InvoiceTypeDao.h"

list<InvoiceTypeVO> InvoiceTypeService::listAll()
{
    InvoiceTypeDAO dao;
    list<InvoiceTypeDO> result = dao.selectInvoiceType();
    list<InvoiceTypeVO> vr;
    //��ѯ����
    for (InvoiceTypeDO sub : result)
    {
        InvoiceTypeVO vo;
        vo.setId(sub.getId());
        vo.setName(sub.getName());
        vr.push_back(vo);
    }
    return vr;
}