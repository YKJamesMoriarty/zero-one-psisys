/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 11:13:11

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

	  https://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
*/
#include "stdafx.h"
#include "MaterialClassificationService.h"
#include "../../dao/MaterialClassification/MaterialClassificationDAO.h"
#include "../../../lib-common/include/SimpleDateTimeFormat.h"
#include "../../../lib-common/src/FastDfsClient.cpp"
#include "../../../lib-common/src/CharsetConvertHepler.cpp"
#include "../../lib-common/include/ExcelComponent.h"

//����vo����Ҫ�ָ�������

const int datacenterId = 1;
const int machineId = 2;
PageVO<MaterialClassificationBaseVO> MaterialClassificationService::listAll(const MaterialClassificationQuery& query)
{
	//�������ض���
	PageVO<MaterialClassificationBaseVO> pages;
	pages.setPageIndex(query.getPageIndex());
	pages.setPageSize(query.getPageSize());

	//��ѯ����������
	MaterialClassificationDO obj;
	MaterialClassificationDAO dao;
	obj.setName(query.getName());
	obj.setCode(query.getCode());
	//������ֺͱ����Ϊ�գ�����ʾ�������Ϸ�����ڵ�

	uint64_t count = dao.count(obj);
	if (count <= 0)
	{
		return pages;
	}
	//��ҳ��ѯ���� 
	pages.setTotal(count);
	pages.calcPages();

	
	if (query.getCode() != "" || query.getName() != "") {//�ж��ǲ����Ӽ�������Ѱ�Ҹ��ڵ�
		list<MaterialClassificationDO> father;
		if (query.getCode() != "") 
			father = dao.selectByCode(query.getCode());
		else if (query.getName() != "")
			father = dao.selectByName(query.getName());
		MaterialClassificationDO f;
		for (MaterialClassificationDO sub : father) {
			f.setId(sub.getId());
			f.setPid(sub.getPid());
		}	
		//�����������ı����������ʱ��ѭ��Ѱ�Ҹ��ڵ�
			while (f.getPid() != "0") {
				father = dao.selectById(f.getPid());
				for (MaterialClassificationDO sub : father) {
					f.setId(sub.getId());
					f.setPid(sub.getPid());
				}
			}
			//�ҵ����ڵ�
			list<MaterialClassificationBaseVO> vr;
			for (MaterialClassificationDO sub : father)
			{
				MaterialClassificationBaseVO vo;
				vo.setId(sub.getId());
				vo.setName(sub.getName());
				vo.setCode(sub.getCode());
				vo.setFullname(sub.getFullname());
				vo.setIsEnabled(sub.getIsEnabled());
				vo.setCreateTime(sub.getCreateTime());
				vo.setCreateBy(sub.getCreateBy());
				vo.setUpdateTime(sub.getUpdateTime());
				vo.setUpdateBy(sub.getUpdateBy());

				vr.push_back(vo);
			}
			pages.setRows(vr);
			return pages;
	}
	else if (query.getCode() == "" && query.getName() == "") {//ȫ����ʾȫ�����ڵ�

		list<MaterialClassificationDO> result = dao.selectWithPage( "0",query.getPageIndex(), query.getPageSize());
		list<MaterialClassificationBaseVO> vr;
		for (MaterialClassificationDO sub : result)
		{
			MaterialClassificationBaseVO vo;
			vo.setId(sub.getId());
			vo.setName(sub.getName());
			vo.setCode(sub.getCode());
			vo.setFullname(sub.getFullname());
			vo.setIsEnabled(sub.getIsEnabled());
			vo.setCreateTime(sub.getCreateTime());
			vo.setCreateBy(sub.getCreateBy());
			vo.setUpdateTime(sub.getUpdateTime());
			vo.setUpdateBy(sub.getUpdateBy());

			vr.push_back(vo);
		}
		pages.setRows(vr);
		return pages;
	}
}

//��ѯ�����б�
list<MaterialClassificationChildVO> MaterialClassificationService::listChildren(const MaterialClassificationQuery& query) {
	MaterialClassificationDO obj;
	obj.setCode(query.getCode());//�������
	MaterialClassificationDAO dao;
	list<MaterialClassificationDO> father = dao.selectByCode(obj.getCode());//���ص���list
	MaterialClassificationDO f;
	f.setId(father.front().getId());
	
	list<MaterialClassificationDO> result = dao.selectByPid(f.getId());
	list<MaterialClassificationChildVO> vr;
	for (MaterialClassificationDO sub : result)
	{
		MaterialClassificationChildVO vo;
		vo.setId(sub.getId());
		vo.setName(sub.getName());
		vo.setCode(sub.getCode());
		vo.setFullname(sub.getFullname());
		vo.setIsEnabled(sub.getIsEnabled());
		vo.setCreateTime(sub.getCreateTime());
		vo.setCreateBy(sub.getCreateBy());
		vo.setUpdateTime(sub.getUpdateTime());
		vo.setUpdateBy(sub.getUpdateBy());

		vr.push_back(vo);

	}

	return vr;

}


list<MaterialClassificationDetailVO> MaterialClassificationService::listDetail(const MaterialClassificationQuery& query) {
	MaterialClassificationDO obj;
	obj.setCode(query.getCode());
	MaterialClassificationDAO dao;
	list<MaterialClassificationDO> result = dao.selectByCode(obj.getCode());
	list<MaterialClassificationDetailVO> vr;
	for (MaterialClassificationDO sub : result)
	{
		MaterialClassificationDetailVO vo;
		vo.setId(sub.getId());
		vo.setPid(sub.getPid());
		vo.setHasChild(sub.getHasChild());
		vo.setName(sub.getName());
		vo.setCode(sub.getCode());
		vo.setFullname(sub.getFullname());
		vo.setIsEnabled(sub.getIsEnabled());
		vo.setCreateTime(sub.getCreateTime());
		vo.setCreateBy(sub.getCreateBy());
		vo.setUpdateTime(sub.getUpdateTime());
		vo.setUpdateBy(sub.getUpdateBy());

		vr.push_back(vo);
	}

	return  vr;
}

int MaterialClassificationService::saveData(const MaterialClassificationDTO& dto, const string& userName)
{
	//��������Ӧ�ò��ù��޸���ص���Ϣ

	//��װ����
	MaterialClassificationDO data;
	//Ӧ��������������id
	SnowFlake sf(datacenterId, machineId);
	data.setId(to_string(sf.nextId()));

	//����¼���ʱ��Ҫ���pid�����pid�ĸ���һ��ʼû���¼�����Ҫ�޸ĸ����has_child
	data.setPid(dto.getPid()==""? "0":dto.getPid());
	data.setHasChild(dto.getHasChild()==""? "0":dto.getHasChild());
	data.setName(dto.getName());
	data.setCode(dto.getCode());
	data.setFullname(dto.getFullname());
	data.setIsEnabled(dto.getIsEnabled());
	data.setCreateBy(userName);

	//����ʱ��
	SimpleDateTimeFormat sdt;
	
	string nowTime  = sdt.format();//ʹ�ð�ΰ���Ĺ�����
	//time_t nowtime;
	//time(&nowtime); //��ȡ1900��1��1��0��0��0�뵽���ھ���������
	//tm p;
	//localtime_s(&p,&nowtime); //������ת��Ϊ����ʱ��,���1900����,��Ҫ+1900,��Ϊ0-11,����Ҫ+1
	////printf("%04d:%02d:%02d %02d:%02d:%02d\n", p.tm_year + 1900, p.tm_mon + 1, p.tm_mday,p.tm_hour,p.tm_min,p.tm_sec);
	//string nowTime = to_string(p.tm_year+1900) + "-" +to_string(p.tm_mon+1)+"-"+to_string(p.tm_mday) + " " + to_string(p.tm_hour)+":"+to_string(p.tm_min) +":"+to_string(p.tm_sec);

	data.setCreateTime(nowTime);
	data.setVersion(dto.getVersion());
	//ִ���������
	MaterialClassificationDAO dao;

	int modify = 1;
	if (dto.getPid() != "") {//�и��ڵ�
		list<MaterialClassificationDO> father = dao.selectById(dto.getPid());
		MaterialClassificationDO f;
		for (MaterialClassificationDO sub : father) {
			f.setHasChild(sub.getHasChild());
		}
		if (f.getHasChild() == "0")
			modify = dao.updateHasChildById(dto.getPid(), "1");//ͨ��id�޸ĸ��ڵ��has_child
	}

	return (modify * dao.insert(data))==1;
}

int MaterialClassificationService::updateData(const MaterialClassificationDTO& dto, const PayloadDTO& payload)
{

	//�޸�����Ҫ���õ�id,�޸�����Ӧ�ò��ùܴ�����ص���Ϣ

	//��װ��������
	MaterialClassificationDO data;
	data.setId(dto.getId());
	data.setPid(dto.getPid());
	data.setHasChild(dto.getHasChild());
	data.setName(dto.getName());
	data.setCode(dto.getCode());
	data.setFullname(dto.getFullname());
	data.setIsEnabled(dto.getIsEnabled());


	SimpleDateTimeFormat sdt;
	string nowTime = sdt.format();
	//time_t nowtime;
	//time(&nowtime); //��ȡ1900��1��1��0��0��0�뵽���ھ���������
	//tm p;
	//localtime_s(&p, &nowtime); //������ת��Ϊ����ʱ��,���1900����,��Ҫ+1900,��Ϊ0-11,����Ҫ+1
	//string nowTime = to_string(p.tm_year + 1900) + "-" + to_string(p.tm_mon + 1) + "-" + to_string(p.tm_mday) + " " + to_string(p.tm_hour) + ":" + to_string(p.tm_min) + ":" + to_string(p.tm_sec);

	data.setUpdateBy(payload.getUsername());
	data.setUpdateTime(nowTime);
	data.setVersion(dto.getVersion());
	//ִ�������޸�
	MaterialClassificationDAO dao;
	return dao.update(data) == 1;
}

//ɾ���Ӽ��ڵ�ĺ���
void removeNode(const MaterialClassificationDO& nodeChild) {
	MaterialClassificationDAO dao;
	if (nodeChild.getHasChild() == "0") {
		dao.deleteById(nodeChild.getId());
		return;
	}
	list<MaterialClassificationDO> children = dao.selectByPid(nodeChild.getId());
	for (MaterialClassificationDO node : children) {
		removeNode(node);
	}
	return;
}

int MaterialClassificationService::removeData(const MaterialClassificationDTO& dto)
{
	MaterialClassificationDAO dao;
	list<MaterialClassificationDO> info = dao.selectById(dto.getId());//��ȡ��ǰ�ڵ����Ϣ
	MaterialClassificationDO bro ;
	for (MaterialClassificationDO node : info) {
		bro.setPid(node.getPid());
		bro.setHasChild(node.getHasChild());
	}
		
	int d = 1;
	if (bro.getHasChild() == "1"){//������Ӽ��ڵ���ɾ��
		for (MaterialClassificationDO node : info) {
			bro.setPid(node.getPid());
			if (node.getHasChild() == "1") {
				removeNode(node);
			}
		}
		d = dao.deleteByPid(dto.getId());
	}
	int myself = dao.deleteById(dto.getId());//ɾ������

	//����պ��丸�ڵ�û�����ӽڵ㣬��Ҫ�޸ĸ��ڵ��has_child
	
	list<MaterialClassificationDO> brother = dao.selectByPid(bro.getPid());

	int tag = 0;
	for (MaterialClassificationDO sub : brother) {
		if (sub.getPid() != "0") {//���ֵ�,���øĸ��ڵ�
			tag++;
			break;
		}
	}
	
	int father = 1;
	if (tag == 0) {//û���ֵܣ�Ҫ�޸ĸ��ڵ�
		int father = dao.updateHasChildById(bro.getPid(),"0");
	}
	return (myself*d*father) == 1;
}


//��������
int MaterialClassificationService::importData(const MaterialClassificationDTO& dto) {
	MaterialClassificationDAO dao;
	ExcelComponent excel;
	list<MaterialClassificationDTO> Dto;
	//��������ϴ��ļ�·���б�
	for (auto file : dto.getFiles()) {
		string sheetName = CharsetConvertHepler::ansiToUtf8("���Ϸ���");
		auto readData = excel.readIntoVector(file, sheetName);
		for (auto data : readData) {
			MaterialClassificationDTO saveDto;
			saveDto.setPid(CharsetConvertHepler::ansiToUtf8(data[0]));
			saveDto.setHasChild(CharsetConvertHepler::ansiToUtf8(data[1])=="��"? "1":"0");
			saveDto.setName(CharsetConvertHepler::ansiToUtf8(data[2]));
			saveDto.setCode(CharsetConvertHepler::ansiToUtf8(data[3]));
			saveDto.setFullname(CharsetConvertHepler::ansiToUtf8(data[4]));
			saveDto.setIsEnabled(CharsetConvertHepler::ansiToUtf8(data[5])=="��"? 1:0);

			Dto.push_back(saveDto);
		}

	} 

	int result = 1;
	for (MaterialClassificationDTO data:Dto) //�����ݴ������ݿ�
		result = saveData(data,"����Ա");			//��ʱ����֪����ô�Ѵ����˵���Ϣ�����ȥ����������ʽ�͵����ļ���ʽһ�����Ϳ��Խ�ȡ����

	return result;
}

//��������
string  MaterialClassificationService::exportData(const StringIDs& IDS,const PayloadDTO& payload) {
	list<string> ids = IDS.getId();
	MaterialClassificationDAO dao;
	list<MaterialClassificationDO> dos;
	//��ȡÿ��id����Ϣ
	for (string id : ids) {
		dos.push_back((dao.selectById(id)).front());
	}
	//װ�����
	string head = CharsetConvertHepler::ansiToUtf8("���Ϸ��౨��");	//����
	string exporter = payload.getUsername();						//������
	//��������ôװ��������

	vector<vector<string>> data{ vector<string>{					//������
		CharsetConvertHepler::ansiToUtf8("���ڵ�"),
			CharsetConvertHepler::ansiToUtf8("�Ƿ����ӽڵ�"),
			CharsetConvertHepler::ansiToUtf8("����"),
			CharsetConvertHepler::ansiToUtf8("����"),
			CharsetConvertHepler::ansiToUtf8("ȫ��"),
			CharsetConvertHepler::ansiToUtf8("�Ƿ�����")
	}};

	//װ�������
	for (MaterialClassificationDO sub:dos) {
		vector<string> rows;
		list<MaterialClassificationDO> father = dao.selectByPid(sub.getPid());
		string fName = father.front().getName();
		rows.push_back(CharsetConvertHepler::ansiToUtf8(fName));
		rows.push_back(CharsetConvertHepler::ansiToUtf8(sub.getHasChild()=="1" ? "��":"��"));
		rows.push_back(CharsetConvertHepler::ansiToUtf8(sub.getName()));
		rows.push_back(CharsetConvertHepler::ansiToUtf8(sub.getCode()));
		rows.push_back(CharsetConvertHepler::ansiToUtf8(sub.getFullname()));
		rows.push_back(CharsetConvertHepler::ansiToUtf8(sub.getIsEnabled() ==1 ? "��":"��"));

		data.push_back(rows);
	}

	// ���屣������λ�ú�ҳǩ����
	std::string fileName = CharsetConvertHepler::ansiToUtf8("../../public/excel/test.xlsx");
	std::string sheetName = CharsetConvertHepler::ansiToUtf8("���Ϸ���");//excel��sheetName
	//���浽�ļ�
	ExcelComponent excel;
	excel.writeVectorToFile(fileName, sheetName, data);
	// �ϴ����ļ�������
	/*FastDfsClient client("1.15.240.108");
	fileName = client.uploadFile(fileName)*/;

	return fileName;
}


