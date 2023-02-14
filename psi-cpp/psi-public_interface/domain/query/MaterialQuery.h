#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: yunjj
 @Date: 2023/2/14 14.26

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
#ifndef _MATERIALQUERY_
#define _MATERIALQUERY_

#include "../GlobalInclude.h"

class MaterialQuery
{
    //���ϵı���
    CC_SYNTHESIZE(uint64_t, code, Code);
    //���ϵ�����
    CC_SYNTHESIZE(std::string, name, Name);
    //���ϵķ���
    CC_SYNTHESIZE(std::string, type, Type); 
public:
    // ��from_json
    friend void from_json(const json& j, MaterialQuery& t) { // NOLINT
        BIND_FROM_TO_NORMAL(j, t, name);
        BIND_FROM_TO_NORMAL(j, t, type);
        BIND_FROM_TO_ULL(j, t, code);
    }

};

#endif// !_MATERIALQUERY_