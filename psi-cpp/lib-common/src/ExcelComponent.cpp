﻿/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/24 15:38:30

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
#include "pch.h"
#include "../include/ExcelComponent.h"
#include "../include/CommonMacros.h"
#include <iostream>
#include "CharsetConvertHepler.h"

void ExcelComponent::createSheet(const std::string& sheetName)
{
	// 如果存在sheet那么删除sheet
	if (wb.contains(sheetName))
	{
		sheet = wb.sheet_by_title(sheetName);
		wb.remove_sheet(sheet);
	}
	// 创建sheet
	sheet = wb.create_sheet();
	sheet.title(sheetName);
}

ExcelComponent::ExcelComponent()
{
	// 初始化工作薄
	wb = xlnt::workbook();
	// 删除默认工作表
	if (wb.contains("Sheet1"))
	{
		wb.remove_sheet(wb.active_sheet());
	}
}

void ExcelComponent::setRowHeight(double rowHeight)
{
	this->rowHeight = rowHeight;
}

void ExcelComponent::setColWidth(double colWidth)
{
	this->colWidth = colWidth;
}

void ExcelComponent::clearWorkbook()
{
	wb.empty();
}

std::vector<std::vector<std::string>> ExcelComponent::readIntoVector(const std::string& fileName, const std::string& sheetName)
{
	// 定义一个返回结果的二维表
	std::vector<std::vector<std::string>> result;

	// 定义一个临时的工作表，并加载文件
	auto tmpWb = xlnt::workbook();
	try
	{
		tmpWb.load(fileName);
	}
	catch (xlnt::exception e)
	{
		std::cout << "ExcelComponent 76: load excel fail(" << e.what() << ")" << std::endl;
		return result;
	}

	// 判断是否存在指定页签
	if (!tmpWb.contains(sheetName))
	{
		std::cout << "ExcelComponent 83: read sheet fail(" << CharsetConvertHepler::utf8ToAnsi(sheetName) << " is not contain)" << std::endl;
		return result;
	}

	// 逐行读取数据
	auto sheet = tmpWb.sheet_by_title(sheetName);
	for (auto row : sheet.rows(false))
	{
		std::vector<std::string> aSingleRow;
		for (auto cell : row)
		{
			aSingleRow.push_back(cell.to_string());
		}
		result.push_back(aSingleRow);
	}

	// 返回读取结果
	return result;
}

void ExcelComponent::writeVectorToFile(const std::string& fileName, const std::string& sheetName, const std::vector<std::vector<std::string>>& data)
{
	// 创建页签
	createSheet(sheetName);

	// 逐行写入数据
	int row = 1;
	int col = 1;
	for (auto aSignRow : data)
	{
		col = 1;
		for (auto cellVal : aSignRow)
		{
			//设置单元格值
			sheet.cell(xlnt::cell_reference(col, row)).value(cellVal);
			//设置列宽度
			sheet.column_properties(col).custom_width = true;
			sheet.column_properties(col).width = colWidth;
			col++;
		}
		//设置行高度
		sheet.row_properties(row).custom_height = true;
		sheet.row_properties(row).height = rowHeight;
		row++;
	}

	//判断目录是否存在，不存在创建目录
	auto dir = fileName.substr(0, fileName.find_last_of("/") + 1);
	const size_t dirLen = dir.length();
	if (dirLen > MAX_DIR_LEN)
	{
		std::cout << "ExcelComponent 134: excel save fail(file path too long)" << std::endl;
		return;
	}
	char tmpDirPath[MAX_DIR_LEN] = { 0 };
	for (size_t i = 0; i < dirLen; i++)
	{
		tmpDirPath[i] = dir[i];
		if (tmpDirPath[i] == '/')
		{
			if (ACCESS(tmpDirPath, 0) != 0)
			{
				if (MKDIR(tmpDirPath) != 0)
				{
					std::cout << "ExcelComponent 147: excel save fail(create dir " << tmpDirPath << " fail)" << std::endl;
					return;
				}
			}
		}
	}

	//保存到文件
	wb.save(fileName);
}



void ExcelComponent::makeName(const std::string& title)
{
	wb.title(title);
}

void ExcelComponent::mergeCell(const std::string& sheetName, const xlnt::cell_reference& columnbegin, const xlnt::cell_reference& columnend)
{
	// 如果存在sheet，那么对指定单元格进行合并
	if (wb.contains(sheetName))
	{
		sheet = wb.sheet_by_title(sheetName);
		sheet.merge_cells(xlnt::range_reference(columnbegin, columnend));
	}
}

// 创建新Sheet
void ExcelComponent::createNewSheet(const std::string& sheetName)
{
	// 如果指定页签不存在，那么创建新页签
	if (!wb.contains(sheetName))
	{
		createSheet(sheetName);
	}
}

void ExcelComponent::cellCpation(const std::string& sheetName, const xlnt::cell_reference& cell_ref, int opt)
{
	xlnt::horizontal_alignment center = xlnt::horizontal_alignment::center;
	xlnt::horizontal_alignment left = xlnt::horizontal_alignment::left;
	xlnt::horizontal_alignment right = xlnt::horizontal_alignment::right;
	xlnt::vertical_alignment vcenter = xlnt::vertical_alignment::center;
	if (wb.contains(sheetName))
	{
		sheet = wb.sheet_by_title(sheetName);
		sheet = wb.active_sheet();
		//xlnt::alignment alignment = sheet.cell(cell).alignment();
		switch (opt)
		{
		case 1:
			// 水平居中
			sheet.cell(cell_ref).alignment().horizontal(center);
			// 垂直居中
			//sheet.cell(cell).alignment().vertical(vcenter);
			break;
		case 2:
			// 水平居左
			//sheet.cell(cell).alignment(alignment.horizontal(left).vertical(vcenter));
			sheet.cell(cell_ref).alignment().horizontal(left);
			break;
		case 3:
			// 水平居右
			sheet.cell(cell_ref).alignment().horizontal(right);
			break;
		default:
			break;
		}
	}

}