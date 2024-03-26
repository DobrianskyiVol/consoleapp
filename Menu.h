//
// Created by user on 26.03.2024.
//

#ifndef CONSOLEAPP_MENU_H
#define CONSOLEAPP_MENU_H
#include "Interface.h"

class Menu: public Interface{
private:
    string dish;
    double price;
    int weight;
public:
    Menu();

    Menu(string dish,double price,int weight);

    void write(ostream &os) override;

    void read(istream &is) override;

    ~Menu() = default;

    bool cmp() const override;

    void erase() override;
};


#endif //CONSOLEAPP_MENU_H
