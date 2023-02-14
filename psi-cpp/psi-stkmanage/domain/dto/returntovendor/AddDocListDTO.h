#ifndef _ADD_DOC_LIST_DTO_
#define _ADD_DOC_LIST_DTO_

#include "../../GlobalInclude.h"
/**
* �ɹ��˻�����(����), ��Ӳɹ��˻����ⵥ���ݴ������
*/
class AddDocListDTO
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
	friend void from_json(const json& j, AddDocListDTO& t); // NOLINT
};

#endif _ADD_DOC_LIST_DTO_ // !_ADD_DOC_LIST_DTO_
