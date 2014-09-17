//
//  main.cpp
//  rwanda
//
//  Created by 6174 on 14-9-17.
//  Copyright (c) 2014年 6174. All rights reserved.
//

#include <iostream>
#include <vector>
#include "tokenizer.h"
#include "document.h"

void tokenHtml(const tstring &);
void scanHTML();
int main() {
	tstring str = "<div>\n<a href=""></a>\n</div>";
	tokenHtml(str);
	scanHTML();
	return 0;
}

void tokenHtml(const tstring& str) {
	std::cout << str
    << _t("\"")
    << std::endl;
    
	std::vector<tstring> result;
	tstring delimeter = _t("\n<>");
	tstring delimeter_preserve = _t("");
	tstring quote = _t("\"\'");
	tstring esc = _t("\\");
	litehtml::tokenize(str, result, delimeter, delimeter_preserve, quote, esc);
    
    std::cout << result.size() << std::endl;
	for(int i = 0; i < result.size(); i ++) {
        std::cout << "=== " << result[i] << std::endl;
	}
}

void scanHTML() {
    char* str = "<html><body><p align=right dir='rtl'>Begin &amp;<style>#body{width: 100px;} .a-class{float:left;}</style> back</p><a href=http://terrainformatica.com/index.php?a=1&b=2>link</a></body></html>";
    litehtml::Document* document = new litehtml::Document();
    document->createFromString(str);
}
