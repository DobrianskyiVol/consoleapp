//
// Created by user on 27.03.2024.
//

#include "Ordering.h"

Ordering::Ordering():
        Ordering(User(),Menu()){};

Ordering ::Ordering(const User& user, const Menu& order):
    user{user},order{order},status{"Checked"}{};

void Ordering::write(std::ostream &os) {
    os << user << order << status;
}

void Ordering::read(std::istream &is) {
    is >> user >> order >> status;
}

bool Ordering::cmp(string nameoffile) const {

    return false;
}

void Ordering::erase() {

}

