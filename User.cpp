//
//  User.cpp
//  Project
//
//  Created by Hadar Israeli on 19/11/2019.
//  Copyright © 2019 Hadar Israeli. All rights reserved.
//

#include "User.hpp"

User::User(){
    
    maxBuyer = 0;
    curBuyer = 0;
    maxSeller = 0;
    curSeller = 0;
    maxProduct = 0;
    curProduct = 0;
}

User::~User(){
 
    for(int i = 0; i < curBuyer; i++)
        delete buyerArray[i];
    delete [] buyerArray;
    for(int i = 0; i < curSeller; i++)
        delete sellerArray[i];
    delete [] sellerArray;
    delete [] productArray;
}

//GETS AND SETS
Buyer** User::getBuyerArray(){return this->buyerArray;}
Seller** User::getSellerArray(){return this->sellerArray;}
int User::getCurSeller()const{return this->curSeller;}
int User::getCurBuyer()const{return this->curBuyer;}


//Adding a new buyer and update the system buyer array
void User::addBuyer(char *userName, char *password, Address &address){

    if(maxBuyer == 0){
        maxBuyer++;
        buyerArray = new Buyer* [maxBuyer];
    }

    if(curBuyer >= maxBuyer)
        buyerArray = buyerRealloc();
    buyerArray[curBuyer] = new Buyer(userName , password, address);
    curBuyer++;
}


//Adding a new seller and update the system seller array
void User::addSeller(char *userName, char *password, Address &address){
    
    if(maxSeller == 0){
        maxSeller++;
        sellerArray = new Seller* [maxSeller];
    }

    if(curSeller >= maxSeller)
        sellerArray = sellerRealloc();
    sellerArray[curSeller] = new Seller(userName , password, address);
    curSeller++;
}

//Adding a new product to the system products array
void User::addProductToArray(Product *product){
    
    if (maxProduct == 0)
        productArray = new Product* [++maxProduct];
    if(curProduct >= maxProduct)
        productArray = ProductRealloc();
    productArray[curProduct] = product;
    curProduct++;
}


//SHOW BUYERS AND SELLER FUNCTION
void User::showBuyers(){
    
    for(int i=0; i < curBuyer; i++)
        buyerArray[i]->showBuyer(i+1);
}

void User::showSellers(){
    
    for(int i=0; i < curSeller; i++)
        sellerArray[i]->showSeller(i+1);
}

//Showing a products with a same name
void User::showProductsByName(char *name){
    
    for(int i=0; i < curProduct; i++)
        if(! (strcmp(productArray[i]->getProductName(),name)))
            productArray[i]->show();
}


//Realloc array system
Buyer** User::buyerRealloc(){
    
    maxBuyer *= 2;
    Buyer **newBuyer = new Buyer* [maxBuyer];
    if(newBuyer)
        for(int i = 0; i < curBuyer; i++)
            newBuyer[i] = buyerArray[i];
    delete [] buyerArray;
    return newBuyer;
}

Seller** User::sellerRealloc(){
    
        maxSeller *= 2;
        Seller **newSeller = new Seller* [maxSeller];
        if(newSeller)
            for(int i = 0; i < curSeller; i++)
                newSeller[i] = sellerArray[i];
        delete [] sellerArray;;
        return newSeller;
    }

Product** User::ProductRealloc(){
    
    maxProduct *= 2;
    Product **newProductArray = new Product* [maxProduct];
    if(newProductArray)
        for(int i = 0; i < curProduct; i++)
            newProductArray[i] = productArray[i];
    delete [] this->productArray;
    return newProductArray;
}




