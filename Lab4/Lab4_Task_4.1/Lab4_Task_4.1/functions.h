#ifndef functions_h
#define functions_h

#include <stdio.h>
#include <alloca.h>
#include <stdlib.h>

void check(int *a);
int sort(char** base, int n, int* length, int* path);
int gamilton(int k, int** a, int* path, int n, int v0, int* c);
void memoryCheck(int *a);

#endif
