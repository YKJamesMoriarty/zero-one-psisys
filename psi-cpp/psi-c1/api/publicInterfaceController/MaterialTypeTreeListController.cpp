#include "stdafx.h"
#include"MaterialTypeTreeListController.h"
#include"../../service/publicInterfaceService/MaterialTypeTreeService.h"


JsonVO<PageVO<MaterialTypeTreeListVO>> MaterialTypeTreeListController::execMaterialTypeTreeListVO(MaterialTypeItemQuery query) {
	//����һ��Service
	MaterialTypeTreeListService service;
	//��ѯ����
	PageVO<MaterialTypeTreeListVO> result = service.listAll(query);
	//��Ӧ���
	return JsonVO<PageVO<MaterialTypeTreeListVO>>(result, RS_SUCCESS);
}