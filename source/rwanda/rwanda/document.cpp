// xh_scanner_demo.cpp : Defines the entry point for the console application.
//
#include "stdio.h"
#include "document.h"
#include "xml_scanner.h"

litehtml::Document::Document() {
  // -- 构造函数
}

litehtml::Document::~Document() {
  // -- 析构函数
}

void litehtml::Document::createFromString(const char* str) {
  str_istream si(str);
  scanner sc(si);
  bool in_text = false;
  bool isEnd   = false;
  while(!isEnd) {
    int t = sc.get_token();
    switch(t) {
      case scanner::TT_ERROR:
        printf("Error\n");
        isEnd = true;
        break;
      case scanner::TT_EOF:
        printf("EOF\n");
        isEnd = true;
        break;
      case  scanner::TT_TAG_START:
        printf("TAG START:%s\n", sc.get_tag_name());
        break;
      case  scanner::TT_TAG_END:
        printf("TAG END:%s\n", sc.get_tag_name());
        break;
      case  scanner::TT_ATTR:
        printf("\tATTR:%s=%S\n", sc.get_attr_name(), sc.get_value());
        break;
      case  scanner::TT_WORD: 
      case  scanner::TT_SPACE:
        printf("{%S}\n", sc.get_value());
        break;
    }
  }
}
 