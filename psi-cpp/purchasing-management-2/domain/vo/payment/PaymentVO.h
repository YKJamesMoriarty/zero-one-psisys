#pragma once


#ifndef _PAYMENTVO_H_
#define _PAYMENTVO_H_

class PaymentVO
{
	// ��������
	CC_SYNTHESIZE(std::string, billDate, BillDate);
	// ��������
	CC_SYNTHESIZE(std::string, subject, Subject);
	// ҵ��Ա
	CC_SYNTHESIZE(std::string, op, Op);
	// ҵ����
	CC_SYNTHESIZE(std::string, opDept, OpDept);
	// ��Ӧ��
	CC_SYNTHESIZE(std::string, supplierId, SupplierId);
	// �ɹ���ⵥ����
	CC_SYNTHESIZE(std::string,srcNo, SrcNo);

public:
	// ��JSONת������
	BIND_TO_JSON(PaymentVO, billDate, subject, op, opDept, supplierId, srcNo);

	PaymentVO() {
		//����
		billDate = u8"2023-2-16";
		subject = u8"����";
		op = u8"jeecg";
		opDept = u8"����F��˾";
		srcNo = u8"CGRK-230215-049";
	}


};




#endif // _PAYMENTVO_H_