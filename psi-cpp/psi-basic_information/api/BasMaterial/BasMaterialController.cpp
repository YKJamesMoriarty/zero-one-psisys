#include "stdafx.h"
#include "BasMaterialController.h"
/*
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
*/

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
