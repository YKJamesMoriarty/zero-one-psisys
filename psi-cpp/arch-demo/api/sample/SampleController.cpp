
#include "stdafx.h"
#include "SampleController.h"
#include "../../service/sample/SampleService.h"

JsonVO<PageVO<SampleVO>> SampleController::execQuerySample(const SampleQuery& query, const PayloadDTO& payload)
{
	//����һ��Service
	SampleService service;
	//��ѯ����
	PageVO<SampleVO> result = service.listAll(query);
	//��Ӧ���
	return JsonVO<PageVO<SampleVO>>(result, RS_SUCCESS);
}

JsonVO<uint64_t> SampleController::execAddSample(const SampleDTO& dto)
{
	JsonVO<uint64_t> result;
	SampleService service;
	//ִ����������
	uint64_t id = service.saveData(dto);
	if (id > 0) {
		result.success(id);
	}
	else
	{
		result.fail(id);
	}
	//��Ӧ���
	return result;
}

JsonVO<uint64_t> SampleController::execModifySample(const SampleDTO& dto)
{
	SampleService service;
	JsonVO<uint64_t> result;
	if (service.updateData(dto)) {
		result.success(dto.getId());
	}
	else
	{
		result.fail(dto.getId());
	}
	return result;
}

JsonVO<uint64_t> SampleController::execRemoveSample(const SampleDTO& dto)
{
	SampleService service;
	JsonVO<uint64_t> result;
	//ִ������ɾ��
	if (service.removeData(dto.getId())) {
		result.success(dto.getId());
	}
	else
	{
		result.fail(dto.getId());
	}
	//��Ӧ���
	return result;
}

JsonVO<uint64_t> SampleController::execRemoveById(const IntID& id)
{
	SampleDTO dto;
	dto.setId(id.getId());
	return execRemoveSample(dto);
}

JsonVO<SampleVO> SampleController::execJsonSample(const SampleDTO& dto)
{
	//����һ������VO
	SampleVO vo;
	vo.setId(dto.getId());
	vo.setName(dto.getName());
	vo.setAge(dto.getAge());
	vo.setSex(dto.getSex());

	//��Ӧ���
	return JsonVO<SampleVO>(vo, RS_API_UN_IMPL);
}

JsonVO<UserVO> SampleController::execModifyUserInfo(const UserDTO& dto)
{
	//����һ������VO
	UserVO vo;
	vo.setNickname(dto.getNickname());
	vo.setIdCard(dto.getIdCard());
	vo.setAge(dto.getAge());

	//��������ϴ��ļ�·���б�
	for (auto file : dto.getFiles()) {
		std::cout << "path " << file << std::endl;
	}

	//��Ӧ���
	return JsonVO<UserVO>(vo, RS_API_UN_IMPL);
}
