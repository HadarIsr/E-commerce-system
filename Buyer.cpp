//
//  Buyer.cpp
//  Project
//
//  Created by Hadar Israeli on 13/11/2019.
//  Copyright © 2019 Hadar Israeli. All rights reserved.
//

#include "Buyer.hpp"

Buyer::Buyer(){
    
    maxProductInWishList = 0;
    curProductInWishList = 0;
    maxProductInCart = 0;
    curProductInCart = 0;
    maxPurshedHistory = 0;
    curPurshedHistory = 0;
    
}

Buyer::Buyer(const char* userName, const char* password, const Address &address ):address(address){
    
    this->setUserName(userName);
    this->setPassword(password);
    maxProductInWishList = 0;
    curProductInWishList = 0;
    maxProductInCart = 0;
    curProductInCart = 0;
    maxPurshedHistory = 0;
    curPurshedHistory = 0;
}

Buyer::~Buyer(){
    
    if(curProductInWishList > 0)
        delete [] wishList;
    
    if(curProductInCart > 0)
        delete [] shoppingCart;
    
    if(curPurshedHistory > 0){
        for(int i = 0; i < curPurshedHistory; i++)
            delete purshedHistory[i];
        delete [] purshedHistory;
    }
    
    
}


//GETS AND SETS
Order** Buyer::getHistory()const { return purshedHistory;}
int Buyer::getCurPurshedHistory()const{ return curPurshedHistory; }

int Buyer::getMaxProductInCart()const{ return maxProductInCart;}
int Buyer::getCurProductInCart()const{ return curProductInCart;}

Product** Buyer::getShoppingCart()const { return shoppingCart; }
Product** Buyer::getWishList()const {return this->wishList; }

char* Buyer::getUserName() {return userName;}
void Buyer::setUserName(const char* userName){
    
    if(strlen(userName) >= MAXNAME){
        cout << "The name must contain " << ( MAXNAME - 1 ) << " letters or less." << endl;
        return;
    }
    strcpy(this->userName, userName);
}

char* Buyer::getPassword(){return password;}
void Buyer::setPassword(const char* password){
    
        if(strlen(password) >= MAXNAME){
            cout << "The password must contain " << ( MAXNAME - 1 ) << " characters or less." << endl;
            return;
        }
        strcpy(this->password, password);
}

Address Buyer::getAddress()const{return address;}
void Buyer::setAddress(const Address address){this->address = address;}

//Adding product to buyer wishList and updating with realloc the array
void Buyer::addToWishList(Product *newProduct){
    
    if(maxProductInWishList == 0)
        wishList = new Product* [++maxProductInWishList];
    if(curProductInWishList >= maxProductInWishList)
        wishList = wishListRealloc();
    wishList[curProductInWishList] = newProduct;
    curProductInWishList++;
}

//Adding product to buyer Shoppingcart and updating with realloc the array
void Buyer::addToShoppingCart(Product *product){
    
    if(maxProductInCart == 0)
        this->shoppingCart = new Product* [++maxProductInCart];
    if(curProductInCart >= maxProductInCart)
        this->shoppingCart = ShoppingCartRealloc();
    this->shoppingCart[curProductInCart] = product;
    curProductInCart++;
}

//After adding product to buyer shoppingcart,
//we will delete it from the wish list
void Buyer::eraseProductFromWishList(){
    
    int newWishListSize = curProductInWishList - curProductInCart;
    if(newWishListSize == 0){
        this->curProductInWishList = 0;
        this->maxProductInWishList = 0;
        delete [] this->wishList;
        this->wishList = nullptr;
        return;
    }
    int newWishlistIndex = 0;
    Product **neWishList = new Product* [newWishListSize];
    for(int i = 0; i < curProductInWishList; i++){
        if(this->wishList[i] != nullptr)
            neWishList[++newWishlistIndex] = this->wishList[i];
    }
    delete [] this->wishList;
    this->wishList = neWishList;
    this->curProductInWishList = newWishListSize;
    this->maxProductInWishList = newWishListSize;
}

//Calculate the whole products thats in the shoppingcart
void Buyer::calculateTheOrderPrice(float &price)const{
    
    for(int i = 0; i < curProductInCart; i++)
        price += this->shoppingCart[i]->getPrice();
}

//Generate an order with the buyer shopping cart and saved it to the history
void Buyer::payOrder(){
    
    float price;
    calculateTheOrderPrice(price);
    Order *order = new Order(this, price, curProductInCart, shoppingCart);
    addOrderToPurshedHistory(order);
    cleanShoppingCart();
}

//After doing a purchase to a buyer , we will clean his shoppingcart
void Buyer::cleanShoppingCart(){
    
    delete [] this->shoppingCart;
    this->shoppingCart = nullptr;
    maxProductInCart = 0;
    curProductInCart = 0;
}

//Saving an order to the history orders array
void Buyer::addOrderToPurshedHistory(Order *order){
    
    if(maxPurshedHistory == 0)
        purshedHistory = new Order*[++maxPurshedHistory];
    if(curPurshedHistory >= maxPurshedHistory)
        purshedHistoryRealloc();
    purshedHistory[curPurshedHistory] = order;
    curPurshedHistory++;
}


//ALL THE REALLOC ARRAY FUNCTIONS
//
//
void Buyer::purshedHistoryRealloc(){
    
    maxPurshedHistory *= 2;
    Order **newPurshedHistory = new Order* [maxPurshedHistory];
    if(newPurshedHistory)
        for(int i = 0; i < curPurshedHistory; i++)
            newPurshedHistory[i] = this->purshedHistory[i];
    delete [] this->purshedHistory;
    this->purshedHistory = newPurshedHistory;
}

Product** Buyer::ShoppingCartRealloc(){
    
    maxProductInCart *= 2;
    Product **newShoppingCart = new Product* [maxProductInCart];
    if(newShoppingCart)
        for(int i = 0; i < curProductInCart; i++)
            newShoppingCart[i] = this->shoppingCart[i];
    delete [] this->shoppingCart;
    return newShoppingCart;
}

Product** Buyer::wishListRealloc(){
    
    
    maxProductInWishList *= 2;
    Product **neWishList = new Product* [maxProductInWishList];
    if(neWishList)
        for(int i = 0; i < curProductInWishList; i++)
            neWishList[i] = this->wishList[i];
    delete [] this->wishList;
    return neWishList;
}

void Buyer::showBuyer(const int &index)const{
    
    cout << "Buyer " << index <<" Details :" << endl;
    cout << "Username : " << userName << endl ;
    address.showAddress();
    cout << " Items in wishList: " << curProductInWishList << " Items in shopping cart: " << curProductInCart << " orders completed: " << curPurshedHistory << endl;
}
