#pragma once

#ifndef _ADD_DTO_
#define _ADD_DTO_
#include "../FileDTO.h"
#include "../../GlobalInclude.h"

/**
 * ʾ���������
 */
class AddSupplierDTO : public FileDTO//�̳�FileDTO����Ϊ��ʵ���ļ��ϴ�
{
	/*��Ӧ����Ϣ*/
	//id
	CC_SYNTHESIZE(string, id, ID);
	// ���1
	CC_SYNTHESIZE(string, code, Code);
	// ����1
	CC_SYNTHESIZE(string, name, Name);
	//������----������Ϣ�ġ��������ơ����������õĶ������ݿ��е�ͬһ���ֶ� 3   1
	CC_SYNTHESIZE(string, aux_name, Aux_Name);//ԭ����Alias
	//��Ӧ�̷��� 1
	CC_SYNTHESIZE(string, supplier_category, Supplier_Category);
	//��Ӧ�̵ȼ� 1
	CC_SYNTHESIZE(string, supplier_level, Supplier_Level);
	//��˰��ģ 1
	CC_SYNTHESIZE(string, tax_scale, Tax_Scale);
	//��ѡ��Ӧ��1
	CC_SYNTHESIZE(string, alter_suppliers, Alter_Suppliers);
	//�Ƿ�����1
	CC_SYNTHESIZE(int, is_enabled, Is_Enabled);
	//��ע1
	CC_SYNTHESIZE(string, remark, Remark);

	/*��Ʊ��Ϣ*/
	//��λ����
	//��λ����1
	CC_SYNTHESIZE(string, invoice_company, Invoice_Company);
	//˰��1
	CC_SYNTHESIZE(string, invoice_tax_code, Invoice_Tax_Code);
	//������1
	CC_SYNTHESIZE(string, invoice_bank_name, Invoice_Bank_Name);
	//�к�1
	CC_SYNTHESIZE(string, invoice_bank_code, Invoice_Bank_Code);//����©
	//�˺�1
	CC_SYNTHESIZE(string, invoice_account, Invoice_Account);
	//��ϵ�绰1
	CC_SYNTHESIZE(string, invoice_phone, Invoice_Phone);
	//��Ʊ��ַ1
	CC_SYNTHESIZE(string, invoice_address, Invoice_Address);
	/*�������*/
	//��λ����Unit name1
	CC_SYNTHESIZE(string, receipt_company, Receipt_Company);
	//������Account bank1
	CC_SYNTHESIZE(string, receipt_bank_name, Receipt_Bank_Name);
	//�к�line number1
	CC_SYNTHESIZE(string, receipt_bank_code, Receipt_Bank_Code);
	//�˺�Account1
	CC_SYNTHESIZE(string, receipt_account, Receipt_Account);
	/*�ռ���Ϣ*/
	//addressee�ռ���1
	CC_SYNTHESIZE(string, recv_name, Recv_Name);
	//Contact number��ϵ�绰1
	CC_SYNTHESIZE(string, recv_phone, Recv_Phone);
	//fax����1
	CC_SYNTHESIZE(string, recv_fax, Recv_Fax);
	//Email1
	CC_SYNTHESIZE(string, recv_email, Recv_Email);
	//address��ַ1
	CC_SYNTHESIZE(string, recv_address, Recv_Address);
	//Zip�ʱ�1
	CC_SYNTHESIZE(string, recv_postcode, Recv_Postcode);

	/*������Ϣ*/
	//������Ϣ��ϵ��1
	CC_SYNTHESIZE(string, fnancial_Contacts, Financial_Contacts);
	//������Ϣ��ϵ�绰1
	CC_SYNTHESIZE(string, financial_phone, Financial_Phone);
	/*������Ϣ*/
	//���1
	CC_SYNTHESIZE(string, short_name, Short_Name);
	//��������(���_������Ϣ�ġ��������ơ����������õĶ������ݿ��е�ͬһ���ֶΡ���ֻ��Ҫдһ�ξ���
	//CC_SYNTHESIZE(string, aux_name2, Aux_Name2);
	//��Ӧ����վ 1
	CC_SYNTHESIZE(string, website, Website);
	//���˴���1
	CC_SYNTHESIZE(string, legal_person, Legal_Person);
	//���˵绰1
	CC_SYNTHESIZE(string, legal_person_phone, Legal_Person_Phone);
	//�����ܹ�˾ 1
	CC_SYNTHESIZE(string, headquarters, HeadQuarters);
	//ҵ������  1
	CC_SYNTHESIZE(string, area, Area);
	//�������� 1
	CC_SYNTHESIZE(string, biz_area, Biz_Area);
	//��Ӧ�̵�ַ 1
	CC_SYNTHESIZE(string, address, Address);
	//�ϴ���������������Ҫ����̳���FileDTO
	//CC_SYNTHESIZE(string, attachment, Attachment);
	/*������Ϣ*/
	//����ʱ��
	CC_SYNTHESIZE(string, create_time, Create_Time);
	//������
	CC_SYNTHESIZE(string, create_by, Create_By);
	//�޸�ʱ��
	CC_SYNTHESIZE(string, update_time, Update_Time);
	//�޸���
	CC_SYNTHESIZE(string, update_by, Update_By);
	//40���ֶ�+Filedto
public:
	// ��JSONת������
	friend void from_json(const json& j, AddSupplierDTO& t); // NOLINT
	AddSupplierDTO()
	{
		is_enabled = -2;//is_enabled�������-2�����û�û������is_enabled��ֵ
	}
};

#endif // !_ADD_DTO_