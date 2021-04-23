#ifndef Tree_hpp
#define Tree_hpp

#include <stdio.h>

struct tnode
{
    int field;
    int depth;
    struct tnode *left;
    struct tnode *right;
};

void treePrint(tnode *tree);
struct tnode *addNode(int x, tnode *tree, tnode *parent);
void freeMem(tnode *tree);

#endif
