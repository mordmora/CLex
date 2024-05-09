#ifndef __AUTOMATONS_H__
#define __AUTOMATONS_H__

#include <string>
#include <iostream>
#include <stack>

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

enum Estado {
  INI,  // Estado inicial
  SAI,  // Estado de Signo al inicio
  DIG,  // Estado de Dígito
  PIS,  // Estado de Punto al inicio o después de Signo
  EXP,  // Estado de Símbolo de exponente
  PDD,  // Estado de Punto después de Dígito
  DDP,  // Estado de Dígito después de Punto
  SDE,  // Estado de Signo después de Exponencial
  DDE,  // Estado de Dígito después de Exponencial
  ERROR // Estado de Error
};

// SIGNO - DIGITO - EXPOTENTE - PUNTO
enum Estado Transiciones[10][4] = {
    {SAI, DIG, ERROR, PIS}, // INI
    {ERROR, DIG, ERROR, PIS}, //SAI
    {ERROR, DIG, EXP, PDD}, //DIG
    {ERROR, DDP, ERROR, ERROR}, //PIS
    {SDE, DDE, ERROR, ERROR}, //EXP
    {ERROR, DIG, EXP, ERROR}, //PDD
    {ERROR, DDP, EXP, ERROR},  //DDP
    {ERROR, DDE, ERROR, ERROR}, //SDE
    {ERROR, DDE, ERROR, ERROR}, //DDE
    {ERROR, ERROR, ERROR, ERROR} //ERROR
};

enum Estado estadoSiguiente(enum Estado estadoActual, char letra) {
    if (letra == '+' || letra == '-')
      return Transiciones[estadoActual][0];
    else if (isdigit(letra))
      return Transiciones[estadoActual][1];
    else if (tolower(letra) == 'e')
      return Transiciones[estadoActual][2];
    else if (letra == '.')
      return Transiciones[estadoActual][3];
    else 
      return ERROR;
}

bool esAceptado(enum Estado estadoActual) {
  return estadoActual == DIG || estadoActual == DDP || estadoActual == DDE;
}

bool isConstant(std::string letra) {
  enum Estado estadoActual = INI;
  int i = 0;
  while (i < letra.length()) {
    estadoActual = estadoSiguiente(estadoActual, letra[i]);
    if (estadoActual == ERROR)
      return false;
    i++;
  }
  return esAceptado(estadoActual);
}


#endif