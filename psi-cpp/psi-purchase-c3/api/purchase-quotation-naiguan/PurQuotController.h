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
	JsonVO<uint64_t> execAddPurQuot(const PurQuotDTO& dto);
	//��ʾ�޸ı���
	JsonVO<uint64_t> execModPurQuot(const PurQuotDTO& dto);
	//��ʾɾ������
	JsonVO<uint64_t> execDelPurQuot(const PurQuotDTO& dto);
	//�޸ı���״̬���رա����ϡ����رգ�
	JsonVO<uint64_t> execPurQuotModBillStatus(const PurQuotDTO& dto);
};

#endif // _PUI_QUOT_CONTROLLER_