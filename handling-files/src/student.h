#ifndef STUDENT_H
#define STUDENT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char name[127];
  char registration[31];
} Student;

Student* createStudent(char* name, char* registration);
void showStudents(Student** students, int size);

#endif  // STUDENT_H