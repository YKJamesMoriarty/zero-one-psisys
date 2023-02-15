
#include "stdafx.h"
#include "Router.h"
#include "api/Aspect.h"
#include "domain/vo/JsonVO.h"

#include "pur-req/PurReqController.h"
#include "pur-compare/PurCompareController.h"
#include "pur-inquiry/PurInquiryController.h"


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


	createPurCompareRouter();
	createPurInquiryRouter();
	createPurReqRouter();

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



void Router::createPurReqRouter() {
	//��ѯ�ȼ۵��б�ӿ�·�ɰ�
	BIND_GET_ROUTER(server, "/get-com-bill-list", &PurReqController::queryPurReqFindBill, nullptr);
	//��ѯָ���ȼ۵���ϸ��Ϣ�ӿ�·�ɰ�
	BIND_GET_ROUTER(server, "/get-one-combill", &PurReqController::queryPurReqFindDetailBill, nullptr);
	//�������뵥�ӿ�·�ɰ�
	BIND_GET_ROUTER(server, "/pur-req-export", &PurReqController::queryPurReqExport, nullptr);
	//�������뵥�ӿ�·�ɰ�
	BIND_POST_ROUTER(server, "/pur-req-into", &PurReqController::modifyPurReqInto, nullptr);

}
void Router::createPurCompareRouter()
{
	//��ѯ�ȼ۵��б�ӿ�·�ɰ�
	BIND_GET_ROUTER(server, "/get-combill-list", &PurCompareController::queryPurComFindBill, nullptr);
	//��ѯָ���ȼ۵���ϸ��Ϣ�ӿ�·�ɰ�
	BIND_GET_ROUTER(server, "/get-one-combill", &PurCompareController::queryPurComFindDetailBill, nullptr);
	//��ѯ���۵��ӿ�·�ɰ�
	BIND_GET_ROUTER(server, "/get-quot-of-combill", &PurCompareController::queryPurComList, nullptr);
	//��ѯ���۵���¼�ӿ�·�ɰ�
	BIND_GET_ROUTER(server, "/get-quotentry-of-combill", &PurCompareController::queryPurComDividedList, nullptr);
}


void Router::createPurInquiryRouter()
{
	//��ѯѯ�۵��б�ӿ�·�ɰ�
	BIND_GET_ROUTER(server, "/pur-inquiry-find-bill", &PurInquiryController::queryPurInquiryFindBill, nullptr);
	//�鿴ָ��ѯ�۵���ϸ��Ϣ�ӿ�·�ɰ�
	BIND_GET_ROUTER(server, "/pur-inquiry-find-detail-bill", &PurInquiryController::queryPurInquiryFindDetailBill, nullptr);
	
	BIND_POST_ROUTER(server, "/add", &PurInquiryController::addPurInquiry, nullptr);
	BIND_PUT_ROUTER(server, "/modify", &PurInquiryController::modifyPurInquiry, nullptr);
	BIND_DEL_ROUTER(server, "/delete", &PurInquiryController::removePurInquiry, nullptr);
	BIND_POST_ROUTER(server, "/purReqInto", &PurInquiryController::PurInquiryInto,nullptr);
	BIND_GET_ROUTER(server, "/purReqExport", &PurInquiryController::PurInquiryExport, nullptr);
}


