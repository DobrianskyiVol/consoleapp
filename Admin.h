//
// Created by user on 26.03.2024.
//

#ifndef CONSOLEAPP_ADMIN_H
#define CONSOLEAPP_ADMIN_H
#include "Interface.h"

class Admin: public Interface{
private:
    string login;
    string password;
public:
    Admin();

    Admin(string login, string password);

    void write(ostream &os) override;

    void read(istream &is) override;

    bool cmp(string nameoffile) const override;

    friend bool operator ==(const Admin &admin, const Admin &admin2);

    void erase() override;
};


#endif //CONSOLEAPP_ADMIN_H
