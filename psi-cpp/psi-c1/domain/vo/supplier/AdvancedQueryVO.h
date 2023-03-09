#pragma once
#ifndef _ADVANCED_VO_
#define _ADVANCED_VO_

#include "../../GlobalInclude.h"

class AdvancedQueryVO 
{
	// ���
	CC_SYNTHESIZE(string, code, Code);
	// ����
	CC_SYNTHESIZE(string, name, Name);
	//������
	CC_SYNTHESIZE(string, aux_name, Aux_Name);
	//��Ӧ�̷��� 
	CC_SYNTHESIZE(string, supplier_category, Supplier_Category);
	//��Ӧ�̵ȼ� 
	CC_SYNTHESIZE(string, supplier_level, Supplier_Level);
	//��˰��ģ 
	CC_SYNTHESIZE(string, tax_scale, Tax_Scale);
	//�����ܹ�˾ 
	CC_SYNTHESIZE(string, headquarters, HeadQuarters);
	//�������� 
	CC_SYNTHESIZE(string, biz_area, Biz_Area);
	//ҵ������  
	CC_SYNTHESIZE(string, area, Area);
	//��Ӧ�̵�ַ 
	CC_SYNTHESIZE(string, address, Address);
	//��Ӧ����վ 
	CC_SYNTHESIZE(string, website, Website);
	//��ѡ��Ӧ��
	CC_SYNTHESIZE(string, alter_suppliers, Alter_Suppliers);
	//�Ƿ�����
	CC_SYNTHESIZE(int, is_enabled, Is_Enabled);
	//��ע
	CC_SYNTHESIZE(string, remark, Remark);
	//������
	CC_SYNTHESIZE(string, create_by, Create_By);
	//�޸�ʱ��
	CC_SYNTHESIZE(string, update_time,Update_Time);
	//�޸���
	CC_SYNTHESIZE(string, update_by, Update_By);

public:
	// ��JSONת������
	BIND_TO_JSON(AdvancedQueryVO, code,name, aux_name, supplier_category, supplier_level, tax_scale,
		headquarters, biz_area, area, address, website, alter_suppliers,
		is_enabled, remark, create_by, update_time, update_by);
};

#endif // !_SAMPLE_VO_

