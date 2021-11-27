//
//  Order.cpp
//  Project
//
//  Created by Hadar Israeli on 23/11/2019.
//  Copyright © 2019 Hadar Israeli. All rights reserved.
//

#include "Order.hpp"


int Order::counterOrderNumber=7000;


Order::Order() : orderNumber(++counterOrderNumber),totalPrice(0),size(0){
    
}

Order::Order(Buyer *buyer, const int& price, const int& size, Product** orderProducts) : orderNumber(++counterOrderNumber),buyer(buyer),totalPrice(price),size(size){
    
    this->orderProducts = new Product* [size];
    for(int i = 0; i < size; i++){
        this->orderProducts[i] = orderProducts[i];
    }
}

Order::~Order(){
    for(int i=0; i<this->size; i++)
        orderProducts[i] = nullptr;
    delete [] orderProducts;
}

Date Order::getDate()const{ return date;}
int Order::getSize()const{ return size;}
Product** Order::getOrderProducts()const{ return orderProducts;}

