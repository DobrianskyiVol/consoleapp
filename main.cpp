#include <iostream>
#include "Admin.h"

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


using namespace std;

int main() {
    Interface *obj = new Admin("USer","Parol");
    string nameoffile = "Admins.txt";

  //  write(nameoffile,*obj);
    read(nameoffile,*obj);

    return 0;
}
