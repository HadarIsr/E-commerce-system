//
//  Seller.hpp
//  Project
//
//  Created by Hadar Israeli on 14/11/2019.
//  Copyright © 2019 Hadar Israeli. All rights reserved.
//

#ifndef Seller_hpp
#define Seller_hpp

#include <stdio.h>
#include "FeedBeck.hpp"




class Seller{
  
private:
    char userName [MAXNAME];
    char password [MAXNAME];
    Address address;
    Product **sellerProducts;
    int maxProduct;
    int curProduct;
    FeedBeck **sellerFeedbecks;
    int maxFeedbecks;
    int curFeedbecks;
    
public:
    Seller();
    Seller(const char* userName, const char* password, const Address &address );
    ~Seller();
    Seller(const Seller &other) = delete;
    char* getUserName();
    void setUserName(const char* userName);
    char* getPassword();
    void setPassword(const char* password);
    Address getAddress()const;
    void setAddress(const Address address);
    void addProduct(Product *product);
    void addFeedBeck(FeedBeck *feedbeck);
    Product** productRealloc();
    void feedBeckRealloc();
    Product** getSellerProducts();
    int getCurProduct();
    void setSellerProducts(int size);
    FeedBeck** getSellerFeedBecks();
    void showSeller(const int &index)const;
};

#endif /* Seller_hpp */
