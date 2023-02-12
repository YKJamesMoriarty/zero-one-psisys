#ifndef _PUR_QUOT_CONTROLLER_
#define _PUR_QUOT_CONTROLLER_

#include "../../domain/query/purchase_quotation_naiguan/pur_quotQuery.h"
#include "../../domain/dto/purchase_quotation_naiguan/pur_quotDTO.h"
#include "domain/dto/IDDTO.h"

class pur_quotController
{
public:
	//��ӱ���
	//����ӱ����У����滹��һ����ѯ�ɹ�ѯ�۵���ѡ����ڲ�ѯ�ɹ�ѯ�۵�
	//��ϸ���ܻ���Ҫ����Ĵ���������һ�����ݣ����Ǻܶ���
	CREAT_API_FUN_BODY_PAYLOAD(addpur_quot, execAddpur_quot, pur_quotDTO);
	//�޸ı���
	CREATE_API_FUN_BODY_PAYLOAD(modifypur_quot, execModifypur_quot, pur_quotDTO);
	//ɾ������
	CREATE_API_FUN_BODY(removepur_quot, execRemovepur_quot, pur_quotDTO);
	CREATE_API_FUN_BODY(removeById, execRemoveById, ID);
	//�޸ı���״̬���رա����ϡ����رգ�
	CREATE_API_FUN_BODY(modifypur_quot_state, execModifypur_quot_state, pur_quotDTO);
	//���뱨��
	CREATE_API_FUN_JSON(jsonpur_quot_import, execJsonpur_quot_import, pur_quotDTO);
	//��������
	CREATE_API_FUN_QUERY(jsonpur_quot_export, execJsonpur_quott_export, pur_quottDTO);
	CREATE_API_FUN_QUERY1(jsonpur_quot_export1, execJsonpur_quott_export1, pur_quottDTO);
	CREATE_API_FUN_QUERY2(jsonpur_quot_export2, execJsonpur_quott_export2, pur_quottDTO);
	CREATE_API_FUN_QUERY3(jsonpur_quot_export3, execJsonpur_quott_export3, pur_quottDTO);


private:
	//��ʾ��������
	nlohmann::json execAddpur_quot(pur_quotDTO dto);
	//��ʾ�޸ı���
	nlohmann::json execModifypur_quot(pur_quotDTO dto);
	//��ʾɾ������
	nlohmann::json execRemovepur_quot(pur_quotDTO dto);
	nlohmann::json execRemoveById(ID id);
	//��ʾJSON����
	nlohmann::json execJsonpur_quot_import(pur_quot_importDTO dto);
	//��ʾJSON����
	nlohmann::json execJsonpur_quot_export(pur_quotDTO dto);
	nlohmann::json execJsonpur_quot_export1(pur_quotDTO dto);
	nlohmann::json execJsonpur_quot_export2(pur_quotDTO dto);
	nlohmann::json execJsonpur_quot_export3(pur_quotDTO dto);
};

#endif // _SAMPLE_CONTROLLER_