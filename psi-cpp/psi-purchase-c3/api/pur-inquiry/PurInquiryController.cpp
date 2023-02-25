
#include "stdafx.h"
#include "PurInquiryController.h"
#include "../../service/pur-inquiry/PurInquiryService.h"
#include "api/pur-inquiry/ExecExport.h"


// ��ѯ�ɹ�ѯ�۵���ҳ�б�
JsonVO<PageVO<PurInquiryFindBillVO>> PurInquiryController::execQueryPurInquiryFindBill(const PurInquiryFindBillQuery& query, const PayloadDTO& payload)
{
	// ����һ��Service
	PurInquiryService service;
	// ��ѯ����
	PageVO<PurInquiryFindBillVO> result = service.listAll(query);
	// ��Ӧ���
	return JsonVO<PageVO<PurInquiryFindBillVO>>(result, RS_SUCCESS);
}

// �鿴ָ��ѯ�۵���ϸ��Ϣ
JsonVO<PurInquiryFindDetailBillVO> PurInquiryController::execQueryPurInquiryFindDetailBill(const PurInquiryFindDetailBillQuery& query, const PayloadDTO& payload)
{
	// ����һ��Service
	PurInquiryService service;
	//����У��
	PurInquiryFindDetailBillVO result;
	if (query.getBill_no() == "") return JsonVO<PurInquiryFindDetailBillVO>(result, RS_PARAMS_INVALID);
	//��ѯ����
	result = service.listPurInquiryFindDetailBill(query);
	// ��Ӧ���
	return JsonVO<PurInquiryFindDetailBillVO>(result, RS_SUCCESS);
}


//��Ӳɹ�ѯ��
JsonVO<uint64_t> PurInquiryController::execAddPurInquiry(const AddPurInquiryDTO& dto, const PayloadDTO& payload)
{
	JsonVO<uint64_t> result;
	PurInquiryService server;
	uint64_t id = server.saveData(dto);
	if (id > 0)
	{
		result.success(id);
	}
	else
	{
		result.fail(id);
	}


	return result;
}

//�޸Ĳɹ�ѯ��
JsonVO<std::string> PurInquiryController::execModifyPurInquiry(const AddPurInquiryDTO& dto, const PayloadDTO& payload)
{
	PurInquiryService service;
	JsonVO<std::string> result;
	if (service.updateData(dto)) {
		result.success(dto.getBill_no());
	}
	else
	{
		result.fail(dto.getBill_no());
	}
	return result;
}

//ɾ���ɹ�ѯ��
JsonVO<string> PurInquiryController::execRemovePurInquiry(const PurInquiryRemoveDTO& dto)
{
	JsonVO<string> result;
	PurInquiryService service;
	if (service.removeData(dto))
	{
		result.success(dto.getBill_no());
	}
	else
	{
		result.fail(dto.getBill_no());
	}


	return result;
}

//�޸ĵ��ݱ��
JsonVO<string> PurInquiryController::execModifyPurQuotModBillStatus(const PurInquiryModBillStatusDTO& dto)
{
	JsonVO<string> result;
	PurInquiryService service;
	if (service.updateDataByStatus(dto))
	{
		result.success(dto.getBill_no());
	}
	else
	{
		result.fail(dto.getBill_no());
	}

	return result;
}


// �����������ݱ��������ѯ�󣬷���xml���������ļ���
JsonVO<std::string> PurInquiryController::execPurInquiryExport(const PurInquiryExportQuery& query, const PayloadDTO& payload)
{
	// ����һ��Service
	PurInquiryService service;
	//��ѯ����
	JsonVO<std::string> result(u8"../../public/temporaryfile/testExportExcel.xlsx", RS_SUCCESS);
	// ����excel��
	vector<std::string> head = { u8"���ʽ", u8"�����ص�", u8"����ʱ��", u8"��ϵ��",u8"��ϵ�绰",\
		u8"fax", u8"email",u8"����", u8"�ο����", u8"��Ч�ı��۵���", u8"����", u8"������λ", u8"����",\
		u8"˰��%", u8"�ο���˰����", u8"�ο���˰���", u8"�Զ���1", u8"Դ����¼��", u8"��¼��", u8"�Զ���2",\
		u8"Դ����¼id", u8"Դ������", u8"��ע", u8"���ݱ��", u8"Դ��id", u8"�Ƿ���Ч", u8"����", u8"Դ��id",\
		u8"��������", u8"���ݽ׶�", u8"Դ����", u8"�Ƿ��Զ�����", u8"��ע", u8"����ʵ��id", u8"������", \
		u8"���ݱ��", u8"�Ƿ����", u8"Դ������", u8"�Ƶ�ʱ��", u8"��Чʱ��", u8"������" , u8"�޸���",\
		u8"�Ƶ�����", u8"�ѹر�", u8"�����������", u8"��������", u8"�Ƶ���", u8"�������" };
	PageVO<PurInquiryExportVO> res = service.PurInquiryExport(query);
	execexport(head, u8"�ɹ�ѯ�۵�", res);
	
	//��Ӧ���
	return JsonVO<std::string>(result);
}

// ���루�ϴ��ļ��󣬽�xml������json/cpp�������ݿ⣬�������ݣ�
JsonVO<PurInquiryIntoVO> PurInquiryController::execPurInquiryInto(const PurInquiryIntoDTO& dto)
{
	JsonVO<PurInquiryIntoVO> result;
	PurInquiryIntoVO vo;



	result.success(vo);
	return result;
}



