#ifndef _MODIFY_CGTHCK_BILL_DTO_
#define _MODIFY_CGTHCK_BILL_DTO_

#include "../../GlobalInclude.h"
/**
* �ɹ��˻�����(����), �޸Ĳɹ��˻����ⵥ(����)���ݴ������
*/
class ModifyCgthckBillDTO
{
	// ���ݱ��
	CC_SYNTHESIZE(std::string, billNo, BillNo);
	// ���ݽ׶�
	CC_SYNTHESIZE(std::string, billStage, BillStage);
	// �����������
	CC_SYNTHESIZE(std::string, approvalResultType, ApprovalResultType);
	// �������
	CC_SYNTHESIZE(std::string, approvalRemark, ApprovalRemark);
	// ��ע
	CC_SYNTHESIZE(std::string, remark, Remark);
public:
	friend void from_json(const json& j, ModifyCgthckBillDTO& t)
	{
		BIND_FROM_TO_NORMAL(j, t, billNo);
		BIND_FROM_TO_NORMAL(j, t, billStage);
		BIND_FROM_TO_NORMAL(j, t, approvalResultType);
		BIND_FROM_TO_NORMAL(j, t, approvalRemark);
	}
};

#endif  // !_MODIFY_DOC_LIST_DTO_
