#pragma once

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
	void createPurReqRouter();
	void createPurCompareRouter();
	void createPurInquiryRouter();
	void purReqRouter();

};


