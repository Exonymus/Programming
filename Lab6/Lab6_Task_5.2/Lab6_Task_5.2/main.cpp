#include <iostream>
#include "Tree.hpp"

using namespace std;

int main()
{
    struct tnode *root = NULL;
    int arr[15] = {49, 28, 83, 18, 40, 71, 97, 11, 19, 32, 44, 69, 72, 92, 99};
    
    for (int i = 0; i < 15; i++)
        root = addNode(arr[i], root, NULL);
    
    treePrint(root);
    cout << "\n";
    freeMem(root);
    
    return 0;
}
