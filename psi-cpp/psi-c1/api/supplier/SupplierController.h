/*Author:Satan*/
#pragma once
#ifndef _SUPPLIER_CONTROLLER_
#define _SUPPLIER_CONTROLLER_

#include "../../domain/dto/supplier/AddSupplierDTO.h"
#include "../../domain/dto/supplier/DeleteSupplierDTO.h"
#include "../../domain/dto/supplier/ModifySupplierDTO.h"
#include "../../domain/dto/IDDTO.h"
#include "../../domain/dto/FileDTO.h"
#include "../../domain/vo/supplier/AdvancedQueryVO.h"
#include "../../domain/vo/supplier/SpecifiedSupplierDataQueryVO.h"
#include "../../domain/vo/PageVO.h"
#include "../../domain/vo/JsonVO.h"
#include "../../domain/query/PageQuery.h"
#include "../../domain/query/supplier/AdvancedQuery.h"
#include "../../domain/query/supplier/SpecifiedSupplierDataQuery.h"


class SupplierController
{
public:
	CREATE_API_FUN_JSON_PAYLOAD(advancedquerySupplier, execAdvancedQuerySupplier, AdvancedQuery);//AdvancedQuery�ǲ�ѯʱҪ����Ķ���
    /*��Ҳ�Ƕ��庯�����������涨��ĺ���querySample�����executeXXX�����ҹ涨�������ͣ�Ȼ��궨��ĺ���querySample��Router����*/
	CREATE_API_FUN_QUERY(specifiedquerySupplier, execSpecifiedQuerySupplier, SpecifiedSupplierDataQuery);//�����е��µı���
	//��ӹ�Ӧ��ʱ��Ҫ�ϴ��ļ�
	CREATE_API_FUN_BODY_PAYLOAD_FILE(addSupplier, execAddSupplier, AddSupplierDTO);
	//�޸Ĺ�Ӧ��ʱ��Ҫ�ϴ��ļ�
	CREATE_API_FUN_BODY_PAYLOAD_FILE(modifySupplier, execModifySupplier, ModifySupplierDTO);
	CREATE_API_FUN_BODY(deleteSupplier, execDeleteSupplier, DeleteSupplierDTO);

private:
	//�߼���ѯ����--��ҳ��ѯ
	JsonVO<PageVO<AdvancedQueryVO>> execAdvancedQuerySupplier(const AdvancedQuery& query, const PayloadDTO& payload);
	//��ѯָ����Ӧ������--���Ƿ�ҳ��ѯ
	JsonVO<SpecifiedSupplierDataQueryVO> execSpecifiedQuerySupplier(const SpecifiedSupplierDataQuery& query);//������һ��
	//��������
	JsonVO<string> execAddSupplier(const AddSupplierDTO& dto, const PayloadDTO& payload);
	//�޸�����
	JsonVO<string> execModifySupplier(const ModifySupplierDTO& dto, const PayloadDTO& payload);
	//ɾ������
	JsonVO<string> execDeleteSupplier(const DeleteSupplierDTO& dto);

};

#endif // _SUPPLIER_CONTROLLER_