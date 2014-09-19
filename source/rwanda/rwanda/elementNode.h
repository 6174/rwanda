//
//  elementNode.h
//  rwanda
//
//  Created by 6174 on 14-9-17.
//  Copyright (c) 2014年 6174. All rights reserved.
//

#ifndef rwanda_elementNode_h
#define rwanda_elementNode_h
#include "node.h"
#include "object.h"
#include "types.h"
#include <vector>

namespace litehtml
{
class ElementNode: public litehtml::Node
{
public:
    typedef litehtml::ObjectPtr<litehtml::ElementNode>  Ptr;
    typedef std::vector<ElementNode::Ptr> ElementNodeVector;
private:
    Node::NodeVector m_children;
    Node*            m_parentNode;
    char*            m_id;
public:
    ElementNode(char* guid,char *tagName);
    ~ElementNode();
    virtual Node               *parentNode();
    virtual void                parentNode(Node *node);
    virtual Node::NodeVector   &children();
    virtual void                appendChild(Node *node);

    //   virtual const char*           get_tagName() const;
    //      virtual void                set_tagName(const char* tag);
    //        virtual void              set_attr(const char* name, const char* val);
    //      virtual const char*         get_attr(const char* name, const char* def = 0);
    //        virtual const char*           get_style_property(const char* name, bool inherited, const char* def = 0);

    //      virtual int                 select(const css_selector& selector, bool apply_pseudo = true);
    //      virtual int                 select(const css_element_selector& selector, bool apply_pseudo = true);
    //      virtual element::ptr        select_one(const tstring& selector);
    //      virtual element::ptr        select_one(const css_selector& selector);
    //      virtual Node*               find_ancestor(const css_selector& selector, bool apply_pseudo = true, bool* is_pseudo = 0);
    //      virtual Node*               find_adjacent_sibling(Node* el, const css_selector& selector, bool apply_pseudo = true, bool* is_pseudo = 0);
    //      virtual Node*               find_sibling(Node* el, const css_selector& selector, bool apply_pseudo = true, bool* is_pseudo = 0);

    //      virtual void                get_text(tstring& text);
    //      virtual void                parse_attributes();
};
}

#endif
