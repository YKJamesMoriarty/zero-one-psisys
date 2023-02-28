#include "stdafx.h"
#include "PurQuotController.h"
#include "../../service/pur-quot/PurQuotService.h"

#if 0
������־2023��2��18��15:34 : 30���ɹ�ʵ�ֽ������ֶΣ�id��bill_no��bill_date��qty���ϴ������ݿ�
Ԥ�ƿ������ܣ�
����Controller�У�����Ƿ��յ��������ݿ�ıش��ֶ�id��bill_no��bill_date
�ڼ���Ƿ��յ�ҵ��ıش��ֶ�....�����г��ش��ֶΣ�
�����������ϴ�����
����������ϸ�б�Ļ�ȡ���ϴ����������ϸ�б��Ƿ��бش��ֶ�
�����ɾ�����۹���
������޸ı���״̬���رա����ϡ����رգ�����
����Ҫ�ж����ұ���״̬�������Ƿ���Թر� / ���رգ�����������ݿ��л�ȡ����״̬���ݵĹ���������������ӿڸ�����ǰ����δ����޸ı���״̬���ֶΣ�
���ǿ������������䣬ͨ������Ǹ������������жϣ������ı仯�Ƿ����ҵ��
��APIPost����ע

��ֵ����
��ʵ����ϸ�б���ϴ�������������������PurQuotDetailDTO������service.cpp��dao.cpp����Ӵ�����ϸ�Ĵ��롪��2023��2��21��18:13 : 24�����
��ʵ�������������ϴ����ܡ���������Controller.cpp��ʵ��
��ʵ���ֶμ�鹦�ܡ���������������Controller.cpp��ʵ��
��ʵ���޸ı���״̬���ܡ�����������Controller.cpp, service.cpp, dao.cpp��ʵ�֡�������2023��2��21��21 : 15 : 40��ʵ��
��ʵ��ɾ�����ܡ�������������������Controller.cpp, service.cpp, dao.cpp��ʵ�֡�������2023��2��21��18 : 46 : 08��ʵ��
��APIPost����ע��������������������APIPost.exe

2023��2��20��14:52 : 45
����ע�⵽����api��domain / do��domain / vo�ж���user�ļ��У����ڸ��������ϴ���
����֮ǰֻע�⵽��domain / do������ݣ�AddDepartDTO��AddDepartMoreDTO
��������api��domain / vo��DepartController��AddDepartVO��AddDepartMoreVO�е�����
���ڣ�������Ҫ���ú��ⲿ�ֵ����ݣ��������ȥ���������۵Ĵ���



#endif

//��ӹ�Ӧ����
JsonVO<uint64_t> PurQuotController::execAddPurQuot(const AddPurQuotDTO& dto, const PayloadDTO& payload)
{
	//����У��û��
	JsonVO<uint64_t> result;
	PurQuotService service;
	uint64_t id = service.saveData(dto, payload);
	if (id > 0) {
		result.success(id);
	}
	else
	{
		result.fail(id);
	}
	return result;
}

//�޸Ĺ�Ӧ����
JsonVO<uint64_t> PurQuotController::execModPurQuot(const ModPurQuotDTO& dto, const PayloadDTO& payload)
{
	JsonVO<uint64_t> result;
	PurQuotService service;
	uint64_t id = service.updateData(dto, payload);
	if (id > 0) {
		result.success(id);
	}
	else
	{
		result.fail(id);
	}
	return result;
}

//ɾ����Ӧ����
JsonVO<uint64_t> PurQuotController::execDelPurQuot(const DelPurQuotDTO& dto)
{
	PurQuotService service;
	JsonVO<uint64_t> result;
	//ִ������ɾ��
	uint64_t id = service.removeData(dto);

	if (id > 0) {
		result.success(id);
	}
	else
	{
		result.fail(id);
	}
	//��Ӧ���
	return result;

}

//�޸ı���״̬������ʾ����δʵ��
JsonVO<uint64_t> PurQuotController::execPurQuotModBillStatus(const PurQuotModBillStatusDTO& dto, const PayloadDTO& payload)
{
	PurQuotService service;
	JsonVO<uint64_t> result;
	//ִ�б���״̬�޸�
	uint64_t id = service.UpdateDataBillStatus(dto);

	if (id > 0) {
		result.success(id);
	}
	else
	{
		result.fail(id);
	}
	//��Ӧ���
	return result;
}


//����
JsonVO<PurQuotExportVO> PurQuotController::execPurQuotExport(const PurQuotExportQuery& query, const PayloadDTO& payload)
{
	//��δ�������У��
	PurQuotService service;
	PurQuotExportVO result = service.listPurQuotExportVO(query);
	std::cout << result.getFile_name() << std::endl;
	return JsonVO<PurQuotExportVO>(result, RS_SUCCESS);
}

//����
uint64_t PurQuotController::execPurQuotInto(const PurQuotIntoDTO& dto)
{
	PurQuotService service;
	uint64_t result = service.updatePurQuotInto(dto);

	return result;
}

//��ѯ�����б�
JsonVO<PageVO<PurQuotFindBillVO>> PurQuotController::execQueryPurQuotFindBill(const PurQuotFindBillQuery& query, const PayloadDTO& payload) {
	//��δ��ʼ����У��

	//����һ��Service
	PurQuotService service;
	//�������ض���
	PageVO<PurQuotFindBillVO> result	= service.listPurQuotFindBillVO(query);
	//��Ӧ���
	return JsonVO<PageVO<PurQuotFindBillVO>>(result, RS_SUCCESS);
}



//��ѯָ�������б�
JsonVO<PurQuotFindDetailBillVO> PurQuotController::execQueryPurQuotFindDetailBill(const PurQuotFindDetailBillQuery& query, const PayloadDTO& payload) {
	PurQuotFindDetailBillVO result;
	//��ʱδ��������У��
	if(query.getBill_no() == "") return JsonVO<PurQuotFindDetailBillVO>(result, RS_PARAMS_INVALID);
	PurQuotService service;
	result = service.getPurQuotFindDetailBillVO(query);
	//��Ӧ���
	return JsonVO<PurQuotFindDetailBillVO>(result, RS_SUCCESS);
}

//ѯ�۵��б�
JsonVO<list<PurQuotListVO>> PurQuotController::execQueryPurQuotList(const PurQuotListQuery& query, const PayloadDTO& payload)
{
	//�������ض���
	list<PurQuotListVO> result;
	//����У��
	if(query.getBill_no() == "") return JsonVO<list<PurQuotListVO>>(result, RS_PARAMS_INVALID);

	//����У��ɹ�,���ض�Ӧ�Ķ���
	PurQuotService service;	
	result = service.listPurQuotListVO(query);
	return JsonVO<list<PurQuotListVO>>(result, RS_SUCCESS);
}
//ѯ�۵���¼�б�
JsonVO<list<PurQuotDividedListVO>> PurQuotController::execQueryPurQuotDividedList(const PurQuotDividedListQuery& query, const PayloadDTO& payload)
{
	//�������ض���
	list<PurQuotDividedListVO> result;
	//����У��
	if(query.getBill_no() == "") return JsonVO<list<PurQuotDividedListVO>>(result, RS_PARAMS_INVALID);

	//����У��ɹ�,���ض�Ӧ�Ķ���
	PurQuotService service;
	result = service.listPurQuotDividedListVO(query);
	return JsonVO<list<PurQuotDividedListVO>>(result, RS_SUCCESS);
}

