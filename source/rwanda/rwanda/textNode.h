//
//  textNode.h
//  rwanda
//
//  Created by 6174 on 14-9-19.
//  Copyright (c) 2014年 6174. All rights reserved.
//

#ifndef rwanda_textNode_h
#define rwanda_textNode_h
#include "types.h"
#include "elementNode.h"
#include <iostream>

namespace litehtml
{
    class TextNode:public litehtml::ElementNode
    {
    private:
        tstring m_val;
    public:
        typedef litehtml::ObjectPtr<TextNode> Ptr;
        typedef std::vector<Ptr> TextNodeVector;
    public:
        TextNode();
        TextNode(tstring val);
        ~TextNode();
        tstring text();
        void text(tstring val);
    };
}

#endif
