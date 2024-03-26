//
// Created by user on 26.03.2024.
//

#ifndef CONSOLEAPP_INTERFACE_H
#define CONSOLEAPP_INTERFACE_H
#include <iostream>
#include <fstream>

using namespace std;


class Interface {
public:
    friend ostream &operator <<(ostream &os, Interface &anInterface);

    virtual void write(ostream &os) = 0;

    friend istream &operator >>(istream &is, Interface &anInterface);

    virtual void read(istream &is) = 0;

    virtual ~Interface() = default;
};


#endif //CONSOLEAPP_INTERFACE_H
