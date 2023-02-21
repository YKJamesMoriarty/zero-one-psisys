#include "stdafx.h"
#include "CgthckService.h"


PageVO<QueryCgthckBillVO> CgthckService::listAll(const QueryCgthckBillQuery& query)
{
    // �������ض���
    PageVO<QueryCgthckBillVO> pages;
    pages.setPageIndex(query.getPageIndex());
    pages.setPageSize(query.getPageSize());

    // ��ѯ����������
    CgthckDO obj;
    obj.setBillNo(query.getBillNo());
    obj.setBillDate(query.getBillDate());
    obj.setSupplierId(query.getSupplierId());

    CgthckDAO dao;
    uint64_t count = dao.count(obj);
    if (count <= 0)
    {
        return pages;
    }

    // ��ҳ��ѯ����
    pages.setTotal(count);
    pages.calcPages();
    list<CgthckDO> result = dao.selectById(query.getBillNo());
    list< QueryCgthckBillVO> vr;
    for (auto sub : result)
    {
        QueryCgthckBillVO vo;
        vo.setBillNo(sub.getBillNo());
        vo.setBillDate(sub.getBillDate());
        vo.setSupplierId(sub.getSupplierId());
        vr.push_back(vo);
    }
    pages.setRows(vr);
    return pages;
}

uint64_t CgthckService::saveData(const AddCgthckBillDTO& dto)
{
    // ��װ����
    CgthckDO data;
    data.setBillNo(dto.getBillNo());
    return uint64_t();
}

bool CgthckService::updateData(const ModifyCgthckBillDTO& dto)
{
    return false;
}

bool CgthckService::removeData(uint64_t id)
{
    return false;
}
