
#include <stdio.h>
#include <string.h>

#include "./file-interface.h"
#include "./student.h"

#define STUDENTS_SIZE 3

void store() {
  printf("--------STORE---------\n");
  Student** students = malloc(sizeof(Student*) * STUDENTS_SIZE);
  students[0] = createStudent("Carlos Santiago", "1");
  students[1] = createStudent("Mauro Antonio", "2");
  students[2] = createStudent("Paulo Silva", "3");

  bool storeWithSuccess = storeStudents(students, STUDENTS_SIZE);
  if (!storeWithSuccess) {
    printf("Ocorreu um erro salvando os estudantes!");
    return;
  }
  showStudents(students, STUDENTS_SIZE);
}

void read() {
  printf("--------READ---------\n");
  int size;
  Student** students = readStudentFile(&size);

  if (students == NULL) {
    printf("Ocorreu um erro ao ler os estudantes!");
    return;
  }

  showStudents(students, size);
}

int main(int argc, char** argv) {
  if (argc != 1)
    store();
  else
    read();
}