//
//  util.h
//  rwanda
//
//  Created by 6174 on 14-9-18.
//  Copyright (c) 2014年 6174. All rights reserved.
//

#ifndef rwanda_util_h
#define rwanda_util_h
#include "types.h"
#include <iostream>

namespace litehtml
{
    
    // 判断字符串val是否包含在string是中
    int value_in_list(const tstring& val, const tstring& strings, t_char delim = _t(';'));
    
    // 去除字符串padding
    void trim(tstring &s);
    
    // 字符串转小写
    void lcase(tstring &s);
    
    // 字符串strings中查找子串val的位置
    int value_index(const tstring& val, const tstring& strings, int defValue = -1, t_char delim = _t(';'));
    t_char* guid();
}
#endif
