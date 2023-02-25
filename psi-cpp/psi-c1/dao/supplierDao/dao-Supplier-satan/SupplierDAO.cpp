#include "stdafx.h"
#include "SupplierDAO.h"
#include <sstream>
#include"SupplierMapper.h"



//��ѯ��������������ҳ��ѯ��service�еĸ߼���ѯ��Ҫʹ�ã�����������������������
uint64_t SupplierDAO::count(const  AdvancedQuery condition)//ԭ�����������ŵ���const SupplierDO & iObj
{
	stringstream sql;
	sql << "SELECT COUNT(*) FROM bas_supplier";
	SqlParams params;//����һ����û���õģ��յġ���װ����������
	/*��sql������û�����Ĳ�ѯ����*/
	list<AdvancedQuerySQLCondition> list = condition.getAdvancedQueryCondition();
	//����list���ֶ���������Ȼ��ʹ��forѭ�����ֶ���������sql��
	int size = list.size();
	//��һ��������Ҫ�õ�where��ͷ
	sql << " WHERE 1=1";
	string rule = condition.getRule();
	while (size > 0)
	{
		sql << rule;//rule����and����or
		string relational_symbol;
		if (list.front().getCondition() == "<=" || "<" || ">=" || ">" || "=" || "!=")
		{
			relational_symbol = list.front().getCondition();
			sql << rule << list.front().getField() << relational_symbol << list.front().getValue();
		}
		else if (list.front().getCondition() == "Include")//Ҫд����ǰ��
		{
			relational_symbol = "like";
			sql << rule << list.front().getField() << relational_symbol << "%" << list.front().getValue() << "%";
		}
		else if (list.front().getCondition() == "Begin")
		{
			relational_symbol = "like";
			sql << rule << list.front().getField() << relational_symbol << list.front().getValue() << "%";
		}
		else if (list.front().getCondition() == "End")
		{
			relational_symbol = "like";
			sql << rule << list.front().getField() << relational_symbol << "%" << list.front().getValue();
		}
		else if (list.front().getCondition() == "Among")
		{
			relational_symbol = "like";
			sql << rule << list.front().getField() << relational_symbol << "%_" << list.front().getValue() << "_%";
		}
		list.pop_front();
		size--;
	}
	string sqlStr = sql.str();
	return sqlSession->executeQueryNumerical(sqlStr, params);//params�Ǻ�SAMPLE_TERAM_PARSE�ж����
}

// �߼���ѯ-��ҳ��ѯ������������������������
std::list<SupplierDO> SupplierDAO::AdvancedSelectWithPage(uint64_t pageIndex, uint64_t pageSize,const  AdvancedQuery &condition)//service��ᴫ��ҳ��
{
	stringstream sql;
	sql << "SELECT * FROM bas_supplier";
	SqlParams params;//û���õģ��յ�����������
	/*��sql������û�����Ĳ�ѯ����*/
	list<AdvancedQuerySQLCondition> list = condition.getAdvancedQueryCondition();
	//����list���ֶ���������Ȼ��ʹ��forѭ�����ֶ���������sql��
	int size = list.size();
	//��һ��������Ҫ�õ�where��ͷ
	sql << " WHERE 1=1";
	string rule = condition.getRule();
	while (size > 0) 
	{
		sql << rule;//rule����and����or
		string relational_symbol;
		if (list.front().getCondition() == "<=" || "<" || ">=" || ">" || "=" || "!=")
		{
			relational_symbol = list.front().getCondition();
			sql << rule << list.front().getField() << relational_symbol << list.front().getValue();
		}
		else if (list.front().getCondition() == "Include")//Ҫд����ǰ��
		{
			relational_symbol = "like";
			sql << rule << list.front().getField() << relational_symbol << "%" << list.front().getValue() << "%";
		}
		else if (list.front().getCondition() == "Begin")
		{
			relational_symbol = "like";
			sql << rule << list.front().getField() << relational_symbol << list.front().getValue() << "%";
		}
		else if (list.front().getCondition() == "End")
		{
			relational_symbol = "like";
			sql << rule << list.front().getField() << relational_symbol << "%" << list.front().getValue();
		}
		else if (list.front().getCondition() == "Among")
		{
			relational_symbol = "like";
			sql << rule << list.front().getField() << relational_symbol << "%_" << list.front().getValue() << "_%";
		}
		list.pop_front();
		size--;
	}
	//��sql�����м����ҳ����
	sql << " LIMIT " << ((pageIndex - 1) * pageSize) << "," << pageSize;//pageSize��ÿҳ�����ݵ���Ŀ����pageindex����ʾ��ҳ��
	SupplierMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<SupplierDO, SupplierMapper>(sqlStr, mapper, params);
}

// ��ѯָ����Ӧ�̡�������code
list<SupplierDO> SupplierDAO::SpecifiedSelect(const string& code)
{
	string sql = "SELECT * FROM bas_supplier WHERE `code` LIKE CONCAT('%',?,'%')";//��Ҫ'?'����ռλ��
	SupplierMapper mapper;
	return sqlSession->executeQuery<SupplierDO, SupplierMapper>(sql, mapper, "%s", code);
}


// �������ݡ����Ѽ�飺�ֶΣ�?��%s
uint64_t SupplierDAO::SupplierInsert(const SupplierDO& iObj)
{
	string sql = "INSERT INTO `bas_supplier` (`id`,`code`,`name`, `short_name` ,`aux_name` ,`supplier_category`,`supplier_level`,`tax_scale`\
		,`headquarters` ,`area` ,`biz_area` ,`address` ,`website` ,`legal_person` ,`legal_person_phone` ,`financial_contacts` ,\
		`financial_phone`, `invoice_company`, `invoice_tax_code`, `invoice_bank_name`, `invoice_bank_code`, `invoice_account`, \
		`invoice_phone`, `invoice_address`, `receipt_company`, `receipt_bank_name`, `receipt_bank_code`, `receipt_account`, \
		`recv_name`, `recv_phone`, `recv_fax`, `recv_email`, `recv_address`, `recv_postcode`, `attachment`, `alter_suppliers`,\
		`is_enabled`, `remark`,`create_by`,`create_time`,`update_time`,`update_by`) VALUES (?, ?, ?, ?, ? , ? , ? , ? , ? , ? , ? , ? , ? , ? , ? , ? , ? ,\
		? , ? , ? , ? , ? , ? , ? , ? , ? , ? , ? , ? , ? , ? , ? , ? , ? , ? , ? , ? , ? , ? , ? , ? , ?)";//�Ѽ�飺?��42��;insert���ֶ�Ҳ��42��(�Ѿ�����id�ķ�)
	return sqlSession->executeUpdate(sql, "%s%s%s%s%s\
		%s%s%s%s%s\
		%s%s%s%s%s\
		%s%s%s%s%s\
		%s%s%s%s%s\
		%s%s%s%s%s\
		%s%s%s%s%s\
		%s%i%s%s%s%s%s", iObj.getID(), iObj.getCode(), iObj.getName(), iObj.getShort_Name(), iObj.getAux_Name()
		, iObj.getSupplier_Category(), iObj.getSupplier_Level(), iObj.getTax_Scale(), iObj.getHeadQuarters(), iObj.getArea(), iObj.getBiz_Area()
		, iObj.getAddress(), iObj.getWebsite(), iObj.getLegal_Person(), iObj.getLegal_Person_Phone(), iObj.getFinancial_Contacts(), iObj.getFinancial_Phone()
		, iObj.getInvoice_Company(), iObj.getInvoice_Tax_Code(), iObj.getInvoice_Bank_Name(), iObj.getInvoice_Bank_Code(), 
		iObj.getInvoice_Account(), iObj.getInvoice_Phone(), iObj.getInvoice_Address(), iObj.getReceipt_Company(), iObj.getReceipt_Bank_Name(),
		iObj.getReceipt_Bank_Code(), iObj.getReceipt_Account(), iObj.getRecv_Name(), iObj.getRecv_Phone(),
		iObj.getRecv_Fax(), iObj.getRecv_Email(), iObj.getRecv_Address(), iObj.getRecv_Postcode(), iObj.getAttachment(),
		iObj.getAlter_Suppliers(), iObj.getIs_Enabled(), iObj.getRemark(), iObj.getCreate_By(), iObj.getCreate_Time(), iObj.getUpdate_Time(),
		iObj.getUpdate_By());  //41���ֶ�-�޸Ĺ����Ѿ���ȷ�ˣ�%s��41���Ļ����϶����һ��(����42��%s)��iObj��id��û�м�
}
// �޸����ݡ����Ѽ�飺�ֶΣ�%s��
int SupplierDAO::SupplierUpdateByCode(const SupplierDO& uObj)
{
	string sql = "UPDATE `bas_supplier` SET `code`=?,`name`=? , `short_name`=? ,`aux_name`=? ,`supplier_category`=?,\
		`supplier_level` =?,`tax_scale`=?,`headquarters`=?,`area`=? ,`biz_area`=? ,`address`=? ,`website` =?,\
		`legal_person`=?,`legal_person_phone`=? ,`financial_contacts`=? ,`financial_phone`=? , `invoice_company`=?, \
		`invoice_tax_code`=?, `invoice_bank_name`=? , `invoice_bank_code`=? , `invoice_account`=?, \
		`invoice_phone`=?, `invoice_address`=?, `receipt_company`=?, `receipt_bank_name`=?, `receipt_bank_code`=?, \
		`receipt_account`=?, `recv_name`=? , `recv_phone`=? , `recv_fax`=?, `recv_email`=?, `recv_address`=?, \
		`recv_postcode`=?, `attachment`=?, `alter_suppliers`=?,`is_enabled`=? , `remark`=? ,`create_by`=? ,\
		`create_time`=? ,`update_time`=? ,`update_by`=? WHERE `id`=?" ;//41���ֶ�+WHERE `id`=?
	return sqlSession->executeUpdate(sql, "%s%s%s%s%s\
        %s%s%s%s%s\
        %s%s%s%s%s\
        %s%s%s%s%s\
		%s%s%s%s%s\
        %s%s%s%s%s\
        %s%s%s%s%s%i\
		%s%s%s%s%s%s", uObj.getCode(),uObj.getName(),uObj.getShort_Name(), uObj.getAux_Name()
		, uObj.getSupplier_Category(), uObj.getSupplier_Level(), uObj.getTax_Scale(), uObj.getHeadQuarters(), uObj.getArea(), uObj.getBiz_Area()
		, uObj.getAddress(), uObj.getWebsite(), uObj.getLegal_Person(), uObj.getLegal_Person_Phone(), uObj.getFinancial_Contacts(), uObj.getFinancial_Phone()
		, uObj.getInvoice_Company(), uObj.getInvoice_Tax_Code(), uObj.getInvoice_Bank_Name(), uObj.getInvoice_Bank_Code(),
		uObj.getInvoice_Account(), uObj.getInvoice_Phone(), uObj.getInvoice_Address(), uObj.getReceipt_Company(), uObj.getReceipt_Bank_Name(),
		uObj.getReceipt_Bank_Code(), uObj.getReceipt_Account(), uObj.getRecv_Name(), uObj.getRecv_Phone(),
		uObj.getRecv_Fax(),uObj.getRecv_Email(), uObj.getRecv_Address(), uObj.getRecv_Postcode(), uObj.getAttachment(),
		uObj.getAlter_Suppliers(), uObj.getIs_Enabled(), uObj.getRemark(), uObj.getCreate_By(), uObj.getCreate_Time(), uObj.getUpdate_Time(),
		uObj.getUpdate_By(), uObj.getID());  
}
// ͨ�������ɾ�����ݡ�������code
int SupplierDAO::SupplierDeleteByCode(string id)
{
	string sql = "DELETE FROM `bas_supplier` WHERE `id`=?";
	return sqlSession->executeUpdate(sql, "%s", id);
}

