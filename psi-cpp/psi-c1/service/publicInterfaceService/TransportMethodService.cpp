/**
 *Author c1-ruizi
 * 2023/2/22 17:46
 * �ӿڣ����䷽ʽ
 */

#include "stdafx.h"
#include "TransportMethodService.h"
#include "../../dao/publicInterfaceDao/TransportMethodDao.h"

list<TransportMethodVO> TransportMethodService::listAll()
{
    TransportMethodDAO dao;
    list<TransportMethodDO> result = dao.selectTransportMethod();
    list<TransportMethodVO> vr;
    //��ѯ����
    for (TransportMethodDO sub : result)
    {
        TransportMethodVO vo;
        vo.setId(sub.getId());
        vo.setName(sub.getName());
        vr.push_back(vo);
    }
    return vr;
}