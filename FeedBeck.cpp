//
//  FeedBeck.cpp
//  Project
//
//  Created by Hadar Israeli on 13/11/2019.
//  Copyright © 2019 Hadar Israeli. All rights reserved.
//

#include "FeedBeck.hpp"

FeedBeck::FeedBeck(Buyer* buyer, Product *product, char* wordFeedBack):buyer(buyer),product(product)
{
    strcpy(this->wordFeedback, wordFeedBack);
}

char* FeedBeck::getFeedbeck(){ return wordFeedback ;}

void FeedBeck::setFeedbeck(const char *feedBeck){
    if(strlen(feedBeck) >= MAXFEEDBECK){
        cout << "The feedbeck must contain " << ( MAXFEEDBECK - 1 ) << " letters or less." << endl;
        return;
    }
    strcpy(wordFeedback, feedBeck);
}
