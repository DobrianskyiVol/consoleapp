#include <iostream>
#include "Admin.h"

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
    return obj.cmp();
}

void erase(string &nameoffile, Interface &obj){
    obj.erase();
}


int main() {
    Interface *obj = new Admin("USer","Parol");
    string nameoffile = "Admins.txt";

//  //  write(nameoffile,*obj);
//   // read(nameoffile,*obj);
//    if (obj->cmp()){
//        cout << "Good";
//    } else
//        cout << "Bad";


    return 0;
}
