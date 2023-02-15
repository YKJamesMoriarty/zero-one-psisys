package com.zeroone.star.project.payable;

import com.zeroone.star.project.vo.JsonVO;
import org.springframework.web.multipart.MultipartFile;

/**
 * <p>
 * 描述：应付核销接口定义
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 *
 * @author naturezh
 * @version 1.0.0
 */
public interface checkApis {

    /**
     * 文件导出
     * return 返回下载路径
     * author naturezh
     */
    JsonVO<String> fileExport();

    /**
     * 文件导入
     * return 返回状态
     * author naturezh
     */
    JsonVO<String> fileImport(MultipartFile file);

}
