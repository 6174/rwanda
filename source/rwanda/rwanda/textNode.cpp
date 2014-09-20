//
//  textNode.cpp
//  rwanda
//
//  Created by 6174 on 14-9-19.
//  Copyright (c) 2014年 6174. All rights reserved.
//

#include "textNode.h"

litehtml::TextNode::TextNode(){
    
}

litehtml::TextNode::TextNode(tstring val) {
    this->m_val = val;
    this->nodeType = Node::TEXT_NODE;
}

litehtml::TextNode::~TextNode(){
    
}

tstring litehtml::TextNode::text() {
    return m_val;
}

void litehtml::TextNode::text(tstring val) {
    m_val = val;
}


