/*
 Copyright Zero One Star. All rights reserved.

 @Author: qingyu
 @Date: 2023/02/17 11:13:11

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

	  https://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
*/
#include "stdafx.h"
#include "PurComService.h"
#include "../../dao/PurCom/PurComDAO.h"

// ��ҳ��ѯ��������
PageVO<PurComVO> PurComService::listAll(const PurComQuery& query)
{
	// �������ض���
	PageVO<PurComVO> pages;
	pages.setPageIndex(query.getPageIndex());
	pages.setPageSize(query.getPageSize());

	// ����DO
	PurComDO obj;
	obj.setBill_no(query.getBill_no());
	obj.setBill_date(query.getBill_date());
	obj.setSubject(query.getSubject());
	obj.setIs_effective(query.getIs_effective());
	obj.setIs_closed(query.getIs_closed());
	obj.setIs_voided(query.getIs_voided());
	
	// ����DAO�����
	PurComDAO dao;
	uint64_t count = dao.count(obj);
	if (count <= 0)
	{
		return pages;
	}
	// ����DAO�㹦��,����DO
	pages.setTotal(count);
	pages.calcPages();
	list<PurComDO> result = dao.selectPurCom(obj, query.getPageIndex(), query.getPageSize());
	list<PurComVO> vr;		//��ҳ��ѯ���ص�VO�б�
	// ����DAO�㷵�ص�DO����VO��Ա���и�ֵ
	for (PurComDO sub : result)
	{
		// �������ڷ��ص�VO
		PurComVO vo;
		
	}
	// ����VO
	return pages;
}

// ��ѯ��������
PurComVO PurComService::getData(uint64_t id) {
	PurComVO data;

	return data;
}