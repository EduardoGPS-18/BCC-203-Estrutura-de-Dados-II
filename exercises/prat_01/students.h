#ifndef ALUNOS_H
#define ALUNOS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char registry[4];
  char name[29];
  char mark1[4];
  char mark2[4];
  char mark3[4];
  char falts[2];
} Students;

void convertToConcepts();

#endif  // ALUNOS_H