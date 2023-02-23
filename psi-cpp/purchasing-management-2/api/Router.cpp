
//�����ӿ�
#include "stdafx.h"
#include "Router.h"
#include "api/Aspect.h"
#include "domain/vo/JsonVO.h"

#include "paymentBillImpl/PayApplyControlle.h"


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


}



#ifdef HTTP_SERVER_DEMO
void Router::createSampleRouter()
{
	//������Ӧ����
	BIND_POST_ROUTER(server, "/post", &PurQuotController::addPurQuot, nullptr);
	//�޸Ĺ�Ӧ����
	BIND_PUT_ROUTER(server, "/put", &PurQuotController::modPurQuot, nullptr);
	//ɾ����Ӧ����
	BIND_DEL_ROUTER(server, "/delete", &PurQuotController::delPurQuot, nullptr);
	//�޸Ĺ�Ӧ����״̬���رա����ס����رգ�
	BIND_PUT_ROUTER(server, "/put", &PurQuotController::purQuotModBillStatus, nullptr);
}

void Router::createUserDepartRouter()
{
	BIND_POST_ROUTER(server, "/depart-add", &DepartController::addDepart, nullptr);
	BIND_POST_ROUTER(server, "/depart-add-more", &DepartController::addDepartMore, nullptr);
}

#endif

void Router::createPayApplyRouter() {
	//��ѯ������
	BIND_GET_ROUTER(server, "/paymentApplyBill", &PayApplyControlle::queryPaymentBill, nullptr);
	//�鿴ָ��������ϸ��Ϣ
	BIND_GET_ROUTER(server, "/paymentApplyDetailBill", &PayApplyControlle::queryPaymentDetailBill, nullptr);
	//��Ӳɹ�����ӿ�
	BIND_POST_ROUTER(server, "/paymentApply/add", &PayApplyControlle::addPayApply, nullptr);
	//�޸Ĳɹ�����ӿ�
	BIND_PUT_ROUTER(server, "/paymentApply/mod", &PayApplyControlle::modPayReqApply, nullptr);
}



