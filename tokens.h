#include <vector>
#include <string>
#ifndef __LEXER_H__
#define __LEXER_H__

enum TokenType {
/*Tokens para las palabras claves */
  AUTO,
  MAIN,
  STRING,
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
  IDENTIFIER,
  QUESTION_MARK,
  DOUBLE_QUOTES,
  SINGLE_QUOTES,
  BACKSLASH,
  HASH
};

std::string tokenToStr(TokenType type){
  switch(type){
    case AUTO: return "auto";
    case MAIN: return "main";
    case DOUBLE: return "double";
    case INT: return "int";
    case STRUCT: return "struct";
    case BREAK: return "break";
    case ELSE: return "else";
    case LONG: return "long";
    case SWITCH: return "switch";
    case CASE: return "case";
    case ENUM: return "enum";
    case REGISTER: return "register";
    case TYPEDEF: return "typedef";
    case CHAR: return "char";
    case STRING: return "string";
    case EXTERN: return "extern";
    case RETURN: return "return";
    case UNION: return "union";
    case CONST: return "const";
    case FLOAT: return "float";
    case SHORT: return "short";
    case UNSIGNED: return "unsigned";
    case CONTINUE: return "continue";
    case FOR: return "for";
    case SIGNED: return "signed";
    case VOID: return "void";
    case DEFAULT: return "default";
    case GOTO: return "goto";
    case SIZEOF: return "sizeof";
    case VOLATILE: return "volatile";
    case DO: return "do";
    case IF: return "if";
    case STATIC: return "static";
    case WHILE: return "while";
    case PLUS: return "+";
    case MINUS: return "-";
    case ASTERISK: return "*";
    case SLASH: return "/";
    case LEFT_PAREN: return "(";
    case RIGHT_PAREN: return ")";
    case LEFT_BRACKET: return "{";
    case RIGHT_BRACKET: return "}";
    case LEFT_SQUARE_BRACKET: return "[";
    case RIGHT_SQUARE_BRACKET: return "]";
    case LESS_THAN: return "<";
    case GREATER_THAN: return ">";
    case DOT: return ".";
    case COMMA: return ",";
    case SEMICOLON: return ";";
    case PIPE: return "|";
    case ASSIGN: return "=";
    case NOT: return "!";
    case AMPERSAND: return "&";
    case UNDERSCORE: return "_";
    case PERCENT: return "%";
    case DOUBLE_QUOTES: return "\"";
    case SINGLE_QUOTES: return "'";
    case BACKSLASH: return "\\";
    case HASH: return "#";
    case IDENTIFIER: return "";
    default: return "ERROR: Token no definido";
  }
};

TokenType getAlphaNumericToken(std::string &identifierStr) {
      if(identifierStr == "auto"){
        return AUTO;
      } else if(identifierStr == "main"){
        return MAIN;
      } else if (identifierStr == "double"){
        return DOUBLE;
      } else if (identifierStr == "int"){
        return INT;
      } else if (identifierStr == "struct"){
        return STRUCT;
      } else if (identifierStr == "break"){
        return BREAK;
      } else if (identifierStr == "else"){
        return ELSE;
      } else if (identifierStr == "long"){
        return LONG;
      } else if (identifierStr == "switch"){
        return SWITCH;
      } else if (identifierStr == "case"){
        return CASE;
      } else if (identifierStr == "enum"){
        return ENUM;
      } else if (identifierStr == "register"){
        return REGISTER;
      } else if (identifierStr == "typedef"){
        return TYPEDEF;
      } else if (identifierStr == "char"){
        return CHAR;
      } else if (identifierStr == "extern"){
        return EXTERN;
        
      } else if (identifierStr == "return"){
        return RETURN;
      } else if (identifierStr == "union"){
        return UNION;
      } else if (identifierStr == "const"){
        return CONST;
      } else if (identifierStr == "float"){
        return FLOAT;
      } else if (identifierStr == "short"){
        return SHORT;
      } else if (identifierStr == "unsigned"){
        return UNSIGNED;
      } else if (identifierStr == "continue"){
        return CONTINUE;
      } else if (identifierStr == "for"){
        return FOR;
      } else if (identifierStr == "signed"){
        return SIGNED;
      } else if (identifierStr == "string"){
        return STRING;
      } else if (identifierStr == "void"){
        return VOID;
      } else if (identifierStr == "default"){
        return DEFAULT;
      } else if (identifierStr == "goto"){
        return GOTO;
      } else if (identifierStr == "sizeof"){
        return SIZEOF;
      } else if (identifierStr == "volatile"){
        return VOLATILE;
      } else if (identifierStr == "do"){
        return DO;
      } else if (identifierStr == "if"){
        return IF;
      } else if (identifierStr == "static"){
        return STATIC;
      } else if (identifierStr == "while"){
        return WHILE;
      }else{
        return IDENTIFIER;
      }
}
//Diccionario de tokens especiales 
TokenType getSpecialsTokens(char c) {
  if(c == '+'){
    return PLUS;
      } else if(c == '-'){
        return MINUS;
      } else if(c == '*'){
        return ASTERISK;
      } else if(c == '/'){
        return SLASH;
      } else if(c == '('){
        return LEFT_PAREN;
      } else if(c == ')'){
        return RIGHT_PAREN;
      } else if(c == '{'){
        return LEFT_BRACKET;
      } else if(c == '}'){
        return RIGHT_BRACKET;
      } else if(c == '['){
        return LEFT_SQUARE_BRACKET;
      } else if(c == ']'){
        return RIGHT_SQUARE_BRACKET;
      } else if(c == ';'){
        return SEMICOLON;
      } else if(c == ','){
        return COMMA;
      } else if(c == '<'){
        return LESS_THAN;
      } else if(c == '>'){
        return GREATER_THAN;
      } else if(c == '='){
        return ASSIGN;
      } else if(c == '&'){
        return AMPERSAND;
      } else if(c == '|'){
        return PIPE;
      } else if(c == '_'){
        return UNDERSCORE;
      } else if(c == '%'){
        return PERCENT;
      } else if(c == '!'){
        return NOT; 
      } else if(c == '.'){
        return DOT;
      } else if(c == '?'){
        return QUESTION_MARK;
      } else if (c == '"'){
        return DOUBLE_QUOTES;
      } else if(c == '\''){
        return SINGLE_QUOTES;
      } else if(c == '#'){
        return HASH;
      } else if (c == '\\'){
        return BACKSLASH;
      }
}

#endif