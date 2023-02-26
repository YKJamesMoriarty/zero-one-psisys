#include "stdafx.h"
#include "CgthckService.h"

PageVO<QueryCgrkBillListsVO> CgthckService::listAll(const QueryCgrkBillQuery& query)
{
    // ����ʱ������
    auto getTimeZone = [](const std::string & begin, const std::string & end)->std::string
    {
        if (!begin.empty() && !end.empty())
        {
            return string{ begin + '%' + end };
        }
        return string{ "" };
    };
    // �������ض���
    PageVO<QueryCgrkBillListsVO> pages;
    pages.setPageIndex(query.getPageIndex());
    pages.setPageSize(query.getPageSize());

    // ��װ��ѯ����
    CgthckDO obj;
    // ���ݱ��
    obj.setBillNo(query.getBillNo());
    // ��������(��ʼʱ��-����ʱ��)
    obj.setBillDate(getTimeZone(query.getBillDateStart(), query.getBillDateEnd()));
    // ��Ʊ����
    obj.setInvoiceType(query.getInvoiceType());
    // ��Ӧ��
    obj.setSupplierId(query.getSupplierId());
    // ҵ��Ա
    obj.setOperator1(query.getSrcOperator());
    // ҵ����
    obj.setOpDept(query.getOpDept());

    CgthckDAO dao;
    uint64_t count = dao.count(obj);
    if (count <= 0)
    {
        return pages;
    }

    // ��ҳ��ѯ����
    pages.setTotal(count);
    pages.calcPages();
    list<CgthckDO> result = dao.selectWithPage(obj, query.getPageIndex(), query.getPageSize());
    list< QueryCgrkBillListsVO> vr;
    for (auto sub : result)
    {
        QueryCgrkBillListsVO vo;
        // ���ݱ��
        vo.setBillNo(sub.getBillNo());
        // ��������
        vo.setBillDate(sub.getBillDate());
        // ��������
        vo.setSubject(sub.getSubject());
        // �������
        vo.setStockIoType(sub.getStockIoType());
        // Դ����
        vo.setSrcNo(sub.getSrcNo());
        // ��Ӧ��
        vo.setSupplierId(sub.getSupplierId());
        // ҵ����
        vo.setOpDept(sub.getOpDept());
        // ҵ��Ա
        vo.setSrcOperator(sub.getOperator1());
        // ������
        vo.setSettleAmt(sub.getSettleAmt());
        // �ѽ�����
        vo.setSettledAmt(sub.getSettledAmt());
        // �ѿ�Ʊ���
        vo.setInvoicedAmt(sub.getInvoicedAmt());
        // ��Ʊ����
        vo.setInvoiceType(sub.getInvoiceType());
        // ���Ƕ�
        vo.setHasSwell(sub.getHasSwell());
        // �ѹر�
        vo.setIsClosed(sub.getIsClosed());

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
    }


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
    uint64_t mid = dao.insert(data);
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
            cnt += dao.insert(entryData);
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

int CgthckService::updateData(const AddCgthckBillDTO& dto)
{
    // ���ݼ���
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

    // ������ݴ���"����Ч"�׶� �����޸�
    if (dto.getIsClosed() || check(dto))
    {
        return -1;
    }
    
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
    }

    // ������װ���κź���
    auto getBanchNo = [](string billNO, string entryNo) -> std::string
    {
        string banchNo = billNO + '-' + entryNo;
        return banchNo;
    };

    // ��װ��������
    CgthckDO data;
    // ���ݱ��
    data.setBillNo(dto.getBillNo());
    // ��������
    data.setBillDate(dto.getBillDate());
    // ��Ӧ��
    data.setSupplierId(dto.getSupplierId());
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
    // ���ݽ׶�
    data.setBillStage(dto.getBillStage());
    // ����
    data.setAttachment(attachment);
    // ��ע
    data.setRemark(dto.getRemark());

    // ��������
    dao.getSqlSession()->beginTransaction();

    // ִ���������
    int row = dao.update(data);
    if (row == 0)
    {
        dao.getSqlSession()->rollbackTransaction();
        // ɾ�������ĸ���
        dao.deleteFile(attachment);
        return -2;
    }

    // ��װ��ϸ����
    CgthckEntryDO entryData;
    list<CgthckBillEntryDTO> entries = dto.getEntry();
    for (auto& ety : entries)
    {
        // ���α��
        entryData.setBatchNo(getBanchNo(dto.getBillNo(), to_string(ety.getEntryNo())));
        // ��¼��
        entryData.setEntryNo(to_string(ety.getEntryNo()));
        // ��������
        entryData.setSettleQty(ety.getSettleQty());
        //˰��
        entryData.setTaxRate(ety.getTaxRate());
        // ������
        entryData.setSettleAmt(ety.getSettleAmt());
        // �ɹ�����
        entryData.setCost(ety.getCost());
        // �������
        entryData.setQty(ety.getQty());
        // ��ע
        entryData.setRemark(ety.getRemark());
        // �Զ���1
        entryData.setCustom1(ety.getCustom1());
        // �Զ���2
        entryData.setCustom2(ety.getCustom2());

        if (dao.update(entryData) == 0)
        {
            dao.getSqlSession()->rollbackTransaction();
            return -3;
        }
    }
    // ����ɹ�, �ύ
    dao.getSqlSession()->commitTransaction();
    return row;
}

int CgthckService::updateApproval(const ModifyCgthckBillDTO& dto, const PayloadDTO& payload)
{
    // ���ݼ��� ֻ�д��ڱ�����������
    if (dto.getBillStage().compare("14")) // 12������, 14������ 
    {
        return -1;
    }

    // ��װ����
    CgthckDO data;
    data.setBillNo(dto.getBillNo());
    data.setRemark(dto.getRemark());
    data.setApprovalRemark(dto.getApprovalRemark());
    data.setApprovalResultType(dto.getApprovalResultType());
    data.setApprover(payload.getUsername());

    // ���ɵ�ǰʱ��
    time_t rawtime;
    struct tm* info;
    char buffer[80];
    time(&rawtime);
    info = localtime(&rawtime);
    strftime(buffer, 80, "%Y-%m-%d %H:%M:%S", info);

    // ��������
    if (stoi(data.getApprovalResultType()) == 1) // ���ͨ��
    {
        data.setIsEffective(1);
        data.setEffectiveTime(string(buffer));
        data.setIsClosed(1);
        data.setBillStage("34"); // 34:ִ����
    }
    else
    {
        data.setBillStage("24"); // 24:������
    }

    // ����DAO��
    CgthckDAO dao;
    // ����ʼ
    dao.getSqlSession()->beginTransaction();
    int row = dao.updateApproval(data);
    if (row == 0)
    {
        dao.getSqlSession()->rollbackTransaction();
        return -2;
    }
    dao.getSqlSession()->commitTransaction();
    return row;
}

int CgthckService::removeData(const DeleteCgthckBillDTO& dto)
{
    CgthckDAO dao;
    int row = -1;
    
    // ��鵥�ݱ���Ƿ�Ϊ��
    if (!dto.getBillNo().empty())
    {
        // ɾ������
        row = dao.deleteBillById(dto.getBillNo());
        // ɾ����ϸ
        row += dao.deleteEntryById(dto.getBillNo());
    }
    return row;
}

int CgthckService::removeEntry(const DeleteCgthckBillDTO& dto)
{
    CgthckDAO dao;

    int row = -1;
    // �����ϸ�б��Ƿ�Ϊ��
    if (!dto.getBillNo().empty() && !dto.getEntries().empty())
    {
        string billNo = dto.getBillNo();
        for (auto& entry : dto.getEntries())
        {
            // ɾ����ϸ
            row += dao.deleteEntryById(billNo, entry);
        }
    }
    return row;
}

int CgthckService::closed(const ModifyCgthckBillDTO& dto, const PayloadDTO& payload)
{
    // ��װ����
    CgthckDO data;
    data.setBillNo(dto.getBillNo());
    data.setIsClosed(1);

    // ���ɵ�ǰʱ��
    time_t rawtime;
    struct tm* info;
    char buffer[80];
    time(&rawtime);
    info = localtime(&rawtime);
    strftime(buffer, 80, "%Y-%m-%d %H:%M:%S", info);

    data.setEffectiveTime(string(buffer));
    data.setApprover(payload.getUsername());

    CgthckDAO dao;
    return dao.updateStatus(data);
}

int CgthckService::unclosed(const ModifyCgthckBillDTO& dto, const PayloadDTO& payload)
{
    // ��װ����
    CgthckDO data;
    data.setBillNo(dto.getBillNo());
    data.setIsClosed(0);

    // ���ɵ�ǰʱ��
    time_t rawtime;
    struct tm* info;
    char buffer[80];
    time(&rawtime);
    info = localtime(&rawtime);
    strftime(buffer, 80, "%Y-%m-%d %H:%M:%S", info);

    data.setEffectiveTime(string(buffer));
    data.setApprover(payload.getUsername());

    CgthckDAO dao;
    return dao.updateStatus(data);
}

int CgthckService::voided(const ModifyCgthckBillDTO& dto, const PayloadDTO& payload)
{
    // ��װ����
    CgthckDO data;
    data.setBillNo(dto.getBillNo());
    data.setIsVoided(1);

    // ���ɵ�ǰʱ��
    time_t rawtime;
    struct tm* info;
    char buffer[80];
    time(&rawtime);
    info = localtime(&rawtime);
    strftime(buffer, 80, "%Y-%m-%d %H:%M:%S", info);

    data.setEffectiveTime(string(buffer));
    data.setApprover(payload.getUsername());

    CgthckDAO dao;
    return dao.updateStatus(data);
}
