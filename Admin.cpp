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

bool Admin::cmp() const {
    ifstream ifs("Admins.txt");
    if (!ifs.is_open())
        return false;

    unique_ptr<Admin> admin = make_unique<Admin>();
    while (ifs >> *admin){
        if (admin->password == password && admin->login == login){
            ifs.close();
            return true;
        }
    }
    ifs.close();
    return false;
}


bool operator ==(const Admin &admin, const Admin &admin2){
    return(admin.password == admin2.password && admin.login == admin2.login);
}
