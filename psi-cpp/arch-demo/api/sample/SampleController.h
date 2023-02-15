#pragma once

#ifndef _SAMPLE_CONTROLLER_
#define _SAMPLE_CONTROLLER_

#include "../../domain/query/sample/SampleQuery.h"
#include "../../domain/dto/sample/SampleDTO.h"
#include "../../domain/dto/IDDTO.h"
#include "../../domain/vo/sample/SampleVO.h"
#include "../../domain/vo/PageVO.h"
#include "../../domain/vo/JsonVO.h"
#include "../../domain/dto/user/UserDTO.h"
#include "../../domain/vo/user/UserVO.h"

/**
 * ʾ������������ʾ�����ӿڵ�ʹ��
 */
class SampleController
{
public:
	CREATE_API_FUN_QUERY_PAYLOAD(querySample, execQuerySample, SampleQuery);
	CREATE_API_FUN_BODY(addSample, execAddSample, SampleDTO);
	CREATE_API_FUN_BODY(modifySample, execModifySample, SampleDTO);
	CREATE_API_FUN_BODY(removeSample, execRemoveSample, SampleDTO);
	CREATE_API_FUN_BODY(removeById, execRemoveById, IntID);
	CREATE_API_FUN_JSON(jsonSample, execJsonSample, SampleDTO);
	CREATE_API_FUN_BODY_FILE(modifyUserInfo, execModifyUserInfo, UserDTO);
private:
	//��ѯ����
	JsonVO<PageVO<SampleVO>> execQuerySample(const SampleQuery& query, const PayloadDTO& payload);
	//��ʾ��������
	JsonVO<uint64_t> execAddSample(const SampleDTO& dto);
	//��ʾ�޸�����
	JsonVO<uint64_t> execModifySample(const SampleDTO& dto);
	//��ʾɾ������
	JsonVO<uint64_t> execRemoveSample(const SampleDTO& dto);
	JsonVO<uint64_t> execRemoveById(const IntID& id);
	//��ʾJSON�ύ
	JsonVO<SampleVO> execJsonSample(const SampleDTO& dto);
	//��ʾ�ļ��ϴ�
	JsonVO<UserVO> execModifyUserInfo(const UserDTO& dto);
};

#endif // _SAMPLE_CONTROLLER_