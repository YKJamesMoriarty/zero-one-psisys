#include "stdafx.h"
#include "BillStageController.h"

/*
���ݽ׶������б�
Author C1-��ľ
2023.2.11 21��42��
*/

JsonVO<list<BillStageVO>> BillStageController::executequeryBillStage()
{
    list<BillStageVO> data;
    BillStageVO vo;
    vo.setId(1);
    vo.setName(u8"�����");
    data.push_back(vo);
    JsonVO<list<BillStageVO>> res;
    res.success(data);
    return res;
}
