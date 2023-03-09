#include "stdafx.h"
#include "../../dao/bank-account/ExportAccountDAO.h"
#include "../../domain/do/bank-account/ExportAccountDO.h"
#include "ExportAccountService.h"
#include "ExcelComponent.h"
#include "CharsetConvertHepler.h"
#include "FastDfsClient.h"

/*
* �����˻�����
* @Author: Oxygen
* @Date: 2023/2/22 10:48:09
*/
JsonVO<std::string> ExportAccountService::listAll(const StringIDs& query)
{
	vector<vector<std::string>> data;
	data.push_back({ CharsetConvertHepler::ansiToUtf8("�����˻�����") });
	vector<std::string> header{
		CharsetConvertHepler::ansiToUtf8("�˺�"),
		CharsetConvertHepler::ansiToUtf8("�˻�����"),
		CharsetConvertHepler::ansiToUtf8("����"),
		CharsetConvertHepler::ansiToUtf8("��ʼ���"),
		CharsetConvertHepler::ansiToUtf8("�к�"),
		CharsetConvertHepler::ansiToUtf8("���е�ַ"),
		CharsetConvertHepler::ansiToUtf8("�˻�����Ա"),
		CharsetConvertHepler::ansiToUtf8("��ע"),
		CharsetConvertHepler::ansiToUtf8("�Ƿ�����"),
	};
	data.push_back(header);
	stringstream ss;

	ExportAccountDAO dao;
	size_t size = query.getId().size();
	//�������ID����ô�����ID������
	if (size != 0) {
		for (auto x : query.getId()) {
			//��ѯ
			ExportAccountDO obj;
			obj.setId(x);
			list<ExportAccountDO> reslist = dao.selectAccount(obj);
			ExportAccountDO res;
			if (!reslist.empty()) {
				res = reslist.front();
			}
			reslist.clear();
			vector<std::string> row;
			//��ӡEXCEL����
			row.push_back(res.getAccountNo());
			row.push_back(res.getName());
			row.push_back(res.getCurrency());
			row.push_back(to_string(res.getInit_bal()));
			row.push_back(res.getBankNo());
			row.push_back(res.getBankAddress());
			row.push_back(res.getManager());
			row.push_back(res.getRemark());
			int flag = res.getIsEnabled();
			if (flag == 1)	row.push_back(CharsetConvertHepler::ansiToUtf8("��"));
			else row.push_back(CharsetConvertHepler::ansiToUtf8("��"));
			data.push_back(row);
		}
	}
	else {
		ExportAccountDO obj;
		list<ExportAccountDO> reslist = dao.selectAllAccount(obj);
		vector<std::string> row;
		for (auto res : reslist) {
			//��ӡEXCEL����
			row.push_back(res.getAccountNo());
			row.push_back(res.getName());
			row.push_back(res.getCurrency());
			row.push_back(to_string(res.getInit_bal()));
			row.push_back(res.getBankNo());
			row.push_back(res.getBankAddress());
			row.push_back(res.getManager());
			row.push_back(res.getRemark());
			int flag = res.getIsEnabled();
			if (flag == 1)	row.push_back(CharsetConvertHepler::ansiToUtf8("��"));
			else row.push_back(CharsetConvertHepler::ansiToUtf8("��"));
			data.push_back(row);
			row.clear();
		}
	}

	//���屣������λ�ú�ҳǩ����
	std::string fileName = "../../public/excel/bankaccount.xlsx";
	std::string sheetName = CharsetConvertHepler::ansiToUtf8("bankaccount");

	//���浽�ļ�
	ExcelComponent excel;
	excel.writeVectorToFile(fileName, sheetName, data);

#ifdef LINUX
	//����ͻ��˶���
	FastDfsClient client("conf/client.conf", 3);
#else
	//����ͻ��˶���
	FastDfsClient client("1.15.240.108");
#endif

	//�ϴ���FastDFS
	std::string fieldName = client.uploadFile(fileName);
	if (!fieldName.empty())
		std::cout << "upload fieldname is : " << fieldName << std::endl;
	else
		std::cout << "upload fieldname false" << std::endl;

	JsonVO<std::string> res;
	res.success(fieldName);
	return res;
}
