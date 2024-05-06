#include <vector>
#include <string>
#ifndef __LEXER_H__
#define __LEXER_H__

enum TokenType {
/*Tokens para las palabras claves */
  AUTO,
  MAIN,
  DOUBLE,
  INT,
  STRUCT,
  BREAK,
  ELSE,
  LONG,
  SWITCH,
  CASE,
  ENUM,
  REGISTER,
  TYPEDEF,
  CHAR,
  EXTERN, 
  RETURN,
  UNION,
  CONST,
  FLOAT,
  SHORT,
  UNSIGNED,
  CONTINUE,
  FOR,
  SIGNED,
  VOID,
  DEFAULT,
  GOTO,
  SIZEOF,
  VOLATILE,
  DO,
  IF,
  STATIC,
  WHILE,
  /*Tokens para los caracteres especiales y operadores*/
  PLUS,
  MINUS,
  ASTERISK,
  SLASH,
  LEFT_PAREN,
  RIGHT_PAREN,
  LEFT_BRACKET,
  RIGHT_BRACKET,
  LEFT_SQUARE_BRACKET,
  RIGHT_SQUARE_BRACKET,
  LESS_THAN,
  GREATER_THAN,
  DOT,
  COMMA,
  SEMICOLON,
  PIPE,
  ASSIGN,
  NOT,
  AMPERSAND,
  UNDERSCORE,
  PERCENT,
  MIDDLE_DASH,
  IDENTIFIER,
};

TokenType getAlphaNumericToken(std::string &identifierStr, std::vector<int> &tokens) {
      if(identifierStr == "auto"){
        tokens.push_back(AUTO);
      } else if(identifierStr == "main"){
        tokens.push_back(MAIN);
      } else if (identifierStr == "double"){
        tokens.push_back(DOUBLE);
      } else if (identifierStr == "int"){
        tokens.push_back(INT);
      } else if (identifierStr == "struct"){
        tokens.push_back(STRUCT);
      } else if (identifierStr == "break"){
        tokens.push_back(BREAK);
      } else if (identifierStr == "else"){
        tokens.push_back(ELSE);
      } else if (identifierStr == "long"){
        tokens.push_back(LONG);
      } else if (identifierStr == "switch"){
        tokens.push_back(SWITCH);
      } else if (identifierStr == "case"){
        tokens.push_back(CASE);
      } else if (identifierStr == "enum"){
        tokens.push_back(ENUM);
      } else if (identifierStr == "register"){
        tokens.push_back(REGISTER);
      } else if (identifierStr == "typedef"){
        tokens.push_back(TYPEDEF);
      } else if (identifierStr == "char"){
        tokens.push_back(CHAR);
      } else if (identifierStr == "extern"){
        tokens.push_back(EXTERN);
      } else if (identifierStr == "return"){
        tokens.push_back(RETURN);
      } else if (identifierStr == "union"){
        tokens.push_back(UNION);
      } else if (identifierStr == "const"){
        tokens.push_back(CONST);
      } else if (identifierStr == "float"){
        tokens.push_back(FLOAT);
      } else if (identifierStr == "short"){
        tokens.push_back(SHORT);
      } else if (identifierStr == "unsigned"){
        tokens.push_back(UNSIGNED);
      } else if (identifierStr == "continue"){
        tokens.push_back(CONTINUE);
      } else if (identifierStr == "for"){
        tokens.push_back(FOR);
      } else if (identifierStr == "signed"){
        tokens.push_back(SIGNED);
      } else if (identifierStr == "void"){
        tokens.push_back(VOID);
      } else if (identifierStr == "default"){
        tokens.push_back(DEFAULT);
      } else if (identifierStr == "goto"){
        tokens.push_back(GOTO);
      } else if (identifierStr == "sizeof"){
        tokens.push_back(SIZEOF);
      } else if (identifierStr == "volatile"){
        tokens.push_back(VOLATILE);
      } else if (identifierStr == "do"){
        tokens.push_back(DO);
      } else if (identifierStr == "if"){
        tokens.push_back(IF);
      } else if (identifierStr == "static"){
        tokens.push_back(STATIC);
      } else if (identifierStr == "while"){
        tokens.push_back(WHILE);
      }else{
        tokens.push_back(IDENTIFIER);
      }
}
//Diccionario de tokens especiales 
TokenType getSpecialsTokens(char c, std::vector<int> &tokens) {
  if(c == '+'){
        tokens.push_back(PLUS);
      } else if(c == '-'){
        tokens.push_back(MINUS);
      } else if(c == '*'){
        printf("Found *\n");
        tokens.push_back(ASTERISK);
      } else if(c == '/'){
        tokens.push_back(SLASH);
      } else if(c == '('){
        tokens.push_back(LEFT_PAREN);
      } else if(c == ')'){
        tokens.push_back(RIGHT_PAREN);
      } else if(c == '{'){
        tokens.push_back(LEFT_BRACKET);
      } else if(c == '}'){
        tokens.push_back(RIGHT_BRACKET);
      } else if(c == '['){
        tokens.push_back(LEFT_SQUARE_BRACKET);
      } else if(c == ']'){
        tokens.push_back(RIGHT_SQUARE_BRACKET);
      } else if(c == ';'){
        tokens.push_back(SEMICOLON);
      } else if(c == ','){
        tokens.push_back(COMMA);
      } else if(c == '<'){
        tokens.push_back(LESS_THAN);
      } else if(c == '>'){
        tokens.push_back(GREATER_THAN);
      } else if(c == '='){
        tokens.push_back(ASSIGN);
      } else if(c == '&'){
        tokens.push_back(AMPERSAND);
      } else if(c == '|'){
        tokens.push_back(PIPE);
      } else if(c == '_'){
        tokens.push_back(UNDERSCORE);
      } else if(c == '%'){
        tokens.push_back(PERCENT);
      } else if(c == '!'){
        tokens.push_back(NOT); 
      } else if(c == '.'){
        tokens.push_back(DOT);
      }
}

#endif