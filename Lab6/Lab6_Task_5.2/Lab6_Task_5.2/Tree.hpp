#ifndef Tree_hpp
#define Tree_hpp

#include <stdio.h>

struct tnode
{
    int field;
    int depth;
    tnode *left;
    tnode *right;
};

void treePrint(tnode *tree);
struct tnode *addNode(int x, tnode *tree, tnode *parent);
void freeMem(tnode *tree);

#endif
