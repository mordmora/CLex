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
  NUM_CONSTAN,
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
  HASH,
  STRINGVAR
};

std::string tokenToStr(TokenType type){
  switch(type){
    case AUTO: return "AUTO";
    case MAIN: return "MAIN";
    case STRINGVAR : return "STRINGVAR";
    case DOUBLE: return "DOUBLE";
    case INT: return "INT";
    case STRUCT: return "STRUCT";
    case BREAK: return "BREAK";
    case ELSE: return "ELSE";
    case LONG: return "LONG";
    case SWITCH: return "SWITCH";
    case CASE: return "CASE";
    case ENUM: return "ENUM";
    case REGISTER: return "REGISTER";
    case TYPEDEF: return "TYPEDEF";
    case CHAR: return "CHAR";
    case STRING: return "STRING";
    case EXTERN: return "EXTERN";
    case RETURN: return "RETURN";
    case UNION: return "UNION";
    case CONST: return "CONST";
    case FLOAT: return "FLOAT";
    case SHORT: return "SHORT";
    case UNSIGNED: return "UNSIGNED";
    case CONTINUE: return "CONTINUE";
    case FOR: return "FOR";
    case SIGNED: return "SIGNED";
    case VOID: return "VOID";
    case DEFAULT: return "DEFAULT";
    case GOTO: return "GOTO";
    case SIZEOF: return "SIZEOF";
    case VOLATILE: return "VOLATILE";
    case DO: return "DO";
    case IF: return "IF";
    case STATIC: return "STATIC";
    case WHILE: return "WHILE";
    case PLUS: return "PLUS";
    case MINUS: return "MINUS";
    case ASTERISK: return "ASTERISK";
    case SLASH: return "SLASH";
    case LEFT_PAREN: return "LPAR";
    case RIGHT_PAREN: return "RPAR";
    case LEFT_BRACKET: return "LBRACKET";
    case RIGHT_BRACKET: return "RBRACKET";
    case LEFT_SQUARE_BRACKET: return "LSQUARE";
    case RIGHT_SQUARE_BRACKET: return "RSQUARE";
    case LESS_THAN: return "LESS_THAN";
    case GREATER_THAN: return "GREATER_THAN";
    case DOT: return "DOR";
    case COMMA: return "COMMA";
    case SEMICOLON: return "SEMICOLON";
    case PIPE: return "PIPE";
    case ASSIGN: return "EQUALS";
    case NOT: return "NOT";
    case AMPERSAND: return "AMPERSAND";
    case UNDERSCORE: return "UNDERSCORE";
    case PERCENT: return "PERCENT";
    case DOUBLE_QUOTES: return "DOUBLE_QUOTES";
    case SINGLE_QUOTES: return "SINGLE_QUOTES";
    case BACKSLASH: return "BACKSLASH";
    case HASH: return "HASH";
    case NUM_CONSTAN : return "NUM_CONSTAN";
    case IDENTIFIER: return "IDENTIFIER";
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