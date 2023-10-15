#include "./students.h"

char calcConcept(Students student) {
  int falts = atoi(student.falts);
  float middleMarks =
      (atoi(student.mark1) + atoi(student.mark2) + atoi(student.mark3)) / 3.0;
  if (falts > 18) return 'F';
  if (middleMarks < 6.0) return 'R';
  if (middleMarks >= 6.0 && middleMarks < 7.5) return 'C';
  if (middleMarks >= 7.5 && middleMarks < 9.0) return 'B';
  if (middleMarks >= 9.0 && middleMarks <= 10.0) return 'A';
  return 'N';
}

void convertToConcepts() {
  FILE* file = fopen("./alunos.txt", "r");
  FILE* conceptFile = fopen("./conceitos.txt", "w+");
  if (!file || !conceptFile) {
    exit(1);
  }

  int i = 0;
  while (!feof(file)) {
    Students student;

    fscanf(file, "%[0-9] %[a-z A-Z] %s %s %s %s\n", student.registry,
           student.name, student.mark1, student.mark2, student.mark3,
           student.falts);
    printf("%s ", student.name);
    printf("%s ", student.registry);
    printf("%s ", student.mark1);
    printf("%s ", student.mark2);
    printf("%s ", student.mark3);
    printf("%s\n", student.falts);

    fprintf(conceptFile, "%s %s %c\n", student.registry, student.name,
            calcConcept(student));
  }

  fclose(file);
  fclose(conceptFile);
}
