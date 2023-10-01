#include "./binary-file.h"

bool storeStudent(Student student) {}

bool storeStudents(Student* students, int size) {
  FILE* file = fopen("../binary-file", "wb");
  if (ferror(file)) return false;

  fwrite(&size, 1, sizeof(int), file);
  if (ferror(file)) return false;

  fwrite(students, sizeof(Student), size, file);
  if (ferror(file)) return false;

  if (fclose(file) != 0) {
    return false;
  }

  return true;
}

Student readStudent() {}

Student* readStudentFile(int* pSize) {
  FILE* file = fopen("../binary-file", "rb");
  if (ferror(file)) {
    printf("Erro ao abrir o arquivo!!\n");
    return NULL;
  }

  fread(pSize, sizeof(int), 1, file);
  if (ferror(file)) {
    printf("Erro ao ler o tamanho!\n");
    return NULL;
  }

  int size = (*pSize);
  Student* students = malloc(sizeof(Student) * size);
  fread(students, sizeof(Student), size, file);
  if (ferror(file)) {
    printf("Erro ao ler os estudantes!!\n");
    return NULL;
  }

  if (fclose(file) != 0) {
    printf("Erro ao fechar o arquivo!\n");
    return NULL;
  }

  return students;
}