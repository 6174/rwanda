//
//  elementNode.cpp
//  rwanda
//
//  Created by 6174 on 14-9-17.
//  Copyright (c) 2014年 6174. All rights reserved.
//

#include "elementNode.h"

/**
 * 构造函数
 */
litehtml::ElementNode::ElementNode(char* guid,char *tagName)
{
    this->m_id = guid;
    this->nodeName = tagName;
    this->nodeType = Node::ELEMENT_NODE;
}

/**
 * 析构函数
 */
litehtml::ElementNode::~ElementNode()
{

}

/**
 * 获取父亲节点
 */
litehtml::Node *litehtml::ElementNode::parentNode()
{
    return m_parentNode;
}

/**
 * 设置父亲节点
 */
void litehtml::ElementNode::parentNode(litehtml::Node *node)
{
    m_parentNode = node;
}

/**
 * 添加child
 */
void litehtml::ElementNode::appendChild(litehtml::Node *node)
{
    this->m_children.push_back(node);
}

/**
 * 得到 children
 */
litehtml::Node::NodeVector &litehtml::ElementNode::children()
{
    return m_children;
}



