#include "stdafx.h"
#include "ImportSupplierController.h"

JsonVO<bool> ImportSupplierController::execImportSupplier(const FileDTO& dto)
{ 
	JsonVO<bool> res;
	//��������ϴ��ļ�·���б�
	for (auto file : dto.getFiles()) {
		std::cout << "path " << file << std::endl;
	}
	//��Ӧ���
	res.success(true);
	return res;
}
