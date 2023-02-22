#pragma once
#ifndef _PUR_QUOT_ENTRY_DO_H_
#define _PUR_QUOT_ENTRY_DO_H_
#include "../../GlobalInclude.h"
//���ݿ��pur_quot_entry��ʵ��
class PurQuotEntryDO {
  //ID
  CC_SYNTHESIZE(string, id, Id);
  //����
  CC_SYNTHESIZE(string, mid, Mid);
  //���ݺ�
  CC_SYNTHESIZE(string, bill_no, Bill_no);
  //��¼��
  CC_SYNTHESIZE(string, entry_no, Entry_no);
  //Դ������
  CC_SYNTHESIZE(string, src_bill_type, Src_bill_type);
  //Դ��ID
  CC_SYNTHESIZE(string, src_bill_id, Src_bill_id);
  //Դ����¼ID
  CC_SYNTHESIZE(string, src_entry_id, Src_entry_id);
  //Դ����¼��
  CC_SYNTHESIZE(string, src_no, Src_no);
  //����
   CC_SYNTHESIZE(string, material_id, Material_id);
  //������λ
   CC_SYNTHESIZE(string, unit_id, Unit_id);
  //����
   CC_SYNTHESIZE(string, qty, Qty);
  //˰��
   CC_SYNTHESIZE(string, tax_rate, Tax_rate);
  //��˰����
   CC_SYNTHESIZE(string, price, Price);
  //�ۿ���
   CC_SYNTHESIZE(string, discount_rate, Discount_rate);
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
public:
  //���ݿ������ʼ��
  PurQuotEntryDO() {
    id = "";
    mid = "";
    bill_no = "";
    entry_no = "";
    src_bill_type = "";
    src_bill_id = "";
    src_entry_id = "";
    src_no = "";
    material_id = "";
    unit_id = "";
    qty = "";
    tax_rate = "";
    price = "";
    discount_rate = "";
    amt = "";
    remark = "";
    custom1 = "";
    custom2 = "";
    version = "";
  }
};

#endif 
