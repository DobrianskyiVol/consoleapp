#include <iostream>
#include "Admin.h"

void write(string &nameoffile, Interface &obj){
    ofstream of(nameoffile,ios::app);
    if (!of.is_open())
        return;
    of << obj;
    of.close();
}

using namespace std;

int main() {
    Interface *obj = new Admin;
    string nameoffile = "Admins.txt";

    write(nameoffile,*obj);

    return 0;
}
