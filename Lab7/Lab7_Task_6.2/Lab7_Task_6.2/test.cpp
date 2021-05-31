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
    assert(gBase.sortList() == 0);
    
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
    
    Deal t, t2;
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
    
    t.Date.Day = t2.Date.Day = 5;
    t.Date.Month = t2.Date.Month = 5;
    t.Date.Year = t2.Date.Year = 1991;
    
    DiscountCard dc, dc2;
    dc.DiscountCardCode = "111111";
    dc.Discount = 2.34;
    dc2 = dc;
    dc2.DiscountCardCode = "12333";
    dcBase.add(dc);
    dcBase.add(dc2);
    
    assert(dcBase.getDiscount(01) == 1);
    assert(2e-10 > dcBase.getDiscount(111111) - 2.34);
    assert(dcBase.sortList() == 0);
    assert(dcBase.search(2) == 0);
    assert(dcBase.search(1000) == 1);
    
    t.GoodsVariety = t2.GoodsVariety = 1;
    t.Summ = 1;
    t2.Summ = 2;
    t.IfUsedCreditCard = false;
    t2.IfUsedCreditCard = true;
    t2.CreditCardCode = "1";
    t.IfUsedDiscount = false;
    t2.IfUsedDiscount = true;
    t2.UsedDiscountCard = dc;
    t.ListOfBuyedGoods = t2.ListOfBuyedGoods =&gBase;
    
    dBase.add(t);
    dBase.add(t2);
    dBase.swap(t,t2);
    
    assert(t.completeDate() == "5.5.1991");
    assert(t.Summ == 2);
    assert(dBase.search("123") == 1);
    assert(dBase.search("5.5.1991") == 0);
    assert(dBase.sortList() == 0);
    
    assert(dBase.printBase() == 0);
    assert(dcBase.printBase() == 0);
    
    for (int i = 0; i < 5; i++)
        assert(printMenu(i) == 0);
    assert(printMenu(5) == 1);
    assert(printMenu(-1) == 1);
    
    assert(gBase.fwrite("") == 1);
    assert(dBase.fwrite("") == 1);
    assert(dcBase.fwrite("") == 1);
    assert(gBase.fwrite("testfile1.txt") == 0);
    assert(dBase.fwrite("testfile2.txt") == 0);
    assert(dcBase.fwrite("testfile3.txt") == 0);
    
    GoodsList gBase2;
    DealList dBase2;
    DcardsList dcBase2;
    
    assert(gBase2.fwrite("testfile1.txt") == 1);
    assert(dBase2.fwrite("testfile2.txt") == 1);
    assert(dcBase2.fwrite("testfile3.txt") == 1);
    
    assert(gBase2.getPrice("BCODE") == -1);
    assert(gBase2.printBase() == 1);
    assert(gBase2.sortList() == 1);
    assert(gBase2.search("123") == 1);
    assert(gBase2.searchB(bcode) == 1);
    
    assert(dBase2.search("123") == 1);
    assert(dBase2.printBase() == 1);
    assert(dBase2.sortList() == 1);
    
    assert(dcBase2.printBase() == 1);
    assert(dcBase2.getDiscount(01) == 1);
    assert(dcBase2.sortList() == 1);
    assert(dcBase2.search(1000) == 1);
    
    DealDate dd;
    dateMark(dd);
    assert(dd.Day = 5);
    assert(dd.Day = 5);
    assert(dd.Day = 1991);
    
    bcodeCheck(bcode);
    assert(bcode == "TP000999");
    dBase.transaction(t, gBase, dcBase);
    dBase.transaction(t, gBase, dcBase);
    
    return 0;
}
#endif
