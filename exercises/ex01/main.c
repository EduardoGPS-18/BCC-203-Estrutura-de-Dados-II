#include <stdio.h>
#include <stdlib.h>

#include "./students.h"

int main() {
  Students** students = malloc(sizeof(Students*) * 3);

  students[0] = createStudents("1", "Carlos", "5.5", "2.3", "3.3", "1");
  students[1] = createStudents("2", "Pedro", "6.0", "2.0", "1.0", "4");
  students[2] = createStudents("3", "Thiago", "7.8", "5.3", "10.0", "3");

  writeFileFromStudents(students, 3);

  return 0;
}