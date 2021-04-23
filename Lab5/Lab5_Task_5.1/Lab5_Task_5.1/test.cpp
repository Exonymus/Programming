#ifdef TEST
#include "functions.h"
#include <assert.h>

int main()
{
    Queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);
    
    reverse(6, q);
    assert(q.pop() == 6);
    cout << "Test 1 - Valid\n";
    
    reverse(5, q);
    assert(q.pop() == 5);
    cout << "Test 2 - Valid\n";
    
    reverse(4, q);
    assert(q.pop() != 2);
    cout << "Test 3 - Valid\n";
    
    q.push(0);
    q.push(9);
    reverse(5, q);
    assert(q.pop() == 9);
    cout << "Test 4 - Valid\n";
    
    assert(q.isEmpty() == false);
    cout << "Test 5 - Valid\n";
    return 0;
}
#endif
