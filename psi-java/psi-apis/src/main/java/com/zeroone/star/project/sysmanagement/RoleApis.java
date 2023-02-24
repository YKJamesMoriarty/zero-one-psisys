package com.zeroone.star.project.sysmanagement;

import com.zeroone.star.project.vo.JsonVO;

import java.util.List;

/**
* 角色管理：对菜单和权限的操作
* @Author:阿狸
* @Version:1.1
*/
public interface RoleApis<T> {
    /**
     * 根据角色id(父id)查询角色所有能访问的菜单或权限列表
     * @param RId
     * @return 菜单或者权限列表
     */
    JsonVO<List<T>> listAll(String RId);

    /**
     * 根据用户选择的权限增加该用户的菜单或者权限列表
     * @param roles 要添加的权限id列表
     * @return 是否添加成功
     */
    JsonVO<Boolean> saveMenuOrPermission(T roles);

    /**
     * 根据用户的角色id和要删除的权限id，删除权限
     * @param Id
     * @return 是否删除成功
     */
    JsonVO<Boolean> deleteMenuOrPermission (String Id);
}
