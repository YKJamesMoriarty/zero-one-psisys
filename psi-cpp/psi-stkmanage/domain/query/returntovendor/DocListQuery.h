#ifndef _DOC_LIST_QUERY_
#define _DOC_LIST_QUERY_
#include "../PageQuery.h"

/**
* �ɹ��˻������ҳ��ѯ����
*/
class DocListQuery : public PageQuery
{
	// ���ݱ��
	CC_SYNTHESIZE(std::string, billNo, BillNo);
	// ��������
	CC_SYNTHESIZE(std::string, billDate, BillDate);
	// ��������
	CC_SYNTHESIZE(std::string, subject, Subject);
	// ��Ӧ��
	CC_SYNTHESIZE(std::string, supplierId, SupplierId);
	// ���ݽ׶�
	CC_SYNTHESIZE(std::string, billStage, BillStage);
	// �Ƿ���Ч
	CC_SYNTHESIZE(bool, isEff, IsEff);
	// �Ƿ�ر�
	CC_SYNTHESIZE(bool, isClosed, IsClosed);
	// �Ƿ�����
	CC_SYNTHESIZE(bool, isVoided, IsVoided);
public:
	// ��from_json
	friend void from_json(const json& j, DocListQuery& t);
};


#endif // !_DOC_LIST_QUERY_

