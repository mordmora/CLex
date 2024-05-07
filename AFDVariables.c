#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>

enum Estado {
  INI,  // Estado inicial
  EAN,  // Estado Alfanumérico con Caracteres Especiales
  ERROR // Estado de Error
};

// LETRA - DIGITO - ESPECIAL
const enum Estado Transiciones[3][3] = {
    {EAN, ERROR, EAN},
    {EAN, EAN, EAN},
    {EAN, EAN, EAN}
};

enum Estado estadoSiguiente(enum Estado estadoActual, char letra) {
    if (isalpha(letra))
      return Transiciones[estadoActual][0];
    else if (isdigit(letra))
      return Transiciones[estadoActual][1];
    else if (letra == '_' || letra == '$')
      return Transiciones[estadoActual][2];
    else
      return ERROR;
}

bool esAceptado(enum Estado estadoActual) { return estadoActual == EAN; }

bool esVariable(const char *letra) {
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

  const char *variables[] = {
      "edad",     "_altura", "numeroDeTelefono", "Velocidad",   "miVariable",
      "a",        "b1",      "_variable1",       "$elemento",   "_",
      "$",        "1numero", "mi variable",      "mi-variable", "@variable",
      "!variable"};

  int n = sizeof(variables) / sizeof(variables[0]);

  for (int i = 0; i < n; i++) {
    if (esVariable(variables[i]))
      printf("%s es un nombre de variable válida.\n", variables[i]);
    else
      printf("%s es un nombre de variable inválida.\n", variables[i]);
  }

  char variable[100];

  printf("Ingrese el nombre de la variable: ");
  scanf("%s", variable);

  if (esVariable(variable)) {
    printf("El nombre de la variable es válido.\n");
  } else {
    printf("El nombre de la variable es inválido.\n");
  }

  return 0;
}