/*
 Copyright Zero One Star. All rights reserved.
 
 @Author: awei
 @Date: 2022/10/24 23:11:30
 
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
#include "TestWs.h"
#include "StringUtil.h"

// ����һ�����Ӷ����
std::map<std::string_view, conn_type*> conn_pool;
// ����һ��������
std::mutex some_mutex;

void TestWs::addChatHandler(http_server* server)
{
	server->set_http_handler<GET, POST>("/chat/*", [](request& req, response& res) {
		// �ж�content-type����
		assert(req.get_content_type() == content_type::websocket);
		// ������
		req.on(ws_open, [](request& req) {
			// ��ȡ�ͻ���ID
			std::string_view id = req.get_query_value("id");
			// �жϿͻ��˶����Ƿ����
			std::lock_guard<std::mutex> guard(some_mutex);
			if (conn_pool.find(id) != conn_pool.end()) {
				// �رվܾ�����
				req.get_conn()->on_close();
				// ����һ���������
				req.set_part_data("reason id");
				return;
			}
			// ��ӵ����ӳ���
			conn_pool.insert(std::make_pair(id, req.get_conn()));
			std::cout << "client(" << id << "): open connection" << std::endl;
			});
		// ������Ϣ
		req.on(ws_message, [](request& req) {
			// ��ȡ��Ϣ����
			auto part_data = req.get_part_data();
			std::string str = std::string(part_data.data(), part_data.length());
			// ������Ϣ => ID::��Ϣ����
			std::vector<string> msgs = StringUtil::split(str, "::");
			// Ⱥ����ϢID=all��ʾȺ��
			if ("all" == msgs[0])
			{
				std::lock_guard<std::mutex> guard(some_mutex);
				for (auto one : conn_pool)
				{
					// �ų��Լ�
					if (one.second == req.get_conn())
					{
						continue;
					}
					// ������Ϣ
					one.second->send_ws_string(msgs[1]);
				}
			}
			// ָ������
			else
			{
				std::lock_guard<std::mutex> guard(some_mutex);
				auto iter = conn_pool.find(msgs[0]);
				if (iter != conn_pool.end())
				{
					iter->second->send_ws_string(msgs[1]);
				}
			}
			req.get_conn()->send_ws_string("message send success");
			});
		// �����쳣
		req.on(ws_error, [](request& req) {
			// ��ȡ�ͻ���ID
			std::string_view id = req.get_query_value("id");
			// ����ͻ����Ƴ�
			if ("reason id" != req.get_part_data())
			{
				// ��ӡ��ʾ��Ϣ
				std::cout << "client(" << id << "): pack error or network error" << std::endl;
				std::cout << "client(" << id << "): close connection" << std::endl;
				// �����Ӷ����map���Ƴ�
				std::lock_guard<std::mutex> guard(some_mutex);
				conn_pool.erase(id);
			}
			else
			{
				// ����ͻ��˾ܾ�����
				std::cout << "client(" << id << "): id has been used" << std::endl;
			}
			});
		}
	);
}
