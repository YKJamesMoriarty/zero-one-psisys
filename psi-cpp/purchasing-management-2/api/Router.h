#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/24 23:36:43
 
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
#ifndef _ROUTER_
#define _ROUTER_

#include "api/ApiHelper.h"

/**
 * ǰ�˷��ʷ�����·�ɰ󶨣����ڶ���ǰ�˷��ʺ�˽ӿںͷ���·����
 */
class Router
{
private:
	http_server* server;
public:
	//�����ʼ��
	explicit Router(http_server* sever);
	//���г�ʼ��
	void initRouter();
private:
#ifdef HTTP_SERVER_DEMO
	//������ʾ·��
	void createSampleRouter();
	//�����û�����-���Ź���·��
	void createUserDepartRouter();
#endif
	/**
	* �����ˣ�Andrew
	* 1. �ɹ�����-�޸ĵ���״̬(�ر�/���ر�/����)
	* 2. �ɹ�Ԥ�����뵥-�޸ĵ���״̬(�ر�/���ر�/����)
	* 3. �ɹ�����-ɾ���ɹ�����(ͨ��id)
	* ...
	* ��ע�������ɹ�ͳ�ƽӿ�
	*/
	void createAndrewRouter();
	/**
	* �����ˣ����
	* 1. ɾ���ɹ��������뵥
	* 2. �޸ĵ���״̬(�ر�/����/���ر�)
	* 3. ���Ӳɹ��������뵥(����/�ύ)
	*/
	void createPaymentRouter();
};

#endif // !_ROUTER_