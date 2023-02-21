/*
 *Author c1-ruizi
 * 2023/2/19  17:56
 * �ӿڣ������˻���ͨ��ѯ
 */
#include "stdafx.h"
#include "BankAccountService.h"
#include "../../dao/bankAccountDao/BankAccountDAO.h"

PageVO<BankAccountListVO> BankAccountService::listAll(const BankAccountQuery& query)
{
	//�������ض���
	PageVO<BankAccountListVO> pages;
	pages.setPageIndex(query.getPageIndex());
	pages.setPageSize(query.getPageSize());

	/*
	//��ѯ����������
	BankAccountDO obj;
	//��ͨ��ѯ���Ӧ��զ����
	//ʲô����set��
	obj.setName(query.getName());
	obj.setSex(query.getSex());
	*/
	BankAccountDAO dao;
	uint64_t count = dao.count();
	if (count <= 0)
	{
		return pages;
	}

	//��ҳ��ѯ����
	pages.setTotal(count);
	pages.calcPages();
	list<BankAccountDO> result = dao.selectWithPage(query.getPageIndex(), query.getPageSize());
	list<BankAccountListVO> vr;
	for (BankAccountDO sub : result)
	{
		BankAccountListVO vo;		
		vo.setAccountNo(sub.getAccountNo());
		vo.setBankAddress(sub.getBankAddress());
		vo.setBankNo(sub.getBankNo());
		vo.setCreateBy_dictText(sub.getCreateBy_dictText());
		vo.setCreateTime(sub.getCreateTime());
		vo.setCurrency_dictText(sub.getCurrency_dictText());
		vo.setIsEnabled_dictText(sub.getIsEnabled_dictText());
		vo.setManager_dictText(sub.getManager_dictText());
		vo.setName(sub.getName());
		vo.setRemark(sub.getRemark());
		vo.setUpdateBy(sub.getUpdateBy());
		vo.setUpdateTime(sub.getUpdateTime());
		vr.push_back(vo);
	}
	pages.setRows(vr);
	return pages;
}



