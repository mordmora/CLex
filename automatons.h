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

std::pair<int, std::string> stackAutomaton(std::string str, int actualIndex, char stackChar) {
    std::string result;
    int index = actualIndex - 1;
    std::stack <char> stack;
    while (index < str.length()) {
        if(str[index] == stackChar) {
            if(!stack.empty() && stack.top() == '"') {
                while(!stack.empty() && stack.top() != stackChar && index < str.length()) {
                    result += stack.top();
                    stack.pop();
                }
                stack.pop();
                return {index, result};
            } else {
                stack.push(stackChar); //Iniicio de un string
            }
        } else if (str[index] == '\\') {
            if(!stack.empty() && stack.top() == stackChar) {
                
                if(validScapeChar(str[++index]) == true) {
                    if(str[index] == '"' || str[index] == '\'') {
                        result += str[index];
                    }
                }
        }
    } else if (!stack.empty() && stack.top() == stackChar) {
        result += str[index];
        }
        index++;
    }
    return {index, result};
}

#endif