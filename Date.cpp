//
//  Date.cpp
//  Project
//
//  Created by Hadar Israeli on 17/12/2019.
//  Copyright © 2019 Hadar Israeli. All rights reserved.
//

#include "Date.hpp"
#include <ctime>

time_t t = time(0);   // get time now
tm* now = localtime(&t);


Date::Date():day(now->tm_mday),month(now->tm_mon + 1),year(now->tm_year + 1900){}

int Date::getDay()const{ return this->day;}
int Date::getMonth()const{return this->month;}
int Date::getYear()const{return this->year;}
void Date::showDate()const{
    
    cout << day << "/" << month << "/" << year;
}



