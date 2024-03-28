#include "Menu.h"
Menu::Menu(): Menu("Unknown",0,0) {};

Menu::Menu(std::string dish, double price, int weight):
    dish{std::move(dish)},price{price},weight{weight}{};

void Menu::write(std::ostream &os) {
    os << dish << endl << price << endl << weight << endl;
}

void Menu::read(std::istream &is) {
    is >> dish >> price >> weight;
}

bool Menu::cmp(string nameoffile) const {
    ifstream ifs(nameoffile);
    if (!ifs.is_open())
        return false;

    unique_ptr<Menu> menu = make_unique<Menu>();
    while (ifs >> *menu){
        if (menu->dish == dish){
            ifs.close();
            return true;
        }
    }
    ifs.close();
    return false;
}

void Menu::erase() {
    ifstream ifs("Users.txt");
    if (!ifs.is_open())
        return;

    unique_ptr<Menu> menu = make_unique<Menu>();
    vector<Menu> menus;
    while (ifs >> *menu) {
        menus.push_back(*menu);
    }
    menu.reset();

    auto it = menus.begin();
    while (it != menus.end()) {
        if (it->dish == dish && it->price == price && it->weight == weight) {
            it = menus.erase(it);
            break;
        }
        it++;
    }

    std::ofstream of("Menus.txt");
    for (const Menu& menu:menus) {
        of << menu.dish<< endl << menu.price  << endl << menu.weight << endl;
    }
    of.close();
}

void Menu::showmenu() {
    ifstream ifs("Menu.txt");
    if (!ifs.is_open())
        return;

    unique_ptr<Menu> meal = make_unique<Menu>();
    cout << "Name" << "\t" << "Price" << "\t" << "Weight" << endl;
    while (ifs >> *meal){
        cout << meal->dish << "\t" << meal->price << "\t" << meal->weight << endl;
    }
    ifs.close();
    meal.reset();
}

void Menu::search(std::string &nameofdish) {
    ifstream ifs("Menu.txt");
    if (!ifs.is_open())
        return;

    unique_ptr<Menu> meal = make_unique<Menu>();
    while (ifs >> *meal){
        if (meal->dish == nameofdish){
            dish = meal->dish;
            price =meal->price;
            weight = meal->weight;
            ifs.close();
            meal.reset();
            break;
        }
    }
    cout << "You entered the wrong food name" << endl;
    ifs.close();
    meal.reset();
}

//Menu Menu::operator=(Menu &menu) const {

//    return menu;
//}