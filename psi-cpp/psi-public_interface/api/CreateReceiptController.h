#pragma once
#ifndef _CREATERECEIPTCONTROLLER_H_
#define _CREATERECEIPTCONTROLLER_H_
#include"../domain/vo/JsonVO.h"
#include"../domain/vo/CreateReceiptVO.h"
#include"../domain/dto/CreateReceiptDTO.h"
class CreateReceiptController {
public:
	CREATE_API_FUN_BODY(createReceipt, execCreateReceipt, CreateReceiptDTO);

private:
	JsonVO<CreateReceiptVO> execCreateReceipt(CreateReceiptDTO& dto);

};


#endif