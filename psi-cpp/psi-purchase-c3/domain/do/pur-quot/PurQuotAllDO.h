#pragma once
#ifndef _PUR_QUOT_ALL_DO_H_
#define _PUR_QUOT_ALL_DO_H_
#include "../../GlobalInclude.h"
//���ݿ��pur_quot��pur_quot_entry��ʵ��
class PurQuotAllDO {
//pur_quot������ֶ�
  //ID
  CC_SYNTHESIZE(string, id, Id);
  //���ݱ��
  CC_SYNTHESIZE(string, bill_no, Bill_no);
  //��������
  CC_SYNTHESIZE(string, bill_date, Bill_date);
  //Դ������
  CC_SYNTHESIZE(string, src_bill_type, Src_bill_type);
  //Դ��ID
  CC_SYNTHESIZE(string, src_bill_id, Src_bill_id);
  //Դ����
  CC_SYNTHESIZE(string, src_no, Src_no);
  //����
  CC_SYNTHESIZE(string, subject, Subject);
  //�Ƿ����
  CC_SYNTHESIZE(string, is_rubric, Is_rubric);
  //�Ƿ���ʱ��Ӧ��
  CC_SYNTHESIZE(string, is_temp_supplier, Is_temp_supplier);
  //��Ӧ��
  CC_SYNTHESIZE(string, supplier_id, Supplier_id);
  //��Ӧ������
  CC_SYNTHESIZE(string, supplier_name, Supplier_name);
  //���ʽ
  CC_SYNTHESIZE(string, payment_method, Payment_method);
  //����ʱ��
  CC_SYNTHESIZE(string, delivery_time, Delivery_time);
  //�����ص�
  CC_SYNTHESIZE(string, delivery_place, Delivery_place);
  //��ϵ��
  CC_SYNTHESIZE(string, contact, Contact);
  //��ϵ�绰
  CC_SYNTHESIZE(string, phone, Phone);
  //����
  CC_SYNTHESIZE(string, fax, Fax);
  //�����ʼ�
  CC_SYNTHESIZE(string, email, Email);
  //����
  CC_SYNTHESIZE(string, qty, Qty);
  //���
  CC_SYNTHESIZE(string, amt, Amt);
  //����
  CC_SYNTHESIZE(string, attachment, Attachment);
  //��ע
  CC_SYNTHESIZE(string, remark, Remark);
  //�Ƿ��Զ�����
  CC_SYNTHESIZE(string, is_auto, Is_auto);
  //���ݽ׶�
  CC_SYNTHESIZE(string, bill_stage, Bill_stage);
  //�����
  CC_SYNTHESIZE(string, approver, Approver);
  //����ʵ��ID
  CC_SYNTHESIZE(string, bpmi_instance_id, Bpmi_instance_id);
  //�����������
  CC_SYNTHESIZE(string, approval_result_type, Approval_result_type);
  //�������
  CC_SYNTHESIZE(string, approval_remark, Approval_remark);
  //�Ƿ���Ч
  CC_SYNTHESIZE(string, is_effective, Is_effective);
  //��Чʱ��
  CC_SYNTHESIZE(string, effective_time, Effective_time);
  //�ѹر�
  CC_SYNTHESIZE(string, is_closed, Is_closed);
  //�Ƿ�����
  CC_SYNTHESIZE(string, is_voided, Is_voided);
  //��������
  CC_SYNTHESIZE(string, sys_org_code, Sys_org_code);
  //������
  CC_SYNTHESIZE(string, create_by, Create_by);
  //����ʱ��
  CC_SYNTHESIZE(string, create_time, Create_time);
  //�޸���
  CC_SYNTHESIZE(string, update_by, Update_by);
  //�޸�ʱ��
  CC_SYNTHESIZE(string, update_time, Update_time);
  //�汾
  CC_SYNTHESIZE(string, version, Version);
//pur_quot_entry�е��ֶ�
  //ID
  CC_SYNTHESIZE(string, entry_id, Entry_id);
  //����
  CC_SYNTHESIZE(string, entry_mid, Entry_mid);
  //���ݺ�
  CC_SYNTHESIZE(string, entry_bill_no, Entry_bill_no);
  //��¼��
  CC_SYNTHESIZE(string, entry_entry_no, Entry_entry_no);
  //Դ������
  CC_SYNTHESIZE(string, entry_src_bill_type, Entry_src_bill_type);
  //Դ��ID
  CC_SYNTHESIZE(string, entry_src_bill_id, Entry_src_bill_id);
  //Դ����¼ID
  CC_SYNTHESIZE(string, entry_src_entry_id, Entry_src_entry_id);
  //Դ����¼��
  CC_SYNTHESIZE(string, entry_src_no, Entry_src_no);
  //����
  CC_SYNTHESIZE(string, entry_material_id, Entry_material_id);
  //������λ
  CC_SYNTHESIZE(string, entry_unit_id, Entry_unit_id);
  //����
  CC_SYNTHESIZE(string, entry_qty, Entry_qty);
  //˰��
  CC_SYNTHESIZE(string, entry_tax_rate, Entry_tax_rate);
  //��˰����
  CC_SYNTHESIZE(string, entry_price, Entry_price);
  //�ۿ���
  CC_SYNTHESIZE(string, entry_discount_rate, Entry_discount_rate);
  //��˰���
  CC_SYNTHESIZE(string, entry_amt, Entry_amt);
  //��ע
  CC_SYNTHESIZE(string, entry_remark, Entry_remark);
  //�Զ���1
  CC_SYNTHESIZE(string, entry_custom1, Entry_custom1);
  //�Զ���2
  CC_SYNTHESIZE(string, entry_custom2, Entry_custom2);
  //�汾
  CC_SYNTHESIZE(string, entry_version, Entry_version);
public:
  //���ݿ������ʼ��
  PurQuotAllDO() {
    id = "";
    bill_no = "";
    bill_date = "";
    src_bill_type = "";
    src_bill_id = "";
    src_no = "";
    subject = "";
    is_rubric = "";
    is_temp_supplier = "";
    supplier_id = "";
    supplier_name = "";
    payment_method = "";
    delivery_time = "";
    delivery_place = "";
    contact = "";
    phone = "";
    fax = "";
    email = "";
    qty = "";
    amt = "";
    attachment = "";
    remark = "";
    is_auto = "";
    bill_stage = "";
    approver = "";
    bpmi_instance_id = "";
    approval_result_type = "";
    approval_remark = "";
    is_effective = "";
    effective_time = "";
    is_closed = "";
    is_voided = "";
    sys_org_code = "";
    create_by = "";
    create_time = "";
    update_by = "";
    update_time = "";
    version = "";
    entry_id = "";
    entry_mid = "";
    entry_bill_no = "";
    entry_entry_no = "";
    entry_src_bill_type = "";
    entry_src_bill_id = "";
    entry_src_entry_id = "";
    entry_src_no = "";
    entry_material_id = "";
    entry_unit_id = "";
    entry_qty = "";
    entry_tax_rate = "";
    entry_price = "";
    entry_discount_rate = "";
    entry_amt = "";
    entry_remark = "";
    entry_custom1 = "";
    entry_custom2 = "";
    entry_version = "";
  }
};

#endif // !_PUR_QUOT_ALL_DO_H_
