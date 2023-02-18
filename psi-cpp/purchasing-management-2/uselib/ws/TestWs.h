#pragma once
/*
 Copyright Zero One Star. All rights reserved.
 
 @Author: awei
 @Date: 2022/10/24 23:10:36
 
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
#ifndef _TESTWS_H_
#define _TESTWS_H_
#include "api/ApiHelper.h"

/**
 * 测试WebSocket
 */
class TestWs
{
public:
	//添加一个聊天websocket处理器
	static void addChatHandler(http_server* server);
};


#endif // _TESTWS_H_
