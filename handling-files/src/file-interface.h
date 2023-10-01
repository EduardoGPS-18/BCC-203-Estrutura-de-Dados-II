#ifndef FILE_INTERFACE_H
#define FILE_INTERFACE_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "./student.h"

bool storeStudents(Student** student, int size);
Student** readStudents(int* size);

#endif  // FILE_INTERFACE_H