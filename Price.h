#ifndef PRICE_H
#define PRICE_H

struct Price
{
    int grn;
    short int kop;
};

void add(const Price& a, const Price& b, Price& result);
void multiply(const Price& p, int quantity, Price& result);
void roundPrice(Price& p);
void print(const Price& p);
void processFile();

#endif