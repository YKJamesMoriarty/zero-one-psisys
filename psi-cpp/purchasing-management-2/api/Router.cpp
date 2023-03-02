#include "stdafx.h"
#include "Router.h"
#include "api/Aspect.h"
#include "domain/vo/JsonVO.h"

#ifdef HTTP_SERVER_DEMO
#include "sample/SampleController.h"
#include "user/DepartController.h"
#include "uselib/ws/TestWs.h"
#endif

#define ANDREW
#include "statis/StatisController.h"
#include "prepayment/PrePayController.h"
#include "PurOrder/PurOrderController.h"

#define ZUICHU
#include "payment/PaymentController.h"

#define J4NNA
#include "PurCom/PurComController.h"

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
	createStatisRouter();
	createPaymentRouter();
	createPrePayRouter();
	createPurComRouter();
	createPurOrderRouter();
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

/**
* Router�󶨽ӿں���ʵ��
*/
void Router::createStatisRouter() {
	// �ɹ�ͳ��Router
	// ��ѯ
	BIND_GET_ROUTER(server, "/query/ExecuteStatus", &StatisController::queryExeStatus, nullptr);
	BIND_GET_ROUTER(server, "/query-all", &StatisController::queryStatis, nullptr);
	BIND_GET_ROUTER(server, "/query-byDept", &StatisController::queryStatisByDept, nullptr);
	BIND_GET_ROUTER(server, "/query-byOperator", &StatisController::queryStatisByOperator, nullptr);
	BIND_GET_ROUTER(server, "/query-bySupplier", &StatisController::queryStatisBySupplier, nullptr);
	BIND_GET_ROUTER(server, "/query-byMaterial", &StatisController::queryStatisByMaterial, nullptr);
	// ����
	BIND_GET_ROUTER(server, "/export/ExecuteStatus", &StatisController::exportExeStatus, nullptr);
	BIND_GET_ROUTER(server, "/export-all", &StatisController::exportStatis, nullptr);
	BIND_GET_ROUTER(server, "/export-byDept", &StatisController::exportStatisByDept, nullptr);
	BIND_GET_ROUTER(server, "/export-byOperator", &StatisController::exportStatisByOperator, nullptr);
	BIND_GET_ROUTER(server, "/export-bySupplier", &StatisController::exportStatisBySupplier, nullptr);
	BIND_GET_ROUTER(server, "/export-byMaterial", &StatisController::exportStatisByMaterial, nullptr);
}

// �ɹ���������
// �����ˣ����
void Router::createPaymentRouter()
{
	//�޸ĵ���״̬
	BIND_PUT_ROUTER(server, "/modify-payment-status", &PaymentController::modifyPayment, nullptr);
	//ɾ������
	BIND_DEL_ROUTER(server, "/DePayment", &PaymentController::deleteById, nullptr);
	//��ӵ���
	BIND_PUT_ROUTER(server, "/AppPayment", &PaymentController::AddPayment, nullptr);
}

void Router::createPrePayRouter()
{
	//��ѯ�����б�
	// �����ˣ�Qi
	BIND_GET_ROUTER(server, "/get-bill-list", &PrePayController::queryPayFindBill1, nullptr);
	//��ѯָ��������ϸ��Ϣ
	// �����ˣ�Qi
	BIND_GET_ROUTER(server, "/get-detail-bill", &PrePayController::queryPayFinDetailBill1, nullptr);
	//�������(����/�ύ)
	// �����ˣ�Qi
	BIND_POST_ROUTER(server, "/post-add", &PrePayController::addPay, nullptr);
	//�޸�����(����/�ύ/���)
	// �����ˣ�Qi
	BIND_PUT_ROUTER(server, "/put-modifyPay", &PrePayController::modifyPay, nullptr);

	// �ɹ�Ԥ������-�޸ĵ���״̬(�ر�/����/���ر�)
	// �����ˣ�Andrew
	BIND_PUT_ROUTER(server, "/modify-bill-status", &PrePayController::modifyPurReqBillStatus, nullptr);

	//xubuxi
	//�ɹ������б�
	BIND_GET_ROUTER(server, "/get-prepaybill", &PrePayController::queryPayFindBill2, nullptr);
	//ָ��������ϸ��Ϣ
	BIND_GET_ROUTER(server, "/get-prepaybill-detail", &PrePayController::queryPayFinDetailBill2, nullptr);
	//ɾ������
	BIND_DEL_ROUTER(server, "/delete-t-prepay-id", &PrePayController::removeDePayId, nullptr);
}

// �ȼ۵��б��ѯ����ϸ�б��ѯ
// �����ˣ�J4nnA
void Router::createPurComRouter() {
	// ��ҳ����
	// �����ˣ�J4nnA
	BIND_GET_ROUTER(server, "/purCom/list", &PurComController::listPurCom, nullptr);
	// ��������
	// �����ˣ�J4nnA
	BIND_GET_ROUTER(server, "/purCom/queryEntryByMainId", &PurComController::getPurCom, nullptr);
	// ��ϸ�б�
	// �����ˣ�J4nnA
	BIND_GET_ROUTER(server, "/purCom/listEntrys", &PurComController::listPurComEntrys, nullptr);
}

// �ɹ�����
// �����ˣ�����, Andrew
void Router::createPurOrderRouter()
{
	// ��ҳ����
	// �����ˣ�����
	BIND_GET_ROUTER(server, "/purOrder/list", &PurOrderController::querylistPurOrder, nullptr);
	// ��������
	// �����ˣ�����
	BIND_GET_ROUTER(server, "/purOrder/queryEntryByMainId", &PurOrderController::getPurOrder, nullptr);
	// ��������
	// �����ˣ�����
	BIND_POST_ROUTER(server, "/purOrder/add", &PurOrderController::addPurOrder, nullptr);
	// �޸�����
	// �����ˣ�����
	BIND_PUT_ROUTER(server, "/purOrder/edit", &PurOrderController::modifyPurOrder, nullptr);

	// �ɹ�����ɾ��
	// �����ˣ�Andrew
	BIND_DEL_ROUTER(server, "/purOrder/deleteById", &PurOrderController::removeById, nullptr);
	// �ɹ�����-�޸�״̬
	// �����ˣ�Andrew
	BIND_PUT_ROUTER(server, "/purOrder/modifyStatus", &PurOrderController::statusPurOrder, nullptr);
}