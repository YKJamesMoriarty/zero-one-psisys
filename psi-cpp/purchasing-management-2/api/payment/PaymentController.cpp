#include "stdafx.h"
#include "PaymentController.h"


JsonVO<uint64_t> PaymentController::execChangePayment(const PaymentChangeDTO& dto)
{
	JsonVO<uint64_t> result;
	if (/*service.updateData(dto)*/true) {
		result.success(dto.getId());
	}
	else
	{
		result.fail(dto.getId());
	}
	return result;
}

JsonVO<uint64_t> PaymentController::execDeleteById(const IntID& id)
{
	//SampleService service;
	JsonVO<uint64_t> result;
	//ִ������ɾ��
	if (/*service.removeData(dto.getId())*/1) {
		result.success(id.getId());
	}
	else
	{
		result.fail(id.getId());
	}
	return result;
}

JsonVO<std::string> PaymentController::execExportPayment(const IntIDs& query)
{
	JsonVO<std::string> result;
	result.success(u8"http://filedownload.com");
	//��Ӧ���
	return result;
}

JsonVO<PaymentVO> PaymentController::exeImportPayment(const PaymentImportDTO& dto)
{
	//����һ������VO
	PaymentVO vo;
	//vo.setNickname(dto.getNickname());
	//vo.setIdCard(dto.getIdCard());
	//vo.setAge(dto.getAge());

	//��������ϴ��ļ�·���б�
	for (auto file : dto.getFiles()) {
		std::cout << "path " << file << std::endl;
	}

	//��Ӧ���
	return JsonVO<PaymentVO>(vo, RS_API_UN_IMPL);
}
