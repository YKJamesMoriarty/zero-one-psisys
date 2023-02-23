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
    // �������ݼ���ĺ���
    auto check = [](const AddCgthckBillDTO& dto)
    {
        for (auto& ety : dto.getEntry())
        {
            // ��¼�Ų���Ϊ�������Һ��ֵ������ݲ���Ϊ����
            if (ety.getEntryNo() < 0 || ety.getSettleQty() > 0 || ety.getTax() > 0 || ety.getSettleAmt() > 0)
                return true;
        }
        return false;
    };

    // ����У��
    if (check(dto))
        return -1;

    // ����dao�����
    CgthckDAO dao;

    // �ϴ�����
    string attachment{ "" };
    for (auto& f : dto.getFiles())
    {
        string fileName = dao.insertFile(f);
        if (!fileName.empty())
        {
            attachment += fileName + ',';
        }
        /*       
        else
        {
            return -2;
        }
        */
    }
    int len = attachment.size();

    // ������װ���κź���
    auto getBanchNo = [](string billNO, string entryNo) -> std::string
    {
        string banchNo = billNO + '-' + entryNo;
        return banchNo;
    };

    // ����ѩ��ID
    SnowFlake sf(1, 5);
    string id = to_string(sf.nextId());

    // ��װ��������
    CgthckDO data;
    // id
    data.setId(id);
    // ���ݱ��
    data.setBillNo(dto.getBillNo());
    // ��������
    data.setBillDate(dto.getBillDate());
    // ��Ӧ��
    data.setSupplierId(dto.getSupplierId());
    // Դ������
    data.setSrcBillType(dto.getSrcBillType());
    // �ɹ���ⵥ���
    data.setSrcNo(dto.getSrcNo());
    // ����Ч
    data.setIsEffective(dto.getIsEff());
    // �ѹر�
    data.setIsClosed(dto.getIsClosed());
    // ������
    data.setIsVoided(dto.getIsVoided());
    // ҵ����
    data.setOpDept(dto.getOpDept());
    // ����
    data.setSubject(dto.getSubject());
    // ��Ʊ����
    data.setInvoiceType(dto.getInvoiceType());
    // ���⾭��
    data.setHandler(dto.getHandler());

    // ��������
    dao.getSqlSession()->beginTransaction();

    // ִ���������
     int cnt = 0; // ��¼������ϸ��������
    // ��ȡmid
    uint64_t mid = dao.insertIntoBill(data);
    if (mid > 0)
    {
        // ��װ��ϸ����
        list<CgthckBillEntryDTO> entries = dto.getEntry();
        for (auto& ety : entries)
        {
            CgthckEntryDO entryData;
            // id
            entryData.setId(to_string(sf.nextId()));
            // ����id
            entryData.setMid(to_string(mid));
            // ���ݱ��
            entryData.setBillNo(dto.getBillNo());
            // ��¼��
            entryData.setEntryNo(to_string(ety.getEntryNo()));
            // ����
            entryData.setMaterialId(ety.getMaterialId());
            // ���κ�
            entryData.setBatchNo(getBanchNo(dto.getBillNo(), to_string(ety.getEntryNo())));
            // �ֿ�
            entryData.setWarehouseId(ety.getWarehouseId());
            // ���뷽��
            entryData.setStockIoDirection("1"); // ��ʱ��֪���ĸ�����������
            // ������λ
            entryData.setUnitId(ety.getUnitId());
            // ��������
            entryData.setSettleQty(ety.getSettleQty());
            // ˰��
            entryData.setTaxRate(ety.getTaxRate());
            // ��˰����
            entryData.setPrice(ety.getPrice());
            // �ۿ���
            entryData.setDiscountRate(ety.getDiscountRate());
            // ˰��
            entryData.setTax(ety.getTax());
            // ������
            entryData.setSettleAmt(ety.getSettleAmt());
            // �������
            entryData.setQty(ety.getQty());
            // �ɹ�����(�ɱ�)
            entryData.setCost(ety.getCost());
            // �����
            entryData.setInvoicedAmt(ety.getInAmt());

            // ִ���������, ���ز���ɹ�������
            cnt += dao.insertIntoEntry(entryData);
        }
    }
    if (mid <= 0 || cnt <= 0)
    {
        // ����ʧ��, �ع�
        dao.getSqlSession()->rollbackTransaction();
    }
    else
    {
        // ����ɹ�, �ύ
        dao.getSqlSession()->commitTransaction();
    }
    return cnt;
}

bool CgthckService::updateData(const ModifyCgthckBillDTO& dto)
{
    return false;
}

bool CgthckService::removeData(uint64_t id)
{
    return false;
}
