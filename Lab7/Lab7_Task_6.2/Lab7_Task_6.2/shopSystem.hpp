#ifndef shopSystem_hpp
#define shopSystem_hpp

#include <iostream>
#include <stdio.h>

using namespace  std;

struct ShopGoods
{
    string BarCode;
    long Price;
    string Name;
    int GoodBought;
    ShopGoods *Next, *Prev;
};

struct DiscountCard
{
    double Discount;
    string DiscountCardCode;
    DiscountCard *Next, *Prev;
};

struct DealDate
{
    short Year;
    short Month;
    short Day;
};

class GoodsList
{
    private:
        ShopGoods *head;
        ShopGoods *tail;
    public:
        GoodsList();
        void add(ShopGoods good);
        long getPrice(string bCode);
        void changeBought(string bCode, int amount);
        void search(string bCode);
        void searchB(string &bCode);
        void setGood(ShopGoods &good);
        void printBase() const;
        ShopGoods *getHead();
        void sortList();
        void swap(ShopGoods &a, ShopGoods &b);
        int fwrite();
};

struct Deal
{
    DealDate Date;
    int GoodsVariety;
    double Summ;
    bool IfUsedDiscount;
    DiscountCard UsedDiscountCard;
    bool IfUsedCreditCard;
    string CreditCardCode;
    GoodsList *ListOfBuyedGoods;
    string completeDate();
    Deal *Next, *Prev;
};

class DcardsList
{
    private:
        DiscountCard *head;
        DiscountCard *tail;
    public:
        DcardsList();
        void add(DiscountCard card);
        double getDiscount(int num);
        void search(int disc);
        void search(int &dcode, double &disc);
        void printBase() const;
        DiscountCard *getHead();
        void sortList();
        void swap(DiscountCard &a, DiscountCard &b);
        int fwrite();
};

class DealList
{
    private:
        Deal *head;
        Deal *tail;
    public:
        DealList();
        void add(Deal deal);
        void transaction(Deal &d, GoodsList base, DcardsList cardBase);
        void search(string date);
        void printBase() const;
        void sortList();
        void swap(Deal &a, Deal &b);
        int fwrite();
};

#endif