#ifndef PRICE_H
#define PRICE_H

struct Price
{
    int grn;
    short int kop;
};

Price add(const Price& a, const Price& b);
Price multiply(const Price& a, int quantity);
void roundPrice(Price& p);
void print(const Price& p);

#endif