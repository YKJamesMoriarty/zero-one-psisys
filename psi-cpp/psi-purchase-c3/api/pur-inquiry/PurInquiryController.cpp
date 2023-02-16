

#include "stdafx.h"
#include "PurInquiryController.h"
#include "../../service/pur-inquiry/PurInquiryService.h"


//��ѯ�ɹ�ѯ�۵���ҳ�б�
JsonVO<PageVO<PurInquiryFindBillVO>> PurInquiryController::execQueryPurInquiryFindBill(const PurInquiryFindBillQuery& query, const PayloadDTO& payload)
{
	//����Apipost
	PurInquiryFindBillVO test;
	list<PurInquiryFindBillVO> ls; 
	ls.push_back(test);
	PageVO<PurInquiryFindBillVO> result(1, 2, 0, 0, ls);
	//PageVO<PurInquiryFindBillVO> result;

	return JsonVO<PageVO<PurInquiryFindBillVO>>(result, RS_SUCCESS);
}

//�鿴ָ��ѯ�۵���ϸ��Ϣ
JsonVO<PurInquiryFindDetailBillVO> PurInquiryController::execQueryPurInquiryFindDetailBill(const PurInquiryFindDetailBillQuery& query, const PayloadDTO& payload)
{
	PurInquiryFindDetailBillVO result;
	//��Ӧ���
	return JsonVO<PurInquiryFindDetailBillVO>(result, RS_SUCCESS);
}

//��Ӳɹ�ѯ��
JsonVO<AddPurInquiryVO> PurInquiryController::execAddPurInquiry(const AddPurInquiryDTO& dto)
{
	JsonVO<AddPurInquiryVO> result;
	AddPurInquiryVO vo;


	result.success(vo);
	return result;
}

//�޸Ĳɹ�ѯ��
JsonVO<AddPurInquiryVO> PurInquiryController::execModifyPurInquiry(const AddPurInquiryDTO& dto)
{
	JsonVO<AddPurInquiryVO> result;
	AddPurInquiryVO vo;


	


	result.success(vo);
	return result;
}

//ɾ���ɹ�ѯ��
JsonVO<uint64_t> PurInquiryController::execRemovePurInquiry(const PurInquiryRemoveDTO& dto)
{
	JsonVO<uint64_t> result;




	return result;
}

//�޸ĵ��ݱ��
JsonVO<uint64_t> PurInquiryController::execModifyPurQuotModBillStatus(const PurInquiryModBillStatusDTO& dto)
{
	JsonVO<uint64_t> result;




	return result;
}

//�ļ��ϴ�
JsonVO<PurInquiryIntoVO> PurInquiryController::execPurInquiryInto(const PurInquiryIntoDTO& dto)
{
	JsonVO<PurInquiryIntoVO> result;
	PurInquiryIntoVO vo;



	result.success(vo);
	return result;
}

//�ļ�����
JsonVO<std::string> PurInquiryController::execPurInquiryExport(const PurInquiryExportQuery& query)
{

	JsonVO<std::string> result;
	string fileName = "d//f//a.txt";


	result.success(fileName);
	return result;
}

