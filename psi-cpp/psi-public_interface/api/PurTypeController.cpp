#include "stdafx.h"
#include "PurTypeController.h"

/*
�ɹ���ʽ
Author C1-��ľ
2023.2.11 21��56��
*/

JsonVO<list<PurTypeVO>> PurTypeController::executequeryPurType()
{
    list<PurTypeVO> data;
    PurTypeVO vo;
    vo.setId(1);
    vo.setName(u8"���вɹ�");
    data.push_back(vo);
    JsonVO<list<PurTypeVO>> res;
    res.success(data);
    return res;
}
