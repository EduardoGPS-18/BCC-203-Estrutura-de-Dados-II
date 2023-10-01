#ifndef FILE_INTERFACE_H
#define FILE_INTERFACE_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "./student.h"

bool storeStudent(Student student);
bool storeStudents(Student* student, int size);

Student readStudent();
Student* readStudentFile();

#endif  // FILE_INTERFACE_H