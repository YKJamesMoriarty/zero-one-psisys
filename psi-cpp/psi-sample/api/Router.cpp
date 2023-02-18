
//公共接口
#include "stdafx.h"
#include "Router.h"
#include "api/Aspect.h"
#include "domain/vo/JsonVO.h"

#include "prepayment/PrePayController.h"

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
	//设置静态文件目录
	server->set_public_root_directory("public");
	server->set_static_dir("static/file");


#ifdef HTTP_SERVER_DEMO
	//绑定首页页面
	BIND_GET_ROUTER(server, "/", [](request& req, response& res) {
		res.render_raw_view("./public/test.html");
		}, nullptr);

	//初始化一个文件上传接口示例
	BIND_POST_ROUTER(server, "/upload-file", [](request& req, response& res) {
		if (req.get_content_type() != content_type::multipart)
		{
			JsonVO vo = JsonVO("", RS_CONTENT_TYPE_ERR);
			nlohmann::json jvo = nlohmann::json(vo);
			jvo.erase("data");
			res.render_json(jvo);
			return;
		}
	//获取表单参数
	std::cout << "nickname:" << req.get_multipart_value_by_key1("nickname") << std::endl;
	std::cout << "age:" << req.get_multipart_value_by_key1("age") << std::endl;
	//获取文件路径
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


	//#TIP :系统扩展路由定义，写在这个后面
	createPayRouter();
}


void Router::createPayRouter() {
	//查询单据列表
	BIND_GET_ROUTER(server, "/get-bill-list", &PrePayController::queryPayFindBill, nullptr);
	//查询指定单据详细信息
	BIND_GET_ROUTER(server, "/get-detail-bill", &PrePayController::queryPayFinDetailBill, nullptr);
	//导出
	BIND_GET_ROUTER(server, "/pay-export", &PrePayController::queryPayExport, nullptr);
	//添加申请(保存/提交)
	BIND_POST_ROUTER(server, "/post-add", &PrePayController::addPay, nullptr);
	//修改申请(保存/提交/审核)
	BIND_PUT_ROUTER(server, "/put-modifyPay", &PrePayController::modifyPay, nullptr);
	//删除申请
	BIND_DEL_ROUTER(server, "/delete-id", &PrePayController::removePayById, nullptr);
	//修改单据状态(关闭/作废/反关闭)
	BIND_POST_ROUTER(server, "/modify-bill-status", &PrePayController::modifyPurReqBillStatus, nullptr);
	//导入
	BIND_POST_ROUTER(server, "/pay-into", &PrePayController::modifyPayInto, nullptr);

}


