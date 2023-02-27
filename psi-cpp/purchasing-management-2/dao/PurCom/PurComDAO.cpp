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
#include "PurComDAO.h"
#include "PurComMApper.h"
#include <sstream>

uint64_t PurComDAO::count(const PurComDO& obj)
{
	stringstream sql;
	sql << "SELECT COUNT(*) FROM pur_compare";
	SqlParams params;
	//____�����ɸѡ����___
	string sqlStr = sql.str();
	return sqlSession->executeQueryNumerical(sqlStr, params);
}


// ͳ����ϸ����
uint64_t countEntrys(const PurComEntryDO& obj) 
{
	stringstream sql;
	sql << "SELECT COUNT(*) FROM pur_compare_entry";
	SqlParams params;
	//____�����ɸѡ����___
	string sqlStr = sql.str();
	//return sqlSession->executeQueryNumerical(sqlStr, params);
	return 1;
}

//��ҳ��ѯ����
list<PurComDO> PurComDAO::selectPurCom(const PurComDO& obj, uint64_t pageIndex, uint64_t pageSize)
{
	stringstream sql;
	// ��Ӳ�ѯ���
	sql << "SELECT id, bill_no, bill_date, src_bill_type,\
		src_bill_id, src_no, `subject`, is_rubric,\
		candidate_quot_ids, payment_method, delivery_place,\
		delivery_time, attachment, remark, is_auto,\
		bill_stage, approver, bpmi_instance_id,\
		approval_result_type, approval_remark,\
		is_effective, effective_time, is_closed,\
		is_voided, sys_org_code, create_by, create_time,\
		update_by, update_time, version FROM pur_compare";
	SqlParams params;

	// ���ɸѡ���
	sql << " WHERE 1=1";
	// ɸѡ����Ϊ���ݱ��
	if (!obj.getBill_no().empty()) {
		sql << " AND `bill_no`=?";
		params.push_back(SqlParam("s", std::make_shared<std::string>(obj.getBill_no())));
	}
	// ɸѡ����Ϊ����ʱ��
	// 
	// ɸѡ����ΪԴ����
	if (!obj.getSrc_no().empty()) {
		sql << " AND `src_no`=?";
		params.push_back(SqlParam("s", std::make_shared<std::string>(obj.getSrc_no())));
	}
	// ��ҳ��ʾ
	sql << " LIMIT " << ((pageIndex - 1) * pageSize) << "," << pageSize;
	PurComMapper mapper;
	string sqlStr = sql.str();
	// ���ز�ѯ���
	return sqlSession->executeQuery<PurComDO, PurComMapper>(sqlStr, mapper, params);
}

list<PurComEntryDO> PurComDAO::selectPurComEntry(const PurComEntryDO& obj, uint64_t pageIndex, uint64_t pageSize)
{
	stringstream sql;
	// ��Ӳ�ѯ���

	sql << "SELECT id, mid. bill_no, \
					entry_no, src_bill_type, src_bill_id, \
					src_entry_no, src_no, supplier_id,\
					material_id, unit_id, qty,\
					tax_rate, price, discountRate,\
					amt, remark, custom1,\
					custom2, version FROM pur_compare_entry";
	SqlParams params;
	// ���ɸѡ���
	sql << " WHERE 1=1";
	//if (!obj.getMid().empty()) {
	//	sql << "AND mid = ?";
	//	params.push_back(SqlParam("s", std::make_shared<std::string>(obj.getId())));
	//}
	// ��ҳ��ʾ
	sql << " LIMIT " << ((pageIndex - 1) * pageSize) << "," << pageSize;
	PurComEntryMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<PurComEntryDO, PurComEntryMapper>(sqlStr, mapper, params);
}
