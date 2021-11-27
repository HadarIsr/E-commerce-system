//
//  Menu.hpp
//  Project
//
//  Created by Hadar Israeli on 15/12/2019.
//  Copyright © 2019 Hadar Israeli. All rights reserved.
//

#ifndef Menu_hpp
#define Menu_hpp

#include <stdio.h>
#include "User.hpp"
#include <string>

void startMenu();
void addBuyer(User &user);
void addSeller(User &user);
void addProductToSellerByName(User &user);
void addFeedbackToSeller(User &user);
void addProductToWishListByName(User &user);
void addProductToShoppingCart(User &user);
void PayOrder(User &user);
void ShowAllBuyer(User &user);
void showAllSeller(User &user);
void showAllProductsByName(User &user);
bool checkBuyerBoughtFromSeller(Buyer *buyer, char *productName, char* sellerName);
void userNameAviable(User &user, char *name);
void setUserName(User &user, char *name);
void setPassword(char *password);
void setAddress(Address &address);

void addProductToSeller(User &user, Seller *seller);
Product* createNewProduct(Seller *seller);
void setProductName(char *name);
void setProudctPrice(float &price);
int setProudctCategory();
void createFeedback(Buyer *buyer,Product *product, Seller *seller);

Buyer* findBuyerByUserName(User &user, char *buyerName);
Seller* findSellerByUserName(User &user, char *sellerName);
Product* findProductByName(Seller *seller, char *productName);

void stringChecker(char *string, int size);

#endif /* Menu_hpp */
