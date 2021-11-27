//
//  Buyer.hpp
//  Project
//
//  Created by Hadar Israeli on 13/11/2019.
//  Copyright © 2019 Hadar Israeli. All rights reserved.
//

#ifndef Buyer_hpp
#define Buyer_hpp

#include <stdio.h>
#include "Product.hpp"
#include "Address.hpp"
#include "Order.hpp"

class Buyer{
  
private:
    char userName [MAXNAME];
    char password [MAXNAME];
    Product **wishList;
    int maxProductInWishList;
    int curProductInWishList;
    Product **shoppingCart;
    int maxProductInCart;
    int curProductInCart;
    Order **purshedHistory;
    int maxPurshedHistory;
    int curPurshedHistory;
    Address address;
    
public:
    Buyer();
    Buyer(const char* userName, const char* password, const Address &address );
    ~Buyer();
    Buyer(const Buyer &other) = delete;
    char* getUserName();
    void setUserName(const char* userName);
    char* getPassword();
    void setPassword(const char* password);
    Address getAddress() const;
    void setAddress(const Address address);
    void addFeedBeck (Seller *seller);
    int getCurPurshedHistory() const;
    int getCurProductInWishList() const {return curProductInWishList;}
    int getMaxProductInCart()const;
    int getCurProductInCart()const;
    Product** getShoppingCart()const;
    Product** getWishList() const;
    void calculateTheOrderPrice(float &price)const;
    void addToWishList(Product *newProduct);
    void eraseProductFromWishList();
    void purshedHistoryRealloc();
    Product** ShoppingCartRealloc();
    Product** wishListRealloc();
    void payOrder();
    void cleanShoppingCart();
    void addToShoppingCart(Product *newProduct);
    void addOrderToPurshedHistory(Order *order);
    Order** getHistory()const;
    void showBuyer(const int &index)const;
};

#endif /* Buyer_hpp */
