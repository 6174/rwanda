#pragma once

#include <vector>
#include <string>
#include "types.h"
#include "elementNode.h"
#include "xml_scanner.h"

namespace litehtml
{
/**
 *  读取html的字符流
 */
struct str_istream: public litehtml::instream
{
    const char *p;
    const char *end;

    str_istream(const char *src): p(src), end(src + strlen(src)) {}
    virtual wchar_t get_char()
    {
        return p < end ? *p++ : 0;
    }
};

/**
 * tag 数据结构体
 */
struct tags_parse_data
{
    const char *tag;
    const char *parents;
    const char *stop_parent;
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

    css_text(const char *txt, const char *url, const char *media_str)
    {
        text    = txt ? txt : _t("");
        baseurl = url ? url : _t("");
        media   = media_str ? media_str : _t("");
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
public:
    typedef litehtml::ObjectPtr<Document> Ptr;
    static litehtml::Document::Ptr createFromString(const char* str);
public:
    Document();
    virtual ~Document();
    ElementNode::Ptr createElementByTagName(char* tagName);
private:
    void beginParse();
    void parseTagStart(const char* tagName);
    void parseTagEnd(const char* tagName);
    void parseAttribute(const char* attrName, const wchar* attrValue);
    void parseWord(const wchar* val);
    void parseSpace(const wchar* val);
    void parseCommentStart();
    void parseCommentEnd();
    void parseData(const wchar* val);
    void pushElement(ElementNode::Ptr node);
    bool popElement();
    bool popElement(const char* tag, const char* stopTags = _t(""));
    void popEmptyElement();
    void popToParent(const char* parents, const char* stopParent);
};
}




