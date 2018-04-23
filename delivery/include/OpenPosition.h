#ifndef _OPEN_POSITION_H_
#define _OPEN_POSITION_H_

#include <string>

//Struct representing an open position
struct OpenPosition
{
    enum SellType {DEFAULT, STOP, LIMIT, PROFIT,STOP_PROFIT};
    std::string symbol;
    double buyPrice;
    SellType type = DEFAULT;
    double sellPrice = 0;
    int count;
    int dayOfPurchase;
    int monthOfPurchase;
    int yearOfPurchase;
    bool notPurchasedToday = false;
};

#endif
