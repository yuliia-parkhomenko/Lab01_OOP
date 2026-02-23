#include <iostream>
#include <windows.h>
#include <fstream>
#include "Price.h"

using namespace std;

int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    ifstream file("prices.txt");

    if (!file) {
        cout << "Не вдалося відкрити файл!" << endl;
        return 1;
    }

    cout << "Файл відкрито успішно!" << endl;

    Price item;
    int quantity;
    Price total = {0, 0};

    while (file >> item.grn >> item.kop >> quantity) {
        cout << "Ціна: " << item.grn << " грн " << item.kop << " коп" << endl;
        cout << "Кількість: " << quantity << endl;
        cout << "------" << endl;

        Price cost = multiply(item, quantity);
        total = add(total, cost);
    }

    Price payment = total;
    roundPrice(payment);

    cout << "Загальна вартість: "
         << total.grn << " грн " << total.kop << " коп." << endl;

    cout << "До оплати (після округлення): "
         << payment.grn << " грн " << payment.kop << " коп." << endl;

    return 0;
}