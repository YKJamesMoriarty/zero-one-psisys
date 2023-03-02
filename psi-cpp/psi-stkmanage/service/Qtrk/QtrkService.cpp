#include "stdafx.h"
#include"QtrkService.h"
#include"dao/Qtrk/QtrkDao.h"
bool QtrkService::updataBillStatus(const ModifyQtrkBillDTO& dto) {
	//��װ��������
	ModifyQtrkBillStatusDO data;
	data.setBillNo(dto.getBillNo());
	data.setIsClosed(dto.getIsClosed());
	data.setIsVoided(dto.getIsVoided());

	//ִ�������޸�
	QtrkDao cd;
	return cd.updataBillStatus(data) == 1;
}
bool QtrkService::deleteBill(const DeleteQtrkBillDTO& dto) {
	//��װ��������
	DeleteBill data;
	data.setId(dto.getId());

	//ִ�������޸�
	QtrkDao cd;
	return cd.deleteBill(data) == 1;
}