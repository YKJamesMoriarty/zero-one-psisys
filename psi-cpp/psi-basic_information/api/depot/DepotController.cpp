#include "stdafx.h"
#include "DepotController.h"
#include "../../../lib-common/include/ExcelComponent.h"
#include "../../../lib-common/include/CharsetConvertHepler.h"
#include <FastDfsClient.h>

/*
* ����У��
* �Ľӿڷ���ֵ
* ������Ϣ��̨ PayloadDTO��ô����ˣ��޸���
* ID��������com-ѩ��
* �ɹ�ʾ����ʧ��ʾ��
* 
*/

JsonVO<PageVO<DepotVO>> DepotController::execQueryDepot(const DepotQuery& query, const PayloadDTO& payload)
{
    //����һ��Service
    DepotService service;
    //��ѯ����
    PageVO<DepotVO> result = service.listAll(query);
    //��Ӧ���
    return JsonVO<PageVO<DepotVO>>(result, RS_SUCCESS);
}

JsonVO<list<DepotVO>> DepotController::execQueryKidDepot(const OnlyValueQuery& query, const PayloadDTO& payload)
{
    // ����У��
    if (query.getId() == "") {
        return JsonVO<list<DepotVO>>({}, RS_PARAMS_INVALID);
    }
    // ����Service
    DepotService service;
    // ��ѯ����
    list<DepotVO> result = service.getKid(query);
    return JsonVO<list<DepotVO>>(result, RS_SUCCESS);
}

JsonVO<DepotDetailVO> DepotController::execQueryDetail(const OnlyValueQuery& query, const PayloadDTO& payload)
{
    //����һ��Service
    DepotService service;
    //��ѯ����
    DepotDetailVO result = service.listDetail(query);
    //��Ӧ���
    return JsonVO<DepotDetailVO>(result, RS_SUCCESS);
}

JsonVO<DepotActionInfoVO> DepotController::execQueryActionInfo(const OnlyValueQuery& query, const PayloadDTO& payload)
{
    //����һ��Service
    DepotService service;
    //��ѯ����
    DepotActionInfoVO result = service.listInfo(query);
    //��Ӧ���
    return JsonVO<DepotActionInfoVO>(result, RS_SUCCESS);
}

JsonVO<bool> DepotController::execAddDepot(const DepotDTO& dto, const PayloadDTO& payload)
{
    JsonVO<bool> result;
    //����һ��Service
    DepotService service;
    //��������
    if (service.saveData(dto, payload.getUsername())){
        result.success(true);
    }
    else {
        result.fail(false);
    }
    return result;
}

JsonVO<bool> DepotController::execAddKidDepot(const DepotDTO& dto)
{
    JsonVO<bool> result;
    //����һ��Service
    DepotService service;
    //��������
    if (service.saveKidData(dto), payload.getUsername())) {
        result.success(true);
    }
    else {
        result.fail(false);
    }
    return result;
}

JsonVO<bool> DepotController::execModifyDepot(const DepotDTO& dto, const PayloadDTO& payload)
{
    JsonVO<bool> result;
    //����һ��Service
    DepotService service;
    if (service.modifyDepot(dto, payload.getUsername())) {
        result.success(true);
    }
    else
    {
        result.fail(false);
    }
    return result;
}

JsonVO<bool> DepotController::execRemoveDepot(const OnlyValueQuery& query)
{
    JsonVO<bool> result;
    //����һ��Service
    DepotService service;
    //ɾ������
    if (service.removeData(query)) {
        result.success(true);
    }
    else
    {
        result.fail(false);
    }
    return result;
}

JsonVO<bool> DepotController::execAddDepots(const DepotDTO& dto, const PayloadDTO& payload)
{
    JsonVO<bool> result;
    bool succeed = true;
    std::list<DepotDTO> vDto;
    ExcelComponent excel;

    // ��ȡ�ϴ��ļ�·���б�
    for (auto file : dto.getFiles()) {
        // ��ȡ�ļ���DTO
        string sheetName = u8"test";
        auto readData = excel.readIntoVector(file, sheetName);
        for (auto row : readData)
        {
            DepotDTO Dto;
            Dto.setName(row[0]);
            Dto.setCode(row[1]);
            Dto.setAuxName(row[2]);
            int phone = 0;
            istringstream ss(row[3]);
            ss >> phone;
            Dto.setPhone(phone);
            Dto.setStart(row[4]);
            Dto.setRemarks(row[5]);
            vDto.push_back(Dto);
        }
    }
    DepotService service;
    // �����ֿ�
    for (auto Dto : vDto) 
    { 
        if (service.saveData(Dto, payload.getUsername())) 
        {
            result.success(true);
        }
        else 
        {
            result.fail(false);
            break;
        }
    }
    return result;
}

JsonVO<string> DepotController::execExportExecl(const DepotQuery& query, const PayloadDTO& payload)
{
    DepotService service;
    // ����excel��
    string filename = u8"../../test/test.xlsx";
    vector<vector<string>> data;
    data.emplace_back(vector<std::string>({ u8"����", u8"���", u8"������", u8"�绰",\
        u8"����", u8"��ע", u8"����ʱ��",u8"������", u8"�޸�ʱ��", u8"�޸���" }));
    // ��ѯ����
    if (!service.getData(query, data))
        return JsonVO<string>(u8"����ʧ��", RS_FAIL);
    string sheetname = u8"test";
    ExcelComponent excel;
    excel.writeVectorToFile(filename, sheetname, data);
    // �ϴ����ļ�������
    FastDfsClient client("1.15.240.108");
    filename = client.uploadFile(filename);
    JsonVO<std::string> result(filename, RS_SUCCESS);
    //��Ӧ���
    return result;
}

JsonVO<string> DepotController::execExportExeclOnly(const OnlyValueQuery& query, const PayloadDTO& payload)
{
    DepotService service;
    // ����excel��
    string filename = u8"../../test/testids.xlsx";
    vector<vector<string>> data;
    data.emplace_back(vector<std::string>({ u8"����", u8"���", u8"������", u8"�绰",\
        u8"����", u8"��ע", u8"����ʱ��",u8"������", u8"�޸�ʱ��", u8"�޸���" }));
    // ��ѯ����
    if (!service.getDataById(query, data))
        return JsonVO<string>(u8"����ʧ��", RS_FAIL);
    string sheetname = u8"testids";
    ExcelComponent excel;
    excel.writeVectorToFile(filename, sheetname, data);
    // �ϴ����ļ�������
    FastDfsClient client("1.15.240.108");
    filename = client.uploadFile(filename);
    JsonVO<std::string> result(filename, RS_SUCCESS);
    //��Ӧ���
    return result;
}

