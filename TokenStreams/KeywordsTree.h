#pragma once
#include <vector>
#include <string>
#include <stack>
#include <map>
#include <iostream>


class KeywordsTree {
private:
    std::string keyword;
    std::map<std::string, std::stack<char>> tree;
    std::map<std::string, std::stack<char>> temp_tree;
    bool keyword_is_found = false;
    bool not_keyword = false;
public:
    KeywordsTree(std::vector<std::string> keywords);
    KeywordsTree(void);
    void refresh_temp_tree();
    void set_keywords(std::vector<std::string> keywords);
    void find_keyword(char input_key);
    bool has_found_not_keyword();
    bool has_found_keyword();
    std::string get_keyword();
};
