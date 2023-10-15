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

void writeFileFromStudents(Students** students, int studentsQuantity);

Students* createStudents(char* registry, char* name, char* mark1, char* mark2,
                         char* mark3, char* falts);

#endif  // ALUNOS_H