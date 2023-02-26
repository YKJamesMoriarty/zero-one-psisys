#include "stdafx.h"
#include "ImportSupplierService.h"
#include "ExcelComponent.h"
#include "CharsetConvertHepler.h"
#include "SnowFlake.h"

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
		int rows = 0;
		for (auto row : readData)
		{
			if (rows < 2)
			{
				rows++;
				continue;
			}
			if (!row.empty())
			{
				int i = 0;
				SnowFlake sf(1, 1);
				data.setId(sf.nextId());
				data.setCode(row.at(i++));
				data.setName(row.at(i++));
				data.setShortName(row.at(i++));
				data.setAuxName(row.at(i++));
				data.setSupplierCategory(row.at(i++));
				data.setSupplierLevel(row.at(i++));
				if (CharsetConvertHepler::utf8ToAnsi(row.at(i++)) == "��") {
					data.setIsEnabled(1);
				}				
				//ִ���������
				ImportSupplierDAO dao;
				dao.insert(data);
				res++;
			}
		}
		
	}

	return res;
}
