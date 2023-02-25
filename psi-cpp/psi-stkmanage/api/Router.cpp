
#include "stdafx.h"
#include "Router.h"
#include "Zdrk/ZdrkController.h"
#include "api/Aspect.h"
#include "domain/vo/JsonVO.h"
#include "Pyrk/PyrkController.h"

#include "Cgthck/CgthckController.h"
#include "Cgrk/CgrkController.h"
#include "Qtrk/QtrkController.h"
#include "Pyrk/PyrkController.h"


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
			//��ȡ��������
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

	//createSampleRouter();
	//createUserDepartRouter();
	TestWs::addChatHandler(server);
#endif

	createCgrkRouter();
	createIncreaseTonRouter();
	createCgthckRouter();
	createQtrkRouter();
	//������ӯ���·��
	createPyrkRouter();

	//#TIP :ϵͳ��չ·�ɶ��壬д���������
	createPyrkRouter();


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


//�ɹ����·��
void Router::createCgrkRouter()
{
	BIND_GET_ROUTER(server, "/query-cgrk-bill-list", &CgrkController::queryCgrkBillList, nullptr);
	BIND_GET_ROUTER(server, "/query-cgrk-bill-list-advanced", &CgrkController::queryCgrkBillListAdvanced, nullptr);
	BIND_GET_ROUTER(server, "/query-cgrk-bill-details", &CgrkController::queryCgrkBillDetails, nullptr);
	BIND_GET_ROUTER(server, "/query-pur-order-list", &CgrkController::queryPurOrderList, nullptr);
	BIND_GET_ROUTER(server, "/query-pur-order-entry", &CgrkController::queryPurOrderEntry, nullptr);
	BIND_POST_ROUTER(server, "/add-cgrk-bill", &CgrkController::addCgrkBill, nullptr);
	BIND_PUT_ROUTER(server, "/modify-cgrk-bill", &CgrkController::modifyCgrkBill, nullptr);
	BIND_DEL_ROUTER(server, "/delete-cgrk-bill", &CgrkController::removeCgrkBill, nullptr);
	BIND_PUT_ROUTER(server, "/modify-cgrk-bill-state", &CgrkController::modifyCgrkBillState, nullptr);
	BIND_POST_ROUTER(server, "/import-cgrk-file", &CgrkController::importCgrkFile, nullptr);
	BIND_GET_ROUTER(server, "/export-cgrk-file", &CgrkController::exportCgrkFile, nullptr);
}
//�Ƕ����·��
void Router::createIncreaseTonRouter()
{
	BIND_GET_ROUTER(server, "/query-zdrk-bill-list", &ZdrkController::queryZdrkBillList, nullptr);
	BIND_GET_ROUTER(server, "/query-zdrk-bill-details", &ZdrkController::queryZdrkBillDetails, nullptr);
	BIND_POST_ROUTER(server, "/add-zdrk-bill", &ZdrkController::addZdrkBill, nullptr);
	BIND_PUT_ROUTER(server, "/modify-zdrk-bill", &ZdrkController::modifyZdrkBill, nullptr);
	BIND_DEL_ROUTER(server, "/delete-zdrk-bill", &ZdrkController::removeZdrkBill, nullptr);
	BIND_PUT_ROUTER(server, "/modify-zdrk-bill-state", &ZdrkController::modifyZdrkBillState, nullptr);
	BIND_POST_ROUTER(server, "/import-zdrk-file", &ZdrkController::ImportZdrkFile, nullptr);
	BIND_GET_ROUTER(server, "/emport-zdrk-file", &ZdrkController::EmportZdrkFile, nullptr);
}
//�ɹ��˻�����·��
void Router::createCgthckRouter()
{
	BIND_GET_ROUTER(server, "/query-cgthck-bill-list", &CgthckController::queryCgthcBillk, nullptr);
	BIND_GET_ROUTER(server, "/query-cgthck-bill-details", &CgthckController::queryCgthckBillDetail, nullptr);
	BIND_POST_ROUTER(server, "/add-cgthck-bill", &CgthckController::addCgthckBill, nullptr);
	BIND_PUT_ROUTER(server, "/modify-cgthck-bill", &CgthckController::modifyCgthckBill, nullptr);
	BIND_DEL_ROUTER(server, "/delete-cgthck-bill-by-id", &CgthckController::deleteCgthckBill, nullptr);
	BIND_POST_ROUTER(server, "/import-cgthck-file", &CgthckController::importCgthckFile, nullptr);
	BIND_GET_ROUTER(server, "/export-cgthck-file", &CgthckController::exportCgthckFile, nullptr);
}

//�������·��
void Router::createQtrkRouter()
{
	
	BIND_GET_ROUTER(server, "/query-qtrk-bill-list", &QtrkController::queryQtrk, nullptr);
	BIND_GET_ROUTER(server, "/query-qtrk-bill-details", &QtrkController::querydetailsQtrk, nullptr);
	BIND_POST_ROUTER(server, "/add-qtrk-bill", &QtrkController::addQtrk, nullptr);
	BIND_PUT_ROUTER(server, "/modify-qtrk-bill", &QtrkController::modifyQtrk, nullptr);
	BIND_PUT_ROUTER(server, "/modify-qtrk-bill-approval", &QtrkController::modifyQtrkApproval, nullptr);
	BIND_DEL_ROUTER(server, "/delete-qtrk-bill", &QtrkController::removeQtrk, nullptr);
	BIND_PUT_ROUTER(server, "/modify-qtrk-bill-state", &QtrkController::modifyQtrk, nullptr);
	//BIND_POST_ROUTER(server, "/import-qtrk-file", [](request& req, response& res) {
	//	if (req.get_content_type() != content_type::multipart)
	//	{
	//		JsonVO vo = JsonVO("", RS_CONTENT_TYPE_ERR);
	//		nlohmann::json jvo = nlohmann::json(vo);
	//		jvo.erase("data");
	//		res.render_json(jvo);
	//		return;
	//	}
	//	//��ȡ������
	//	std::cout << "nickname:" << req.get_multipart_value_by_key1("nickname") << std::endl;
	//	std::cout << "age:" << req.get_multipart_value_by_key1("age") << std::endl;
	//	//��ȡ�ļ�·��
	//	auto& files = req.get_upload_files();
	//	std::vector<string> filePaths;
	//	for (auto& file : files) {
	//		filePaths.push_back(file.get_file_path().substr(1));
	//		std::cout << "path " << file.get_file_path() << ",size " << file.get_file_size() << std::endl;
	//	}
	//	res.render_json(nlohmann::json(JsonVO<std::vector<std::string>>(filePaths, RS_SUCCESS)));
	//	}, nullptr);
	BIND_POST_ROUTER(server, "/import-qtrk-file", &QtrkController::importFileQtrk, nullptr);

	BIND_POST_ROUTER(server, "/export-qtrk-file", &QtrkController::exportFileQtrk, nullptr);
	//BIND_DEL_ROUTER(server, "/delete-by-id", &SampleController::removeById, nullptr);
	//BIND_POST_ROUTER(server, "/json", &QtrkController::jsonSample, nullptr);
	//BIND_POST_ROUTER(server, "/Qtrk/uploadFile", &QtrkController::uploadFile, nullptr);
}

//��ӯ���·��
void Router::createPyrkRouter()
{
	BIND_GET_ROUTER(server, "/query-pyrk-bill-list", &PyrkController::queryQueryBillList, nullptr);
	BIND_GET_ROUTER(server, "/query-pyrk-bill-details", &PyrkController::queryQueryBillDetailed, nullptr);
	BIND_POST_ROUTER(server, "/post-pyrk-bill", &PyrkController::addBillDetailed, nullptr);
	BIND_PUT_ROUTER(server, "/modify-pyrk-bill-approval", &PyrkController::modifyBillApproval, nullptr);
	BIND_PUT_ROUTER(server, "/modify-pyrk-bill", &PyrkController::updateBillDetailed, nullptr);
	BIND_DEL_ROUTER(server, "/delete-pyrk-bill-by-id", &PyrkController::removePyrkBillById, nullptr);
	BIND_PUT_ROUTER(server, "/modify-pyrk-bill-state-to-close", &PyrkController::modifyPyrkBillStateToClose, nullptr);
	BIND_PUT_ROUTER(server, "/modify-pyrk-bill-state-to-unclose", &PyrkController::modifyPyrkBillStateToUnclose, nullptr);
	BIND_PUT_ROUTER(server, "/modify-pyrk-bill-state-to-void", &PyrkController::modifyPyrkBillStateToVoid, nullptr);
	BIND_POST_ROUTER(server, "/import-pyrk-file", &PyrkController::importPyrkFile, nullptr);
	BIND_GET_ROUTER(server, "/export-pyrk-file", &PyrkController::exportPyrkFile, nullptr);
}

