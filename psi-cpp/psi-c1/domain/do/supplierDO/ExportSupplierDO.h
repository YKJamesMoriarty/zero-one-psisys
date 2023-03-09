#pragma once
#ifndef _EXPORT_SUPPLIER_DO_
#define _EXPORT_SUPPLIER_DO_
#include "../DoInclude.h"

/**
 * ���ݿ�ʵ����
 */
class ExportSupplierDO
{
	// ID
	CC_SYNTHESIZE(string, id, Id);
	// ���
	CC_SYNTHESIZE(string, code, Code);
	// ��Ӧ������
	CC_SYNTHESIZE(string, name, Name);
	// ���
	CC_SYNTHESIZE(string, shortName, ShortName);
	// ������
	CC_SYNTHESIZE(string, auxName, AuxName);
	// ��Ӧ�̷���
	CC_SYNTHESIZE(string, supplierCategory, SupplierCategory);
	// ��Ӧ�̵ȼ�
	CC_SYNTHESIZE(string, supplierLevel, SupplierLevel);
	// ��˰��ģ
	CC_SYNTHESIZE(string, taxScale, TaxScale);
	// �����ܹ�˾
	CC_SYNTHESIZE(string, headquarters, Headquarters);
	// ��������
	CC_SYNTHESIZE(string, area, Area);
	// ҵ������
	CC_SYNTHESIZE(string, bizArea, BizArea);
	// �ͻ���ַ
	CC_SYNTHESIZE(string, address, Address);
	// �ͻ���վ
	CC_SYNTHESIZE(string, website, Website);
	// ���˴���
	CC_SYNTHESIZE(string, legalPerson, LegalPerson);
	// ���˵绰
	CC_SYNTHESIZE(string, legalPersonPhone, LegalPersonPhone);
	// ������Ϣ��ϵ��
	CC_SYNTHESIZE(string, financialContacts, FinancialContacts);
	// ������Ϣ��ϵ�绰
	CC_SYNTHESIZE(string, financialPhone, FinancialPhone);
	// ��Ʊ��Ϣ��λ����
	CC_SYNTHESIZE(string, invoiceCompany, InvoiceCompany);
	// ��Ʊ��Ϣ˰��
	CC_SYNTHESIZE(string, invoiceTaxCode, InvoiceTaxCode);
	// ��Ʊ��Ϣ������
	CC_SYNTHESIZE(string, invoiceBankName, InvoiceBankName);
	// ��Ʊ��Ϣ�����˺�
	CC_SYNTHESIZE(string, invoiceBankCode, InvoiceBankCode);
	// ��Ʊ��Ϣ�˺�
	CC_SYNTHESIZE(string, invoiceAccount, InvoiceAccount);
	// ��Ʊ��Ϣ��ϵ�绰
	CC_SYNTHESIZE(string, invoicePhone, InvoicePhone);
	// ��Ʊ��ַ
	CC_SYNTHESIZE(string, invoiceAddress, InvoiceAddress);
	// ������ϵ�λ����
	CC_SYNTHESIZE(string, receiptCompany, ReceiptCompany);
	// ������Ͽ�����
	CC_SYNTHESIZE(string, receiptBankName, ReceiptBankName);
	// ��������к�
	CC_SYNTHESIZE(string, receiptBankCode, ReceiptBankCode);
	// ��������˺�
	CC_SYNTHESIZE(string, receiptAccount, ReceiptAccount);
	// �ռ���Ϣ�ռ���
	CC_SYNTHESIZE(string, recvName, RecvName);
	// �ռ���Ϣ��ϵ�绰
	CC_SYNTHESIZE(string, recvPhone, RecvPhone);
	// �ռ���Ϣ����
	CC_SYNTHESIZE(string, recvFax, RecvFax);
	// �ռ���Ϣ����
	CC_SYNTHESIZE(string, recvEmail, RecvEmail);
	// �ռ���Ϣ��ַ
	CC_SYNTHESIZE(string, recvAddress, RecvAddress);
	// �ռ���Ϣ�ʱ�
	CC_SYNTHESIZE(string, recvPostcode, RecvPostcode);
	// ����
	CC_SYNTHESIZE(string, attachment, Attachment);
	// ��Ӧ���Ƿ�����
	CC_SYNTHESIZE(int, isEnabled, IsEnabled);
	// ��ѡ��Ӧ��
	CC_SYNTHESIZE(string, alterSuppliers, AlterSuppliers);
	// ��ע
	CC_SYNTHESIZE(string, remark, Remark);
	// �汾
	CC_SYNTHESIZE(int, version, Version);
public:
	ExportSupplierDO() {
		id = "";
		code = "";
		name = "";
		shortName = "";
		auxName = "";
		supplierCategory = "";
		supplierLevel = "";
		isEnabled = 1;
	}
};

#endif // !_EXPORT_SUPPLIER_DO_