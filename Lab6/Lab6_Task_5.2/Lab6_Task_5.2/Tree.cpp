#include "Tree.hpp"
#include <iostream>

void treePrint(tnode *tree)
{
    if (tree != NULL)
    {
        treePrint(tree->right);
        for (int i = 0; i < tree->depth * 5; i++)
            std::cout << " ";
        std::cout << tree->field << "\n";
        treePrint(tree->left);
    }
}

struct tnode *addNode(int x, tnode *tree, tnode *parent)
{
    if (tree == NULL)
    {
        tree = new tnode;
        tree->field = x;
        if(parent)
            tree->depth = parent->depth + 1;
        else
            tree->depth = 0;
        tree->left = NULL;
        tree->right = NULL;
    }
    else if (x <= tree->field)
        tree->left = addNode(x, tree->left, tree);
    else
        tree->right = addNode(x, tree->right, tree);
    
    return tree;
}

void freeMem(tnode *tree)
{
    if (tree != NULL)
    {
        freeMem(tree->left);
        freeMem(tree->right);
        delete tree;
    }
}
