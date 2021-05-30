#ifdef TEST
#include "functions.h"
#include <assert.h>

int main()
{
    GoodsList gBase;
    DcardsList dcBase;
    DealList dBase;
    
    assert(baseCheck(gBase, dcBase) == 1);
    cout << "Test 1 - Valid\n";
    
    assert(gBase.getHead() == NULL);
    cout << "Test 2 - Valid\n";
    
    ShopGoods temp;
    gBase.add(temp);
    
    assert(gBase.getHead() != NULL);
    cout << "Test 3 - Valid\n";
    
    assert(baseCheck(gBase, dcBase) == 1);
    cout << "Test 4 - Valid\n";
    
    DiscountCard tempc;
    dcBase.add(tempc);
    
    assert(baseCheck(gBase, dcBase) == 0);
    cout << "Test 5 - Valid\n";
    
    assert(fileRead(gBase, dcBase, dBase) == 1);
    cout << "Test 6 - Valid\n";
    
    Deal t;
    t.Date.Day = 0;
    assert(t.completeDate() == "ERROR");
    cout << "Test 7 - Valid\n";
    
    t.Date.Day = 5;
    t.Date.Month = 5;
    t.Date.Year = 0;
    assert(t.completeDate() == "ERROR");
    cout << "Test 8 - Valid\n";
    
    t.Date.Day = 5;
    t.Date.Month = 5;
    t.Date.Year = 1991;
    assert(t.completeDate() == "5.5.1991");
    cout << "Test 9 - Valid\n";
    
    

    
    return 0;
}
#endif
