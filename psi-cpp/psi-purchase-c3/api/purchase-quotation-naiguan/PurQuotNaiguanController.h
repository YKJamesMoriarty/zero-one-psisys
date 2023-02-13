#ifndef _PUR_QUOT_NAIGUAN_CONTROLLER_
#define _PUR_QUOT_NAIGUAN_CONTROLLER_
//��Ϊ�ж����ͬʱдPUR_QUOT�Ĺ��ܣ���ˣ�Ϊ�˷�ֹ����ط��ظ������ȼ���NAIGUAN��������
//������������

#include "../../domain/query/purchase-quotation-naiguan/PurQuotNaiguanQUERY.h"
#include "../../domain/dto/purchase-quotation-naiguan/PurQuotNaiguanDTO.h"
#include "domain/dto/IDDTO.h"

class PurQuotNaiguanController
{
public:
	//��ӱ���
	//����ӱ����У����滹��һ����ѯ�ɹ�ѯ�۵���ѡ����ڲ�ѯ�ɹ�ѯ�۵�
	//��ϸ���ܻ���Ҫ����Ĵ���������һ�����ݣ����Ǻܶ���
	CREATE_API_FUN_BODY_PAYLOAD(addPurQuot, execAddPurQuot, PurQuotNaiguanDTO);
	//�޸ı���
	CREATE_API_FUN_BODY_PAYLOAD(modPurQuot, execModPurQuot, PurQuotNaiguanDTO);
	//ɾ������
	CREATE_API_FUN_BODY(delPurQuot, execDelPurQuot, PurQuotNaiguanDTO);
	//�޸ı���״̬���رա����ϡ����رգ�
	CREATE_API_FUN_BODY(purQuotModBillStatus, execPurQuotModBillStatus, PurQuotNaiguanDTO);


private:
	//��ʾ��������
	nlohmann::json execAddPurQuot(PurQuotNaiguanDTO dto);
	//��ʾ�޸ı���
	nlohmann::json execModPurQuot(PurQuotNaiguanDTO dto);
	//��ʾɾ������
	nlohmann::json execDelPurQuot(PurQuotNaiguanDTO dto);
	//�޸ı���״̬���رա����ϡ����رգ�
	nlohmann::json execPurQuotModBillStatus(PurQuotNaiguanDTO dto);
};

#endif // _PUI_QUOT_NAIGUAN_CONTROLLER_