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
    ifstream ifs(nameoffile);
    if (!ifs.is_open())
        return false;
    unique_ptr<Ordering> ordering = make_unique<Ordering>();
    while (ifs >> *ordering){
        if (ordering->user.cmp(nameoffile))
            return (ordering->status == "Checked");
    }

    ifs.close();
    return false;
}

void Ordering::erase() {
    ofstream of("Orderings.txt");
    of.close();
}

void Ordering::showhistory(User &user1) {
    ifstream ifs("Orderings.txt");
    if (!ifs.is_open())
        return;
    unique_ptr<Ordering> ordering = make_unique<Ordering>();
    bool wasmentioned = false;
    while (ifs >> *ordering){
        if (ordering->user == user1){
            cout << "Food: ";
            ordering->order.showsingledish();
            cout << "\t" << "Status: " << status;
            wasmentioned = true;
        }
    }
    if (!wasmentioned)
        cout << "You dont have any history on that account:(. Let's fix that:)"<<endl;
    ifs.close();
}
