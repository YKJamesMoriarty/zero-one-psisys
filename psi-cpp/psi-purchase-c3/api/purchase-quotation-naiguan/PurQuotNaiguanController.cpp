#include "stdafx.h"
#include "PurQuotNaiguanController.h"
#include "../../domain/vo/JsonVO.h"
#include "../../domain/vo/PageVO.h"
#include "../../domain/vo/purchase-quotation-naiguan/PurQuotNaiguanVO.h"
#include "../../domain/dto/purchase-quotation-naiguan/PurQuotNaiguanDTO.h"
#include "../../domain/query/purchase-quotation-naiguan/PurQuotNaiguanQUERY.h"
#include "../../service/purchase-quotation-naiguan/PurQuotNaiguanService.h"



//��ʾ��������
//��ͷ�ļ�����������������
//nlohmann::json execAddPurQuot(PurQuotNaiguanDTO dto);
nlohmann::json PurQuotNaiguanController::execAddPurQuot(PurQuotNaiguanQUERY query, PayloadDTO payload)
{
	//����һ��Service
	PurQuotNaiguanService service;
	//��ѯ����
	//PageVO<PurQuotVO> result = service.listAll(query);
	//δ����ʼ����ͨ��Ĭ�Ϲ��캯����result���г�ʼ������
	PageVO<AddPurQuotVO> result;
	//��Ӧ���
	return nlohmann::json(JsonVO<PageVO<AddPurQuotVO>>(result, RS_SUCCESS));
}

//��ʾ�޸ı���

nlohmann::json PurQuotNaiguanController::execModPurQuot(PurQuotNaiguanQUERY query, PayloadDTO payload)
{
	//����һ��Service
	PurQuotNaiguanService service;
	//��ѯ����
	//δ����ʼ����ͨ��Ĭ�Ϲ��캯����result���г�ʼ������
	PageVO<ModPurQuotVO> result;
	//��Ӧ���
	return nlohmann::json(JsonVO<PageVO<ModPurQuotVO>>(result, RS_SUCCESS));
}


//��ʾɾ������
nlohmann::json PurQuotNaiguanController::execDelPurQuot(PurQuotNaiguanQUERY query, PayloadDTO payload)
{
	//����һ��Service
	PurQuotNaiguanService service;
	//��ѯ����
	//PageVO<PurQuotVO> result = service.listAll(query);
	//δ����ʼ����ͨ��Ĭ�Ϲ��캯����result���г�ʼ������
	PageVO<DelPurQuotVO> result;
	//��Ӧ���
	return nlohmann::json(JsonVO<PageVO<DelPurQuotVO>>(result, RS_SUCCESS));
}


//�޸ı���״̬���رա����ϡ����رգ�
nlohmann::json PurQuotNaiguanController::execPurQuotModBillStatus(PurQuotNaiguanQUERY query, PayloadDTO payload)
{
	//����һ��Service
	PurQuotNaiguanService service;
	//��ѯ����
	//PageVO<PurQuotVO> result = service.listAll(query);
//δ����ʼ����ͨ��Ĭ�Ϲ��캯����result���г�ʼ������
	PageVO<PurQuotModBillStatusVO> result;
	//��Ӧ���
	return nlohmann::json(JsonVO<PageVO<PurQuotModBillStatusVO>>(result, RS_SUCCESS));
}



