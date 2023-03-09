#pragma once
#ifndef _IDDTO_H_
#define _IDDTO_H_

#include "../GlobalInclude.h"

/**
 * �������ͱ�Ŷ���
 */
class IntID
{
	// ���
	CC_SYNTHESIZE(uint64_t, id, Id);
public:
	// ��JSONת������
	friend void from_json(const json& j, IntID& t) { // NOLINT
		BIND_FROM_TO_ULL(j, t, id);
	}
};

/**
 * �������ͱ�Ŷ��󼯺�
 */
class IntIDs
{
	// ���
	CC_SYNTHESIZE(std::list<uint64_t>, id, Id);
public:
	// ��JSONת������
	friend void from_json(const json& j, IntIDs& t) { // NOLINT
		BIND_FROM_TO_OBJ(j, t, id, std::list<uint64_t>);
	}
};

/**
 * �ַ������ͱ�Ŷ���
 */
class StringID
{
	// ���
	CC_SYNTHESIZE(std::string, id, Id);
public:
	// ��JSONת������
	friend void from_json(const json& j, StringID& t) { // NOLINT
		BIND_FROM_TO_NORMAL(j, t, id);
	}
};

/**
 * �ַ������ͱ�Ŷ��󼯺�
 */
class StringIDs
{
	// ���
	CC_SYNTHESIZE(std::list<std::string>, id, Id);
public:
	// ��JSONת������
	friend void from_json(const json& j, StringIDs& t) { // NOLINT
		BIND_FROM_TO_OBJ(j, t, id, std::list<std::string>);
	}
};

#endif // !_IDDTO_H_
