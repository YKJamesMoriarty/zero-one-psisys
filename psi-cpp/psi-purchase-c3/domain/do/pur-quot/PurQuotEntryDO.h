#pragma once
#ifndef _PUR_QUOT_ENTRY_DO_H_
#define _PUR_QUOT_ENTRY_DO_H_
#include "../../GlobalInclude.h"
//���ݿ��pur_quot_entry��ʵ��
class PurQuotEntryDO {
  //ID
  CC_SYNTHESIZE(string, id, Id);
  //����
  CC_SYNTHESIZE(string, id, Id);
  //���ݺ�
  CC_SYNTHESIZE(string, id, Id);
  //��¼��
  CC_SYNTHESIZE(string, id, Id);
  //Դ������
  CC_SYNTHESIZE(string, id, Id);
  //Դ��ID
  CC_SYNTHESIZE(string, id, Id);
  //Դ����¼ID
  CC_SYNTHESIZE(string, id, Id);
  //Դ����¼��
  CC_SYNTHESIZE(string, id, Id);
  //����
   CC_SYNTHESIZE(string, id, Id);
  //������λ
   CC_SYNTHESIZE(string, id, Id);
  //����
   CC_SYNTHESIZE(string, id, Id);
  //˰��
   CC_SYNTHESIZE(string, id, Id);
  //��˰����
   CC_SYNTHESIZE(string, id, Id);
  //�ۿ���
   CC_SYNTHESIZE(string, id, Id);
  //��˰���
   CC_SYNTHESIZE(string, id, Id);
  //��ע
   CC_SYNTHESIZE(string, id, Id);
  //�Զ���1
   CC_SYNTHESIZE(string, id, Id);
  //�Զ���2
   CC_SYNTHESIZE(string, id, Id);
  //�汾
   CC_SYNTHESIZE(string, id, Id);
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
