#pragma once

#ifndef _MACROS_
#define _MACROS_

/** �����ܱ����ı��������ṩget��set���� */
#define CC_SYNTHESIZE(varType, varName, funName)\
protected: varType varName;\
public: varType get##funName(void) const { return varName; }\
public: void set##funName(varType var){	varName = var; }

/** �����ܱ�����map���������ṩget��set���� */
#define CC_SYNTHESIZE_MAP(keyType, valType, varName, funName)\
protected: std::map<keyType, valType> varName;\
public: std::map<keyType, valType> get##funName(void) const { return varName; }\
public: void set##funName(std::map<keyType,valType> var){ varName = var; }

/** �����ܱ����ı��������ṩget���� */
#define CC_SYNTHESIZE_GET(varType, varName, funName)\
protected: varType varName;\
public: varType get##funName(void) const { return varName; }

/** �����ܱ�����map���������ṩget���� */
#define CC_SYNTHESIZE_MAP_GET(keyType, valType, varName, funName)\
protected: std::map<keyType, valType> varName;\
public: std::map<keyType, valType> get##funName(void) const { return varName; }\

/** �����ܱ����ı��������ṩset���� */
#define CC_SYNTHESIZE_SET(varType, varName, funName)\
protected: varType varName;\
public: void set##funName(varType var){	varName = var; }

/** �����ܱ�����map���������ṩset���� */
#define CC_SYNTHESIZE_MAP_SET(keyType, valType, varName, funName)\
protected: std::map<keyType, valType> varName;\
public: void set##funName(std::map<keyType,valType> var){ varName = var; }

/** �����ܱ����ı��������ṩget���������ر������� */
#define CC_SYNTHESIZE_CR_GET(varType, varName, funName)\
protected: varType varName;\
public: varType& get##funName(void) { return varName; }\

/** �����ܱ�����map���������ṩget����������map���� */
#define CC_SYNTHESIZE_CR_MAP_GET(keyType, valType, varName, funName)\
protected: std::map<keyType, valType> varName;\
public: std::map<keyType, valType>& get##funName(void) { return varName; }\

/** �����ܱ����ı��������ṩ��get��set���� */
#define CC_SYNTHESIZE_VIRTUAL(varType, varName, funName)\
protected: varType varName;\
public: virtual varType get##funName(void) const { return varName; }\
public: virtual void set##funName(varType var){ varName = var; }

/** �����ܱ����ı��������ṩ��get���� */
#define CC_SYNTHESIZE_VIRTUAL_GET(varType, varName, funName)\
protected: varType varName;\
public: virtual varType get##funName(void) const { return varName; }

/** �����ܱ����ı��������ṩ��set���� */
#define CC_SYNTHESIZE_VIRTUAL_SET(varType, varName, funName)\
protected: varType varName;\
public: virtual void set##funName(varType var){ varName = var; }

/** �����ܱ����ı��������ṩ��get���������ر������� */
#define CC_SYNTHESIZE_VIRTUAL_CR_GET(varType, varName, funName)\
protected: varType varName;\
public: virtual varType& get##funName(void) { return varName; }

/** ˽�л���ֵ�����/��������/�޲ι��� */
#define SINGLETON_HEPLER(TypeName) \
private: \
TypeName() {/*std::cout << #TypeName << std::endl;*/} \
TypeName(const TypeName&) = delete; \
TypeName& operator=(const TypeName&) = delete;

/** ���嵥��ģʽ */
#define DECLARE_INSTANCE(TypeName) \
SINGLETON_HEPLER(TypeName) \
public: \
	static TypeName& getInstance() { \
		static TypeName instance; \
		return instance; \
	} 

#endif // !_MACROS_