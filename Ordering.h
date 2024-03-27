//
// Created by user on 27.03.2024.
//

#ifndef CONSOLEAPP_ORDERING_H
#define CONSOLEAPP_ORDERING_H
#include "Interface.h"
#include "User.h"
#include "Menu.h"

class Ordering: public Interface{
private:
    User user;
    Menu order;
    string status;
public:
    Ordering();

    Ordering(const User& user, const Menu& order);

    void write(ostream &os) override;

    void read(istream &is) override;

    ~Ordering() = default;

    bool cmp(string nameoffile) const override;

    void erase() override;
};


#endif //CONSOLEAPP_ORDERING_H
