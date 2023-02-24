/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/24 23:38:25

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

/**
 *Author c1-ruizi
 * 2023/2/12  17:46
 * �ӿڣ���Ʊ��ʽ
 */

#include "stdafx.h"
#include "Router.h"
#include "api/Aspect.h"
#include "api/ApiHelper.h"
#include "domain/vo/JsonVO.h"

#include "supplierController/SuppliersNomalQueryController.h"
#include "supplierController/SupplierController.h"
#include "supplierController/SupplierLevelController.h"
#include "supplierController/SupplierQueryCriteriaController.h"
#include "supplierController/ImportSupplierController.h"
#include "supplierController/ExportSupplierController.h"
#include "supplierController/SuppliersNameController.h"

#include "publicInterfaceController/MaterialTypeController.h"
#include "publicInterfaceController/DeliveryMethodController.h"
#include "publicInterfaceController/PayMethodController.h"
#include "publicInterfaceController/InvoiceTypeController.h"
#include "publicInterfaceController/InvoiceMethodController.h"
#include "publicInterfaceController/SettleMethodController.h"
#include "publicInterfaceController/TransportMethodController.h"
#include "publicInterfaceController/BillStageController.h"
#include "publicInterfaceController/PurTypeController.h"
#include "publicInterfaceController/TaxRateController.h"
#include "publicInterfaceController/TaxScaleController.h"
#include "publicInterfaceController/CurrencyTypeController.h"
#include "publicInterfaceController/DeliveryTypeController.h"
#include "publicInterfaceController/WarehouseController.h"
#include "publicInterfaceController/CurrencyTypeController.h"
#include "publicInterfaceController/DeliveryTypeController.h"
#include "publicInterfaceController/WarehouseController.h"

#include "bankAccountController/AddAccountController.h"
#include "bankAccountController/EditAccountController.h"
#include "bankAccountController/DeleteAccountController.h"
#include "bankAccountController/ImportAccountController.h"


#ifdef HTTP_SERVER_DEMO
#include "sample/SampleController.h"
#include "user/DepartController.h"
#include "uselib/ws/TestWs.h"
#endif

Router::Router(http_server* sever)
{
	this->server = sever;
}

void Router::initRouter()
{
	//���þ�̬�ļ�Ŀ¼
	server->set_public_root_directory("public");
	server->set_static_dir("static/file");
	initAreaSetting();
	initUserChoiceSetting();
	initMaterialQuerySetting();
	initSupplierSetting();
	initDepartChioceSetting();

	//�����ӿڵĹ�Ӧ���ʽ��˻�
	createBasBankAccount();

	//���Ϸ�����״�ṹ�б�
	createMaterialTypeTreeList();

	//�ֿ���״�ṹ�б�
	
	createBasWareHouseTreeList();

	createBankAccount();

	createCreateReceipt();
	initInvoiceMethodSetting();
	initInvoiceTypeSetting();
	initSettleMethodSetting();
	initTransportMethodSetting();
	//���ݽ׶������б�
	initBillStage();
	//�ɹ����������б�
	initPurType();
	//˰�������б�
	initTaxRate();
	//��˰��ģ�����б�
	initTaxScale();
	//�����˻�
	initbaSetting();
	initSuppliersSetting();
	//#TIP :ϵͳ��չ·�ɶ��壬д���������
	initBankAccount();
	initCurrencyType();
	initDeliveryType();
	initWarehouse();
	initSupplier();

#ifdef HTTP_SERVER_DEMO
	//����ҳҳ��
	BIND_GET_ROUTER(server, "/", [](request& req, response& res) {
		res.render_raw_view("./public/test.html");
		}, nullptr);

	//��ʼ��һ���ļ��ϴ��ӿ�ʾ��
	BIND_POST_ROUTER(server, "/upload-file", [](request& req, response& res) {
		if (req.get_content_type() != content_type::multipart)
		{
			JsonVO vo = JsonVO("", RS_CONTENT_TYPE_ERR);
			nlohmann::json jvo = nlohmann::json(vo);
			jvo.erase("data");
			res.render_json(jvo);
			return;
		}
		//��ȡ������
		std::cout << "nickname:" << req.get_multipart_value_by_key1("nickname") << std::endl;
		std::cout << "age:" << req.get_multipart_value_by_key1("age") << std::endl;
		//��ȡ�ļ�·��
		auto& files = req.get_upload_files();
		std::vector<string> filePaths;
		for (auto& file : files) {
			filePaths.push_back(file.get_file_path().substr(1));
			std::cout << "path " << file.get_file_path() << ",size " << file.get_file_size() << std::endl;
		}
		res.render_json(nlohmann::json(JsonVO<std::vector<std::string>>(filePaths, RS_SUCCESS)));
		}, nullptr);

	createSampleRouter();
	createUserDepartRouter();
	TestWs::addChatHandler(server);




#endif
}

#ifdef HTTP_SERVER_DEMO
void Router::createSampleRouter()
{
	BIND_GET_ROUTER(server, "/get", &SampleController::querySample, nullptr);
	BIND_POST_ROUTER(server, "/post", &SampleController::addSample, nullptr);
	BIND_PUT_ROUTER(server, "/put", &SampleController::modifySample, nullptr);
	BIND_DEL_ROUTER(server, "/delete", &SampleController::removeSample, nullptr);
	BIND_DEL_ROUTER(server, "/delete-by-id", &SampleController::removeById, nullptr);
	BIND_POST_ROUTER(server, "/json", &SampleController::jsonSample, nullptr);
	BIND_POST_ROUTER(server, "/modify-user-info", &SampleController::modifyUserInfo, nullptr);
}

void Router::createUserDepartRouter()
{
	BIND_POST_ROUTER(server, "/depart-add", &DepartController::addDepart, nullptr);
	BIND_POST_ROUTER(server, "/depart-add-more", &DepartController::addDepartMore, nullptr);
}

#endif
void Router::initAreaSetting()
{
	BIND_GET_ROUTER(server, "/get-area", &AreaController::queryArea, nullptr);
}

void Router::initUserChoiceSetting()
{
	BIND_GET_ROUTER(server, "/get-user", &UserChoiceController::queryUser, nullptr);
}

void Router::initMaterialQuerySetting()
{
	BIND_GET_ROUTER(server, "/get-material", &MaterialQueryController::queryMaterial, nullptr);
}

void Router::initDepartChioceSetting()
{
	BIND_GET_ROUTER(server, "/get-depart", &DepartChoiceController::queryDepart, nullptr);
}

void Router::initSupplierSetting()
{
	BIND_GET_ROUTER(server, "/get-supplier", &SupplierCategoryController::querySupplierCategory, nullptr);
}

void Router::createBasBankAccount()
{
	BIND_GET_ROUTER(server, "/query-bas-bank-account", &BasBankAccountController::queryBasBankAccount, nullptr);
}
void Router::createMaterialTypeTreeList()
{                                            
	BIND_GET_ROUTER(server, "/query-material-type-tree-list", &MaterialTypeTreeListController::queryMaterialTypeTreeList, nullptr);
}
void Router::createBasWareHouseTreeList()
{
	BIND_GET_ROUTER(server, "/query-bas-ware-house-tree-list", &BasWareHouseTreeListController::queryBasWareHouseTreeList, nullptr);
}

void Router::createBankAccount() {
	BIND_GET_ROUTER(server, "/query-specified-bank-account", &BankAccountController::querySpecifiedBankAccount, nullptr);
}

void Router::createCreateReceipt() {
	BIND_PUT_ROUTER(server, "/create-receipt", &CreateReceiptController::createReceipt, nullptr);
}

void Router::initBankAccount()
{
	BIND_POST_ROUTER(server, "/post-account", &AddAccountController::addBankAccount, nullptr);
	BIND_PUT_ROUTER(server, "/put-account", &EditAccountController::modifyBankAccount, nullptr);
	BIND_DEL_ROUTER(server, "/delete-account", &DeleteAccountController::removeBankAccount, nullptr);
	BIND_POST_ROUTER(server, "/import-account", &ImportAccountController::modifyAccountInfo, nullptr);
}

void Router::initSuppliersSetting()
{
	BIND_GET_ROUTER(server, "/query-suppliers-name", &SuppliersNameController::querySuppliersName, nullptr);
	BIND_GET_ROUTER(server, "/query-material-type", &MaterialTypeController::queryMaterialType, nullptr);
	BIND_GET_ROUTER(server, "/query-paymethod-type", &PayMethodController::queryPayMethod, nullptr);
	BIND_GET_ROUTER(server, "/query-deliverymothod-type", &DeliveryMethodController::queryDeliveryMethod, nullptr);
	BIND_GET_ROUTER(server, "/query-suppliernomal-type", &SuppliersNomalQueryController::querySuppliersNomal, nullptr);
}


void Router::initInvoiceMethodSetting()
{
	BIND_GET_ROUTER(server, "/query-invoice-method", &InvoiceMethodController::queryInvoiceMethod, nullptr);
}
void Router::initInvoiceTypeSetting()
{
	BIND_GET_ROUTER(server, "/query-invoice-type", &InvoiceTypeController::queryInvoiceType, nullptr);
}
void Router::initSettleMethodSetting()
{
	BIND_GET_ROUTER(server, "/query-settle-method", &SettleMethodController::querySettleMethod, nullptr);
}
void Router::initTransportMethodSetting()
{
	BIND_GET_ROUTER(server, "/query-transport-method", &TransportMethodController::queryTransportMethod, nullptr);
}

//���ݽ׶�
void Router::initBillStage()
{
	BIND_GET_ROUTER(server, "/query-bill-stage", &BillStageController::queryBillStage, nullptr);
}
//�ɹ�����
void Router::initPurType()
{
	BIND_GET_ROUTER(server, "/query-purchase-type", &PurTypeController::queryPurType, nullptr);
}
//˰��
void Router::initTaxRate()
{
	BIND_GET_ROUTER(server, "/query-tax-rate", &TaxRateController::queryTaxRate, nullptr);
}
//��˰��ģ
void Router::initTaxScale()
{
	BIND_GET_ROUTER(server, "/query-tax-scale", &TaxScaleController::queryTaxScale, nullptr);
}
void Router::initCurrencyType()
{
	//��ȡ��������
	BIND_GET_ROUTER(server, "/query-Currency-Type", &CurrencyTypeController::queryCurrencyType, nullptr);
}

void Router::initDeliveryType()
{
	//��ȡ������ʽ
	BIND_GET_ROUTER(server, "/query-Delivery-Type", &DeliveryTypeController::queryDeliveryType, nullptr);
}

void Router::initWarehouse()
{
	//��ȡ�ֿ�
	BIND_GET_ROUTER(server, "/query-Warehouse", &WarehouseController::queryWarehouse, nullptr);
}

void Router::initbaSetting()
{
	BIND_GET_ROUTER(server, "/query-bankaccount-list", &BankAccountController::queryBankAccountList, nullptr);
}

void Router::initSupplier()
{
	//�߼���ѯ
	BIND_GET_ROUTER(server, "/Advanced-Query", &SupplierController::advancedquerySupplier, nullptr);
	//ָ����ѯ
	BIND_GET_ROUTER(server, "/Specified-Supplier-Data-Query", &SupplierController::specifiedquerySupplier, nullptr);
	//����
	BIND_POST_ROUTER(server, "/add-supplier", &SupplierController::addSupplier, nullptr);
	//ɾ��
	BIND_DEL_ROUTER(server, "/delete-supplier", &SupplierController::deleteSupplier, nullptr);
	//�޸�
	BIND_PUT_ROUTER(server, "/modify-supplier", &SupplierController::modifySupplier, nullptr);
	//��Ӧ�̵��뵼��
	BIND_POST_ROUTER(server, "/import-supplier", &ImportSupplierController::importSupplier, nullptr);
	BIND_GET_ROUTER(server, "/export-supplier", &ExportSupplierController::exportSupplier, nullptr);
	//��Ӧ�̵ȼ������б�
	BIND_GET_ROUTER(server, "/qurey-supplier-level", &SupplierLevelController::querySupplierLevel, nullptr);
	//��Ӧ�̸߼���ѯ���������б�
	BIND_GET_ROUTER(server, "/qurey-supplier-advanced_criteria", &SupplierQueryCriteriaController::querySupplierQueryCriteria, nullptr);
}

