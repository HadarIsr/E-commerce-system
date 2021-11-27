//
//  Product.cpp
//  Project
//
//  Created by Hadar Israeli on 13/11/2019.
//  Copyright © 2019 Hadar Israeli. All rights reserved.
//

#include "Product.hpp"

int Product::counterSeriaelNumber = 1000;

Product::Product(Seller *seller, const char* name, const float price, const Ecategory category):seriaelNumber(++counterSeriaelNumber), seller(seller){
    
    setProductName(name);
    this->priceProduct = price;
    this->category = category;
}

Product::Product():seriaelNumber(++counterSeriaelNumber){}

int Product::getSerialNumber()const {return seriaelNumber;}

char* Product::getProductName(){return nameProduct;}

 Seller* Product::getSeller() const{return seller;}

void Product::setProductName(const char *name){
    
    if(strlen(name) >= MAXNAME){
        cout << "The name must contain " << ( MAXNAME - 1 ) << " letters or less." << endl;
        return;
    }
    strcpy(nameProduct, name);
}

float Product::getPrice() const {return priceProduct;}

void Product::setPrice(const float price) {priceProduct = price;}

void Product::show() const{

    cout << this->seriaelNumber << " name: " << this->nameProduct << " price:" << this->priceProduct << " category: " << EcategoryArr[this->category] << endl;
}
