#pragma once
#ifndef _SYS_DEPART_
#define _SYS_DEPART_

#include "DoInclude.h"

/**
* sys_depart ��֯���������ݿ�ʵ����
*/

class SysDepartDO
{
	// ID
	CC_SYNTHESIZE(std::string, id, Id);
	// ������ID
	CC_SYNTHESIZE(std::string, parentId, ParentId);
	// ����/��������
	CC_SYNTHESIZE(std::string, departName, DepartName);
	// Ӣ����
	CC_SYNTHESIZE(std::string, departNameEn, DepartNameEn);
	// ��д
	CC_SYNTHESIZE(std::string, departNameAbbr, DepartNameAbbr);
	// ����
	CC_SYNTHESIZE(int, departOrder, DepartOrder);
	// ����
	CC_SYNTHESIZE(std::string, description, Description);
	// ������� 1��֯������2��λ
	CC_SYNTHESIZE(std::string, orgCategory, OrgCategory);
	// �������� 1һ������ 2�Ӳ���
	CC_SYNTHESIZE(std::string, orgType, OrgType);
	// ��������
	CC_SYNTHESIZE(std::string, orgCode, OrgCode);
	// �ֻ���
	CC_SYNTHESIZE(std::string, mobile, Mobile);
	// ����
	CC_SYNTHESIZE(std::string, fax, Fax);
	// ��ַ
	CC_SYNTHESIZE(std::string, address, Address);
	//��ע
	CC_SYNTHESIZE(std::string, memo, Memo);
	// ״̬(1����, 0������)
	CC_SYNTHESIZE(std::string, status, Status);
	// ɾ��״̬��0��������1��ɾ����
	CC_SYNTHESIZE(std::string, delFlag, DelFlag);
	// �Խ���ҵ΢�ŵ�ID
	CC_SYNTHESIZE(std::string, qywxIdentifier, QywxIdentifier);
	// ������
	CC_SYNTHESIZE(std::string, createBy, CreateBy);
	// ��������
	CC_SYNTHESIZE(std::string, createTime, CreateTime);
	// ������
	CC_SYNTHESIZE(std::string, updateBy, UpdateBy);
	// ��������
	CC_SYNTHESIZE(std::string, updateTime, UpdateTime);
public:
	SysDepartDO() : id(""), parentId(""), departName(""), departNameEn(""), departNameAbbr(""),
		departOrder(0), description(""), orgCategory(""), orgType(""), orgCode(""), mobile(""),
		fax(""), address(""), memo(""), status(""), delFlag(""), qywxIdentifier(""), createBy(""),
		createTime(""), updateBy(""), updateTime("") {}
};

#endif // !_SYS_DEPART_
