//
// Created by user on 26.03.2024.
//

#ifndef CONSOLEAPP_USER_H
#define CONSOLEAPP_USER_H
#include "Interface.h"

class User: public Interface{
private:
    string login;
public:
    User();

    User(string login);

    void write(ostream &os) override;

    void read(istream &is) override;

    ~User() = default;

    bool cmp(string nameoffile) const override;

    void erase() override;

};


#endif //CONSOLEAPP_USER_H
