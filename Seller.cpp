//
//  Seller.cpp
//  Project
//
//  Created by Hadar Israeli on 14/11/2019.
//  Copyright © 2019 Hadar Israeli. All rights reserved.
//

#include "Seller.hpp"

Seller::Seller(){
    
    maxProduct = 0;
    curProduct = 0;
    maxFeedbecks = 0;
    curFeedbecks = 0;

}

Seller::Seller(const char* userName, const char* password, const Address &address ):address(address){
    
    this->setUserName(userName);
    this->setPassword(password);
    maxProduct = 0;
    curProduct = 0;
    maxFeedbecks = 0;
    curFeedbecks = 0;

}

Seller::~Seller(){
    
    if(curProduct > 0){
        for (int i = 0; i < curProduct; i++)
            delete sellerProducts[i];
        delete [] sellerProducts;
    }
    
    if(curFeedbecks > 0){
        for (int i = 0; i < curFeedbecks; i++)
            delete  sellerFeedbecks[i];
        delete [] sellerFeedbecks;
    }
}


//GETS AND SETS
char* Seller::getUserName(){return this->userName; }
void Seller::setUserName(const char* userName){strcpy(this->userName, userName);}
char* Seller::getPassword(){return password;}
void Seller::setPassword(const char* password){strcpy(this->password, password);}
Address Seller::getAddress()const{return address;}
void Seller::setAddress(const Address address){this->address = address;}
Product** Seller::getSellerProducts(){return sellerProducts;}
void Seller::setSellerProducts(int size){sellerProducts = new Product* [size];}
FeedBeck** Seller::getSellerFeedBecks(){return sellerFeedbecks;}
int Seller::getCurProduct(){return curProduct;}


//Adding a products to the prodcts arrays
void Seller::addProduct(Product *product){ 
    
    if(maxProduct == 0)
        sellerProducts = new Product* [++maxProduct];
    if(curProduct >= maxProduct)
        sellerProducts = productRealloc();
    sellerProducts[curProduct] = product;
    curProduct++;
    
}

// Adding feedbeck to the seller
void Seller::addFeedBeck(FeedBeck *feedbeck){

    if(maxFeedbecks == 0)
        sellerFeedbecks = new FeedBeck* [++maxFeedbecks];
    if(curFeedbecks >= maxFeedbecks)
         feedBeckRealloc();
    sellerFeedbecks[curFeedbecks] = feedbeck;
    curFeedbecks++;
}



//REALLOC ARRAYS
Product** Seller::productRealloc(){
    
    maxProduct *= 2;
    Product **newProduct = new Product* [maxProduct];
    if(newProduct)
        for(int i = 0; i < curProduct; i++)
            newProduct[i] = this->sellerProducts[i];
    delete [] this->sellerProducts;
    return newProduct;
}

void Seller::feedBeckRealloc(){
    maxFeedbecks *= 2;
    FeedBeck **newFeedBeck = new FeedBeck* [maxFeedbecks];
    if(newFeedBeck)
        for(int i = 0; i < curFeedbecks; i++)
            newFeedBeck[i] = this->sellerFeedbecks[i];
    delete [] this->sellerFeedbecks;
    this->sellerFeedbecks = newFeedBeck;
}

void Seller::showSeller(const int &index)const{
    
    cout << "Seller Number " << index <<" Details :" << endl;
    cout << "Username : " << userName << endl ;
    address.showAddress();
    cout << "products:\n";
    for(int i = 0; i < curProduct; i++)
        sellerProducts[i]->show();
    
}


