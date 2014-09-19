// xh_scanner_demo.cpp : Defines the entry point for the console application.
//
#include "stdio.h"
#include "document.h"
#include "util.h"

litehtml::Document::Document()
{
    // -- 构造函数
}

litehtml::Document::~Document()
{
    // -- 析构函数
}

/**
 * 工厂函数， 通过HTML字符串创建document实例对象
 */
litehtml::Document::Ptr litehtml::Document::createFromString(const char *str)
{
    // 创建document对象
    litehtml::Document::Ptr doc = new litehtml::Document();
    
    // 穿件字符流读入
    str_istream si(str);
    
    // 穿件scanner
    scanner sc(si);
    
    // 开始解析，生产root节点
    doc->beginParse();
    
    bool isEnd = false;
    tstring tmp_str;
    while (!isEnd && !doc->m_parse_stack.empty())
    {
        int t = sc.get_token();
        switch (t)
        {
            // 注释开始
            case scanner::TT_COMMENT_START:
                doc->parseCommentStart();
                break;
            // 注释结束
            case scanner::TT_COMMENT_END:
                doc->parseCommentEnd();
                break;
            // Data数据
            case scanner::TT_DATA:
                doc->parseData(sc.get_value());
                break;
            // 标签开始
            case  scanner::TT_TAG_START:
                printf("TAG START:%s\n", sc.get_tag_name());
                {
                    tmp_str = sc.get_tag_name();
                    lcase(tmp_str);
                    doc->parseTagStart(tmp_str.c_str());
                }
                break;
            // 标签闭合
            case  scanner::TT_TAG_END:
                printf("TAG END:%s\n", sc.get_tag_name());
                {
                    tmp_str = sc.get_tag_name();
                    lcase(tmp_str);
                    doc->parseTagEnd(tmp_str.c_str());
                }
                break;
            // 标签自闭合
            case scanner::TT_TAG_END_EMPTY:
                printf("TAG EMPTY END:%s\n", sc.get_tag_name());
                {
                    tmp_str = sc.get_tag_name();
                    lcase(tmp_str);
                    doc->parseTagEnd(tmp_str.c_str());
                }
                break;
            // 属性开始
            case  scanner::TT_ATTR:
                printf("\tATTR:%s=%S\n", sc.get_attr_name(), sc.get_value());
                {
                    tmp_str = sc.get_tag_name();
                    lcase(tmp_str);
                    doc->parseAttribute(tmp_str.c_str(), sc.get_value());
                }
                break;
            // 单词
            case  scanner::TT_WORD:
                doc->parseWord(sc.get_value());
                break;
            // 空格
            case  scanner::TT_SPACE:
                printf("{%S}\n", sc.get_value());
                doc->parseSpace(sc.get_value());
                break;
            // 错误
            case scanner::TT_ERROR:
                printf("Error\n");
                isEnd = true;
                break;
            // 结束
            case scanner::TT_EOF:
                printf("EOF\n");
                isEnd = true;
                break;
        }
    }
    return doc;
}

/**
 * 初始化根节点
 */
void litehtml::Document::beginParse() {
    char* tagName("div");
    m_root = createElementByTagName(tagName);
    m_parse_stack.push_back(m_root);
}

/**
 * 根据tag name 来穿件节点
 */
litehtml::ElementNode::Ptr litehtml::Document::createElementByTagName(char* tagName) {
    char* id = litehtml::guid();
    litehtml::ElementNode::Ptr element = new litehtml::ElementNode(id, tagName);
    return element;
}

/**
 * 解析标签开始
 */
void litehtml::Document::parseTagStart(const char* tagName) {
    
}

void litehtml::Document::parseTagEnd(const char *tagName) {
    
}

void litehtml::Document::parseAttribute(const char *attrName, const wchar *attrValue) {
    
}

void litehtml::Document::parseWord(const wchar *val) {
    
}

void litehtml::Document::parseSpace(const wchar *val) {
    
}

void litehtml::Document::parseCommentStart() {
    
}

void litehtml::Document::parseCommentEnd() {
    
}

void litehtml::Document::parseData(const wchar *val) {
    
}

void litehtml::Document::pushElement(ElementNode::Ptr node) {
    
}

bool litehtml::Document::popElement() {
    return true;
}

bool litehtml::Document::popElement(const char *tag, const char* stopTags) {
    return true;
}

void litehtml::Document::popEmptyElement() {
    
}

void litehtml::Document::popToParent(const char *parents, const char *stopParent) {
    
}










