#ifndef _PUR_REQ_EXPORT_QUERY_
#define _PUR_REQ_EXPORT_QUERY_

#include "../../GlobalInclude.h"
//#include "../FileDTO.h"

/**
 * ������� ���� ���ݱ�ţ����õ��ݱ�Ų�ѯ�뵼���Ķ�����
 */

 //����
class PrePayExportQuery
{
	//���������Ϣ ���� ���õ��ݱ�Ų�ѯ�뵼���Ķ���
	CC_SYNTHESIZE(string, prepayId, PrepayId);

public:
	// ��JSONת������
	friend void from_json(const json& j, PrePayExportQuery& t);
};

#endif // !_PUR_REQ_EXPORT_QUERY_