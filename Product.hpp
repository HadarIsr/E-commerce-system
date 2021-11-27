//
//  Product.hpp
//  Project
//
//  Created by Hadar Israeli on 13/11/2019.
//  Copyright © 2019 Hadar Israeli. All rights reserved.
//

#ifndef Product_hpp
#define Product_hpp

#include <stdio.h>
#include <string.h>
#include <iostream>


class Seller;

using namespace std;

const int MAXNAME = 22;//the limits of address, password and names is 20 charcters
const int MAXFEEDBECK = 122;// the limits of feedbeck is max 120 charcters

enum Ecategory{children, electronic, office, clothing};

class Product{

public:
    
    //Ctor
    Product(Seller *seller, const char* name, const float price, const Ecategory category);
    Product();
//    ~Product();
    
    int getSerialNumber()const;
    char* getProductName();
    void setProductName(const char *name);
    float getPrice()const;
    void setPrice(const float price);
    void show() const;
    Seller* getSeller() const;
    
private:
    
    const char* EcategoryArr[4] = {"children","electronic","office","clothing"};
    static int counterSeriaelNumber;
    const int seriaelNumber;
    Seller *seller;
    char nameProduct[MAXNAME];
    float priceProduct;
    Ecategory category;
};


#endif /* Product_hpp */
