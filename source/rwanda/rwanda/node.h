//
//  node.h
//  rwanda
//
//  Created by 6174 on 14-9-17.
//  Copyright (c) 2014年 6174. All rights reserved.
//

#ifndef rwanda_node_h
#define rwanda_node_h
#include "object.h"
#include <vector>
namespace litehtml
{
class Node:public litehtml::Object
{
public:
    typedef litehtml::ObjectPtr<litehtml::Node> Ptr;
    typedef std::vector<Ptr> NodeVector;
public:
    // 节点类型
    enum NodeType
    {
        ELEMENT_NODE, // 元素节点
        ATTR_NODE,    // 属性节点
        TEXT_NODE,    // 文本节点
        COMMENT_NODE  // 注释节点
    };

    NodeType nodeType;
    char *nodeName;

public:
    Node();
    virtual ~Node();
};
}

#endif
