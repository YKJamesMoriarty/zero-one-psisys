#include "stdafx.h"
#include "PurTypeController.h"
#include "../../service/publicInterfaceService/PurTypeService.h"
/*
�ɹ���ʽ�����б�
Author C1-��ľ
2023.2.11 21��56��
*/

JsonVO<list<PurTypeVO>> PurTypeController::executequeryPurType()
{
    PurTypeService service;
    list<PurTypeVO> data=service.listAll();
    JsonVO<list<PurTypeVO>> res;
    res.success(data);
    return res;
}
