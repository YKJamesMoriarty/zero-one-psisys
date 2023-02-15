#ifndef _RTV_CONTROLLER_
#define _RTV_CONTROLLER_

#include "../psi-stkmanage/domain/vo/JsonVO.h"
#include "../psi-stkmanage/domain/vo/Message.h"
#include "../psi-stkmanage/domain/vo/PageVO.h"
#include "../psi-stkmanage/domain/query/Cgthck/DocListQuery.h"
#include "../psi-stkmanage/domain/dto/Cgthck/AddDocListDTO.h"
#include "../psi-stkmanage/domain/dto/Cgthck/ExportDocListDTO.h"
#include "../psi-stkmanage/domain/dto/Cgthck/ModifyDocListDTO.h"
#include "../psi-stkmanage/domain/dto/Cgthck/RemoveDocListDTO.h"
#include "../psi-stkmanage/domain/vo/Cgthck/ReturnToVendorVO.h"

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

