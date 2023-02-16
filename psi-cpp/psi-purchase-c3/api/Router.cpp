
//�����ӿ�
#include "stdafx.h"
#include "Router.h"
#include "api/Aspect.h"
#include "domain/vo/JsonVO.h"
#include "pur-quot/PurQuotController.h"


//
#include "pur-req/PurReqController.h"
#include "pur-compare/PurCompareController.h"
#include "pur-inquiry/PurInquiryController.h"


#ifdef HTTP_SERVER_DEMO
#include "sample/SampleController.h"
#include "user/DepartController.h"
#include "uselib/ws/TestWs.h"
#endif

#include "pur-req/PurReqController.h"

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
	createPurQuotRouter();

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


//�ɹ�����
void Router::createPurReqRouter() {
	//��ѯ�����б�
	BIND_GET_ROUTER(server, "/get-com-bill-list", &PurReqController::queryPurReqFindBill, nullptr);
	//��ѯָ��������ϸ��Ϣ
	BIND_GET_ROUTER(server, "/get-one-combill", &PurReqController::queryPurReqFindDetailBill, nullptr);
	//�������(����/�ύ)
	BIND_POST_ROUTER(server, "/pur-req/post", &PurReqController::addPurReq, nullptr);
	//�޸�����(����/�ύ/���)
	BIND_PUT_ROUTER(server, "/pur-req/put", &PurReqController::modifyPurReq, nullptr);
	//ɾ������
	BIND_DEL_ROUTER(server, "/pur-req/delete-by-id", &PurReqController::removePurReqById, nullptr);
	//�޸ĵ���״̬(�ر�/����/���ر�)
	BIND_POST_ROUTER(server, "/pur-req/modify-bill-status", &PurReqController::modifyPurReqBillStatus, nullptr);
	//����
	BIND_POST_ROUTER(server, "/pur-req-into", &PurReqController::modifyPurReqInto, nullptr);
	//����
	BIND_GET_ROUTER(server, "/pur-req-export", &PurReqController::queryPurReqExport, nullptr);
}
<<<<<<< HEAD
//�ɹ�ѯ��
void Router::createPurInquiryRouter() {
	//��ѯ�����б�
	BIND_GET_ROUTER(server, "/pur-inquiry-find-bill", &PurInquiryController::queryPurInquiryFindBill, nullptr);
	//��ѯָ��������ϸ��Ϣ
	BIND_GET_ROUTER(server, "/pur-inquiry-find-detail-bill", &PurInquiryController::queryPurInquiryFindDetailBill, nullptr);
	BIND_POST_ROUTER(server, "/add", &PurInquiryController::addPurInquiry, nullptr);
	BIND_PUT_ROUTER(server, "/modify", &PurInquiryController::modifyPurInquiry, nullptr);
	BIND_DEL_ROUTER(server, "/delete", &PurInquiryController::removePurInquiry, nullptr);
	BIND_PUT_ROUTER(server, "/modify-status", &PurInquiryController::modifyPurQuotModBillStatus, nullptr);
	BIND_POST_ROUTER(server, "/purReqInto", &PurInquiryController::PurInquiryInto,nullptr);
	BIND_GET_ROUTER(server, "/purReqExport", &PurInquiryController::PurInquiryExport, nullptr);

}

//��Ӧ����
void Router::createPurQuotRouter()
{
	//��ӱ���(����/�ύ)
	BIND_POST_ROUTER(server, "/add-pur-quot", &PurQuotController::addPurQuot, nullptr);
	//�޸ı���(����/�ύ/���)
	BIND_PUT_ROUTER(server, "/mod-pur-quot", &PurQuotController::modPurQuot, nullptr);
	//ɾ������
	BIND_DEL_ROUTER(server, "/del-pur-quot", &PurQuotController::delPurQuot, nullptr);
	//�޸ĵ���״̬(�ر�/����/���ر�)
	BIND_PUT_ROUTER(server, "/pur-quot-mod-bill-status", &PurQuotController::purQuotModBillStatus, nullptr);
	//����
	BIND_PUT_ROUTER(server, "/pur-quot-mod-into", &PurQuotController::modifyPurQuotInto, nullptr);
	//����
	BIND_PUT_ROUTER(server, "/pur-quot-query-export", &PurQuotController::queryPurQuotExport, nullptr);
}

//�ɹ��ȼ�
void Router::createPurCompareRouter(){
	//��ѯ�����б�
	BIND_GET_ROUTER(server, "/get-combill-list", &PurCompareController::queryPurComFindBill, nullptr);
	//��ѯָ��������ϸ��Ϣ
	BIND_GET_ROUTER(server, "/get-one-combill", &PurCompareController::queryPurComFindDetailBill, nullptr);
	//���۵��б�
	BIND_GET_ROUTER(server, "/get-quot-of-combill", &PurCompareController::queryPurComList, nullptr);
	//���۵���¼�б�
	BIND_GET_ROUTER(server, "/get-quotentry-of-combill", &PurCompareController::queryPurComDividedList, nullptr);
	//��ӱȼ�(����/�ύ)
	BIND_POST_ROUTER(server, "/add-pur-com", &PurCompareController::addPurCom, nullptr);
	//�޸ıȽ�(����/�ύ/���)
	BIND_POST_ROUTER(server, "/mod-pur-com", &PurCompareController::modifyPurCom, nullptr);
	//ɾ���ȼ�
	BIND_DEL_ROUTER(server, "/del-pur-com", &PurCompareController::removePurCom, nullptr);
	//�޸ĵ���״̬(�ر�/����/���ر�)
	BIND_POST_ROUTER(server, "/mod-pur-com-bill-status", &PurCompareController::purComModBillStatus, nullptr);
	//����
	BIND_POST_ROUTER(server, "/pur-into-into", &PurCompareController::modifyPurComInto, nullptr);
	//����
	BIND_GET_ROUTER(server, "/pur-com-export", &PurCompareController::queryPurComExport, nullptr);
}




