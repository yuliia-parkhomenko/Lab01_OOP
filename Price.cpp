#include "Price.h"
#include <iostream>

using namespace std;

Price add(const Price& a, const Price& b)         
{  
    Price result;
    result.grn = a.grn + b.grn;
    result.kop = a.kop + b.kop;

    if(result.kop >= 100)
    {
        result.grn += result.kop / 100;
        result.kop %= 100;
    }
      return result;
}

Price multiply(const Price& p, int quantity)
{ 
    Price result;
    result.grn = p.grn * quantity;
    result.kop = p.kop * quantity;

    {
        result.grn += result.kop / 100;
        result.kop %= 100;
    }
      return result;

}

void roundPrice(Price& p)
{
    if (p.kop <= 24)
     p.kop = 0;

    else if (p.kop <= 74)
     p.kop = 50;

    else{
     p.kop = 0;
     p.grn += 1;
    }   
}

void print(const Price& p)
{
 cout << p.grn << "грн" << p.kop << "коп" << endl;
}
