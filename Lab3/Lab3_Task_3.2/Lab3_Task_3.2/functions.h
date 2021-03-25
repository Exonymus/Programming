#ifndef functions_h
#define functions_h

#include <stdio.h>

void check(int *a);
void printField(int m, int n, int** field);
int change(int num, int m, int n, int boarderSecond, int** field);
void pcChoice(int m, int n, int *rndM, int *rndN, int** field);
void plChoice(int m, int n, int *mPlayer, int *nPlayer, int** field);
void choiceCheckM(int m, int *mPlayer);
void choiceCheckN(int n, int *nPlayer);

#endif
