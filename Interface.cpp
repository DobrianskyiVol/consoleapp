//
// Created by user on 26.03.2024.
//

#include "Interface.h"

ostream &operator<<(ostream &os, Interface &anInterface) {
    anInterface.write(os);
    return os;
}

istream &operator >>(istream &is, Interface &anInterface){
    anInterface.read(is);
    return is;
}
