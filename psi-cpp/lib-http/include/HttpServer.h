#pragma once
/*
 Copyright Zero One Star. All rights reserved.
 
 @Author: awei
 @Date: 2022/10/24 13:55:27
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
#ifndef _HTTP_SERVER_
#define _HTTP_SERVER_

#include "api/ApiHelper.h"
/**
 * ������������
 * ע�⣺
 *  1 ʹ�õ�ʱ����Ҫ���ⲿʵ��api/Aspect.h�ж����������Ա����
 *  2 ��api/ApiHelper.h�����ṩ��һϵ������ת�������
 *  3 HttpLibMacros���涨��ĺ���Ҫ�ڶ�Ӧ��Ŀ���������Ԥ����
 */
class HttpServer
{
public:
	//************************************
	// Method:    startServer
	// FullName:  HttpServer::startServer
	// Access:    public static 
	// Returns:   int
	// Qualifier: ����HTTP������
	// Parameter: string port �󶨶˿�
	// Parameter: function<void(http_server*)> bindRouterFun ��ʼ��·�ɻص�
	// Parameter: string host �󶨵�ַ��Ĭ��ֵ0.0.0.0
	//************************************
	static int startServer(string port, function<void(http_server*)> bindRouterFun, string host = "0.0.0.0");
};

#endif // _HTTP_SERVER_

