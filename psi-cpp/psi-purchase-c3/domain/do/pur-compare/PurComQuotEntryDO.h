#pragma once
#ifndef _PUR_COM_QUOT_ENTRY_DO_H_
#define _PUR_COM_QUOT_ENTRY_DO_H_
#include "../../GlobalInclude.h"
//���ݿ��pur_quot_entry��ʵ��
class PurComQuotEntryDO {
    //ID
    CC_SYNTHESIZE(string, id, Id);
    //����
    CC_SYNTHESIZE(string, mid, Mid);
    //���ݺ�
    CC_SYNTHESIZE(string, billNo, BillNo);
    //��¼��
    CC_SYNTHESIZE(string, entryNo, EntryNo);
    //Դ������
    CC_SYNTHESIZE(string, srcBillType, SrcBillType);
    //Դ��ID
    CC_SYNTHESIZE(string, srcBillId, SrcBillId);
    //Դ����¼ID
    CC_SYNTHESIZE(string, srcEntryId, SrcEntryId);
    //Դ����¼��
    CC_SYNTHESIZE(string, srcNo, SrcNo);
    //����
    CC_SYNTHESIZE(string, materialId, MaterialId);
    //������λ
    CC_SYNTHESIZE(string, unitId, UnitId);
    //����
    CC_SYNTHESIZE(string, qty, Qty);
    //˰��
    CC_SYNTHESIZE(string, taxRate, TaxRate);
    //��˰����
    CC_SYNTHESIZE(string, price, Price);
    //�ۿ���
    CC_SYNTHESIZE(string, discountRate, DiscountRate);
    //��˰���
    CC_SYNTHESIZE(string, amt, Amt);
    //��ע
    CC_SYNTHESIZE(string, remark, Remark);
    //�Զ���1
    CC_SYNTHESIZE(string, custom1, Custom1);
    //�Զ���2
    CC_SYNTHESIZE(string, custom2, Custom2);
    //�汾
    CC_SYNTHESIZE(string, version, version);
    // ��������
    CC_SYNTHESIZE(string, materialName, MaterialName);
    // ��λ����
    CC_SYNTHESIZE(string, unitName, UnitName);
    // ����ͺ�
    CC_SYNTHESIZE(string, specifications, Specifications);
public:
    //���ݿ������ʼ��
    PurComQuotEntryDO() {
        billNo = "";
    }
};

#endif 