//
//  Address.cpp
//  Project
//
//  Created by Hadar Israeli on 27/11/2019.
//  Copyright © 2019 Hadar Israeli. All rights reserved.
//

#include "Address.hpp"


char* Address::getCity(){return city;}
void Address::setCity(const char* city){
    
    if(strlen(city) >= MAXNAME){
        cout << "The city must contain " << ( MAXNAME - 1 ) << " letters or less." << endl;
        return;
    }
    strcpy(this->city, city);
}

char* Address::getStreet(){return this->streetName;}
void Address::setStreet(const char* streetName){
        
    if(strlen(streetName) >= MAXNAME){
        cout << "The street must contain " << ( MAXNAME - 1 ) << " letters or less." << endl;
        return;
    }
    strcpy(this->streetName, streetName);
}

int Address::getHouseNumber()const{return houseNumber;}

void Address::setHouseNumber(const int houseNumber){this->houseNumber = houseNumber;}

void Address::showAddress()const{
    
    cout << "Address:\nCity: " << city << " Housenumber: " << houseNumber << " StreetName: " << streetName << endl;
}
