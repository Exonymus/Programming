#include "shopSystem.hpp"
#include "functions.h"

string Deal::completeDate()
{
    return to_string(Date.Day) + '.' + to_string(Date.Month) + '.' + to_string(Date.Year);
}

GoodsList::GoodsList()
{
   head = tail = NULL;
}

void GoodsList::add(ShopGoods good)
{
    ShopGoods *buf  = new ShopGoods;
    
    buf->BarCode = good.BarCode;
    buf->GoodBought = good.GoodBought;
    buf->Name = good.Name;
    buf->Price = good.Price;
    
    if (!head)
    {
        buf->Next = tail;
        head = buf;
        buf->Prev = NULL;
    }
    else
    {
        buf->Next = tail->Next;
        buf->Prev = tail;
        tail->Next = buf;
    }
    tail = buf;
}

long GoodsList::getPrice(string bCode)
{
    if (head)
    {
        ShopGoods *buf = head;
        while (buf)
        {
            if (buf->BarCode == bCode)
                return buf->Price;
        }
        cout << "Ошибка. Неизвестный продукт.";
    }
    else cout << "Ошибка. База пуста.\n";
    return NULL;
}

void GoodsList::setGood(ShopGoods &good)
{
    ShopGoods *seargood = head;
    while (seargood)
    {
        if (seargood->BarCode == good.BarCode)
        {
            good.Name = seargood->Name;
            good.Price = seargood->Price;
            return;
        }
        seargood = seargood->Next;
    }
}

void GoodsList::changeBought(string bCode, int amount)
{
    ShopGoods *temp = head;
    while (temp)
    {
        if (temp->BarCode == bCode)
        {
            temp->GoodBought += amount;
            return;
        }
        temp = temp->Next;
    }
}

void GoodsList::printBase() const
{
    if (head)
    {
        ShopGoods *buf = head;
        while (buf)
        {
            cout << "\nШтрихкод: " << buf->BarCode
            << "  Название: " << buf->Name
            << "  Цена: " << buf->Price
            << "  Продано: " << buf->GoodBought;
            
            buf = buf->Next;
        }
        cout << endl;
    }
    else cout << "Ошибка. База пуста.\n";
}

void GoodsList::delHead()
{
    if (head) {
        ShopGoods *buf = head;
        head = head->Next;
        head->Prev = NULL;
        delete buf;
    }
    else cout << "Ошибка. База пуста.\n" << endl;
}
 
void GoodsList::delTail()
{
    if (tail)
    {
        ShopGoods *buf = tail;
        tail = tail->Prev;
        tail->Next = NULL;
        delete buf;
    }
    else
        cout << "Ошибка. База пуста.\n" << endl;
}

void GoodsList::swap(ShopGoods &a, ShopGoods &b)
{
    ShopGoods temp;
    temp.Name = a.Name;
    temp.BarCode = a.BarCode;
    temp.GoodBought = a.GoodBought;
    temp.Price = a.Price;
    
    a.Name = b.Name;
    a.Price = b.Price;
    a.BarCode = b.BarCode;
    a.GoodBought = b.GoodBought;
    
    b.Name = temp.Name;
    b.Price = temp.Price;
    b.BarCode = temp.BarCode;
    b.GoodBought = temp.GoodBought;
}
 
void GoodsList::sortList()
{
    ShopGoods *buf = head;
    for (ShopGoods *i = buf; i; i = i->Next)
        for (ShopGoods *j = i->Next; j; j = j->Next)
            if (i->Price < j->Price)
                swap(*i, *j);
}

ShopGoods *GoodsList::getHead()
{
    return head;
}

void GoodsList::search(string bCode, bool menu)
{
    if (head)
    {
        ShopGoods *buf = head;
        int amount = 0;
        if (menu)
            cout << "\t\tРезультат поиска:\n";
        while (buf)
        {
            if (buf->BarCode == bCode)
            {
                amount++;
                if (menu)
                    cout << amount << ")  Название: " << buf->Name
                         << "  Цена: " << buf->Price
                         << "  Продано: " << buf->GoodBought << endl;
            }
            
            buf = buf->Next;
        }
        if (amount && !menu)
            return;
        if (!amount)
        {
            if (menu)
                cout << "Ошибка. Товар не найден.";
            else
            {
                cout << "Штрихкод неверен!\n";
                bcodeCheck(bCode);
                search(bCode, false);
            }
        }
    }
    else
        cout << "Ошибка. База пуста.\n";
}

DcardsList::DcardsList()
{
   head = tail = NULL;
}

void DcardsList::add(DiscountCard good)
{
    DiscountCard *buf  = new DiscountCard;
    
    buf->Discount = good.Discount;
    buf->DiscountCardCode = good.DiscountCardCode;
    
    if (!head)
    {
        buf->Next = tail;
        head = buf;
        buf->Prev = NULL;
    }
    else
    {
        buf->Next = tail->Next;
        buf->Prev = tail;
        tail->Next = buf;
    }
    tail = buf;
}

double DcardsList::getDiscount(int num)
{
    if (head)
    {
        DiscountCard *buf = head;
        while (buf)
        {
            if (buf->DiscountCardCode == to_string(num))
                return buf->Discount;
        }
        cout << "Ошибка. Неверный код карты.";
    }
    else
        cout << "Ошибка. База пуста.\n";
    return NULL;
}

void DcardsList::printBase() const
{
    if (head)
    {
        DiscountCard *buf = head;
        cout << "\t\tБаза Cкидочных Карт:";
        while (buf)
        {
            cout << "\nНомер Карты: " << buf->DiscountCardCode
            << "  Объем скидки: " << buf->Discount << "%";
            
            buf = buf->Next;
        }
        cout << endl;
    }
    else
        cout << "Ошибка. База пуста.\n";
}

void DcardsList::delHead()
{
    if (head)
    {
        DiscountCard *buf = head;
        head = head->Next;
        head->Prev = NULL;
        delete buf;
    }
    else
        cout << "Ошибка. База пуста.\n" << endl;
}
 
void DcardsList::delTail()
{
    if (tail)
    {
        DiscountCard *buf = tail;
        tail = tail->Prev;
        tail->Next = NULL;
        delete buf;
    }
    else
        cout << "Ошибка. База пуста.\n" << endl;
}

void DcardsList::swap(DiscountCard &a, DiscountCard &b)
{
    DiscountCard temp;
    temp.Discount = a.Discount;
    temp.DiscountCardCode = a.DiscountCardCode;
    
    a.Discount = b.Discount;
    a.DiscountCardCode = b.DiscountCardCode;
    
    b.Discount = temp.Discount;
    b.DiscountCardCode = temp.DiscountCardCode;
}
 
void DcardsList::sortList()
{
    DiscountCard *buf = head;
    for (DiscountCard *i = buf; i; i = i->Next)
        for (DiscountCard *j = i->Next; j; j = j->Next)
            if (i->Discount < j->Discount)
                swap(*i, *j);
}

void DcardsList::search(int disc)
{
    if (head)
    {
        DiscountCard *buf = head;
        int amount = 0;
        cout << "\t\tРезультат поиска:\n";
        while (buf)
        {
            if (buf->Discount < disc + 1 && buf->Discount > disc - 1)
            {
                amount++;
                cout << amount << ") Номер Карты: " << buf->DiscountCardCode
                     << "  Объем скидки: " << buf->Discount << "%" << endl;
            }
            
            buf = buf->Next;
        }
        if (!amount)
            cout << "Ошибка. Карты не найдены.";
    }
    else
        cout << "Ошибка. База пуста.\n";
}

void DcardsList::search(string dcode, double &disc)
{
    bool checked = false;
    DiscountCard *searcard = head;
    while (searcard)
    {
        if (searcard->DiscountCardCode == dcode)
        {
            disc = searcard->Discount;
            checked = true;
        }
        searcard = searcard->Next;
    }
    
    if (!checked)
    {
        cout << "Введенный код карты отсуствует в базе. Повторите ввод: ";
        int code;
        check(&code, 10000000, 99999999);
        search(to_string(code), disc);
    }
}

DiscountCard *DcardsList::getHead()
{
    return head;
}

DealList::DealList()
{
   head = tail = NULL;
}

void DealList::add(Deal deal)
{
    Deal *buf  = new Deal;
    
    buf->Date = deal.Date;
    buf->GoodsVariety = deal.GoodsVariety;
    buf->Summ = deal.Summ;
    buf->IfUsedDiscount = deal.IfUsedDiscount;
    buf->UsedDiscountCard = deal.UsedDiscountCard;
    buf->IfUsedCreditCard = deal.IfUsedCreditCard;
    buf->CreditCardCode = deal.CreditCardCode;
    buf->ListOfBuyedGoods = deal.ListOfBuyedGoods;
    
    if (!head)
    {
        buf->Next = tail;
        head = buf;
        buf->Prev = NULL;
    }
    else
    {
        buf->Next = tail->Next;
        buf->Prev = tail;
        tail->Next = buf;
    }
    tail = buf;
}

void DealList::printBase() const
{
    if (head)
    {
        int i = 0;
        Deal *buf = head;
        cout << "\t\tИстория покупок:";
        while (buf)
        {
            i++;
            cout << "\n" << i << ") Дата покупки: " << buf->completeDate()
                 << "\nКол-во товаров: " << buf->GoodsVariety
                 << "\nСумма чека: " << buf->Summ
                 << "\n\tСписок покупок: ";
            buf->ListOfBuyedGoods->printBase();
            
            if (buf->IfUsedDiscount)
                cout << "Номер скидочной карты: " << buf->UsedDiscountCard.DiscountCardCode
                     << "\tОбъем скидки: " << buf->UsedDiscountCard.Discount << "%" << endl;
            else
                cout << "Скидочная карта не использовалась.\n";
            
            if (buf->IfUsedCreditCard)
                cout << "Номер кредитной карты: " << buf->CreditCardCode;
            else
                cout << "Кредитная карта не использовалась.";
            
            buf = buf->Next;
            if (buf)
                cout << endl;
        }
        cout << endl;
    }
    else cout << "Ошибка. База пуста.\n";
}

void DealList::delHead()
{
    if (head) {
        Deal *buf = head;
        head = head->Next;
        head->Prev = NULL;
        delete buf;
    }
    else cout << "Ошибка. База пуста.\n" << endl;
}
 
void DealList::delTail()
{
    if (tail)
    {
        Deal *buf = tail;
        tail = tail->Prev;
        tail->Next = NULL;
        delete buf;
    }
    else
        cout << "Ошибка. База пуста.\n" << endl;
}

void DealList::swap(Deal &a, Deal &b)
{
    Deal temp;
    
    temp.Date = a.Date;
    temp.GoodsVariety = a.GoodsVariety;
    temp.Summ = a.Summ;
    temp.IfUsedDiscount = a.IfUsedDiscount;
    temp.UsedDiscountCard = a.UsedDiscountCard;
    temp.IfUsedCreditCard = a.IfUsedCreditCard;
    temp.CreditCardCode = a.CreditCardCode;
    temp.ListOfBuyedGoods = a.ListOfBuyedGoods;
    
    a.Date = b.Date;
    a.GoodsVariety = b.GoodsVariety;
    a.Summ = b.Summ;
    a.IfUsedDiscount = b.IfUsedDiscount;
    a.UsedDiscountCard = b.UsedDiscountCard;
    a.IfUsedCreditCard = b.IfUsedCreditCard;
    a.CreditCardCode = b.CreditCardCode;
    a.ListOfBuyedGoods = b.ListOfBuyedGoods;
    
    b.Date = temp.Date;
    b.GoodsVariety = temp.GoodsVariety;
    b.Summ = temp.Summ;
    b.IfUsedDiscount = temp.IfUsedDiscount;
    b.UsedDiscountCard = temp.UsedDiscountCard;
    b.IfUsedCreditCard = temp.IfUsedCreditCard;
    b.CreditCardCode = temp.CreditCardCode;
    b.ListOfBuyedGoods = temp.ListOfBuyedGoods;
}
 
void DealList::sortList()
{
    Deal *buf = head;
    for (Deal *i = buf; i; i = i->Next)
        for (Deal *j = i->Next; j; j = j->Next)
            if (i->Summ < j->Summ)
                swap(*i, *j);
}

void DealList::search(string date)
{
    if (head)
    {
        Deal *buf = head;
        int amount = 0;
        cout << "\t\tРезультат поиска:";
        while (buf)
        {
            if (buf->completeDate() == date)
            {
                amount++;
                cout << "\n" << amount << ") Дата покупки: " << buf->completeDate()
                     << "\nКол-во товаров: " << buf->GoodsVariety
                     << "\nСумма чека: " << buf->Summ
                     << "\n\tСписок покупок: ";
                buf->ListOfBuyedGoods->printBase();
                
                if (buf->IfUsedDiscount)
                    cout << "Номер скидочной карты: " << buf->UsedDiscountCard.DiscountCardCode
                         << "\tОбъем скидки: " << buf->UsedDiscountCard.Discount << "%" << endl;
                else
                    cout << "Скидочная карта не использовалась.\n";
                
                if (buf->IfUsedCreditCard)
                    cout << "Номер кредитной карты: " << buf->CreditCardCode;
                else
                    cout << "Кредитная карта не использовалась.";
                    cout << endl;
            }
            
            buf = buf->Next;
        }
        if (!amount)
            cout << "Ошибка. Товары не найден.";
    }
    else
        cout << "Ошибка. База пуста.\n";
}

void DealList::transaction(Deal &d, GoodsList base, DcardsList cardBase)
{
    dateMark(d.Date);
    GoodsList *goods = new GoodsList;
    double rawSumm = 0;
    d.GoodsVariety = 0;
    
    cout << "\t\tВвод продуктов:\n";
    while(true)
    {
        ShopGoods temp;
        string barcode;
        int checked, amount;
        
        bcodeCheck(barcode);
        base.search(barcode, false);
        temp.BarCode = barcode;
        base.setGood(temp);
        
        cout << "Введите кол-во продукта: ";
        cin >> amount;
        base.changeBought(barcode, amount);
        temp.GoodBought = amount;
        d.GoodsVariety++;
        rawSumm += base.getPrice(barcode) * amount;
        goods->add(temp);
        
        cout << "Чтобы завершить ввод продуктов введите 0, чтобы продолжить - 1: ";
        check(&checked, 0, 1);
        
        if (checked == 0)
            break;
        else
            checked = -1;
    }
    
    d.ListOfBuyedGoods = goods;
    
    int code;
    double disc;
    cout << "Если Вы используете скидочную карту, введите ее номер(если нет введите 0):\n";
    check(&code, 0, 99999999);
    
    if ((code && code < 10000000) || code < 0)
    {
        cout << "Ввод не верен! Повторите ввод: ";
        check(&code, 10000000, 99999999);
        
    }
    else
        d.IfUsedDiscount = false;
    
    if (code)
    {
        d.IfUsedDiscount = true;
        cardBase.search(to_string(code), disc);
        d.UsedDiscountCard.DiscountCardCode = to_string(code);
        d.UsedDiscountCard.Discount = disc;
        rawSumm = rawSumm * (100 - disc) / 100;
    }
    
    d.Summ = rawSumm;
    
    cout << "Если Вы используете кредитную карту, введите ее номер(если нет введите 0):\n";
    check(&code, 0, 99999999);
    if ((code && code < 10000000) || code < 0)
    {
        cout << "Ввод не верен! Повторите ввод: ";
        check(&code, 10000000, 99999999);
    }
    else
        d.IfUsedCreditCard = false;
    
    if (code)
    {
        d.CreditCardCode = to_string(code);
        d.IfUsedCreditCard = true;
    }
}
