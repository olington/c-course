#ifndef MAIN_FUNC_H
#define MAIN_FUNC_H

int arrayLen(FILE *fin);
void readFromFile(FILE *fin, int *pa, int count);
void printInFile(const int *array, const int *array_end, FILE *file);
int editArray(int *pa, int *pb, FILE *fin, FILE *fout, char *f);
void freeAll(FILE *fin, FILE *fout, int *pa);

#endif 