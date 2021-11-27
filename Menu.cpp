//
//  Menu.cpp
//  Project
//
//  Created by Hadar Israeli on 15/12/2019.
//  Copyright © 2019 Hadar Israeli. All rights reserved.
//

#include "Menu.hpp"

void startMenu(){

        User user;
        int choice = 0; // for the menu
    
        cout << "Press 1 - Add seller" << endl;
        cout << "Press 2 - Add buyer" << endl;
        cout << "Press 3 - Add product to seller" << endl;
        cout << "Press 4 - Add feedback to seller" << endl;
        cout << "Press 5 - Add product to buyer wishlist" << endl;
        cout << "Press 6 - Add products to buyer shopping cart " << endl;
        
        cout << "Press 7 - Make order to buyer shopping cart" << endl;
        cout << "Press 8 - Show buyers info" << endl;
        cout << "Press 9 - Show sellers info" << endl;
        
        cout << "Press 10 - Show products by name "<< endl;
        cout << "Press 11 - Exit" << endl;

        while(choice != 11){
            cin >> choice;
            cin.ignore();

            switch (choice) {
                case 1:
                    addSeller(user);
                    break;
                case 2:
                    addBuyer(user);
                    break;
                case 3:
                    addProductToSellerByName(user);
                    break;
                case 4:
                    addFeedbackToSeller(user);
                    break;
                case 5:
                    addProductToWishListByName(user);
                    break;
                case 6:
                    addProductToShoppingCart(user);
                    break;
                case 7:
                    PayOrder(user);
                    break;
                case 8:
                    ShowAllBuyer(user);
                    break;
                case 9:
                    showAllSeller(user);
                    break;
                case 10:
                    showAllProductsByName(user);
                    break;
                case 11:
                    return;
                    break;
                    
                default:
                    break;
            }
            cout << " Choose again from the menu\n" << endl;
        }
        
        
    }
    


//Adding buyer to the system
void addBuyer(User &user){
    
    char name [MAXNAME];// the user limit is 20 charcters in the user name
    char password [MAXNAME];// also in the password
    Address address;
    
    setUserName(user, name);
    setPassword(password);
    setAddress(address);
    
    user.addBuyer(name, password, address);
}
//Adding seller to the system
void addSeller(User &user){
    
    char name[MAXNAME];
    char password[MAXNAME];
    Address address;
    
    setUserName(user, name);
    setPassword(password);
    setAddress(address);
    
    user.addSeller(name, password, address);
}

//Adding a product to a seller and to the products array in the system
void addProductToSellerByName(User &user){
    
    char userName[MAXNAME];
    Seller *seller;
    
    cout << "Please enter the Seller User name\n";
    cin.getline(userName, MAXNAME - 1);
    stringChecker(userName, MAXNAME);
    seller = findSellerByUserName(user, userName);
    if(seller != nullptr)
        addProductToSeller(user, seller);
}


//Adding feedback to a seller
void addFeedbackToSeller(User &user){

    Buyer *buyer;
    Seller *seller;
    Product *product;
    char buyerName[MAXNAME];
    char sellerName[MAXNAME];
    char productName[MAXNAME];
    
    cout << "Please enter the Buyer User Name\n";
    cin.getline(buyerName, MAXNAME - 1);
    stringChecker(buyerName, MAXNAME); // INPUT VALIDATION
    buyer = findBuyerByUserName(user, buyerName); // CHECKING IF THE BUYER IS IN THE SYSTEM
    if (buyer == nullptr){return;}
    cout << "Please enter the Seller User Name\n";
    cin.getline(sellerName, MAXNAME - 1);
    stringChecker(sellerName, MAXNAME);
    seller = findSellerByUserName(user, sellerName);
    if (seller == nullptr){return;}
    cout << "Please enter the Product Name\n";
    cin.getline(productName, MAXNAME - 1);
    stringChecker(productName, MAXNAME);
    product = findProductByName(seller, productName); // CHECKING IF THE PRODUCT IS IN THE SYSTEM
    if (product == nullptr){return;}
    
    // CHECKING IF THE BUYER HAS ORDER FROM THIS SELLER
    if(checkBuyerBoughtFromSeller(buyer, productName, sellerName))
        createFeedback(buyer, product, seller);
}

// Creating the feedback
void createFeedback(Buyer *buyer,Product *product, Seller *seller){
    
    char feedbackWords[MAXFEEDBECK];
    cout << "Please enter your feedback/n";
    cin.getline(feedbackWords, MAXFEEDBECK - 1);
    stringChecker(feedbackWords, MAXFEEDBECK);
    FeedBeck *feedBack = new FeedBeck(buyer, product, feedbackWords);
    seller->addFeedBeck(feedBack); // Adding and updating the feedback array
}


//Adding products to a buyer wishlist by his name
void addProductToWishListByName(User &user){

    char buyerName[MAXNAME];
    char sellerName[MAXNAME];
    char productName[MAXNAME];
    Buyer *buyer;
    Product *product;
    Seller *seller;
    
    cout << "Please enter the Buyer User Name\n";
    cin.getline(buyerName, MAXNAME - 1);
    stringChecker(buyerName, MAXNAME);
    buyer = findBuyerByUserName(user, buyerName);
    if (buyer == nullptr){return;}
    
    cout << "Please enter the Seller Name\n";
    cin.getline(sellerName, MAXNAME - 1);
    stringChecker(sellerName, MAXNAME);
    seller = findSellerByUserName(user, sellerName);
    if (seller == nullptr){return;}
    
    cout << "Please enter the Product Name\n";
    cin.getline(productName, MAXNAME - 1);
    stringChecker(productName, MAXNAME);
    product = findProductByName(seller, productName);
    if (product == nullptr){return;}
    
    buyer->addToWishList(product);
}

//Adding prodcuts to buyer shopping cart from his wish list
void addProductToShoppingCart(User &user){
    
    bool addProductToShoppingCart = false;
    Buyer *buyer;
    char buyerName[MAXNAME];
    int choice;
    cout << "Please enter the Buyer User Name\n";
    cin.getline(buyerName, MAXNAME - 1);
    stringChecker(buyerName, MAXNAME);
    
    buyer = findBuyerByUserName(user, buyerName);
    if (buyer == nullptr){return;}
    
    if(buyer->getCurProductInWishList() == 0){
        cout << "No Products in wishList";
        return;
    }
    cout << "Press 1 to add this item to this Buyer Shopping cart\n";
    for(int i = 0; i < buyer->getCurProductInWishList(); i++){
        cout << "item info: ";
        buyer->getWishList()[i]->show();
        cout << "Press 1 to add this item: ";
        cin >> choice;
        if(choice == 1){
            buyer->addToShoppingCart(buyer->getWishList()[i]);
            buyer->getWishList()[i] = nullptr;
            addProductToShoppingCart = true;
        }
    }
    
    if(addProductToShoppingCart)
        buyer->eraseProductFromWishList(); // Delete the products he choose from the wish list
}

//Make a purchase from a buyer shopping cart
void PayOrder(User &user){
    
    Buyer *buyer;
    char buyerName[MAXNAME];
    int choice;
    float price = 0;
    
    cout << "Please enter the Buyer User Name\n";
    cin.getline(buyerName, MAXNAME - 1);
    stringChecker(buyerName, MAXNAME);
    buyer = findBuyerByUserName(user, buyerName);
    if (buyer == nullptr){return;}
    if (buyer->getCurProductInCart() == 0){
        cout << "No product in cart\n";
        return;
    }
    buyer->calculateTheOrderPrice(price);
    
    cout << "This Order price is: " << price << endl << "to confirm press 1: ";
    cin >> choice;
    if (choice == 1){
        buyer->payOrder();
        cout << "Order complete";
    }
}


//Checking if the buyer has a product from this seller
bool checkBuyerBoughtFromSeller(Buyer *buyer, char* productName, char* sellerName){
    
    for(int i = 0; i < buyer->getCurPurshedHistory(); i++)
        for(int k = 0; k < buyer->getHistory()[i]->getSize(); k++){
            if (! strcmp(buyer->getHistory()[i]->getOrderProducts()[k]->getSeller()->getUserName(), sellerName))
                if(! strcmp(buyer->getHistory()[i]->getOrderProducts()[k]->getProductName(), productName))
                    return true;
        }
    cout << "this buyer can't give feedback to this seller\n";
    return false;
}

//Showing all the sellers and buyers in the system
void ShowAllBuyer(User &user){user.showBuyers();}
void showAllSeller(User &user){user.showSellers();}

//Showing all the products with a same name
void showAllProductsByName(User &user){
    
    char productName[MAXNAME];
    cout << "Please enter the Product Name\n";
    cin.getline(productName, MAXNAME - 1);
    stringChecker(productName, MAXNAME);
    user.showProductsByName(productName);
}

//Checking that there is a user name with that name
void userNameAviable(User &user, char *name){

    for(int i = 0 ; i < user.getCurBuyer() ; i++)
        if(!strcmp(user.getBuyerArray()[i]->getUserName() , name )){
            cout << "this user name is not aviable please choose other User Name\n";
            setUserName(user, name);
            break;
        }
    
    for(int i = 0 ; i < user.getCurSeller() ; i++)
        if(!strcmp( user.getSellerArray()[i]->getUserName() , name )){
            cout << "this user name is not aviable please choose other User Name\n";
            setUserName(user, name);
            break;
        }
}

//GETS AND SETS
//
//
void setUserName(User &user, char *name){
        
    cout << "Please enter your user name between 0 - 20 charcter\n";
    cin.getline(name, MAXNAME);
   stringChecker(name, MAXNAME);
    userNameAviable(user, name);
}

void setPassword(char *password){
    cout << "Please enter your password (the password length between 1-20)\n";
    cin.getline(password, MAXNAME - 1);
    stringChecker(password, MAXNAME);
}


void setAddress(Address &address){
    
    char streetName[MAXNAME];
    char city[MAXNAME];
    int houseNumber;
     
    cout << "Please enter your City between 0 - 20 charcter\n";
    cin.getline(city, MAXNAME - 1);
    stringChecker(city, MAXNAME);
    address.setCity(city);
     
    cout << "Please enter your street name between 0 - 20 charcter\n";
    cin.getline(streetName, MAXNAME - 1);
    stringChecker(streetName, MAXNAME);
    address.setStreet(streetName);

    cout << "Please enter your house number\n";
    cin >> houseNumber;
    cin.ignore();
    address.setHouseNumber(houseNumber);
}

void setProductName(char *name){
    
    cout << "Please enter the product name\n";
    cin.getline(name, MAXNAME - 1);
    stringChecker(name, MAXNAME);
    
}

void setProudctPrice(float &price){
    
    cout << "Please enter the price\n";
    cin >> price;
    cin.ignore();
}

//setting the Enum Category
int setProudctCategory(){
    
    int category;
    cout << "Please enter the Category\npress '1' for Children, '2' for Electronic, '3' for Office, '4' for Clothing\n";
    cin >> category;
    cin.ignore();
    while (category < 1 || category > 4) {
        cout << "incorrect input please press 1 2 3 or 4\n";
        cin >> category;
        cin.ignore();
    }
    return (category-1);
}



//adding product to a seller and also to the products array
void addProductToSeller(User &user, Seller *seller){
    
    Product* newProduct = createNewProduct(seller);
    seller->addProduct(newProduct);
    user.addProductToArray(newProduct);
}

//creating new product to a seller
//and also to the array of products in the system

Product* createNewProduct(Seller *seller){
    
    char name[MAXNAME];
    Ecategory category;
    float price;
    
    category = (Ecategory) setProudctCategory();
    setProductName(name);
    setProudctPrice(price);
    return new Product(seller, name, price, category);
}



//finding a buyer with that name
Buyer* findBuyerByUserName(User &user, char *buyerName){
    
    for(int i = 0 ; i < user.getCurSeller() ; i++)
        if (!strcmp(user.getBuyerArray()[i]->getUserName(), buyerName))
            return user.getBuyerArray()[i];
    cout << "didnt find this Buyer\n";
    return nullptr;
}

//finding a seller with that name
Seller* findSellerByUserName(User &user, char *sellerName){
    
    for(int i = 0; i < user.getCurSeller(); i++)
        if(!strcmp(sellerName, user.getSellerArray()[i]->getUserName()))
            return user.getSellerArray()[i];
    
    cout << "Didn't find this Seller";
    return nullptr;
}

//finding product from this seller
Product* findProductByName(Seller *seller, char *productName){
    
    for(int i = 0; i < seller->getCurProduct(); i++){
        if(!strcmp(seller->getSellerProducts()[i]->getProductName(), productName))
            return seller->getSellerProducts()[i];
    }
    cout << "didn't found this product";
    return nullptr;
}


//Checking input validiation
void stringChecker(char *string, int size){
    
    while (strlen(string) >= size - 2) {
        cout << "Worng input!!!OVERLOAD MAX STRING Try again\n";
        cin.clear();
        fflush(stdin);
        cin.getline(string, MAXNAME - 1);
    }
    while (strlen(string) < 1){
        cout << "Worng input!!!\n";
        cin.clear();
        fflush(stdin);
        cin.getline(string, MAXNAME - 1);
    }
}


