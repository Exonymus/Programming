#ifdef TEST
#include "functions.h"
#include <assert.h>

int main()
{
    GoodsList gBase;
    DcardsList dcBase;
    DealList dBase;
    
    assert(baseCheck(gBase, dcBase) == 1);
    assert(gBase.getHead() == NULL);
    
    ShopGoods temp;
    gBase.add(temp);
    
    assert(gBase.getHead() != NULL);
    assert(baseCheck(gBase, dcBase) == 1);
    
    DiscountCard tempc;
    dcBase.add(tempc);
    
    assert(baseCheck(gBase, dcBase) == 0);
    
    assert(fileRead(gBase, dcBase, dBase) == 0);
    
    Deal t;
    t.Date.Day = 0;
    assert(t.completeDate() == "ERROR");
    
    t.Date.Day = 2;
    t.Date.Month = 0;
    assert(t.completeDate() == "ERROR");
    
    t.Date.Day = 0;
    t.Date.Month = 5;
    t.Date.Year = 5;
    assert(t.completeDate() == "ERROR");
    
    t.Date.Day = 5;
    t.Date.Month = 5;
    t.Date.Year = 1991;
    assert(t.completeDate() == "5.5.1991");
    
    

    
    return 0;
}
#endif
