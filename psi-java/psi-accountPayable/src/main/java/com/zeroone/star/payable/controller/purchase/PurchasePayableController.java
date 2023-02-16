package com.zeroone.star.payable.controller.purchase;

import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.zeroone.star.project.dto.payable.purchase.FinPayableDTO;
import com.zeroone.star.project.payable.purchasePayableAPI.PurchasePayableApis;
import com.zeroone.star.project.query.patable.purchase.PayableQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.payable.purchase.FinPayableVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.validation.annotation.Validated;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;

import org.springframework.web.bind.annotation.RestController;

/**
 * <p>
 * 应付单 前端控制器
 * </p>
 *
 * @author chosen1
 * @since 2023-02-14
 */
@RestController
@RequestMapping("/jeecg-boot/finance/finPayable/")
@Api(tags = "采购预付")
@Validated
public class PurchasePayableController implements PurchasePayableApis {

    @ApiOperation("分页查询所有单据")
    @GetMapping("list/201")
    @Override
    public JsonVO<Page<FinPayableVO>> listAll(FinPayableDTO payableDTO) {
        return null;
    }

    @ApiOperation("查询单据详情")
    @GetMapping("query")
    @Override
    public JsonVO<FinPayableVO> getById(@Validated PayableQuery query) {
        return null;
    }
}
