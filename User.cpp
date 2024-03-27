//
// Created by user on 26.03.2024.
//

#include "User.h"

User::User(): User("Guest") {}

User::User(std::string login):
    login{std::move(login)}{};

void User::write(std::ostream &os) {
    os << login;
}

void User::read(std::istream &is) {
    is >> login;
}

bool User::cmp() const {
    ifstream ifs("Users.txt");
    if (!ifs.is_open())
        return false;

    unique_ptr<User> user = make_unique<User>();
    while (ifs >> *user){
        if (user->login == login){
            ifs.close();
            return true;
        }
    }
    ifs.close();
    return false;
}

void User::erase() {
    ifstream ifs("Users.txt");
    if (!ifs.is_open())
        return;

    unique_ptr<User> user = make_unique<User>();
    vector<User> users;
    while (ifs >> *user){
        users.push_back(*user);
    }
    user.reset();

    auto it = users.begin();
    while(it!=users.end()){
        if (it->login == login){
            it = users.erase(it);
            break;
        }
        it++;
    }

    std::ofstream of("Users.txt");
    for (const User& user:users) {
        of << user.login << endl;
    }
    of.close();
}

