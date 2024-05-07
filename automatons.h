#ifndef __AUTOMATONS_H__
#define __AUTOMATONS_H__

#include <string>
#include <iostream>
#include <stack>

enum stringStates {
   INITIAL,
    IN_STRING_DOUBLE,
    IN_STRING_SINGLE,
    ESCAPE_SEQUENCE,
    ERROR
};

bool validScapeChar(char c) {
    return c == 'n' || c == '0' || c == 'r' || c == 't' || c == '\\' || c == 'v' || c == 'f' || c == 'a' || c == '\'' || c == '"';
}

std::pair<int, std::string> strAutomaton(int actualIndex, std::string &str) {
    std::pair<int, std::string> result;
    int index = actualIndex - 1;
    std::stack <char> stack;



    for(char c : str) {
        if(c == '"') {
            if(stack.empty()) {
        }
    }

    std::cout<<"position: "<<str[index]<<std::endl;
    return {index, ""};
}

#endif