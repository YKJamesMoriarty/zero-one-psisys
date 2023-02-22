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
    // ��װ��������
    CgthckDO data;
    string billNo = dto.getBillNo();
    data.setBillNo(billNo);
    // data.setBillNo(dto.getBillNo());
    data.setBillDate(dto.getBillDate());
    data.setSupplierId(dto.getSupplierId());
    data.setSrcBillType(dto.getSrcBillType());
    // TO DO

    // ִ���������
    CgthckDAO dao;
    uint64_t mid =  dao.insertIntoBill(data);
    if (mid > 0)
    {
        // ��װ��ϸ����
        int cnt = 0;
        // ��װ���κ�
        auto getBanchNo = [](string billNO, string entryNo) -> std::string
        {
            string banchNo = billNO + '-' + entryNo;
            return banchNo;
        };
        list<CgthckBillEntryDTO> entries = dto.getEntry();
        for (auto ety : entries)
        {
            CgthckEntryDO entryData;
            // ����id
            entryData.setMid(to_string(mid));
            // ��¼��
            string entryNo = to_string(ety.getEntryNo());
            entryData.setEntryNo(entryNo);
            //entryData.setEntryNo(to_string(ety.getEntryNo()));
            // ����
            entryData.setMaterialId(ety.getMaterialId());
            // ���κ�
            entryData.setBatchNo(getBanchNo(billNo, entryNo));
            // �ֿ�
            entryData.setWarehouseId(ety.getWarehouseId());
            // ���뷽��
            entryData.setStockIoDirection("1");
            // ������λ
            entryData.setUnitId(ety.getUnitId());
            // TO DO

            // ִ���������
            cnt += dao.insertIntoEntry(entryData);
        }
        return cnt;
    }
    else
    {
        return mid;
    }
}

bool CgthckService::updateData(const ModifyCgthckBillDTO& dto)
{
    return false;
}

bool CgthckService::removeData(uint64_t id)
{
    return false;
}
