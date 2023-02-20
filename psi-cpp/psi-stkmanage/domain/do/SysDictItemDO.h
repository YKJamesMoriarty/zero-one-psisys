#pragma once
#ifndef _SYS_DICT_ITEM_DO_
#define _SYS_DICT_ITEM_DO_

#include "DoInclude.h"

/*
* sys_dict_item��ʵ����
*/
class SysDictItemDO
{
	// ���
	CC_SYNTHESIZE(string, id, Id);
	// �ֵ�id
	CC_SYNTHESIZE(string, dictId, DictId);
	// �ֵ����ı�
	CC_SYNTHESIZE(string, itemText, ItemText);
	// �ֵ���ֵ
	CC_SYNTHESIZE(string, itemValue, ItemValue);
	// ����
	CC_SYNTHESIZE(string, description, Description);
	// ����
	CC_SYNTHESIZE(int, sortOrder, SortOrder);
	// ״̬(1:����, 2:������)
	CC_SYNTHESIZE(int, status, Status);
	// ������
	CC_SYNTHESIZE(string, createBy, CreateBy);
	// ����ʱ��
	CC_SYNTHESIZE(string, createTime, CreateTime);
	// �޸���
	CC_SYNTHESIZE(string, updateBy, UpdateBy);
	// �޸�ʱ��
	CC_SYNTHESIZE(string, updateTime, UpdateTime);
public:
	SysDictItemDO() {
		id = "";
		dictId = "";
		itemText = "";
		itemValue = "";
		description = "";
		sortOrder = -1;
		status = 2;
		createBy = "";
		createTime = "";
		updateBy = "";
		updateTime = "";
	}
};

#endif // !_SYS_DICT_ITEM_DO_