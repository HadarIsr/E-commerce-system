//
//  User.hpp
//  Project
//
//  Created by Hadar Israeli on 19/11/2019.
//  Copyright © 2019 Hadar Israeli. All rights reserved.
//

#ifndef User_hpp
#define User_hpp

#include <stdio.h>
#include "Seller.hpp"


class Address;

class User{
private:
    Buyer **buyerArray;
    int maxBuyer;
    int curBuyer;
    Seller **sellerArray;
    int maxSeller;
    int curSeller;
    Product **productArray;
    int maxProduct;
    int curProduct;
public:
    
    User();
    ~User();
    User(const User& other) = delete;
    Buyer** getBuyerArray();
    Seller** getSellerArray();
    void addSeller(char *userName, char *password, Address &address);
    void addBuyer(char *userName, char *password, Address &address);
    int getCurSeller()const;
    int getCurBuyer()const;
    void addProductToArray(Product *product);
    void showBuyers();
    void showSellers();
    void showProductsByName(char *name);
    Buyer** buyerRealloc();
    Seller** sellerRealloc();
    Product** ProductRealloc();
  
};
#endif /* User_hpp */
