#pragma once
/*
 Copyright Zero One Star. All rights reserved.
 
 @Author: awei
 @Date: 2022/10/24 23:36:43
 
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
#ifndef _ROUTER_
#define _ROUTER_

#include "api/ApiHelper.h"
#include "publicInterfaceController/AreaController.h"
#include "publicInterfaceController/UserChoiceController.h"
#include "publicInterfaceController/MaterialQueryController.h"
#include "publicInterfaceController/DepartChoiceController.h"
#include "supplierController/SupplierCategoryController.h"
#include "bankAccountController/BasBankAccountController.h"
#include "publicInterfaceController/MaterialTypeTreeListController.h"
#include "publicInterfaceController/BasWareHouseTreeListController.h"
#include "bankAccountController/BankAccountController.h"
#include "publicInterfaceController/CreateReceiptController.h"

/**
 * ǰ�˷��ʷ�����·�ɰ󶨣����ڶ���ǰ�˷��ʺ�˽ӿںͷ���·����
 */
 /**
  *Author c1-ruizi
  * 2023/2/12  17:46
  * �ӿڣ���Ʊ��ʽ
  */
class Router
{
private:
	http_server* server;
public:
	//�����ʼ��
	explicit Router(http_server* sever);
	//���г�ʼ��
	void initRouter();

	//�����ӿڵĹ�Ӧ���ʽ��˻�
	void createBasBankAccount();

	//���Ϸ�����״�ṹ�б�
	void createMaterialTypeTreeList();

	//�ֿ���״�ṹ�б�
	void createBasWareHouseTreeList();

	//�����˻�
	void createBankAccount();

	//�������ݱ��
	void createCreateReceipt();
	void initAreaSetting();
	void initUserChoiceSetting();
	void initMaterialQuerySetting();
	void initDepartChioceSetting();
	void initSupplierSetting();
	void initBankAccount();
	void initSuppliersSetting();
	void initInvoiceMethodSetting();
	void initInvoiceTypeSetting();
	void initSettleMethodSetting();
	void initTransportMethodSetting();
	//���ݽ׶������б�
	void initBillStage();
	//�ɹ����������б�
	void initPurType();
	//˰�������б�
	void initTaxRate();
	//��˰��ģ�����б�
	void initTaxScale();
	void initCurrencyType();
	void initDeliveryType();
	void initWarehouse();
	void initbaSetting();
	//���濪ʼ���Լ�д��
	void initSupplier();
	
private:
#ifdef HTTP_SERVER_DEMO
	//������ʾ·��
	void createSampleRouter();
	//�����û�����-���Ź���·��
	void createUserDepartRouter();

	
#endif
};

#endif // !_ROUTER_