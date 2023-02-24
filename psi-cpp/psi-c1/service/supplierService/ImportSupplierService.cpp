#include "stdafx.h"
#include "ImportSupplierService.h"
#include "ExcelComponent.h"
#include "CharsetConvertHepler.h"

uint64_t ImportSupplierService::saveData(const FileDTO& dto)
{
	ExcelComponent excel;
	uint64_t res = 0;
	//��������ϴ��ļ�·���б�
	for (auto file : dto.getFiles()) {
		std::cout << "path " << file << std::endl;
		//���ļ��ж�ȡ
		ImportSupplierDO data;
		std::string sheetName = CharsetConvertHepler::ansiToUtf8("supplier");
		auto readData = excel.readIntoVector(file, sheetName);
		for (auto row : readData)
		{
			/*for (auto cellVal : row)
			{
				cout << CharsetConvertHepler::utf8ToAnsi(cellVal) << ",";
			}
			cout << endl;*/
			int i = 0;
			data.setCode(row.at(i++));
			data.setName(row.at(i++));
			//ִ���������
			ImportSupplierDAO dao;
			dao.insert(data);
			res++;
		}
		
	}

	return res;
}
