#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: akun
 @Date: 2023/2/14 00:15:01

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
#ifndef _PUR_QUOT_INTO_VO_
#define _PUR_QUOT_INTO_VO_

#include "../../GlobalInclude.h"

#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: akun
 @Date: 2023/2/14 00:15:01

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
#ifndef _PUR_QUOT_INTO_DTO_
#define _PUR_QUOT_INTO_DTO_
#include "../FileDTO.h"
class PurQuotIntoVO : public FileDTO {

	//单据编号
	CC_SYNTHESIZE(string, bill_no, bill_no);
	//单据日期
	CC_SYNTHESIZE(string, bill_date, bill_date);
	//已生效
	CC_SYNTHESIZE(int, is_effective, Is_effective);
	//已关闭
	CC_SYNTHESIZE(int, is_closed, Is_closed);
	//已作废
	CC_SYNTHESIZE(int, is_voided, Ss_voided);
	//单据主题
	CC_SYNTHESIZE(string, subject, subject);
	//付款方式
	CC_SYNTHESIZE(string, payment_method, payment_method);
	//交货地点
	CC_SYNTHESIZE(string, delivery_place, delivery_place);
	//联系人
	CC_SYNTHESIZE(string, contact,contact);
	//联系电话
	CC_SYNTHESIZE(string, phone, phone);
	//传真
	CC_SYNTHESIZE(string, fax, fax);
	//电子邮件
	CC_SYNTHESIZE(string, email, email);
	//备注
	CC_SYNTHESIZE(string, remark, remark);
	//附件
	CC_SYNTHESIZE(string, attachment, attachment);
public:
	BIND_TO_JSON(PurReqFindBillVO, bill_no, bill_date, is_effective, is_closed, is_voided,
		subject, payment_method, delivery_place,contact, phone, fax, email,remark, attachment);
};

#endif // !





