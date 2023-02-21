#pragma once
/*
 @Author:Satan
 @Date: 2023/2/17
*/
#ifndef _SUPPLIER_DO_
#define _SUPPLIER_DO_
#include "../DoInclude.h"

/**
 * ���ݿ�ʵ���ࡪ�������ݿ�������ֶζ������
 */
class SupplierDO
{
	/*��Ӧ����Ϣ*/
	//ID
	CC_SYNTHESIZE(string, id, ID);
	// ���-1
	CC_SYNTHESIZE(string, code, Code);
	// ���� 2
	CC_SYNTHESIZE(string, name, Name);
	// ��ơ�����ѯָ����Ӧ�̵���Ϣ��������Ϣ������ֶ�
	CC_SYNTHESIZE(string, short_name, Short_Name);
	//������----������Ϣ�ġ��������ơ����������õĶ������ݿ��е�ͬһ���ֶ� 3
	CC_SYNTHESIZE(string, aux_name, Aux_Name);
	//��Ӧ�̷��� 4
	CC_SYNTHESIZE(string, supplier_category, Supplier_Category);
	//��Ӧ�̵ȼ� 5
	CC_SYNTHESIZE(string, supplier_level, Supplier_Level);
	//��˰��ģ 6
	CC_SYNTHESIZE(string, tax_scale, Tax_Scale);

	//�����ܹ�˾ 7
	CC_SYNTHESIZE(string, headquarters, HeadQuarters);
	//ҵ������  9
	CC_SYNTHESIZE(string, area, Area);
	//�������� 8
	CC_SYNTHESIZE(string, biz_area, Biz_Area);
	//��Ӧ�̵�ַ 10
	CC_SYNTHESIZE(string, address, Address);

	//��Ӧ����վ 11
	CC_SYNTHESIZE(string, website, Website);
	//���˴���
	CC_SYNTHESIZE(string, legal_person, Legal_Person);
	//���˵绰
	CC_SYNTHESIZE(string, legal_person_phone, Legal_Person_Phone);
	/*������Ϣ*/
	//������Ϣ��ϵ��
	CC_SYNTHESIZE(string, financial_contacts, Financial_Contacts);
	//������Ϣ��ϵ�绰
	CC_SYNTHESIZE(string, financial_phone, Financial_Phone);

	/*��Ʊ��Ϣ*/
    //��λ����
	CC_SYNTHESIZE(string, invoice_company, Invoice_Company);
	//˰��
	CC_SYNTHESIZE(string, invoice_tax_code, Invoice_Tax_Code);
	//������
	CC_SYNTHESIZE(string, invoice_bank_name, Invoice_Bank_Name);
	//�к�
	CC_SYNTHESIZE(string, invoice_bank_code, Invoice_Bank_Code);
	//�˺�
	CC_SYNTHESIZE(string, invoice_account, Invoice_Account);
	//��ϵ�绰
	CC_SYNTHESIZE(string, invoice_phone, Invoice_Phone);
	//��Ʊ��ַ
	CC_SYNTHESIZE(string, invoice_address, Invoice_Address);
	/*�������*/
	//��λ����Unit name
	CC_SYNTHESIZE(string, receipt_company, Receipt_Company);
	//������Account bank
	CC_SYNTHESIZE(string, receipt_bank_name, Receipt_Bank_Name);
	//�к�line number
	CC_SYNTHESIZE(string, receipt_bank_code, Receipt_Bank_Code);
	//�˺�Account
	CC_SYNTHESIZE(string, receipt_account, Receipt_Account);
	/*�ռ���Ϣ*/
	//addressee�ռ���
	CC_SYNTHESIZE(string, recv_name, Recv_Name);
	//Contact number��ϵ�绰
	CC_SYNTHESIZE(string, recv_phone, Recv_Phone);
	//fax����
	CC_SYNTHESIZE(string, recv_fax, Recv_Fax);
	//Email
	CC_SYNTHESIZE(string, recv_email, Recv_Email);
	//address��ַ
	CC_SYNTHESIZE(string, recv_address, Recv_Address);
	//Zip�ʱ�
	CC_SYNTHESIZE(string, recv_postcode, Recv_Postcode);
	//�ϴ�����������ȷ��Ҫ��Ҫ��
	CC_SYNTHESIZE(string, attachment, Attachment);
	//��ѡ��Ӧ�� 12
	CC_SYNTHESIZE(string, alter_suppliers, Alter_Suppliers);
	//�Ƿ����� 13
	CC_SYNTHESIZE(int, is_enabled, Is_Enabled);
	//��ע  14
	CC_SYNTHESIZE(string, remark, Remark);
	/*������Ϣ*/
	//������ 15
	CC_SYNTHESIZE(string, create_by, Create_By);
    //����ʱ�� 16
	CC_SYNTHESIZE(string, create_time, Create_Time);
	//�޸�ʱ��
	CC_SYNTHESIZE(string, update_time, Update_Time);
	//�޸��� 17
	CC_SYNTHESIZE(string, update_by, Update_By);
	//�汾---���ӹ�Ӧ�̵�ʱ����Ҫ�����Ϣ
	CC_SYNTHESIZE(int, version, Version);


public:
	SupplierDO() {
		id ="";
		name = "";
		aux_name = "";
		is_enabled = 1;

	}
};

#endif // !_SUPPLIER_DO_