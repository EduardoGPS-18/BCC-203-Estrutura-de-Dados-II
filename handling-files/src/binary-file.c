#include "./binary-file.h"

bool storeStudents(Student** students, int size) {
  FILE* file = fopen("../binary-file", "wb");
  if (ferror(file)) return false;

  fwrite(&size, 1, sizeof(int), file);
  if (ferror(file)) return false;

  for (int i = 0; i < size; i++) {
    fwrite(students[i], sizeof(Student), 1, file);
    if (ferror(file)) return false;
  }

  if (fclose(file) != 0) return false;

  return true;
}

Student** readStudents(int* pSize) {
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
  Student** students = malloc(sizeof(Student*) * size);
  for (int i = 0; i < size; i++) {
    students[i] = malloc(sizeof(Student));
    fread(students[i], sizeof(Student), 1, file);
    if (ferror(file)) {
      printf("Erro ao ler os estudantes!!\n");
      return NULL;
    }
  }

  if (fclose(file) != 0) {
    printf("Erro ao fechar o arquivo!\n");
    return NULL;
  }

  return students;
}