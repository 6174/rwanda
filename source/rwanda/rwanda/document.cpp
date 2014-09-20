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
litehtml::Document::Ptr litehtml::Document::parseHtml(const t_char *str)
{
    // 创建document对象
    litehtml::Document::Ptr doc = new litehtml::Document();
    
    // 穿件字符流读入
    str_istream si(str);
    
    // 创建scanner
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
                printf("\tATTR:%s=%s\n", sc.get_attr_name(), sc.get_value());
                {
                    tmp_str = sc.get_tag_name();
                    lcase(tmp_str);
                    doc->parseAttribute(tmp_str.c_str(), sc.get_value());
                }
                break;
            // 单词
            case  scanner::TT_WORD:
                printf("\tWORD:%s\n", sc.get_value());
                doc->parseWord(sc.get_value());
                break;
            // 空格
            case  scanner::TT_SPACE:
//                printf("{%S}\n", sc.get_value());
                doc->parseSpace(sc.get_value());
                break;
            // 错误
            case scanner::TT_ERROR:
                printf("Error\n");
                isEnd = true;
                break;
            // 结束
            case scanner::TT_EOF:
                printf("EOFA\n");
                isEnd = true;
                break;
        }
    }
    doc->dump();
    return doc;
}

/**
 * 初始化根节点
 */
void litehtml::Document::beginParse()
{
    const t_char* tagName("div");
    m_root = createElementByTagName(tagName);
    m_parse_stack.push_back(m_root);
}

/**
 * 根据tag name 来创建件节点
 */
litehtml::ElementNode::Ptr litehtml::Document::createElementByTagName(const t_char* tagName)
{
    t_char* id = litehtml::guid();
    litehtml::ElementNode::Ptr element = new litehtml::ElementNode(id, tagName);
    return element;
}

/**
 * 解析标签开始
 */
void litehtml::Document::parseTagStart(const t_char* tagName)
{
    litehtml::ElementNode::Ptr element = new litehtml::ElementNode(litehtml::guid(), tagName);
    pushElement(element);
}

/**
 * 解析标签结束
 */
void litehtml::Document::parseTagEnd(const t_char *tagName)
{
    if (!m_parse_stack.empty())
    {
        // tagName 和 上一个元素tagName相同
        if (!t_strcmp(m_parse_stack.back()->nodeName, tagName))
        {
            litehtml::TextNode::Ptr textNode = new litehtml::TextNode(m_tmpString);
            std::cout << "\t TEXT" << m_tmpString << std::endl;
            m_tmpString = "";
            m_parse_stack.back()->appendChild(textNode);
            popElement();
        }
        else
        {
            printf("how can it be diferent %s", tagName);
        }
    }
}

/**
 * 解析属性
 */
void litehtml::Document::parseAttribute(const t_char *attrName, const t_char *attrValue)
{
    if (!m_parse_stack.empty()) {
        m_parse_stack.back()->setAttribute(attrName, attrValue);
    }
}

/**
 * 遇到单词
 */
void litehtml::Document::parseWord(const t_char *val) {
//    tstring tmp(val);
//    m_tmpString += tmp;
//    std::cout << "\t\t VAL " << m_tmpString << std::endl;
}

/**
 * 遇到空格
 */
void litehtml::Document::parseSpace(const t_char *val)
{
    m_tmpString += *val;
}

void litehtml::Document::parseCommentStart()
{
    
}

void litehtml::Document::parseCommentEnd()
{
    
}

void litehtml::Document::parseData(const t_char *val)
{
    
}

/**
 * 往stack里边push元素节点
 */
void litehtml::Document::pushElement(ElementNode::Ptr node)
{
    if (!m_parse_stack.empty())
    {
        m_parse_stack.back()->appendChild(node);
        m_parse_stack.push_back(node);
    }
}

/**
 * stack pop 元素
 */
bool litehtml::Document::popElement()
{
    if (!m_parse_stack.empty()) {
        m_parse_stack.pop_back();
        return true;
    }
    return false;
}


void litehtml::Document::popEmptyElement()
{
    
}

void litehtml::Document::popToParent(const t_char *parents, const t_char *stopParent)
{
    
}


void litehtml::Document::dump()
{
    litehtml::TextNode::Ptr textNode = new litehtml::TextNode("hellotext");
    
    litehtml::Node *node = textNode;
    
    litehtml::TextNode *a;
    a = dynamic_cast<litehtml::TextNode *>(node);
    if (a) {
        tstring str = a->text();
        std::cout << str;
    }
}












