#include "stdafx.h"
#include "BasMaterialController.h"
#include <service/BasMaterial/BasMaterialService.h>

//��ͨ��ѯ����
JsonVO<PageVO<BasMaterialVO>> execQueryBasMaterial(const BasMaterialQuery& query, const PayloadDTO& payload) {

	//��ѯ����
	PageVO<BasMaterialVO> result;
	//��Ӧ���
	return JsonVO<PageVO<BasMaterialVO>>(result, RS_SUCCESS);
}
//�鿴ָ������������Ϣ��������������Ϣ
JsonVO<BasMaterialVO> execQueryDetail(const BasMaterialQuery& query, const PayloadDTO& payload) {

	JsonVO <BasMaterialVO> result;
	return result;
}
//��������
JsonVO<BasMaterialVO> execAddBasMaterial(const BasMaterialDTO& dto) {
	JsonVO <BasMaterialVO> result;
	return result;
}
//�޸�����
JsonVO<BasMaterialVO> execModifyBasMaterial(const BasMaterialDTO& dto) {
	JsonVO <BasMaterialVO> result;
	return result;
}
//ɾ������
JsonVO<BasMaterialVO> execRemoveBasMaterial(const BasMaterialDTO& dto) {
	JsonVO <BasMaterialVO> result;
	return result;
}
//����
JsonVO<PageVO<BasMaterialVO>> execImportBasMaterial(const BasMaterialDTO& dto) {
	//��ѯ����
	PageVO<BasMaterialVO> result;
	//��Ӧ���
	return JsonVO<PageVO<BasMaterialVO>>(result, RS_SUCCESS);
}
//����
JsonVO<string> execExportExecl(const BasMaterialQuery& query, const PayloadDTO& payload) {
	JsonVO <string> result;
	return result;
}


JsonVO<PageVO<BasMaterialVO>> BasMaterialController::execQueryBasMaterial(const BasMaterialQuery& query, const PayloadDTO& payload)
{
	return JsonVO<PageVO<BasMaterialVO>>();
}

JsonVO<BasMaterialVO> BasMaterialController::execQueryDetail(const BasMaterialQuery& query, const PayloadDTO& payload)
{
	return JsonVO<BasMaterialVO>();
}

JsonVO<BasMaterialVO> BasMaterialController::execAddBasMaterial(const BasMaterialDTO& dto)
{
	return JsonVO<BasMaterialVO>();
}

JsonVO<BasMaterialVO> BasMaterialController::execModifyBasMaterial(const BasMaterialDTO& dto)
{
	return JsonVO<BasMaterialVO>();
}

JsonVO<BasMaterialVO> BasMaterialController::execRemoveBasMaterial(const BasMaterialDTO& dto)
{
	return JsonVO<BasMaterialVO>();
}

JsonVO<PageVO<BasMaterialVO>> BasMaterialController::execImportBasMaterial(const BasMaterialDTO& dto)
{
	return JsonVO<PageVO<BasMaterialVO>>();
}

JsonVO<string> BasMaterialController::execExportExecl(const BasMaterialQuery& query, const PayloadDTO& payload)
{
	return JsonVO<string>();
}
*/
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 10:58:42

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

	  https://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
*/
JsonVO<PageVO<BasMaterialVO>> BasMaterialController::execQueryBasMaterial(const BasMaterialQuery& query, const PayloadDTO& payload)
{
	//����һ��Service
	BasMaterialService service;
	//��ѯ����
	PageVO<BasMaterialVO> result = service.listAll(query);
	//��Ӧ���
	return JsonVO<PageVO<BasMaterialVO>>(result, RS_SUCCESS);
}
JsonVO<BasMaterialVO> BasMaterialController::execQueryDetail(const BasMaterialQuery& query, const PayloadDTO& payload)
{
	//����һ��Service
	BasMaterialService service;
	//��ѯ����
	BasMaterialVO result = service.getData(query);
	//��Ӧ���
	return JsonVO<BasMaterialVO>(result, RS_SUCCESS);
	
}
JsonVO<uint64_t> BasMaterialController::execAddBasMaterial(const BasMaterialDTO& dto)
{
	JsonVO<uint64_t> result;
	BasMaterialService service;
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

////�޸�����
//JsonVO<uint64_t> BasMaterialController::execModifyBasMaterial(const BasMaterialDTO& dto)
//{
//	BasMaterialService service;
//	JsonVO<uint64_t> result;
//	if (service.updateData(dto)) {
//		result.success(dto.getId());
//	}
//	else
//	{
//		result.fail(dto.getId());
//	}
//	return result;
//}
JsonVO<uint64_t> BasMaterialController::execModifyBasMaterial(const BasMaterialDTO& dto)
{
	BasMaterialService service;
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

//ɾ��
JsonVO<uint64_t> BasMaterialController::execRemoveBasMaterial(const BasMaterialDTO& dto)
{
	BasMaterialService service;
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

JsonVO<uint64_t> BasMaterialController::execRemoveById(const IntID& id)
{
	BasMaterialDTO dto;
	dto.setId(id.getId());
	return execRemoveBasMaterial(dto);
}

JsonVO<PageVO<BasMaterialVO>> BasMaterialController::execImportBasMaterial(const BasMaterialDTO& dto)
{
	return JsonVO<PageVO<BasMaterialVO>>();
}

JsonVO<string> BasMaterialController::execExportExecl(const BasMaterialQuery& query, const PayloadDTO& payload)
{
	return JsonVO<string>();
}
//���⣺�ļ����룬������ôʵ�֣���

//JsonVO<BasMaterialVO> BasMaterialController::execJsonBasMaterial(const BasMaterialDTO& dto)
//{
//	//����һ������VO
//	BasMaterialVO vo;
//	vo.setId(dto.getId());
//	vo.setName(dto.getName());
//	vo.setAge(dto.getAge());
//	vo.setSex(dto.getSex());
//
//	//��Ӧ���
//	return JsonVO<BasMaterialVO>(vo, RS_API_UN_IMPL);
//}

//JsonVO<UserVO> BasMaterialController::execModifyUserInfo(const UserDTO& dto)
//{
//	//����һ������VO
//	UserVO vo;
//	vo.setNickname(dto.getNickname());
//	vo.setIdCard(dto.getIdCard());
//	vo.setAge(dto.getAge());
//
//	//��������ϴ��ļ�·���б�
//	for (auto file : dto.getFiles()) {
//		std::cout << "path " << file << std::endl;
//	}
//
//	//��Ӧ���
//	return JsonVO<UserVO>(vo, RS_API_UN_IMPL);
//}
