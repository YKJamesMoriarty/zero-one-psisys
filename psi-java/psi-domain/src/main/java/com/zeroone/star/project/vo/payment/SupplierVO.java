package com.zeroone.star.project.vo.payment;

import io.swagger.annotations.ApiModelProperty;


/**
 * @Author: Kong
 * @License: (C) Copyright 2005-2019, xxx Corporation Limited.
 * @Contact: xxx@xxx.com
 * @Date: 2023-02-11 21:20
 * @Version: 1.0
 * @Description:
 */

public class SupplierVO {
    /**
     * id
     */
    @ApiModelProperty(value = "id",example = "1623600860981665793")
    private String id;

    /**
     * 助记名
     */
    @ApiModelProperty(value = "助记名",example = "00001 公交卡")
    private String aux_name;

}