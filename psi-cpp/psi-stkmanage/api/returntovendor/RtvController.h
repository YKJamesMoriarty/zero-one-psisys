#ifndef _RTV_CONTROLLER_
#define _RTV_CONTROLLER_

#include "../psi-stkmanage/domain/vo/JsonVO.h"
#include "../psi-stkmanage/domain/vo/Message.h"
#include "../psi-stkmanage/domain/vo/PageVO.h"
#include "../psi-stkmanage/domain/query/returntovendor/DocListQuery.h"
#include "../psi-stkmanage/domain/dto/returntovendor/AddDocListDTO.h"
#include "../psi-stkmanage/domain/dto/returntovendor/ExportDocListDTO.h"
#include "../psi-stkmanage/domain/dto/returntovendor/ModifyDocListDTO.h"
#include "../psi-stkmanage/domain/dto/returntovendor/RemoveDocListDTO.h"
#include "../psi-stkmanage/domain/vo/returntovendor/ReturnToVendorVO.h"

/**
* ������, �ɹ��˻�����ӿڵ�ʹ��
*/
class RtvController
{
public:
	CREATE_API_FUN_QUERY(rtvQuery, execRtvQuery, DocListQuery);
	CREATE_API_FUN_QUERY(rtvEntryQuery, execRtvEntryQuery, DocListQuery);
private:
	// ���Բ�ѯ����
	JsonVO<PageVO<RtvShowVO>> execRtvQuery(const DocListQuery& query);
	JsonVO<PageVO<RtvCheckVO>> execRtvEntryQuery(const DocListQuery& query);
	// �����������
	// �����޸�����
	// ����ɾ������
	// �����ύJSON
	// �����ļ��ϴ�
};


#endif // !_RTV_CONTROLLER_

