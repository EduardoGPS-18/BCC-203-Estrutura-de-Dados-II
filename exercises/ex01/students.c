#include "students.h"

void writeFileFromStudents(Students** students, int studentsQuantity) {
  FILE* file = fopen("../students.txt", "w+");
  if (!file) {
    printf("Erro ao abrir o arquivo");
    exit(1);
  }

  for (int i = 0; i < studentsQuantity; i++) {
    Students* currentStudent = students[i];
    fprintf(file, "%4s %29s %4s %4s %4s %2s\n", currentStudent->registry,
            currentStudent->name, currentStudent->mark1, currentStudent->mark2,
            currentStudent->mark3, currentStudent->falts);
  }
  fclose(file);
}

Students* createStudents(char* registry, char* name, char* mark1, char* mark2,
                         char* mark3, char* falts) {
  Students* student = malloc(sizeof(Students));

  strcpy(student->name, name);
  strcpy(student->registry, registry);
  strcpy(student->falts, falts);
  strcpy(student->mark1, mark1);
  strcpy(student->mark2, mark2);
  strcpy(student->mark3, mark3);

  return student;
}
