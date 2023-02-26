#include "stdafx.h"
#include "CgrkService.h"
#include"../../dao/Cgrk/CgrkDao.h"
#include"../../domain/do/Cgrk/ModifyCgrkBillStatusDO.h"
bool CgrkService::updataBillStatus(const ModifyCgrkBillStateDTO& dto) {
	//��װ��������
	ModifyCgrkBillStatusDO data;
	data.setBillNo(dto.getBillNo());
	data.setIsClosed(dto.getIsClosed());
	data.setIsVoided(dto.getIsVoided());

	//ִ�������޸�
	CgrkDao cd;
	return cd.updataBillStatus(data) == 1;
}