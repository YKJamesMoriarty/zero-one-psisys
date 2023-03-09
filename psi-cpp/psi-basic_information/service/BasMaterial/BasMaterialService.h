#ifndef _BASMATERIAL_SERVICE_
#define _BASMATERIAL_SERVICE_
#include <list>
#include "../../domain/vo/BasMaterial/BasMaterialVO.h"
#include "../../domain/vo/PageVO.h"
#include "../../domain/query/BasMaterial/BasMaterialQuery.h"
#include "../../domain/query/BasMaterial/BasMaterialDetailQuery.h"
#include "../../domain/dto/BasMaterial/BasMaterialDTO.h"

/**
 * ʾ������ʵ�֣���ʾ������ʾ������ʵ��
 */
class BasMaterialService
{
public:
	// ��ҳ��ѯ��������
	PageVO<BasMaterialVO> listAll(const BasMaterialQuery& query);
	//id��ѯ
	BasMaterialVO getData(const BasMaterialDetailQuery& query);

	// ��������
	uint64_t saveData(const BasMaterialDTO& dto, const PayloadDTO& payload);
	// �޸�����
	bool updateData(const BasMaterialDTO& dto, const PayloadDTO& payload);
	// ͨ��code����ɾ������
	bool removeData(uint64_t id);
	//����
	bool getExceData(const BasMaterialQuery& query, vector<vector<string>>& data);
	//����
	uint64_t saveExceData(const FileDTO& dto, const PayloadDTO& payload);
};

#endif // !_BASMATERIAL_SERVICE_

