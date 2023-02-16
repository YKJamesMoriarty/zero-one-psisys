#include "stdafx.h"
#include "ImportSupplierController.h"
#include "ExcelComponent.h"
#include "CharsetConvertHepler.h"

JsonVO<bool> ImportSupplierController::execImportSupplier(const FileDTO& dto)
{ 
	JsonVO<bool> res;
	ExcelComponent excel;
	//��������ϴ��ļ�·���б�
	for (auto file : dto.getFiles()) {
		std::cout << "path " << file << std::endl;
		//���ļ��ж�ȡ
		std::string sheetName = CharsetConvertHepler::ansiToUtf8("���ݱ�");
		auto readData = excel.readIntoVector(file, sheetName);
		for (auto row : readData)
		{
			for (auto cellVal : row)
			{
				cout << CharsetConvertHepler::utf8ToAnsi(cellVal) << ",";
			}
			cout << endl;
		}
	}
	//��Ӧ���
	res.success(true);
	return res;
}
