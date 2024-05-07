#include<stdio.h>
#include <iostream>
#include <vector>
#include "tokens.h"
#include "automatons.h"
#include <stack>

//extern "C" int fopen(FILE** pFile, const char* filename, const char* mode);

std::string identifierStr;


void displayDebugInfo(std::string strTok) {
  std::cout << "[*] Lexer says: I found " << strTok << std::endl;
}

void lexer(std::string &str) {
  std::vector<TokenType> tokens;
  int index = 0;
  static int lastChar = ' ';

  while(index < str.length()){
    while(isspace(lastChar)){
      lastChar = str[index++];
    };
    if(isdigit(lastChar)){
      int num = lastChar - '0';
    } else if(isalpha(lastChar)){
      identifierStr = lastChar;
      while(isalnum((lastChar = str[index++]))) {
        identifierStr += lastChar;
        }
        if(getAlphaNumericToken(identifierStr) == IDENTIFIER) {
          displayDebugInfo(identifierStr);
        }else{
          displayDebugInfo(tokenToStr(getAlphaNumericToken(identifierStr)));
        }
     // displayDebugInfo(tokenToStr(getAlphaNumericToken(identifierStr)));
    }else{
      TokenType tokenAux = getSpecialsTokens(lastChar);
        std::pair<int, std::string> result;
      if(tokenAux == DOUBLE_QUOTES){
        result = stackAutomaton(str, index, '"');
        index = result.first + 1;
      } if(tokenAux == SINGLE_QUOTES){
        result = stackAutomaton(str, index, '\'');
        index = result.first + 1;
        }else{
        displayDebugInfo(tokenToStr(tokenAux));
      }
    }
    lastChar = str[index++];
  }
}


std::string transform(FILE*&file) {
  std::string str;
  char buffer[1024];

  while (!feof(file)) {
    size_t bytesRead = fread(buffer, sizeof(char), sizeof(buffer), file);

    if (bytesRead > 0) {
      str.append(buffer, bytesRead);
    }
  }
  fclose(file);
  return str;
}

int main() {
    FILE* file = fopen("test.txt", "r");
    std::vector<TokenType> tokens;
    std::string path = "test.txt";

    if(file == NULL){
        std::cout << "[*] Lexer says: Error file not found x(" << std::endl;
    } else {
        std::string str = transform(file);
        std::stack <TokenType> stack;
        lexer(str);

    }
    return 0;
    
}