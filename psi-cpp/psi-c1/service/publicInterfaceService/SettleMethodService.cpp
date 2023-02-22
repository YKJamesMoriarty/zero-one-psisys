/**
 *Author c1-ruizi
 * 2023/2/22  15:46
 * �ӿڣ����㷽ʽ
 */

#include "stdafx.h"
#include "SettleMethodService.h"
#include "../../dao/publicInterfaceDao/SettleMethodDao.h"

list<SettleMethodVO> SettleMethodService::listAll()
{
    SettleMethodDAO dao;
    list<SettleMethodDO> result = dao.selectSettleMethod();
    list<SettleMethodVO> vr;
    //��ѯ����
    for (SettleMethodDO sub : result)
    {
        SettleMethodVO vo;
        vo.setId(sub.getId());
        vo.setName(sub.getName());
        vr.push_back(vo);
    }
    return vr;
}