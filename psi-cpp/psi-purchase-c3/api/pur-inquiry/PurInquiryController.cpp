
#include "stdafx.h"
#include "PurInquiryController.h"
#include "../../service/pur-inquiry/PurInquiryService.h"
#include "api/pur-inquiry/ExecExport.h"
#include "CharsetConvertHepler.h"


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
	uint64_t id = server.saveData(dto, payload);
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
	if (service.updateData(dto, payload)) {
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
JsonVO<std::string> PurInquiryController::execQueryPurInquiryExport(const PurInquiryExportQuery& query, const PayloadDTO& payload)
{
	// �������ض�������
	JsonVO<std::string> result;
	// ����exlce��ͷ����
	vector<std::string> head = {
		CharsetConvertHepler::ansiToUtf8("���ݱ��"),CharsetConvertHepler::ansiToUtf8("��������"), \
		CharsetConvertHepler::ansiToUtf8("���ݽ׶�"), CharsetConvertHepler::ansiToUtf8("��������"),\
		CharsetConvertHepler::ansiToUtf8("Դ����"), CharsetConvertHepler::ansiToUtf8("Դ��id"),\
		CharsetConvertHepler::ansiToUtf8("Դ������"),CharsetConvertHepler::ansiToUtf8("���ʽ"),\
		CharsetConvertHepler::ansiToUtf8("�����ص�"), CharsetConvertHepler::ansiToUtf8("����ʱ��"),\
		CharsetConvertHepler::ansiToUtf8("��ϵ��"), CharsetConvertHepler::ansiToUtf8("��ϵ�绰"),\
		CharsetConvertHepler::ansiToUtf8("fax"), CharsetConvertHepler::ansiToUtf8("email"),\
		CharsetConvertHepler::ansiToUtf8("����"), CharsetConvertHepler::ansiToUtf8("�ο����"),\
		CharsetConvertHepler::ansiToUtf8("��Ч�ı��۵���"), CharsetConvertHepler::ansiToUtf8("��ע"),
		CharsetConvertHepler::ansiToUtf8("�Ƿ���Ч"), CharsetConvertHepler::ansiToUtf8("��Чʱ��"),\
		CharsetConvertHepler::ansiToUtf8("�ѹر�"), CharsetConvertHepler::ansiToUtf8("������"),\
		CharsetConvertHepler::ansiToUtf8("�Ƿ��Զ�����"), CharsetConvertHepler::ansiToUtf8("�Ƿ����"),\
		CharsetConvertHepler::ansiToUtf8("�Ƶ���"), CharsetConvertHepler::ansiToUtf8("�Ƶ�ʱ��"),\
		CharsetConvertHepler::ansiToUtf8("�Ƶ�����"), CharsetConvertHepler::ansiToUtf8("�޸���"),\
		CharsetConvertHepler::ansiToUtf8("����"), CharsetConvertHepler::ansiToUtf8("����ʵ��id"),\
		CharsetConvertHepler::ansiToUtf8("������"), CharsetConvertHepler::ansiToUtf8("�����������"),\
		CharsetConvertHepler::ansiToUtf8("�������"), CharsetConvertHepler::ansiToUtf8("���ݱ��"),\
		CharsetConvertHepler::ansiToUtf8("��¼��"), CharsetConvertHepler::ansiToUtf8("Դ��id"),\
		CharsetConvertHepler::ansiToUtf8("Դ����¼��"), CharsetConvertHepler::ansiToUtf8("Դ����¼id"),\
		CharsetConvertHepler::ansiToUtf8("Դ������"), CharsetConvertHepler::ansiToUtf8("����"),\
		CharsetConvertHepler::ansiToUtf8("������λ"), CharsetConvertHepler::ansiToUtf8("����"),\
		CharsetConvertHepler::ansiToUtf8("˰��%"), CharsetConvertHepler::ansiToUtf8("�ο���˰����"),\
		CharsetConvertHepler::ansiToUtf8("�ο���˰���"), CharsetConvertHepler::ansiToUtf8("�Զ���1"),\
		CharsetConvertHepler::ansiToUtf8("�Զ���2"), CharsetConvertHepler::ansiToUtf8("��ע")};
	// ��ѯҪ�����ĵ��ݱ���б�
	list<std::string> exres = query.getBill_no_list();
	// ����excel��������fastDfs��ַ
	std::string url = execexport(head, CharsetConvertHepler::ansiToUtf8("�ɹ�ѯ�۵�"), exres);
	if (url == "")
		result.fail("");
	else 
		result.success(url);
	//��Ӧ���
	return JsonVO<std::string>(result);
}

// ���루�ϴ��ļ��󣬽�xml������json/cpp�������ݿ⣬�������ݣ�
JsonVO<uint64_t> PurInquiryController::execaddPurInquiryInto(const PurInquiryIntoDTO& dto, const PayloadDTO& payload)
{
	JsonVO<uint64_t> result;
	//�����ļ����ҽ���execl����
	PurInquiryService service;
	uint64_t ret = 1;
	for (string file : dto.getFiles()) {
		ret = service.PurInquiryInto(file, payload);
		if (ret == 0)
		{
			result.fail(9995);
			break;
		}
	}
	//��Ӧ���
	if (ret)
	{
		result.success(100);
	}
	return result;
}



