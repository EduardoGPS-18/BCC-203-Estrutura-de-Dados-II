
#include "text-file.h"

bool storeStudents(Student** students, int size) {
  FILE* file = fopen("../text-file.txt", "w");

  if (file == NULL) return false;

  fprintf(file, "%d\n", size);

  for (int i = 0; i < size; i++)
    fprintf(file, "%s %s\n", students[i]->name, students[i]->registration);

  if (ferror(file)) return false;

  return true;
}

Student** readStudents(int* pSize) {
  FILE* file = fopen("../text-file.txt", "r");

  if (file == NULL) return NULL;

  fscanf(file, "%d\n", pSize);

  int size = *pSize;

  Student** students = malloc(sizeof(Student*) * size);
  for (int i = 0; i < size; i++) {
    students[i] = malloc(sizeof(Student));
    fscanf(file, "%[a-z A-Z] %[1-9]\n", students[i]->name,
           students[i]->registration);
  }

  if (ferror(file)) return NULL;

  return students;
}
