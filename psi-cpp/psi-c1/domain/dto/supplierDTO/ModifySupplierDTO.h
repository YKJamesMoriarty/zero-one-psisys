#pragma once

#ifndef _MODIFY_DTO_
#define _MODIFY_DTO_
#include "../FileDTO.h"
#include "../../GlobalInclude.h"

/**
 * ʾ���������
 */
class ModifySupplierDTO : public FileDTO//�̳�FileDTO����Ϊ��ʵ���ļ��ϴ�
{
	/*��Ӧ����Ϣ*/
	//id
	CC_SYNTHESIZE(string, id, ID);
	// ���
	CC_SYNTHESIZE(string, code, Code);
	// ����
	CC_SYNTHESIZE(string, name, Name);
	//������----������Ϣ�ġ��������ơ����������õĶ������ݿ��е�ͬһ���ֶ� 3
	CC_SYNTHESIZE(string, aux_name, Aux_Name);
	//��Ӧ�̷��� 
	CC_SYNTHESIZE(string, supplier_category, Supplier_Category);
	//��Ӧ�̵ȼ� 
	CC_SYNTHESIZE(string, supplier_level, Supplier_Level);
	//��˰��ģ 
	CC_SYNTHESIZE(string, tax_scale, Tax_Scale);
	//��ѡ��Ӧ��
	CC_SYNTHESIZE(string, alter_suppliers, Alter_Suppliers);
	//�Ƿ�����
	CC_SYNTHESIZE(int, is_enabled, Is_Enabled);
	//��ע
	CC_SYNTHESIZE(string, remark, Remark);

	/*��Ʊ��Ϣ*/
	//��λ����
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

	/*������Ϣ*/
	//������Ϣ��ϵ��
	CC_SYNTHESIZE(string, fnancial_Contacts, Financial_Contacts);
	//������Ϣ��ϵ�绰
	CC_SYNTHESIZE(string, financial_phone, Financial_Phone);
	/*������Ϣ*/
	//���
	CC_SYNTHESIZE(string, short_name, Short_Name);
	//��������(���_������Ϣ�ġ��������ơ����������õĶ������ݿ��е�ͬһ���ֶ�
	//CC_SYNTHESIZE(string, aux_name2, Aux_Name2);
	//��Ӧ����վ 11
	CC_SYNTHESIZE(string, website, Website);
	//���˴���
	CC_SYNTHESIZE(string, legal_person, Legal_Person);
	//���˵绰
	CC_SYNTHESIZE(string, legal_person_phone, Legal_Person_Phone);
	//�����ܹ�˾ 
	CC_SYNTHESIZE(string, headquarters, HeadQuarters);
	//ҵ������  
	CC_SYNTHESIZE(string, area, Area);
	//�������� 
	CC_SYNTHESIZE(string, biz_area, Biz_Area);
	//��Ӧ�̵�ַ 
	CC_SYNTHESIZE(string, address, Address);
	//�ϴ���������controller����ʵ�֣�
	//CC_SYNTHESIZE(string, attachment, Attachment);
	/*������Ϣ*/
	//����ʱ��
	//CC_SYNTHESIZE(string, create_time, Create_Time);
	//������
	//CC_SYNTHESIZE(string, create_by, Create_By);
	//�޸�ʱ��
	//CC_SYNTHESIZE(string, update_time, Update_Time);
	//�޸���
	//CC_SYNTHESIZE(string, update_by, Update_By);
	/*����create_time��create_by��update_time��update_by�ĸ��ֶζ�����Ҫ�û����룬��ϵͳ���ɵģ�����dto�в���Ҫ����service�л�д*/
	//40���ֶ�
	public:
		// ��JSONת������
		friend void from_json(const json& j, ModifySupplierDTO& t); // NOLINT
};

#endif // !_MODIFY_DTO_
