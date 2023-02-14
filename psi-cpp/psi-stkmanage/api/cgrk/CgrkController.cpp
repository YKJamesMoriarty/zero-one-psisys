/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 10:58:42

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
#include "stdafx.h"
#include "CgrkController.h"




JsonVO<PageVO<CgrkQueryVO>> CgrkController::execCgrkQuery(const CgrkQuery& query)
{
	PageVO<CgrkQueryVO> result;
	return JsonVO<PageVO<CgrkQueryVO>>(result, RS_FAIL);
}

JsonVO<PageVO<CgrkBillDetailsVO>> CgrkController::execCgrkBillDetailsQuery(const CgrkBillDetailsQuery& query)
{
	PageVO<CgrkBillDetailsVO> result;
	return JsonVO<PageVO<CgrkBillDetailsVO>>(result, RS_SUCCESS);
}