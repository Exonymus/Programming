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
    
    ShopGoods temp1, temp2;
    temp1.Name = "Pr1";
    temp1.Price = 100;
    temp1.BarCode = "BCODE";
    temp1.GoodBought = 1;
    temp2.Name = "Pr2";
    temp2.BarCode = "Bcode123";
    temp2.Price = 150;
    temp2.GoodBought = 1;
    
    gBase.add(temp1);
    gBase.add(temp2);
    gBase.swap(temp1, temp2);
    assert(temp1.Name == "Pr2");
    assert(temp2.Name == "Pr1");
    
    string bcode = "BCODE";
    assert(gBase.getPrice("BCODE") == 100);
    assert(gBase.getPrice("123") == -1);
    assert(gBase.changeBought("123", 1) == 1);
    assert(gBase.changeBought("BCODE", 1) == 0);
    assert(gBase.search("123") == 1);
    assert(gBase.searchB(bcode) == 0);
    assert(gBase.search("BCODE") == 0);
    
    assert(gBase.getHead() != NULL);
    assert(baseCheck(gBase, dcBase) == 1);
    assert(gBase.printBase() == 0);
    
    DiscountCard tempc;
    dcBase.add(tempc);
    
    assert(baseCheck(gBase, dcBase) == 0);
    
    assert(fileRead(gBase, dcBase, dBase, "shopHistory.txt", "", "") == 1);
    assert(fileRead(gBase, dcBase, dBase, "shopHistory.txt", "cardBase.txt", "") == 1);
    assert(fileRead(gBase, dcBase, dBase, "shopHistory.txt", "", "productBase.txt") == 1);
    assert(fileRead(gBase, dcBase, dBase, "shopHistory.txt", "cardBase.txt", "productBase.txt") == 0);
    assert(fileRead(gBase, dcBase, dBase, "", "", "") == 1);
    
    Deal t;
    t.Date.Day = 0;
    assert(t.completeDate() == "ERROR");
    
    t.Date.Day = 2;
    t.Date.Month = 0;
    assert(t.completeDate() == "ERROR");
    
    t.Date.Day = 5;
    t.Date.Month = 5;
    t.Date.Year = 0;
    assert(t.completeDate() == "ERROR");
    
    t.Date.Day = 5;
    t.Date.Month = 0;
    t.Date.Year = 5;
    assert(t.completeDate() == "ERROR");
    
    t.Date.Day = 0;
    t.Date.Month = 5;
    t.Date.Year = 5;
    assert(t.completeDate() == "ERROR");
    
    t.Date.Day = 5;
    t.Date.Month = 5;
    t.Date.Year = 1991;
    assert(t.completeDate() == "5.5.1991");
    
    for (int i = 0; i < 5; i++)
        assert(printMenu(i) == 0);
    assert(printMenu(5) == 1);
    assert(printMenu(-1) == 1);
    
    assert(gBase.fwrite("") == 1);
    assert(gBase.fwrite("testfile1.txt") == 0);
    
    GoodsList gBase2;
    assert(gBase2.fwrite("testfile1.txt") == 1);
    assert(gBase2.getPrice("BCODE") == -1);
    assert(gBase2.printBase() == 1);
    assert(gBase2.sortList() == 1);
    assert(gBase2.search("123") == 1);
    assert(gBase2.searchB(bcode) == 1);
    
    

    
    return 0;
}
#endif
