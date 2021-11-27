//
//  Date.hpp
//  Project
//
//  Created by Hadar Israeli on 17/12/2019.
//  Copyright © 2019 Hadar Israeli. All rights reserved.
//

#ifndef Date_hpp
#define Date_hpp

#include <stdio.h>
#include <iostream>
using namespace std;

class Date{
    const int day;
    const int month;
    const int year;
    
public:
    Date();
    int getDay()const;
    int getMonth()const;
    int getYear()const;
    void showDate()const;
};


#endif /* Date_hpp */
