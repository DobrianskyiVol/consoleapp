#include <iostream>
#include "Admin.h"
#include "Ordering.h"

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

//void erase(string nameoffile, Interface &obj){
//    if (obj.cmp(nameoffile))
//        obj.erase();
//    else
//        cout << "There arent such an object";
//}

int main() {
    const User *obj = new User();
//    string nameoffile = "Admins.txt";

//  //  write(nameoffile,*obj);
//   // read(nameoffile,*obj);
//    if (obj->cmp()){
//        cout << "Good";
//    } else
//        cout << "Bad";

//    obj->erase();

    const Menu *meal = new Menu;

    Interface *obj2 = new Ordering(*obj,*meal);

    string nameoffile = "Orderings.txt";
//    write(nameoffile,*obj2);
    if (obj2->cmp(nameoffile))
        cout << "Success";
    else
        cout << "fail";
    return 0;
}
