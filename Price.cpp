#include "Price.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void add(const Price& a, const Price& b, Price& result)
{
    result.grn = a.grn + b.grn;
    result.kop = a.kop + b.kop;

    result.grn += result.kop / 100;
    result.kop %= 100;
}

void multiply(const Price& p, int quantity, Price& result)
{
    result.grn = p.grn * quantity;
    result.kop = p.kop * quantity;

    result.grn += result.kop / 100;
    result.kop %= 100;
}

void roundPrice(Price& p)
{
    int lastDigit = p.kop % 10;

    if (lastDigit <= 7)
        p.kop -= lastDigit;
    else
        p.kop += (10 - lastDigit);

    if (p.kop >= 100) {
        p.grn += 1;
        p.kop -= 100;
    }
}

void print(const Price& p)
{
    cout << p.grn << " грн " << p.kop << " коп" << endl;
}

void processFile()
{
    ifstream file("prices.txt");

    if (!file) {
        cout << "Не вдалося відкрити файл!" << endl;
        return;
    }

    string name;
    Price item;
    int quantity;

    Price total = {0, 0};

    cout << "Список покупок:\n\n";

    while (file >> name >> item.grn >> item.kop >> quantity)
    {
        Price cost;
        multiply(item, quantity, cost);
        add(total, cost, total);

        cout << name << " : ";
        print(item);
        cout << "Кількість: " << quantity << endl;
        cout << "Вартість: ";
        print(cost);
        cout << "-------------------\n";
    }

    Price payment = total;
    roundPrice(payment);

    cout << "\nЗагальна сума: ";
    print(total);

    cout << "До оплати (після округлення): ";
    print(payment);
}