/**
 *Author c1-ruizi
 * 2023/2/22 17:46
 * �ӿڣ���Ʊ��ʽ
 */

#include "stdafx.h"
#include "InvoiceMethodService.h"
#include "../../dao/publicInterfaceDAO/InvoiceMethodDao.h"

list<InvoiceMethodVO> InvoiceMethodService::listAll()
{
    InvoiceMethodDAO dao;
    list<InvoiceMethodDO> result = dao.selectInvoiceMethod();
    list<InvoiceMethodVO> vr;
    //��ѯ����
    for (InvoiceMethodDO sub : result)
    {
        InvoiceMethodVO vo;
        vo.setId(sub.getId());
        vo.setName(sub.getName());
        vr.push_back(vo);
    }
    return vr;
}