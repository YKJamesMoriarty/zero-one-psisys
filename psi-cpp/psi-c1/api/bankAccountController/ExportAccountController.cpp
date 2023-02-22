#include "stdafx.h"
#include "ExportAccountController.h"
#include "domain/service/bankAccountService/ExportAccountService.h"
#include "CharsetConvertHepler.h"
#include "domain/do/bankAccountDO/ExportAccountDO.h"
#include "ExcelComponent.h"
#include "FastDfsClient.h"

/*
* �˻���Ϣ����
* @Author: Oxygen
* @Date: 2023/2/15 11:20:02
*/
JsonVO<std::string> ExportAccountController::execExportAccountExecl(const SpecifiedBankAccountQuery& query)
{
	vector<vector<std::string>> data;
	data.push_back({ CharsetConvertHepler::ansiToUtf8("�����˻�����") });
	vector<std::string> header{
		CharsetConvertHepler::ansiToUtf8("�˺�"),
		CharsetConvertHepler::ansiToUtf8("�˻�����"),
	};
	data.push_back(header);
	stringstream ss;

	ExportAccountService service;
	list<ExportAccountDO> vo = service.listAll(query);
	for (ExportAccountDO sub : vo)
	{
		vector<std::string> row;
		ss.clear();
		ss << sub.getAccount_no();
		row.push_back(ss.str());
		ss.str("");
		ss.clear();
		ss << sub.getName();
		row.push_back(ss.str());
		ss.str("");
		data.push_back(row);
	}

	//���屣������λ�ú�ҳǩ����
	std::string fileName = "../../public/excel/1.xlsx";
	std::string sheetName = CharsetConvertHepler::ansiToUtf8("�����˻�");

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