#include "./student.h"

Student createStudent(char* name, char* registration) {
  Student student;
  strcpy(student.name, name);
  strcpy(student.registration, registration);
  return student;
}

void showStudent(Student student) {
  printf("%s %s", student.name, student.registration);
}

void showStudents(Student* students, int size) {
  for (int i = 0; i < size; i++) {
    showStudent(students[i]);
    printf("\n");
  }
}
