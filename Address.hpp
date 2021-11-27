//
//  Address.hpp
//  Project
//
//  Created by Hadar Israeli on 27/11/2019.
//  Copyright © 2019 Hadar Israeli. All rights reserved.
//

#ifndef Address_hpp
#define Address_hpp

#include <stdio.h>
#include "Product.hpp"

class Address{
    
private:
    char city[MAXNAME];
    char streetName[MAXNAME];
    int houseNumber;
    
public:
    
    char* getCity();
    void setCity(const char* city);
    char* getStreet();
    void setStreet(const char* streetName);
    int getHouseNumber()const;
    void setHouseNumber(const int houseNumber);
    void showAddress()const;
};

#endif /* Address_hpp */
