#pragma once

#ifndef _SysUser_DO_
#define _SysUser_DO_
#include "./DoInclude.h"

/**
 * SysUser���ݿ�ʵ����
 */
class SysUserDO
{
	// �û�id
	CC_SYNTHESIZE(string, id, Id);
	// ��¼�˺�
	CC_SYNTHESIZE(string, username, Username);
	// ��ʵ����
	CC_SYNTHESIZE(string, realname, Realname);
	// ����
	CC_SYNTHESIZE(string, password, Password);
	// md5������
	CC_SYNTHESIZE(string, salt, Salt);
	// ͷ��
	CC_SYNTHESIZE(string, avatar, Avatar);
	// ����
	CC_SYNTHESIZE(string, birthday, Birthday);
	// �Ա�(0-Ĭ��δ֪,1-��,2-Ů)
	CC_SYNTHESIZE(int, sex, Sex);
	// �����ʼ�
	CC_SYNTHESIZE(string, email, Email);
	// �绰
	CC_SYNTHESIZE(string, phone, Phone);
	// ��¼�Ự�Ļ�������
	CC_SYNTHESIZE(string, org_code, Org_code);
	// �Ա�(1-����,2-����)
	CC_SYNTHESIZE(int, status, Status);
	// ɾ��״̬(0-����,1-��ɾ��)
	CC_SYNTHESIZE(int, del_flag, Del_flag);
	// ͬ������������(1-ͬ��,0-��ͬ��)
	CC_SYNTHESIZE(int, activiti_sync, Activiti_sync);
	// ���ţ�Ψһ��
	CC_SYNTHESIZE(string, work_no, Work_no);
	// ְ�񣬹���ְ���
	CC_SYNTHESIZE(string,post, Post);
	// ������
	CC_SYNTHESIZE(string,telephone, Telephone);
	// ������
	CC_SYNTHESIZE(string, creat_by, Creat_by);
	// ����ʱ��
	CC_SYNTHESIZE(string, creat_time, Creat_time);
	// ������
	CC_SYNTHESIZE(string, update_by, Update_by);
	// ����ʱ��
	CC_SYNTHESIZE(string,update_time,Update_time);
	// ��ݣ�1��ͨ��Ա 2�ϼ���
	CC_SYNTHESIZE(int, user_identity, User_identity);
	// ������
	CC_SYNTHESIZE(string,depart_ids,Depart_ids);
	// ���⻧��ʶ
	CC_SYNTHESIZE(string,rel_tenant_ids,Rel_tenant_ids);
	// �豸ID
	CC_SYNTHESIZE(string,client_id,Client_id);
	
public:
	SysUserDO() {
		id = "";
		username = "";
		realname = "";
		password = "";
		salt = "";
		avatar = "";
		birthday = "";
		sex = 1;
		email = "";
		phone = "";
		org_code = "";
		status = 1;
		del_flag = 0;
		activiti_sync = 1;
		work_no = "";
		post = "";
		telephone = "";
		creat_by = "";
		creat_time = "";
		update_by = "";
		update_time = "";
		user_identity = 1;
		depart_ids = "";
		rel_tenant_ids = "";
		client_id = "";
	}
};

#endif // !_SAMPLE_DO_
