#pragma once
#ifndef _PUR_QUOT_DO_H_
#define _PUR_QUOT_DO_H_
#include "../../GlobalInclude.h"
//���ݿ��pur_quot��ʵ��
class PurQuotDO {
  //1ID1
  CC_SYNTHESIZE(string, id, Id);
  //2���ݱ��
  CC_SYNTHESIZE(string, bill_no, Bill_no);
  //3��������
  CC_SYNTHESIZE(string, bill_date, Bill_date);
  //4Դ������
  CC_SYNTHESIZE(string, src_bill_type, Src_bill_type);
  //5Դ��ID
  CC_SYNTHESIZE(string, src_bill_id, Src_bill_id);
  //6Դ����
  CC_SYNTHESIZE(string, src_no, Src_no);
  //7����
  CC_SYNTHESIZE(string, subject, Subject);
  //8�Ƿ����
  CC_SYNTHESIZE(int, is_rubric, Is_rubric);
  //9�Ƿ���ʱ��Ӧ��
  CC_SYNTHESIZE(int, is_temp_supplier, Is_temp_supplier);
  //10��Ӧ��
  CC_SYNTHESIZE(string, supplier_id, Supplier_id);
  //11��Ӧ������
  CC_SYNTHESIZE(string, supplier_name, Supplier_name);
  //12���ʽ
  CC_SYNTHESIZE(string, payment_method, Payment_method);
  //13����ʱ��
  CC_SYNTHESIZE(string, delivery_time, Delivery_time);
  //14�����ص�
  CC_SYNTHESIZE(string, delivery_place, Delivery_place);
  //15��ϵ��
  CC_SYNTHESIZE(string, contact, Contact);
  //16��ϵ�绰
  CC_SYNTHESIZE(string, phone, Phone);
  //17����
  CC_SYNTHESIZE(string, fax, Fax);
  //18�����ʼ�
  CC_SYNTHESIZE(string, email, Email);
  //19����
  CC_SYNTHESIZE(double, qty, Qty);
  //20���
  CC_SYNTHESIZE(double, amt, Amt);
  //21����
  CC_SYNTHESIZE(string, attachment, Attachment);
  //22��ע
  CC_SYNTHESIZE(string, remark, Remark);
  //23�Ƿ��Զ�����
  CC_SYNTHESIZE(int, is_auto, Is_auto);
  //24���ݽ׶�
  CC_SYNTHESIZE(string, bill_stage, Bill_stage);
  //25�����
  CC_SYNTHESIZE(string, approver, Approver);
  //26����ʵ��ID
  CC_SYNTHESIZE(string, bpmi_instance_id, Bpmi_instance_id);
  //27�����������
  CC_SYNTHESIZE(string, approval_result_type, Approval_result_type);
  //28�������
  CC_SYNTHESIZE(string, approval_remark, Approval_remark);
  //29�Ƿ���Ч
  CC_SYNTHESIZE(int, is_effective, Is_effective);
  //30��Чʱ��
  CC_SYNTHESIZE(string, effective_time, Effective_time);
  //31�ѹر�
  CC_SYNTHESIZE(int, is_closed, Is_closed);
  //32�Ƿ�����
  CC_SYNTHESIZE(int, is_voided, Is_voided);
  //33��������
  CC_SYNTHESIZE(string, sys_org_code, Sys_org_code);
  //34������
  CC_SYNTHESIZE(string, create_by, Create_by);
  //35����ʱ��
  CC_SYNTHESIZE(string, create_time, Create_time);
  //36�޸���
  CC_SYNTHESIZE(string, update_by, Update_by);
  //37�޸�ʱ��
  CC_SYNTHESIZE(string, update_time, Update_time);
  //38�汾
  CC_SYNTHESIZE(int, version, Version);
public:
  //���ݿ������ʼ��
  PurQuotDO() {
    id = "";
    bill_no = "";
    bill_date = "";
    src_bill_type = "";
    src_bill_id = "";
    src_no = "";
    subject = "";
    is_rubric = -1;
    is_temp_supplier = -1;
    supplier_id = "";
    supplier_name = "";
    payment_method = "";
    delivery_time = "";
    delivery_place = "";
    contact = "";
    phone = "";
    fax = "";
    email = "";
    qty = -1.0; //double
    amt = -1.0; //double
    attachment = -1;
    remark = "";
    is_auto = -1;
    bill_stage = -1;
    approver = "";
    bpmi_instance_id = "";
    approval_result_type = "";
    approval_remark = "";
    is_effective = -1;
    effective_time = "";
    is_closed = -1;
    is_voided = -1;
    sys_org_code = "";
    create_by = "";
    create_time = "";
    update_by = "";
    update_time = "";
    version = -1;
  }
};

#endif // !_PUR_QUOT_DO_H_
