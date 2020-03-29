#include "KeywordsTree.h"


void KeywordsTree::set_keywords(std::vector<std::string> keywords) {
    std::stack<char>* temp_stack;
    std::string reversed_keyword;
    for (std::string keyword: keywords) {
        reversed_keyword = std::string(keyword.rbegin(), keyword.rend());
        temp_stack = new std::stack<char>();
        for (char reversed_character : reversed_keyword) {
            temp_stack->push(reversed_character);
        }
        this->tree.insert(std::pair<std::string, std::stack<char>>(keyword, *temp_stack));
        delete temp_stack;
    }
    this->refresh_temp_tree();
}

void KeywordsTree::refresh_temp_tree() {
    this->not_keyword = false;
    this->keyword_is_found = false;
    this->temp_tree = std::map<std::string, std::stack<char>>(this->tree);
}

bool KeywordsTree::has_found_keyword() {
    return this->keyword_is_found;
}

bool KeywordsTree::has_found_not_keyword() {
    return this->not_keyword;
}

std::string KeywordsTree::get_keyword() {
    return this->keyword;
}

void KeywordsTree::find_keyword(char input_key) {
    std::vector<std::map<std::string, std::stack<char>>::iterator> to_erase;
    std::map<std::string, std::stack<char>>::iterator it;

    for (it = this->temp_tree.begin(); it != this->temp_tree.end(); it++) {
        if (it->second.empty()) {
            this->not_keyword = true;
            return;
        }
        if (it->second.top() != input_key) {
            to_erase.push_back(it);
            continue;
        }
        it->second.pop();
        
    }
    for (std::map<std::string, std::stack<char>>::iterator erase_it : to_erase) {
        this->temp_tree.erase(erase_it->first);
    }

    if (this->temp_tree.size() == 0) {
        this->not_keyword = true;
        return;
    }

    if (this->temp_tree.size() == 1) {
        if (this->temp_tree.begin()->second.size() == 0) {
            this->keyword_is_found = true;
            this->keyword = this->temp_tree.begin()->first;
        }
    }
}
