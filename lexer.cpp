#include<stdio.h>
#include <iostream>
#include <vector>
#include "lexer.h"

//extern "C" int fopen(FILE** pFile, const char* filename, const char* mode);

std::string identifierStr;

static std::vector<int> lexer(std::string &str) {
  std::vector<int> tokens;
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
      while(isalnum((lastChar = str[index]))) {
        identifierStr += str[index++];
        }
      getAlphaNumericToken(identifierStr, tokens);
    }else{
      getSpecialsTokens(lastChar, tokens);
    }
    lastChar = str[index++];
  }
  return tokens;
}


std::string transform(FILE*&file) {
  std::string str;
  char buffer[1024];

  while (!feof(file)) {
    size_t bytesRead = fread(buffer, sizeof(char), sizeof(buffer), file);

    if (bytesRead > 0) {
      str.append(buffer, bytesRead);
      std::cout << "[*] Lexer says: i found --> " << str << " <-- in file"  << std::endl;
    }
  }
  fclose(file);
  return str;
}

int main() {
    FILE* file = fopen("test.txt", "r");
    std::vector<int> tokens;
    std::string path = "test.txt";

    if(file == NULL){
        std::cout << "[*] Lexer says: Error file not found x(" << std::endl;
    } else {
        std::string str = transform(file);
        tokens = lexer(str);
        for(int i = 0; i < tokens.size(); i++){
            std::cout << tokens[i] << std::endl;
        }
    }
    return 0;
}