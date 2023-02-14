#pragma once

#ifndef _MODIFY_DTO_
#define _MODIFY_DTO_

#include "../../GlobalInclude.h"

/**
 * ʾ���������
 */
class ModifySupplierDTO
{
	/*��Ӧ����Ϣ*/
	// ���
	CC_SYNTHESIZE(int, code, Code);
	// ����
	CC_SYNTHESIZE(string, name, Name);
	//������
	CC_SYNTHESIZE(string, alias, Alias);
	//��Ӧ�̷���
	CC_SYNTHESIZE(string, supplierClassification, SupplierClassification);
	//��Ӧ�̵ȼ�
	CC_SYNTHESIZE(string, supplierLevel, SupplierLevel);
	//��˰��ģ
	CC_SYNTHESIZE(string, taxScale, TaxScale);
	//��ѡ��Ӧ��
	CC_SYNTHESIZE(string, alternativeSuppliers, AlternativeSuppliers);
	//�Ƿ�����
	CC_SYNTHESIZE(string, enable, Enable);
	//��ע
	CC_SYNTHESIZE(string, remark, Remark);

	/*��Ʊ��Ϣ*/
	//��λ����
	CC_SYNTHESIZE(string, unitName1, UnitName1);
	//˰��
	CC_SYNTHESIZE(string, TaxiD, TaxID);
	//������
	CC_SYNTHESIZE(string, accountbank1, AccountBank1);
	//�к�
	CC_SYNTHESIZE(string, lineNumber1, LineNumber1);
	//�˺�
	CC_SYNTHESIZE(string, account1, Account1);
	//��ϵ�绰
	CC_SYNTHESIZE(string, contactNumber1, ContactNumber1);
	//��Ʊ��ַ
	CC_SYNTHESIZE(string, invoicingAddress, InvoicingAddress);
	/*�������*/
	//��λ����Unit name
	CC_SYNTHESIZE(string, unitName2, UnitName2);
	//������Account bank
	CC_SYNTHESIZE(string, accountBank2, AccountBank2);
	//�к�line number
	CC_SYNTHESIZE(string, lineNumber2, LineNumber2);
	//�˺�Account
	CC_SYNTHESIZE(string, account2, Account2);
	/*�ռ���Ϣ*/
	//addressee�ռ���
	CC_SYNTHESIZE(string, addressee, Addressee);
	//Contact number��ϵ�绰
	CC_SYNTHESIZE(string, contactNumber2, ContactNumber2);
	//fax����
	CC_SYNTHESIZE(string, fax, Fax);
	//Email
	CC_SYNTHESIZE(string, email, Email);
	//address��ַ
	CC_SYNTHESIZE(string, address, Address);
	//Zip�ʱ�
	CC_SYNTHESIZE(string, zip, Zip);
	/*������Ϣ*/
	//������Ϣ��ϵ��
	CC_SYNTHESIZE(string, financial_InformationContact, Financial_InformationContact);
	//������Ϣ��ϵ�绰
	CC_SYNTHESIZE(string, contactNumberOfFinancial_Information, ContactNumberOfFinancial_Information);
	/*������Ϣ*/
	//���
	CC_SYNTHESIZE(string, abbreviation, Abbreviation);
	//��������(���
	CC_SYNTHESIZE(string, accessibleName, AccessibleName);
	//��Ӧ����վ
	CC_SYNTHESIZE(string, supplierWebsite, SupplierWebsite);
	//���˴���
	CC_SYNTHESIZE(string, legalRepresentative, LegalRepresentative);
	//���˵绰
	CC_SYNTHESIZE(string, corporateTelephone, CorporateTelephone);
	//�����ܹ�˾
	CC_SYNTHESIZE(string, headOffice, HeadOffice);
	//ҵ������
	CC_SYNTHESIZE(string, businessArea, BusinessArea);
	//��������
	CC_SYNTHESIZE(string, region, Region);
	//��Ӧ�̵�ַ
	CC_SYNTHESIZE(string, supplierAddress, SupplierAddress);
	//�ϴ�����
	//CC_SYNTHESIZE(string, remark, Remark);
	/*������Ϣ*/
	//����ʱ��
	CC_SYNTHESIZE(string, creationTime, CreationTime);
	//������
	CC_SYNTHESIZE(string, createdBy, CreatedBy);
	//�޸�ʱ��
	CC_SYNTHESIZE(string, modificationTime, ModificationTime);
	//�޸���
	CC_SYNTHESIZE(string, modifiedBy, ModifiedBy);
	public:
		// ��JSONת������
		friend void from_json(const json& j, ModifySupplierDTO& t); // NOLINT
};

#endif // !_MODIFY_DTO_
