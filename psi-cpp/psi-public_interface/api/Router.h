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
#include "AreaController.h"
#include "UserChoiceController.h"
#include"MaterialQueryController.h"
#include"DepartChoiceController.h"
#include"SupplierCategoryController.h"
#include"api/BasBankAccountController.h"
#include"api/MaterialTypeTreeListController.h"
#include"api/BasWareHouseTreeListController.h"
#include"./BankAccount/BankAccountController.h"
#include"api/CreateReceiptController.h"

/**
 * 前端访问服务器路由绑定，用于定义前端访问后端接口和访问路径绑定
 */
 /**
  *Author c1-ruizi
  * 2023/2/12  17:46
  * 接口：开票方式
  */
class Router
{
private:
	http_server* server;
public:
	//构造初始化
	explicit Router(http_server* sever);
	//呼叫初始化
	void initRouter();

	//公共接口的供应商资金账户
	void createBasBankAccount();

	//物料分类树状结构列表
	void createMaterialTypeTreeList();

	//仓库树状结构列表
	void createBasWareHouseTreeList();

	//银行账户
	void createBankAccount();

	//创建单据编号
	void createCreateReceipt();
	
private:
#ifdef HTTP_SERVER_DEMO
	//创建演示路由
	void createSampleRouter();
	//创建用户管理-部门管理路由
	void createUserDepartRouter();

	
#endif
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
};

#endif // !_ROUTER_