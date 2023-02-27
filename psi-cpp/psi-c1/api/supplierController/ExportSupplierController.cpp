#include "stdafx.h"
#include "ExportSupplierController.h"
#include "ExcelComponent.h"
#include "CharsetConvertHepler.h"
#include "FastDfsClient.h"
#include "../../service/supplierService/ExportSupplierService.h"
using namespace std;

JsonVO<std::string> ExportSupplierController::execExportSupplier(const list<ExportSupplierQuery>& query, const PayloadDTO& payload)
{
	vector<vector<std::string>> data;
	data.push_back({ CharsetConvertHepler::ansiToUtf8("��Ӧ�̱���") });
	vector<std::string> header{
		CharsetConvertHepler::ansiToUtf8("����"),
		CharsetConvertHepler::ansiToUtf8("����"),
		CharsetConvertHepler::ansiToUtf8("���"),
		CharsetConvertHepler::ansiToUtf8("������"),
		CharsetConvertHepler::ansiToUtf8("��Ӧ�̷���"),
		CharsetConvertHepler::ansiToUtf8("��Ӧ�̵ȼ�"),
		CharsetConvertHepler::ansiToUtf8("��˰��ģ"),
		CharsetConvertHepler::ansiToUtf8("�����ܹ�˾"),
		CharsetConvertHepler::ansiToUtf8("��������"),
		CharsetConvertHepler::ansiToUtf8("ҵ������"),
		CharsetConvertHepler::ansiToUtf8("�ͻ���ַ"),
		CharsetConvertHepler::ansiToUtf8("�ͻ���վ"),
		CharsetConvertHepler::ansiToUtf8("���˴���"),
		CharsetConvertHepler::ansiToUtf8("���˵绰"),
		CharsetConvertHepler::ansiToUtf8("������Ϣ��ϵ��"),
		CharsetConvertHepler::ansiToUtf8("������Ϣ��ϵ�绰"),
		CharsetConvertHepler::ansiToUtf8("��Ʊ��Ϣ��λ����"),
		CharsetConvertHepler::ansiToUtf8("��Ʊ��Ϣ˰��"),
		CharsetConvertHepler::ansiToUtf8("��Ʊ��Ϣ������"),
		CharsetConvertHepler::ansiToUtf8("��Ʊ��Ϣ�����˺�"),
		CharsetConvertHepler::ansiToUtf8("��Ʊ��Ϣ�˺�"),
		CharsetConvertHepler::ansiToUtf8("��Ʊ��Ϣ��ϵ�绰"),
		CharsetConvertHepler::ansiToUtf8("��Ʊ��ַ"),
		CharsetConvertHepler::ansiToUtf8("������ϵ�λ����"),
		CharsetConvertHepler::ansiToUtf8("������Ͽ�����"),
		CharsetConvertHepler::ansiToUtf8("��������к�"),
		CharsetConvertHepler::ansiToUtf8("��������˺�"),
		CharsetConvertHepler::ansiToUtf8("�ռ���Ϣ�ռ���"),
		CharsetConvertHepler::ansiToUtf8("�ռ���Ϣ��ϵ�绰"),
		CharsetConvertHepler::ansiToUtf8("�ռ���Ϣ����"),
		CharsetConvertHepler::ansiToUtf8("recvEmail"),
		CharsetConvertHepler::ansiToUtf8("�ռ���Ϣ��ַ"),
		CharsetConvertHepler::ansiToUtf8("�ռ���Ϣ�ʱ�"),
		CharsetConvertHepler::ansiToUtf8("����"),
		CharsetConvertHepler::ansiToUtf8("�Ƿ�����"),
		CharsetConvertHepler::ansiToUtf8("��ѡ��Ӧ��"),
		CharsetConvertHepler::ansiToUtf8("��ע"),
		CharsetConvertHepler::ansiToUtf8("�汾"),
	};
	data.push_back(header);
	stringstream ss;

	ExportSupplierService service;
	list<list<ExportSupplierDO>> vo = service.listAll(query);
	for (list<ExportSupplierDO> i : vo)
	{
		for (ExportSupplierDO sub : i) {
			vector<std::string> row;
			ss.clear();
			ss << sub.getCode();
			row.push_back(ss.str());
			ss.str("");

			ss.clear();
			ss << sub.getName();
			row.push_back(ss.str());
			ss.str("");

			ss.clear();
			ss << sub.getShortName();
			row.push_back(ss.str());
			ss.str("");

			ss.clear();
			ss << sub.getAuxName();
			row.push_back(ss.str());
			ss.str("");

			ss.clear();
			ss << sub.getSupplierCategory();
			row.push_back(ss.str());
			ss.str("");

			ss.clear();
			ss << sub.getSupplierLevel();
			row.push_back(ss.str());
			ss.str("");

			ss.clear();
			ss << sub.getTaxScale();
			row.push_back(ss.str());
			ss.str("");

			ss.clear();
			ss << sub.getHeadquarters();
			row.push_back(ss.str());
			ss.str("");

			ss.clear();
			ss << sub.getArea();
			row.push_back(ss.str());
			ss.str("");

			ss.clear();
			ss << sub.getBizArea();
			row.push_back(ss.str());
			ss.str("");

			ss.clear();
			ss << sub.getAddress();
			row.push_back(ss.str());
			ss.str("");

			ss.clear();
			ss << sub.getWebsite();
			row.push_back(ss.str());
			ss.str("");

			ss.clear();
			ss << sub.getLegalPerson();
			row.push_back(ss.str());
			ss.str("");

			ss.clear();
			ss << sub.getLegalPersonPhone();
			row.push_back(ss.str());
			ss.str("");

			ss.clear();
			ss << sub.getFinancialContacts();
			row.push_back(ss.str());
			ss.str("");

			ss.clear();
			ss << sub.getFinancialPhone();
			row.push_back(ss.str());
			ss.str("");

			ss.clear();
			ss << sub.getInvoiceCompany();
			row.push_back(ss.str());
			ss.str("");

			ss.clear();
			ss << sub.getInvoiceTaxCode();
			row.push_back(ss.str());
			ss.str("");

			ss.clear();
			ss << sub.getInvoiceBankName();
			row.push_back(ss.str());
			ss.str("");

			ss.clear();
			ss << sub.getInvoiceBankCode();
			row.push_back(ss.str());
			ss.str("");

			ss.clear();
			ss << sub.getInvoiceAccount();
			row.push_back(ss.str());
			ss.str("");

			ss.clear();
			ss << sub.getInvoicePhone();
			row.push_back(ss.str());
			ss.str("");

			ss.clear();
			ss << sub.getInvoiceAddress();
			row.push_back(ss.str());
			ss.str("");

			ss.clear();
			ss << sub.getReceiptCompany();
			row.push_back(ss.str());
			ss.str("");

			ss.clear();
			ss << sub.getReceiptBankName();
			row.push_back(ss.str());
			ss.str("");

			ss.clear();
			ss << sub.getReceiptBankCode();
			row.push_back(ss.str());
			ss.str("");

			ss.clear();
			ss << sub.getReceiptAccount();
			row.push_back(ss.str());
			ss.str("");

			ss.clear();
			ss << sub.getRecvName();
			row.push_back(ss.str());
			ss.str("");

			ss.clear();
			ss << sub.getRecvPhone();
			row.push_back(ss.str());
			ss.str("");

			ss.clear();
			ss << sub.getRecvFax();
			row.push_back(ss.str());
			ss.str("");

			ss.clear();
			ss << sub.getRecvEmail();
			row.push_back(ss.str());
			ss.str("");

			ss.clear();
			ss << sub.getRecvAddress();
			row.push_back(ss.str());
			ss.str("");

			ss.clear();
			ss << sub.getRecvPostcode();
			row.push_back(ss.str());
			ss.str("");

			ss.clear();
			ss << sub.getAttachment();
			row.push_back(ss.str());
			ss.str("");

			if (sub.getIsEnabled() == 1) {
				row.push_back(CharsetConvertHepler::ansiToUtf8("��"));
			}

			ss.clear();
			ss << sub.getAlterSuppliers();
			row.push_back(ss.str());
			ss.str("");

			ss.clear();
			ss << sub.getRemark();
			row.push_back(ss.str());
			ss.str("");

			ss.clear();
			ss << sub.getVersion();
			row.push_back(ss.str());
			ss.str("");

			data.push_back(row);
		}
	}
	/*for (int i = 1; i <= 10; i++)
	{
		vector<std::string> row;
		for (int j = 1; j <= 5; j++)
		{
			ss.clear();
			ss
				<< CharsetConvertHepler::ansiToUtf8("��Ԫ�����꣺(") << i
				<< CharsetConvertHepler::ansiToUtf8(",") << j << ")";
			row.push_back(ss.str());
			ss.str("");
		}
		data.push_back(row);
	}*/

	//���屣������λ�ú�ҳǩ����
	std::string fileName = "./public/excel/1.xlsx";
	std::string sheetName = CharsetConvertHepler::ansiToUtf8("supplier");

	//���浽�ļ�
	ExcelComponent excel;
	excel.writeVectorToFile(fileName, sheetName, data);
	

#ifdef LINUX
	//����ͻ��˶���
	FastDfsClient client("conf/client.conf", 3);
#else
	//����ͻ��˶���
	FastDfsClient client("1.15.240.108");
#endif

	//�ϴ���FastDFS
	std::string fieldName = client.uploadFile(fileName);
	std::cout << "upload fieldname is : " << fieldName << std::endl;

	//��FastDFS���ص�����
	/*if (!fieldName.empty())
	{
		std::string path = "./public/fastdfs";
		fileName = client.downloadFile(fieldName, &path);
		std::cout << "download savepath is : " << fileName << std::endl;
	}*/
	//����ɾ���ļ�
	/*if (!fieldName.empty())
	{
		std::cout << "delete file result is : " << client.deleteFile(fieldName) << std::endl;
	}*/
	//�������ص�ַ
	JsonVO<std::string> res;
	res.success("http://1.15.240.108:8888/" + fieldName);
	
    return res;
}
