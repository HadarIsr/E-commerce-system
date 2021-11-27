//
//  FeedBeck.hpp
//  Project
//
//  Created by Hadar Israeli on 13/11/2019.
//  Copyright © 2019 Hadar Israeli. All rights reserved.
//

#ifndef FeedBeck_hpp
#define FeedBeck_hpp


#include "Buyer.hpp"
#include "Date.hpp"

class FeedBeck{
    
private:
    const Buyer *buyer;
    const Product *product;
    const Date date;
    char wordFeedback [MAXFEEDBECK];
    
public:
    FeedBeck(Buyer* buyer, Product *product, char* wordFeedBack);
    char* getNameFeedBeck();
    char* getFeedbeck();
    void setFeedbeck(const char *feedBeck);
    
};
#endif /* FeedBeck_hpp */
