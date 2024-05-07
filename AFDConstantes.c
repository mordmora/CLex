#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>

const enum Estado {
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
const enum Estado Transiciones[10][4] = {
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

bool esConstante(const char *letra) {
  enum Estado estadoActual = INI;
  while (*letra != '\0') {
    estadoActual = estadoSiguiente(estadoActual, *letra);
    if (estadoActual == ERROR)
      return false;
    letra++;
  }
  return esAceptado(estadoActual);
}

int main() {

  const char *constantes[] = {
      "123",   "+123", "-123",  "1.23", ".123", "+.123", "-.123", "1E10",
      "1E-10", "1e10", "1e-10", "E",    "e",    "+E",    "-e",    "1E",
      "1e",    "3-E",  "3+E",   "1-e",  "1+e",  ".-1",   ".+1",   "1.2.3"};
  int n = sizeof(constantes) / sizeof(constantes[0]);

  for (int i = 0; i < n; i++) {
    if (esConstante(constantes[i]))
      printf("%s es una constante numérica válida.\n", constantes[i]);
    else
      printf("%s es una constante numérica inválida.\n", constantes[i]);
  }

  while (true) {
    char constante[100];

    printf("Digite constante numérica: ");
    scanf("%s", constante);

    if (esConstante(constante)) {
      printf("Valor de la constante numérica es válido.\n");
    } else {
      printf("Valor de la constante numérica es inválido.\n");
    }
  }

  return 0;
}
