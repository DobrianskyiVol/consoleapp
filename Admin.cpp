//
// Created by user on 26.03.2024.
//

#include "Admin.h"


Admin::Admin(): Admin("Unknown","Abscent") {}

Admin::Admin(std::string login, std::string password):
    login{std::move(login)},password{std::move(password)}{}

void Admin::write(std::ostream &os) {
    os << login << endl << password << endl;
}

void Admin::read(std::istream &is) {
    is >> login >> password;
}