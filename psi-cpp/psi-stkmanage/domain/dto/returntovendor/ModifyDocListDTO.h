#ifndef _MODIFY_DOC_LIST_DTO_
#define _MODIFY_DOC_LIST_DTO_

#include "../../GlobalInclude.h"
/**
* �ɹ��˻�����(����), �޸Ĳɹ��˻����ⵥ���ݴ������
*/
class ModifyDocListDTO
{
	// �ɹ���ⵥ���
	CC_SYNTHESIZE(std::string, srcNo, SrcNo);
	// ��������
	CC_SYNTHESIZE(std::string, billDate, BillDate);
	// ��������
	CC_SYNTHESIZE(std::string, subject, Subject);
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
	friend void from_json(const json& j, ModifyDocListDTO& t); // NOLINT
};

#endif _MODIFY_DOC_LIST_DTO_ // !_MODIFY_DOC_LIST_DTO_
