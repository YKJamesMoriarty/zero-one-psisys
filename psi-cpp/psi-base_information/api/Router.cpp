/*
��Ӧ�̸߼���ѯ���������б�
Author C1-��ľ
2023.2.13 21��10��
*/


#include "stdafx.h"
#include "Router.h"
#include "api/Aspect.h"
#include "domain/vo/JsonVO.h"
#include "BankAccountController.h"
#include "../api/supplier/SupplierController.h"
#include "api/bas_supplier/SupplierLevelController.h"
#include "api/bas_supplier/SupplierQueryCriteriaController.h"
#include "Supplier/ImportSupplierController.h"
#include "Supplier/ExportSupplierController.h"

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
	//��Ӧ�̵ȼ�
	initSupplierLevel();
	//��Ӧ�̸߼���ѯ����
	initSupplierQueryCriteria();


	//�����˻�
	initbaSetting();

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

	//#TIP :ϵͳ��չ·�ɶ��壬д���������
	initSupplier();
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
}




//��Ӧ�̵ȼ������б�
void Router::initSupplierLevel()
{
	BIND_GET_ROUTER(server, "/qurey-supplier-level", &SupplierLevelController::querySupplierLevel, nullptr);

}
//��Ӧ�̸߼���ѯ���������б�
void Router::initSupplierQueryCriteria()
{
	BIND_GET_ROUTER(server, "/qurey-supplier-advanced_criteria", &SupplierQueryCriteriaController::querySupplierQueryCriteria, nullptr);
}


void Router::initSupplier()
{
	BIND_POST_ROUTER(server, "/import-supplier", &ImportSupplierController::importSupplier, nullptr);
	BIND_GET_ROUTER(server, "/export-supplier", &ExportSupplierController::exportSupplier, nullptr);
}
