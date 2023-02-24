/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 14:26:52

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
#include "MaterialClassificationDAO.h"
#include "MaterialClassificationMapper.h"
#include <sstream>

//�������������꣬�����ظ�����
//�������������꣬�����ظ�����
#define MATERIALCLASSIFICATION_TERAM_PARSE(obj, sql) \
SqlParams params; \
sql<<" WHERE 1=1"; \
if (!obj.getName().empty()) { \
	sql << " AND `name`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, obj.getName()); \
} \
if (!obj.getCode().empty()) { \
	sql << " AND code=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, obj.getCode()); \
} 


#define MATERIALCLASSIFICATION_CODE_PARSE(code, sql) \
SqlParams params; \
sql<<" WHERE 1=1"; \
if (!(code=="")) { \
	sql << " AND code=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, code); \
} 

#define MATERIALCLASSIFICATION_NAME_PARSE(name, sql) \
SqlParams params; \
sql<<" WHERE 1=1"; \
if (!(name=="")) { \
	sql << " AND `name`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, name); \
} \



//�yӋ������������Ă���
uint64_t MaterialClassificationDAO::count(const MaterialClassificationDO& iObj)
{
	stringstream sql;
	sql << "SELECT COUNT(id) FROM bas_material_category";
	MATERIALCLASSIFICATION_TERAM_PARSE(iObj, sql);
	string sqlStr = sql.str();
	return sqlSession->executeQueryNumerical(sqlStr, params);
}

//��ҳ���� #��Ҫ���ƻ����
std::list<MaterialClassificationDO> MaterialClassificationDAO::selectWithPage(const MaterialClassificationDO& obj, uint64_t pageIndex, uint64_t pageSize)
{
	stringstream sql;
	sql << "SELECT id,pid,has_child,code,name,fullname,is_enabled,create_by,create_time,update_by,update_time,version FROM bas_material_category";
	MATERIALCLASSIFICATION_TERAM_PARSE(obj, sql);
	sql << " LIMIT " << ((pageIndex - 1) * pageSize) << "," << pageSize;
	MaterialClassificationMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<MaterialClassificationDO, MaterialClassificationMapper>(sqlStr, mapper, params);
}

//�����Ʋ��� 
std::list<MaterialClassificationDO> MaterialClassificationDAO::selectByName(const string& name)
{
	stringstream sql;
	sql << "SELECT id,pid,has_child,code,name,fullname,is_enabled,create_by,create_time,update_by,update_time,version FROM bas_material_category";
	MATERIALCLASSIFICATION_NAME_PARSE(name, sql);
	MaterialClassificationMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<MaterialClassificationDO, MaterialClassificationMapper>(sqlStr, mapper, "%s", name);
}

//�������ѯ
std::list<MaterialClassificationDO> MaterialClassificationDAO::selectByCode(const string& code)
{
	stringstream sql;
	sql << "SELECT id,pid,has_child,code,name,fullname,is_enabled,create_by,create_time,update_by,update_time,version FROM bas_material_category";
	MATERIALCLASSIFICATION_CODE_PARSE(code, sql);
	MaterialClassificationMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<MaterialClassificationDO, MaterialClassificationMapper>(sqlStr, mapper, "%s", code);
}

//�����ڵ��ѯ #�������Ӽ�
std::list<MaterialClassificationDO> MaterialClassificationDAO::selectByPid(const string& pid)
{
	string sql = "SELECT id,pid,has_child,code,name,fullname,is_enabled,create_by,create_time,update_by,update_time,version FROM bas_material_category WHERE `pid` =?";
	MaterialClassificationMapper mapper;
	return sqlSession->executeQuery<MaterialClassificationDO, MaterialClassificationMapper>(sql, mapper, "%s", pid);
}

//��id��ѯ
std::list<MaterialClassificationDO> MaterialClassificationDAO::selectById(const string& id)
{
	string sql = "SELECT id,pid,has_child,code,name,fullname,is_enabled,create_by,create_time,update_by,update_time,version FROM bas_material_category WHERE `id` =?";
	MaterialClassificationMapper mapper;
	return sqlSession->executeQuery<MaterialClassificationDO, MaterialClassificationMapper>(sql, mapper, "%s", id);
}



//�������� #ʱ����string��
uint64_t MaterialClassificationDAO::insert(const MaterialClassificationDO& iObj)
{
	string sql = "INSERT INTO `bas_material_category` (`id`,`pid`,`has_child`,`code`,`name`,`fullname`,`is_enabled`,`create_by`,`create_time`,`version`) VALUES (?,?,?,?,?,?,?,?,?,?)";
	return sqlSession->executeUpdate(sql,"%s%s%s%s%s%s%i%s%s%i", iObj.getId(),iObj.getPid(),iObj.getHasChild(),iObj.getCode(),iObj.getName(),iObj.getFullname(),iObj.getIsEnabled(), iObj.getCreateBy(),iObj.getCreateTime(), iObj.getVersion());
}

//�޸����� 
int MaterialClassificationDAO::update(const MaterialClassificationDO& iObj)
{
	string sql = "UPDATE `bas_material_category` SET `name`= ?,`code`=?,`fullname`=?,`is_enabled`=? ,`update_by`=? ,`update_time`= ? WHERE `id`=?";
	return sqlSession->executeUpdate(sql, "%s%s%s%i%s%s%s", iObj.getName(), iObj.getCode(), iObj.getFullname(),iObj.getIsEnabled(),iObj.getUpdateBy(),iObj.getUpdateTime(),iObj.getId());
}

//��id�޸ģ����ڵ���Ƿ����ӽڵ���,�����ӽڵ�ʱ�Ż����
int MaterialClassificationDAO::updateById(const string id)
{
	string sql = "UPDATE `bas_material_category` SET `has_child`= ? WHERE `id`=?";
	return sqlSession->executeUpdate(sql, "%s", "1");
}

//ͨ��idɾ������ #ɾ�����ݺ������ĳ�������Ƿ�Ӧ�ð�����һ��ɾ�������������Ӧ��Ҫͬʱ�޸Ķ�Ӧ�����has_child

//���Ҫͬʱɾ�����࣬�����ɾ��pid=id�����ݣ�������޸ĸ��࣬������countͳ��pid=id�ĸ���
int MaterialClassificationDAO::deleteById(string id)
{
	string sql = "DELETE FROM `bas_material_category` WHERE `id`=?";
	return sqlSession->executeUpdate(sql, "%s", id);
}

int MaterialClassificationDAO::deleteByPid(string pid) {
	string sql = "DELETE FROM `bas_material_category` WHERE `pid`=?";
	return sqlSession->executeUpdate(sql, "%s", pid);
}