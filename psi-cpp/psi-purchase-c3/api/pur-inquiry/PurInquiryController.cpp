#include "stdafx.h"
#include "PurInquiryController.h"

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

//�ļ�����
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

