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


//�yӋ������������Ă���
uint64_t MaterialClassificationDAO::count(const MaterialClassificationDO& iObj)
{
	stringstream sql;
	sql << "SELECT COUNT(id) FROM bas_material_category";
	MATERIALCLASSIFICATION_TERAM_PARSE(iObj, sql);
	string sqlStr = sql.str();
	return sqlSession->executeQueryNumerical(sqlStr, params);
}

//��ҳ���� #��Ҫ���ƺͱ���
std::list<MaterialClassificationDO> MaterialClassificationDAO::selectWithPage(const MaterialClassificationDO& obj, uint64_t pageIndex, uint64_t pageSize)
{
	stringstream sql;
	sql << "SELECT name,code,fullname,is_enabled,create_time,create_by,update_time,update_by FROM bas_material_category";
	MATERIALCLASSIFICATION_TERAM_PARSE(obj, sql);
	sql << " LIMIT " << ((pageIndex - 1) * pageSize) << "," << pageSize;
	MaterialClassificationMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<MaterialClassificationDO, MaterialClassificationMapper>(sqlStr, mapper, params);
}

//���������� 
std::list<MaterialClassificationDO> MaterialClassificationDAO::selectByName(const string& name)
{
	string sql = "SELECT name,code,fullname,is_enabled,create_time,create_by,update_time,update_by FROM bas_material_category WHERE `name` LIKE CONCAT('%',?,'%')";
	MaterialClassificationMapper mapper;
	return sqlSession->executeQuery<MaterialClassificationDO, MaterialClassificationMapper>(sql, mapper, "%s", name);
}

//�������ѯ
std::list<MaterialClassificationDO> MaterialClassificationDAO::selectByCode(const string& code)
{
	string sql = "SELECT name,code,fullname,is_enabled,create_time,create_by,update_time,update_by FROM bas_material_category WHERE `code` LIKE CONCAT('%',?,'%')";
	MaterialClassificationMapper mapper;
	return sqlSession->executeQuery<MaterialClassificationDO, MaterialClassificationMapper>(sql, mapper, "%s", code);
}

//�����ڵ��ѯ #�������Ӽ�
std::list<MaterialClassificationDO> MaterialClassificationDAO::selectByPid(const string& pid)
{
	string sql = "SELECT name,code,fullname,is_enabled,create_time,create_by,update_time,update_by FROM bas_material_category WHERE `pid` LIKE CONCAT('%',?,'%')";
	MaterialClassificationMapper mapper;
	return sqlSession->executeQuery<MaterialClassificationDO, MaterialClassificationMapper>(sql, mapper, "%s", pid);
}



//�������� #ʱ����string���������ֵ���񷵻ص���id���������ݿ��е�id��varchar
uint64_t MaterialClassificationDAO::insert(const MaterialClassificationDO& iObj)
{
	string sql = "INSERT INTO `bas_material_category` (`id`,`pid`, `name`,`code`,`fullname`,`is_enabled`,`create_time`,`create_by`,`update_time`,`update_by`) VALUES (?, 0, ?, ?, ?, ?, ?, ?, ?. ?)";
	return sqlSession->executeInsert(sql, "%s%s%s%i", iObj.getId(), iObj.getPid(), iObj.getName(), iObj.getCode(), iObj.getFullname(),iObj.getIsEnabled());
}

//�޸����� #ͬ�� ���ص�������
int MaterialClassificationDAO::update(const MaterialClassificationDO& uObj)
{
	string sql = "UPDATE `bas_material_category` SET `name`= ?,`code`= ?,`fullname`= ?,`is_enabled`= ?,`create_time`= ?,`create_by`= ?,`update_time`= ?,`update_by` = ? WHERE `id`=?";
	return sqlSession->executeUpdate(sql, "%s%s%s%s", uObj.getName(), uObj.getCode(), uObj.getFullname(), uObj.getId());
}

//ͨ��idɾ������ #ɾ�����ݺ������ĳ�������Ƿ�Ӧ�ð�����һ��ɾ�������������Ӧ��Ҫͬʱ�޸Ķ�Ӧ�����has_child

//���Ҫͬʱɾ�����࣬�����ɾ��pid=id�����ݣ�������޸ĸ��࣬������countͳ��pid=id�ĸ���
int MaterialClassificationDAO::deleteById(string id)
{
	string sql = "DELETE FROM `bas_material_category` WHERE `id`=?";
	return sqlSession->executeUpdate(sql, "%s", id);
}