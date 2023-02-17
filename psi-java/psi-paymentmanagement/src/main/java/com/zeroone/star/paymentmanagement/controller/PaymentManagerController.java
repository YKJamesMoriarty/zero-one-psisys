package com.zeroone.star.paymentmanagement.controller;

import com.zeroone.star.paymentmanagement.service.PaymentManagerService;
import com.zeroone.star.project.paymentManager.PaymentManagerApis;
import com.zeroone.star.project.vo.JsonVO;
import io.swagger.annotations.Api;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.validation.annotation.Validated;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;
import org.springframework.web.multipart.MultipartFile;

import javax.annotation.Resource;

@RestController
@RequestMapping("paymentmanager")
@Api(tags = "付款管理-采购付款")
@Validated
public class PaymentManagerController implements PaymentManagerApis {
    @Resource
    private PaymentManagerService paymentManagerService;

    @PostMapping("/import")
    @Override
    public JsonVO importAll(MultipartFile file) {
        paymentManagerService.importAll();
        return null;
    }

    @Override
    public JsonVO updateBillStage(Integer id) {
        paymentManagerService.updateBillStage(id);
        return null;
    }
}