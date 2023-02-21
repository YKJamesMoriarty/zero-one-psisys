#pragma once

#ifndef _SYS_ROLE_DO_
#define _SYS_ROLE_DO_
#include "./DoInclude.h"

/**
 * SysRole���ݿ�ʵ����
 */
class SysRoleDO {
	// ��ɫID
	CC_SYNTHESIZE(string, id, RoleId);
	// ��ɫ״̬ 
	CC_SYNTHESIZE(string, state, State);
	// ��ɫ����
	CC_SYNTHESIZE(string, name, RoleName);
	// ��ɫ����ʱ��
	CC_SYNTHESIZE(string, createTime, CreateTime);


public:
	SysRoleDO() {
		id = "";
		state = "";
		name = "";
		createTime = "";
	}
};

#endif // !_SYS_ROLE_DO_