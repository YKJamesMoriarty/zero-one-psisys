#pragma once
/*
 Copyright Zero One Star. All rights reserved.
 
 @Author: awei
 @Date: 2022/10/24 15:33:44
 
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
#ifndef _EXCELCOMPONENT_H_
#define _EXCELCOMPONENT_H_
#include <xlnt/xlnt.hpp>
#include <string>
#include <vector>
/**
 * Excel���
 */
class ExcelComponent
{
private:
	xlnt::workbook wb;
	xlnt::worksheet sheet;
	double rowHeight = 20;
	double colWidth = 20;
	//��ʼ��������
	void initWorkbook(const std::string& fileName = "");
	//����Sheet
	void createSheet(const std::string& sheetName);
public:
	//�����и�
	void setRowHeight(double rowHeight);
	//�����п�
	void setColWidth(double colWidth);
	//��ȡָ��ҳǩ���ݵ�����,ע���ļ�·��ʹ��/
	std::vector<std::vector<std::string>> readIntoVector(const std::string& fileName, const std::string& sheetName);
	//����ָ��ҳǩ���ݵ��ļ�,ע���ļ�·��ʹ��/
	void writeVectorToFile(const std::string& fileName, const std::string& sheetName, const std::vector<std::vector<std::string>>& data);


//--ʮ��
	// ��չ�����
	void clearWorkbook();
	// ����������
	void makeName(const std::string& title);
	// �ϲ���Ԫ��
	void mergeCell(std::string& sheetName, const xlnt::cell_reference& columnbegin, const xlnt::cell_reference& columnend);
	// ��Ԫ��ֵ
	void cellVaule(const std::string& sheetName, std::string& cell, std::string value);
};
#endif // _EXCELCOMPONENT_H_
