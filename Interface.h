//
// Created by user on 26.03.2024.
//

#ifndef CONSOLEAPP_INTERFACE_H
#define CONSOLEAPP_INTERFACE_H
#include <iostream>

using namespace std;


class Interface {
public:
    friend ostream &operator <<(ostream &os, Interface &anInterface);

    virtual void write(ostream &os) = 0;
};


#endif //CONSOLEAPP_INTERFACE_H
