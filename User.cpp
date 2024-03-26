//
// Created by user on 26.03.2024.
//

#include "User.h"

User::User(): User("Guest") {}

User::User(std::string login):
    login{std::move(login)}{}