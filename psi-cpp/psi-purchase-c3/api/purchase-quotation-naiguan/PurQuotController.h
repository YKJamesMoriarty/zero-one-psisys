#ifndef _PUR_QUOT_CONTROLLER_
#define _PUR_QUOT_CONTROLLER_

#include "../../domain/dto/purchase-quotation-naiguan/PurQuotDTO.h"
#include "domain/dto/IDDTO.h"

class PurQuotController
{
public:
	//��ӱ���
	//����ӱ����У����滹��һ����ѯ�ɹ�ѯ�۵���ѡ����ڲ�ѯ�ɹ�ѯ�۵�
	//��ϸ���ܻ���Ҫ����Ĵ���������һ�����ݣ����Ǻܶ���
	CREATE_API_FUN_BODY_PAYLOAD(addPurQuot, execAddPurQuot, PurQuotDTO);
	//�޸ı���
	CREATE_API_FUN_BODY_PAYLOAD(modPurQuot, execModPurQuot, PurQuotDTO);
	//ɾ������
	CREATE_API_FUN_BODY(delPurQuot, execDelPurQuot, PurQuotDTO);
	//�޸ı���״̬���رա����ϡ����رգ�
	CREATE_API_FUN_BODY(purQuotModBillStatus, execPurQuotModBillStatus, PurQuotDTO);


private:
	//��ʾ��������
	nlohmann::json execAddPurQuot(PurQuotDTO dto);
	//��ʾ�޸ı���
	nlohmann::json execModPurQuot(PurQuotDTO dto);
	//��ʾɾ������
	nlohmann::json execDelPurQuot(PurQuotDTO dto);
	//�޸ı���״̬���رա����ϡ����رգ�
	nlohmann::json execPurQuotModBillStatus(PurQuotDTO dto);
};

#endif // _PUI_QUOT_CONTROLLER_