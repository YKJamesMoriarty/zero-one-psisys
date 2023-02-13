#ifndef _DOC_LIST_QUERY_
#define _DOC_LIST_QUERY_
#include "../PageQuery.h"

/**
* �ɹ��˻������ҳ��ѯ����
*/
class DocListQuery : public PageQuery
{
	// ���ݱ��
	CC_SYNTHESIZE(std::string, bill_no, BillNo);
	// ��������
	CC_SYNTHESIZE(std::string, bill_date, BillDate);
	// ��������
	CC_SYNTHESIZE(std::string, subject, Subject);
	// ��Ӧ��
	CC_SYNTHESIZE(std::string, supplier_id, SupplierId);
	// ���ݽ׶�
	CC_SYNTHESIZE(std::string, bill_stage, BillStage);
	// �Ƿ���Ч
	CC_SYNTHESIZE(bool, is_eff, IsEff);
	// �Ƿ�ر�
	CC_SYNTHESIZE(bool, is_closed, IsClosed);
	// �Ƿ�����
	CC_SYNTHESIZE(bool, is_voided, IsVoided);
public:
	// ��from_json
	friend void from_json(const json& j, DocListQuery& t);
};


#endif // !_DOC_LIST_QUERY_

