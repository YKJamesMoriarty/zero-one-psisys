package com.zeroone.star.project.user;

import com.zeroone.star.project.dto.user.UserDTO;
import com.zeroone.star.project.query.user.UserQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.PageVO;
import com.zeroone.star.project.vo.user.UserVO;

import java.util.List;

public interface UserApis {
    /**
     * 用户列表
     * @param query 查询条件
     * @return 查询结果
     */
    JsonVO<PageVO<UserVO>> listAllUsers(UserQuery query);

    /**
     * 查询用户
     * @param query 查询条件
     * @return 查询结果
     */
    JsonVO<PageVO<UserVO>> queryUser(UserQuery query);

    /**
     * 数据回显
     * @param id 用户id
     * @return 用户信息
     */
    JsonVO<UserVO> review(String id);

    /**
     * 新增用户
     * @param dto 数据对象
     * @return 新增用户的编号
     */
    JsonVO<String> addUser(UserDTO dto);

    /**
     * 删除用户
     * @param id 用户id
     * @return 删除用户的编号
     */
    JsonVO<String> deleteUser(String id);

    /**
     * 修改用户
     * @param dto 数据数据内容
     * @return 修改后的用户编号
     */
    JsonVO<String> modifyUser(UserDTO dto);

    /**
     * 冻结/解冻用户
     * @param id 用户id
     * @return 修改的用户编号
     */
    JsonVO<String> modifyStatus(String id);

    /**
     * 用户导入
     * @return
     */
    JsonVO<String> upload();

    /**
     * 导出选定用户
     * @param id 用户id
     * @return 下载地址
     */
    JsonVO<String> download(List<String> id);

    /**
     * 导出全部用户
     * @return 下载地址
     */
    JsonVO<String> downloadAllUsers();
}