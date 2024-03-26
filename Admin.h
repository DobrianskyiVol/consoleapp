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
private:
    Admin();

    Admin(string login, string password);


};


#endif //CONSOLEAPP_ADMIN_H
