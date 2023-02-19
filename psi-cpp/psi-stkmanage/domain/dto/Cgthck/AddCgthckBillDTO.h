#ifndef ADD_CGTHCK_BILL_DTO_
#define ADD_CGTHCK_BILL_DTO_

#include "../../GlobalInclude.h"
/**
* �ɹ��˻�����(����), ��Ӳɹ��˻����ⵥ���ݴ������
*/
class AddCgthckBillDTO
{
	// ��������
	CC_SYNTHESIZE(std::string, billDate, BillDate);
	// ��������
	CC_SYNTHESIZE(std::string, subject, Subject);
	// Դ��ҵ����Ա
	CC_SYNTHESIZE(std::string, srcOperator, SrcOperator);
	// ҵ����
	CC_SYNTHESIZE(std::string, opDept, OpDept);
	// ��Ӧ��
	CC_SYNTHESIZE(std::string, supplierId, SupplierId);
	// �ɹ���ⵥ
	CC_SYNTHESIZE(std::string, srcNo, SrcNo);
	// ���⾭��
	CC_SYNTHESIZE(std::string, handler, Handler);
	// ��������
	CC_SYNTHESIZE(double, settleQty, SettleQty);
	// ˰��
	CC_SYNTHESIZE(double, tax, Tax);
	// ������
	CC_SYNTHESIZE(double, settleAmt, SettleAmt);
	// �ɹ�����
	CC_SYNTHESIZE(double, cost, Cost);
	// ��ע
	CC_SYNTHESIZE(std::string, remark, Remark);
	// �Զ���1
	CC_SYNTHESIZE(std::string, custom1, Custom1);
	// �Զ���2
	CC_SYNTHESIZE(std::string, custom2, Custom2);
public:
	// ��JSONת������
	friend void from_json(const json& j, AddCgthckBillDTO& t) // NOLINT
	{
		BIND_FROM_TO_NORMAL(j, t, billDate);
		BIND_FROM_TO_NORMAL(j, t, subject);
		BIND_FROM_TO_NORMAL(j, t, srcOperator);
		BIND_FROM_TO_NORMAL(j, t, opDept);
		BIND_FROM_TO_NORMAL(j, t, supplierId);
		BIND_FROM_TO_NORMAL(j, t, srcNo);
		BIND_FROM_TO_NORMAL(j, t, handler);
		BIND_FROM_TO_D(j, t, settleQty);
		BIND_FROM_TO_D(j, t, tax);
		BIND_FROM_TO_D(j, t, settleAmt);
		BIND_FROM_TO_D(j, t, cost);
		BIND_FROM_TO_NORMAL(j, t, remark);
		BIND_FROM_TO_NORMAL(j, t, custom1);
		BIND_FROM_TO_NORMAL(j, t, custom2);
	}
};

#endif // !ADD_CGTHCK_BILL_DTO_
