#pragma once

#include <vector>
#include <string>
#include "types.h"
#include "elementNode.h"
#include "textNode.h"
#include "xml_scanner.h"

namespace litehtml
{
/**
 *  读取html的字符流
 */
struct str_istream: public litehtml::instream
{
    const t_char *p;
    const t_char *end;

    str_istream(const t_char *src): p(src), end(src + strlen(src)) {}
    virtual t_char get_t_char()
    {
        return p < end ? *p++ : 0;
    }
};

/**
 * tag 数据结构体
 */
struct tags_parse_data
{
    const t_char *tag;
    const t_char *parents;
    const t_char *stop_parent;
};

/**
 * css 文本 结构体
 */
struct css_text
{
    typedef std::vector<css_text>   vector;

    tstring text;
    tstring baseurl;
    tstring media;

    css_text() {}

    css_text(const t_char *txt, const t_char *url, const t_char *media_str)
    {
//        text    = txt ? txt : _t("");
//        baseurl = url ? url : _t("");
//        media   = media_str ? media_str : _t("");
    }

    css_text(const css_text &val)
    {
        text    = val.text;
        baseurl = val.baseurl;
        media   = val.media;
    }
};

/**
 * Document 类头定义
 */
class Document:public litehtml::Object
{
private:
    ElementNode::Ptr                    m_root;
    ElementNode::ElementNodeVector      m_parse_stack;
    css_text::vector                    m_css;
    // 用于记录文本节点
    tstring                             m_tmpString;
public:
    typedef litehtml::ObjectPtr<Document> Ptr;
    static litehtml::Document::Ptr parseHtml(const t_char* str);
public:
    Document();
    virtual ~Document();
    ElementNode::Ptr createElementByTagName(const t_char* tagName);
private:
    void beginParse();
    void parseTagStart(const t_char* tagName);
    void parseTagEnd(const t_char* tagName);
    void parseAttribute(const t_char* attrName, const t_char* attrValue);
    void parseWord(const t_char* val);
    void parseSpace(const t_char* val);
    void parseCommentStart();
    void parseCommentEnd();
    void parseData(const t_char* val);
    void pushElement(ElementNode::Ptr node);
    bool popElement();
    void popEmptyElement();
    void popToParent(const t_char* parents, const t_char* stopParent);
    // 测试打印构造的dom 树结构
    void dump();
};
}




