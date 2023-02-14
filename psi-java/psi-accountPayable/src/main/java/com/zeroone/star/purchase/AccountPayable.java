package com.zeroone.star.purchase;

import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.cloud.client.discovery.EnableDiscoveryClient;

/**
 * <p>
 * 启动类
 * </p>
 *
 * @author chosen1
 * @since 2023-02-14
 */
@SpringBootApplication
@EnableDiscoveryClient
public class AccountPayable {
    public static void main(String[] args) {
        SpringApplication.run(AccountPayable.class, args);
    }
}
