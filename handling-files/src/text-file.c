
#include "text-file.h"

bool storeStudent(Student* student) {
  FILE* file = fopen("../text-file.txt", "w");
  if (file == NULL) return false;

  fprintf(file, "%s %s", student->name, student->registration);
  if (ferror(file)) return false;

  return true;
}

bool storeStudents(Student** students, int size) {
  FILE* file = fopen("../text-file.txt", "w");
  if (file == NULL) return false;
  for (int i = 0; i < size; i++)
    fprintf(file, "%s %s\n", students[i]->name, students[i]->registration);

  if (ferror(file)) return false;

  return true;
}

Student** readStudents(int size) {
  FILE* file = fopen("../text-file.txt", "w");
  if (file == NULL) return false;
  // for (int i = 0; i < size; i++) {
  //   fscanf(file, "%s %s\n", students[i]->name, students[i]->registration);
  // }
  if (ferror(file)) return false;

  return true;
}

Student** readStudentFile() {}
