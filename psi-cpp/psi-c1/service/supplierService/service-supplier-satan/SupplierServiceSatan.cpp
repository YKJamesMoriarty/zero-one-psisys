#include "stdafx.h"
#include "SupplierServiceSatan.h"
#include "../../../dao/supplierDAO/dao-Supplier-satan/SupplierDAO.h"
#include "../lib-common/include/SnowFlake.h"
#include <sstream>
#include "../lib-common/include/SimpleDateTimeFormat.h"
#include "../lib-http/include/JWTUtil.h"

// �߼���ѯ
PageVO<AdvancedQueryVO> SupplierService::advancedListSupplierData(const AdvancedQuery& query)
{
	//�������ض���
	PageVO<AdvancedQueryVO> pages;//��ҳ���ط��صľ���ҳ�棬ҳ������洢������
	//�ڷ��ض���VO�д��뷵��ҳ��
	/*query.setPageSize(9);
	query.setPageIndex(1);*/
	pages.setPageIndex(query.getPageIndex());//���õ�ǰҳ��
	pages.setPageSize(query.getPageSize());//����ÿҳ�����������
	//����dao�е�count()��������ѯ����������
	SupplierDAO dao;
	uint64_t count = dao.count(query);//count��������ִ�������ݿ��н��в�������ҳ���ĺ���
	if (count <= 0)
	{
		return pages;//���Ҳ������ݣ�ֱ�ӷ���0ҳ
	}
	//��¼��ѯ����ҳ��
	pages.setTotal(count);
	pages.calcPages();                                            
	//ִ��DAO��ĸ߼���ѯ����
	list<SupplierDO> result = dao.AdvancedSelectWithPage(query.getPageIndex(), query.getPageSize(),query);
	list<AdvancedQueryVO> vr;
	for (SupplierDO sub : result)
	{
		AdvancedQueryVO vo;
		vo.setCode(sub.getCode());
		vo.setName(sub.getName());
		vo.setAux_Name(sub.getAux_Name());
		vo.setSupplier_Category(sub.getSupplier_Category());
		vo.setSupplier_Level(sub.getSupplier_Level());
		vo.setTax_Scale(sub.getTax_Scale());
		vo.setHeadQuarters(sub.getHeadQuarters());
		vo.setBiz_Area(sub.getBiz_Area());
		vo.setArea(sub.getArea());
		vo.setAddress(sub.getAddress());
		vo.setWebsite(sub.getWebsite());
		vo.setAlter_Suppliers(sub.getAlter_Suppliers());
		vo.setIs_Enabled(sub.getIs_Enabled());
		vo.setRemark(sub.getRemark());
		vo.setCreate_By(sub.getCreate_By());
		vo.setUpdate_Time(sub.getUpdate_Time());
		vo.setUpdate_By(sub.getUpdate_By());
		vr.push_back(vo);
	}
	pages.setRows(vr);
	return pages;

}

//��ѯָ����Ӧ����ϸ����
SpecifiedSupplierDataQueryVO  SupplierService::specifiedListSupplierData(const SpecifiedSupplierDataQuery& query)
{
	//�������ض���
	SpecifiedSupplierDataQueryVO data;
	//����DO���DAO���ѯ����
	SupplierDAO dao;
	SupplierDO result = dao.SpecifiedSelect(query.getID());
	data.setCode(result.getCode());
	data.setName(result.getName());
	data.setAux_Name(result.getAux_Name());
	data.setSupplier_Category(result.getSupplier_Category());
	data.setSupplier_Level(result.getSupplier_Level());
	data.setTax_Scale(result.getTax_Scale());
	data.setAlter_Suppliers(result.getAlter_Suppliers());
	data.setIs_Enabled(result.getIs_Enabled());
	data.setRemark(result.getRemark());
	data.setInvoice_Company(result.getInvoice_Company());
	data.setInvoice_Tax_Code(result.getInvoice_Tax_Code());
	data.setInvoice_Bank_Name(result.getInvoice_Bank_Name());
	data.setInvoice_Bank_Code(result.getInvoice_Bank_Code());
	data.setInvoice_Account(result.getInvoice_Account());
	data.setInvoice_Phone(result.getInvoice_Phone());
	data.setInvoice_Address(result.getInvoice_Address());
	data.setReceipt_Company(result.getReceipt_Company());
	data.setReceipt_Bank_Name(result.getReceipt_Bank_Name());
	data.setReceipt_Bank_Code(result.getReceipt_Bank_Code());
	data.setReceipt_Account(result.getReceipt_Account());
	data.setRecv_Name(result.getRecv_Name());
	data.setRecv_Phone(result.getRecv_Phone());
	data.setRecv_Fax(result.getRecv_Fax());
	data.setRecv_Email(result.getRecv_Email());
	data.setRecv_Address(result.getRecv_Address());
	data.setRecv_Postcode(result.getRecv_Postcode());
	data.setFinancial_Contacts(result.getFinancial_Contacts());
	data.setFinancial_Phone(result.getFinancial_Phone());
	data.setShort_Name(result.getShort_Name());
	data.setWebsite(result.getWebsite());
	data.setLegal_Person(result.getLegal_Person());
	data.setLegal_Person_Phone(result.getLegal_Person_Phone());
	data.setHeadQuarters(result.getHeadQuarters());
	data.setArea(result.getArea());
	data.setBiz_Area(result.getBiz_Area());
	data.setAddress(result.getAddress());
	data.setAttachment(result.getAttachment());
	data.setCreate_Time(result.getCreate_Time());
	data.setCreate_By(result.getCreate_By());
	data.setUpdate_Time(result.getUpdate_Time());
	data.setUpdate_By(result.getUpdate_By());
	
	return data;
}

// ��ӹ�Ӧ��
uint64_t SupplierService::addSupplierData(const AddSupplierDTO& dto,const PayloadDTO& payload)
{
	//��װ����
	SupplierDO data;
	data.setCode(dto.getCode());
	data.setName(dto.getName());
	data.setAux_Name(dto.getAux_Name());
	data.setSupplier_Category(dto.getSupplier_Category());
	data.setSupplier_Level(dto.getSupplier_Level());
	data.setTax_Scale(dto.getTax_Scale());
	data.setAlter_Suppliers(dto.getAlter_Suppliers());
	data.setIs_Enabled(dto.getIs_Enabled());
	data.setRemark(dto.getRemark());
	data.setInvoice_Company(dto.getInvoice_Company());
	data.setInvoice_Tax_Code(dto.getInvoice_Tax_Code());
	data.setInvoice_Bank_Name(dto.getInvoice_Bank_Name());
	data.setInvoice_Bank_Code(dto.getInvoice_Bank_Code());//��һ���ڵڶ��ִ����ʱ����©��
	data.setInvoice_Account(dto.getInvoice_Account());
	data.setInvoice_Phone(dto.getInvoice_Phone());
	data.setInvoice_Address(dto.getInvoice_Address());
	data.setReceipt_Company(dto.getReceipt_Company());
	data.setReceipt_Bank_Name(dto.getReceipt_Bank_Name());
	data.setReceipt_Bank_Code(dto.getReceipt_Bank_Code());
	data.setReceipt_Account(dto.getReceipt_Account());
	data.setRecv_Name(dto.getRecv_Name());
	data.setRecv_Phone(dto.getRecv_Phone());
	data.setRecv_Fax(dto.getRecv_Fax());
	data.setRecv_Email(dto.getRecv_Email());
	data.setRecv_Address(dto.getRecv_Address());
	data.setRecv_Postcode(dto.getRecv_Postcode());
	data.setFinancial_Contacts(dto.getFinancial_Contacts());
	data.setFinancial_Phone(dto.getFinancial_Phone());
	data.setShort_Name(dto.getShort_Name());
	data.setWebsite(dto.getWebsite());
	data.setLegal_Person(dto.getLegal_Person());
	data.setLegal_Person_Phone(dto.getLegal_Person_Phone());
	data.setHeadQuarters(dto.getHeadQuarters());
	data.setArea(dto.getArea());
	data.setBiz_Area(dto.getBiz_Area());
	data.setAddress(dto.getAddress());
	//data.setCreate_Time(dto.getCreate_Time());������������ʱ��ʹ��format����
	//data.setCreate_By(dto.getCreate_By());�������������û���Ϣʹ��payloaddto��
	//data.setUpdate_Time(dto.getUpdate_Time());
	//data.setUpdate_By(dto.getUpdate_By());
	//���ļ����ϴ�·��Ҳװ��DO����ģ�����У���ִ��SupplierInsert���з���
	string file_router;
	for (auto file_segment : dto.getFiles())
	{
		file_router = file_router + file_segment;
	}
	data.setAttachment(file_router);
	//��ѩ���㷨����id��ת��DO����
	SnowFlake sf(1, 1);
	uint64_t id_int = sf.nextId();
	//��intת��Ϊstring
	ostringstream stream;
	stream << id_int;  //nΪint����
	string id_string=stream.str();
	data.setID(id_string);
	//��format����create_time����ʱ���update_time�޸�ʱ��
	SimpleDateTimeFormat time;
	string create_time = time.format();
	string update_time = create_time;
	data.setCreate_Time(create_time);
	data.setUpdate_Time(update_time);
	//��PayloadDTO����Create_By��Update_By
	string create_by= payload.getUsername();
	string update_by = payload.getUsername();
	data.setCreate_By(create_by);
	data.setUpdate_By(update_by);
	//data����װ��42������
	//ִ���������
	SupplierDAO dao;
	return dao.SupplierInsert(data);
}

// �޸Ĺ�Ӧ��
uint64_t SupplierService::modifySupplierData(const ModifySupplierDTO& dto, const PayloadDTO& payload)
{
	//��װ����
	SupplierDO data;
	data.setCode(dto.getCode());
	data.setName(dto.getName());
	data.setAux_Name(dto.getAux_Name());
	data.setSupplier_Category(dto.getSupplier_Category());
	data.setSupplier_Level(dto.getSupplier_Level());
	data.setTax_Scale(dto.getTax_Scale());
	data.setAlter_Suppliers(dto.getAlter_Suppliers());
	//is_enableҪ����������Ϊ��ϣ������ʾ��ǰ�˵�ʱ��ֻ����0��1
	//if(dto.getIs_Enabled())
	data.setIs_Enabled(dto.getIs_Enabled());
	data.setRemark(dto.getRemark());
	data.setInvoice_Company(dto.getInvoice_Company());
	data.setInvoice_Tax_Code(dto.getInvoice_Tax_Code());
	data.setInvoice_Bank_Name(dto.getInvoice_Bank_Name());
	data.setInvoice_Account(dto.getInvoice_Account());
	data.setInvoice_Phone(dto.getInvoice_Phone());
	data.setInvoice_Address(dto.getInvoice_Address());
	data.setReceipt_Company(dto.getReceipt_Company());
	data.setReceipt_Bank_Name(dto.getReceipt_Bank_Name());
	data.setReceipt_Bank_Code(dto.getReceipt_Bank_Code());
	data.setReceipt_Account(dto.getReceipt_Account());
	data.setRecv_Name(dto.getRecv_Name());
	data.setRecv_Phone(dto.getRecv_Phone());
	data.setRecv_Fax(dto.getRecv_Fax());
	data.setRecv_Email(dto.getRecv_Email());
	data.setRecv_Address(dto.getRecv_Address());
	data.setRecv_Postcode(dto.getRecv_Postcode());
	data.setFinancial_Contacts(dto.getFinancial_Contacts());
	data.setFinancial_Phone(dto.getFinancial_Phone());
	data.setShort_Name(dto.getShort_Name());
	data.setWebsite(dto.getWebsite());
	data.setLegal_Person(dto.getLegal_Person());
	data.setLegal_Person_Phone(dto.getLegal_Person_Phone());
	data.setHeadQuarters(dto.getHeadQuarters());
	data.setArea(dto.getArea());
	data.setBiz_Area(dto.getBiz_Area());
	data.setAddress(dto.getAddress());
	//data.setCreate_Time(dto.getCreate_Time());������������ʱ��ʹ��format����
	//data.setCreate_By(dto.getCreate_By());�������������û���Ϣʹ��payloaddto��
	//data.setUpdate_Time(dto.getUpdate_Time());������������ʱ��ʹ��format����
	//data.setUpdate_By(dto.getUpdate_By());�������������û���Ϣʹ��payloaddto��
	data.setID(dto.getID());
	//��format����update_time�޸�ʱ��
	SimpleDateTimeFormat time;
	string update_time = time.format();
	data.setUpdate_Time(update_time);
	//��PayloadDTO����Update_By�޸���
	string update_by = payload.getUsername();
	data.setUpdate_By(update_by);
	//ִ�������޸�
	SupplierDAO dao;
	return dao.SupplierUpdateByCode(data) ;

}

//ɾ����Ӧ��
uint64_t SupplierService::deleteSupplierData(const DeleteSupplierDTO& dto)
{
	SupplierDAO dao;
	return dao.SupplierDeleteByCode(dto.getID()) == 1;
}