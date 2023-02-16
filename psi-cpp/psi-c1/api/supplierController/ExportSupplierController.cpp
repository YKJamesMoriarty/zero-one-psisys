#include "stdafx.h"
#include "ExportSupplierController.h"
#include "ExcelComponent.h"
#include "CharsetConvertHepler.h"
#include "FastDfsClient.h"
using namespace std;

JsonVO<std::string> ExportSupplierController::execExportSupplier()
{
	vector<vector<std::string>> data;
	stringstream ss;
	//�����̨��ѯ�������ݣ���װ����
	for (int i = 1; i <= 10; i++)
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
	}

	//���屣������λ�ú�ҳǩ����
	std::string fileName = "./public/excel/1.xlsx";
	std::string sheetName = CharsetConvertHepler::ansiToUtf8("���ݱ�");

	//���浽�ļ�
	ExcelComponent excel;
	excel.writeVectorToFile(fileName, sheetName, data);
	//�������ص�ַ

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

	JsonVO<std::string> res;
	res.success("http://1.15.240.108:8888/" + fieldName);
	
    return res;
}
