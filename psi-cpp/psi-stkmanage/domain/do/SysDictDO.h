#pragma once

#ifndef _SYS_DICT_DO_
#define _SYS_DICT_DO_
#include "./DoInclude.h"

/**
 * SysDict���ݿ�ʵ����
 */
class SysDictDO {
	// ���
	CC_SYNTHESIZE(string, id, Id);
	// �ֵ�����
	CC_SYNTHESIZE(string, dictName, DictName);
	// �ֵ����
	CC_SYNTHESIZE(string, dictCode, DictCode);
	// ����
	CC_SYNTHESIZE(string, description, Description);
	// ɾ��״̬
	CC_SYNTHESIZE(int, delFlag, DelFlag);
	// ������
	CC_SYNTHESIZE(string, createBy, CreateBy);
	// ����ʱ��
	CC_SYNTHESIZE(string, createTime, CreateTime);
	// �޸���
	CC_SYNTHESIZE(string, updateBy, UpdateBy);
	// �޸�ʱ��
	CC_SYNTHESIZE(string, updateTime, UpdateTime);
	//�ֵ�����
	CC_SYNTHESIZE(int, type, Type);


public:
	SysDictDO() {
		id = "";
		dictName = "";
		dictCode = "";
		description = "";
		delFlag = 1;
		createBy = "";
		createTime = "";
		updateBy = "";
		updateTime = "";
		type = 1;
	}
};

#endif // !_SYS_DICT_DO_
