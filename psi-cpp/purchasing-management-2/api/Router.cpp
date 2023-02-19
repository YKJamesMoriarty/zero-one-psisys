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
#include "stdafx.h"
#include "Router.h"
#include "api/Aspect.h"
#include "domain/vo/JsonVO.h"

#define PURORDER
#include "PurOrder/PurOrderController.h"
#include "PueReq/PurReqController.h"
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

	// �󶨷���ҳ��

#ifdef PURORDER
	createPurOrderRouter();
	createPurReqRouter();
	createPurComRouter();
#endif

	//#TIP :ϵͳ��չ·�ɶ��壬д���������

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
#endif

void Router::createPurOrderRouter()
{
	// ��ҳ����
	BIND_GET_ROUTER(server, "/purOrder/list", &PurOrderController::listPurOrder, nullptr);
	// ��������
	BIND_GET_ROUTER(server, "/purOrder/queryEntryByMainId", &PurOrderController::getPurOrder, nullptr);
	// ��������
	BIND_POST_ROUTER(server, "/purOrder/add", &PurOrderController::addPurOrder, nullptr);
	// �޸�����
	BIND_PUT_ROUTER(server, "/purOrder/edit", &PurOrderController::modifyPurOrder, nullptr);
	// ɾ������
	BIND_DEL_ROUTER(server, "/purOrder/delete", &PurOrderController::removePurOrder, nullptr);
	// ɾ��ById
	BIND_DEL_ROUTER(server, "/purOrder/deleteById", &PurOrderController::removeById, nullptr);
}

void Router::createPurReqRouter() {
	// ��ҳ����
	BIND_GET_ROUTER(server, "/purReq/list", &PurReqController::listPurReq, nullptr);
	// ��������
	BIND_GET_ROUTER(server, "/purReq/queryEntryByMainId", &PurReqController::getPurReq, nullptr);
}

void Router::createPurComRouter() {
	// ��ҳ����
	BIND_GET_ROUTER(server, "/purCom/list", &PurComController::listPurCom, nullptr);
	// ��������
	BIND_GET_ROUTER(server, "/purCom/queryEntryByMainId", &PurComController::getPurCom, nullptr);
}