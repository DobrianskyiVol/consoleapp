#include <iostream>
#include "Admin.h"
#include "Ordering.h"
#include <cstdlib>


using namespace std;

void write(string &nameoffile, Interface &obj){
    ofstream of(nameoffile,ios::app);
    if (!of.is_open())
        return;
    of << obj;
    of.close();
}

void read(string &nameoffile, Interface &obj){
    ifstream ifs(nameoffile);
    if (!ifs.is_open())
        return;
    while (ifs >> obj){
        cout << obj;
    }
}

bool check(string &nameoffile, Interface &obj){
    return obj.cmp(nameoffile);
}

int main() {
    int option;
    string orderings, admins, menus, users;
    orderings = "Orderings.txt";
    admins = "Admins.txt";
    menus = "Menu.txt";
    users = "Users.txt";

    cout << "Welcome to restaurant console application" << endl;
    cout << "Firstly identify yourself " << endl;

    while (true){
        cout << "Input 0 to exit" << endl;
        cout << "Input 1 if you want to enter as admin " << endl;
        cout << "Input 2 if - user" << endl;
        cin >> option;
        if (option == 1){
            bool statement = false;
            unique_ptr<Interface> admin = make_unique<Admin>();
            for (int i = 0; i < 3; ++i) {
                cout << "Enter login and password";
                cin >> *admin;
                if (check(admins,*admin)){
                    statement = true;
                    cout << "Welcome back master:) " << endl;
                    break;
                } else
                    cout << "You entered wrong data;(" << "Please try again. You have " << 3-(i+1) << " more tries" << endl;
            }
            while (statement){
                cout << "Here is your humble functionality: " << endl;
                cout << "0 - to exit"<<endl;
                cout << "1 - to add new admin" << endl;
                cout << "2 - to fire some admin" << endl;
                cout << "3 - to add new meal into Menu " << endl;
                cout << "4 - to erase some meal from the menu" << endl;
                cout << "5 - to clear the Ordering list" << endl;
                cin >> option;

                if (option == 0)
                    break;

                switch (option) {
                    case 1:{
                        unique_ptr<Interface> newadmin = make_unique<Admin>();
                        cout << "Enter new admins login and password:" << endl;
                        cin >> *newadmin;
                        write(admins, *newadmin);
                        newadmin.reset();
                        system("pause");
                        break;
                        };
                    case 2:{
                        unique_ptr<Interface> eraseadmin = make_unique<Admin>();
                        cout << "Enter admin login and password to erase " << endl;
                        cin >> *eraseadmin;
                        if (check(admins,*eraseadmin))
                            eraseadmin->erase();
                        else
                            cout << "There aren't such admins:)" << endl;
                        eraseadmin.reset();
                        system("pause");
                        break;
                    };
                    case 3:{
                        unique_ptr<Interface> newdish = make_unique<Menu>();
                        cout << "Enter new dish name,price and weight" << endl;
                        cin >> *newdish;
                        write(menus,*newdish);
                        newdish.reset();
                        system("pause");
                        break;
                    }
                    case 4:{
                        unique_ptr<Interface> deleteddish = make_unique<Menu>();
                        cout << "Enter dish which you want to delete: " << endl;
                        cin >> *deleteddish;
                        if (deleteddish->cmp(menus))
                            deleteddish->erase();
                        else
                            cout << "It seems there wasn't such kind of food:)" << endl;
                        deleteddish.reset();
                        system("pause");
                        break;
                    };
                    case 5:{
                        unique_ptr<Interface> order = make_unique<Ordering>();
                        order->erase();
                        order.reset();
                        system("pause");
                        break;
                    };
                    default:
                        cout << "I'm really sorry my lord but this function is not existing";
                }
            }
        }else if(option == 2){
            cout << "Welcome user. Firstly enter your login" << endl;
            unique_ptr<User> user = make_unique<User>();
            cin >> *user;
            cout << "Thank you so much " << *user;
            while (true){
                cout << " Here is your fuctionality "<< endl;
                cout << "Enter: 0 - to exit" << endl;
                cout << "1 - to read the Menu" << endl;
                cout << "2 - to make an order" << endl;
                cout << "3 - to see the history of ordering" << endl;
                cin >> option;

                if (option == 0)
                    break;

                switch (option) {
                    case 1:{
                        unique_ptr<Menu> menu = make_unique<Menu>();
                        menu->showmenu();
                        menu.reset();
                        system("pause");
                        break;
                    };
                    case 2:{
                        unique_ptr<Menu> menu = make_unique<Menu>();
                        label1:
                        string nameofdishtoorder;
                        cout << "Enter name of food which you'd like to order:)" << endl;
                        cin >> nameofdishtoorder;
                        menu->search(nameofdishtoorder);
                        if (menu->cmp(menus)){
                            unique_ptr<Ordering> ordering = make_unique<Ordering>(*user,*menu);
                            write(orderings,*ordering);
                        }else{
                            cout << "You must have entered the wrong name of a dish. Pls try again" << endl;
                            goto label1;
                        }
                        menu.reset();
                        system("pause");
                        break;
                    };
                    case 3:{
                        unique_ptr<Ordering> ordering = make_unique<Ordering>();
                        ordering->showhistory(*user);
                        system("pause");
                        break;
                    };
                }
            }
        }else if(option == 0)
            break;
        else
            cout << "There aren't such an option" << endl;
    }

    return 0;
}
