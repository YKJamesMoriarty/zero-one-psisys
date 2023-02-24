#pragma once
#ifndef _PUR_QUOT_DETAIL_DTO_
#define _PUR_QUOT_DETAIL_DTO_

#include "stdafx.h"
#include "../../GlobalInclude.h"

class PurQuotDetailDTO
{
	//�����ֶ����ڣ�pur_quot_entry���е��ֶΣ�
	// ����id
	CC_SYNTHESIZE(string, id, Id);								//������Ĭ��Ϊ0�������ظ�
	//����
	CC_SYNTHESIZE(string, mid, Mid);							//���ݿ�ش�ֵ��ΨһԼ���������ظ�
	//���ݺ�
	CC_SYNTHESIZE(string, bill_no, Bill_no);
	//��¼��
	CC_SYNTHESIZE(int, entry_no, Entry_no);						//���ݿ�ش�ֵ����ΨһԼ���������ظ�

	//Դ������
	CC_SYNTHESIZE(string, src_bill_type, Src_bill_type);
	//srcbillid
	CC_SYNTHESIZE(string, src_bill_id, Src_bill_id);
	//Դ����¼id
	CC_SYNTHESIZE(string, src_entry_id, Src_entry_id);
	//Դ����¼��
	CC_SYNTHESIZE(string, src_no, Src_no);

	//����
	CC_SYNTHESIZE(string, material_id, Material_id);			//���ݿ�ش�ֵ
	//������λ
	CC_SYNTHESIZE(string, unit_id, Unit_id);					//���ݿ�ش�ֵ
	//����
	CC_SYNTHESIZE(double, qty, Qty);							//���ݿ�ش�ֵ
	//˰��%
	CC_SYNTHESIZE(double, tax_rate, Tax_rate);					//���ݿ�ش�ֵ

	//��˰����
	CC_SYNTHESIZE(double, price, Price);						//���ݿ�ش�ֵ
	//�ۿ���%
	CC_SYNTHESIZE(double, discount_rate, Discount_rate);
	//��˰���
	CC_SYNTHESIZE(double, amt, Amt);							//���ݿ�ش�ֵ
	//��ע
	CC_SYNTHESIZE(string, remark, Remark);

	//�Զ���1
	CC_SYNTHESIZE(string, custom1, Custom1);
	//�Զ���2
	CC_SYNTHESIZE(string, custom2, Custom2);
	//�汾
	CC_SYNTHESIZE(int, version, Version);

public:
	//����д�Ժ�ǰ��json���ݴ����������detail�����������ݣ����Զ��γ�����������
	//��JSONת������
	friend void from_json(const json& j, PurQuotDetailDTO& t) {

		BIND_FROM_TO_I(j, t, entry_no);
		BIND_FROM_TO_I(j, t, version);

		BIND_FROM_TO_D(j, t, qty);
		BIND_FROM_TO_D(j, t, amt);
		BIND_FROM_TO_D(j, t, tax_rate);
		BIND_FROM_TO_D(j, t, price);
		BIND_FROM_TO_D(j, t, discount_rate);

		//BIND_FROM_TO_NORMAL(j, t, mid);		����������գ���������װ���ݵ�ʱ�򣬽��������ƷŽ�ȥ
		BIND_FROM_TO_NORMAL(j, t, id);
		BIND_FROM_TO_NORMAL(j, t, bill_no);
		BIND_FROM_TO_NORMAL(j, t, src_bill_type);
		BIND_FROM_TO_NORMAL(j, t, src_bill_id);
		BIND_FROM_TO_NORMAL(j, t, src_entry_id);
		BIND_FROM_TO_NORMAL(j, t, src_no);
		BIND_FROM_TO_NORMAL(j, t, material_id);
		BIND_FROM_TO_NORMAL(j, t, unit_id);
		BIND_FROM_TO_NORMAL(j, t, remark);
		BIND_FROM_TO_NORMAL(j, t, custom1);
		BIND_FROM_TO_NORMAL(j, t, custom2);
	}
};

#endif // !_PUR_QUOT_DETAIL_DTO_