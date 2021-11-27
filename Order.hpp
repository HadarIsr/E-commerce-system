//
//  Order.hpp
//  Project
//
//  Created by Hadar Israeli on 23/11/2019.
//  Copyright © 2019 Hadar Israeli. All rights reserved.
//

#ifndef Order_hpp
#define Order_hpp

#include <stdio.h>
#include "Date.hpp"


class Buyer;
class Product;
class Seller;


class Order{
    
private:
    static int counterOrderNumber;
    const int orderNumber;
    const int totalPrice;
    const int size;
    Product **orderProducts;
    const Date date;
    const Buyer *buyer;
    
public:
    Order();
    Order(Buyer *buyer, const int& price, const int& size, Product** orderProducts);
    ~Order();
    
    int getPrice()const;
    Date getDate()const;
    Product** getOrderProducts()const;
    int getSize()const;
    
};

#endif /* Order_hpp */
