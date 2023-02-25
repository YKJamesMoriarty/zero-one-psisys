#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: Eleanor
 @Date: 2023/2/18 22:43

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
#ifndef _PUR_INQUIRY_DAO_
#define _PUR_INQUIRY_DAO_
#include "BaseDAO.h"
#include "../../domain/do/pur-inquiry/PurInquiryDO.h"
#include "../../domain/do/pur-inquiry/PurInquiryEntryDO.h"
#include "../../domain/do/pur-inquiry/PurReqDO.h"
#include "../../domain/do/pur-inquiry/PurReqEntryDO.h"

#include "../../domain/do/pur-inquiry/AddPurInquiryDO.h"
#include "../../domain/do/pur-inquiry/AddPurInquiryEntryDO.h"
#include "../../domain/dto/pur-inquiry/PurInquiryRemoveDTO.h"
#include "../../domain/do/pur-inquiry/PurInquiryModBillStatusDO.h"

/*
*  ���ݿ����ʵ��
*/


class PurInquiryDAO : public BaseDAO
{
public:
	// ��������
	uint64_t insert(const AddPurInquiryDO& iObj);
	//������ϸ
	uint64_t insertByEntry(const AddPurInquiryEntryDO& iObj);
	// �޸�����
	int update(const AddPurInquiryDO& uObj);
	//�޸���ϸ
	int updateByEntry(const AddPurInquiryEntryDO& uObj);
	// ͨ�����ݱ��ɾ��ѯ��
	int deleteById(string bill_no);
	//�޸ĵ���״̬
	int updateByModBillStatus(const PurInquiryModBillStatusDO& uObj);

	// ͳ����������
	uint64_t count(const PurInquiryDO& iObj);
	// ͳ�Ƶ�������������
	uint64_t countExport(PurInquiryDO iObj);
	// ͳ�Ƶ������������
	uint64_t countInto(PurInquiryDO iObj);	
	// ��ҳ��ѯ����
	list<PurInquiryDO> selectPurInquiryFindBillWithPage(const PurInquiryDO& obj, uint64_t pageIndex, uint64_t pageSize);
	// �鿴ָ���������飨�����ݱ�Ų�ѯ��
	list<PurInquiryDO> selectPurInquiryFindDetailBill(const PurInquiryDO& obj);
	// ָ��������ϸ��¼
	list<PurInquiryEntryDO> selectPurInquiryFindDetailBillEntry(const PurInquiryEntryDO& obj);

	//// ָ���������뵥��¼
	//list<PurReqDO> selectPurReq(const PurReqDO& obj, uint64_t pageIndex, uint64_t pageSize);
	//// ָ���������뵥��ϸ
	//list<PurReqEntryDO> selectPurReqEntry(const PurReqEntryDO& obj);

	// �����������ݱ��������ѯ�󣬷���xml���������ļ���
	list<PurInquiryDO> selectPurInquiryExport(const PurInquiryDO& obj, long pageIndex, long pageSize);

	list<PurInquiryEntryDO> selectPurInquiryExportEntry(const PurInquiryEntryDO& obj);
	



	// ���루�ϴ��ļ��󣬽�xml������json/cpp�������ݿ⣬�������ݣ�
	 
};


#endif // !_PUR_INQUIRY_FIND_BILL_DAO_