#include "stdafx.h"
#include"MaterialTypeTreeListController.h"
#include"../../service/publicInterfaceService/MaterialTypeTreeService.h"


JsonVO<PageVO<MaterialTypeTreeListVO>> MaterialTypeTreeListController::execMaterialTypeTreeListVO(MaterialTypeItemQuery query) {
	//����һ��Service
	MaterialTypeTreeListService service;
	//��ѯ����
	cout << "1" << endl;
	PageVO<MaterialTypeTreeListVO> result = service.listAll(query);
	cout << "10" << endl;
	//��Ӧ���
	return JsonVO<PageVO<MaterialTypeTreeListVO>>(result, RS_SUCCESS);
}