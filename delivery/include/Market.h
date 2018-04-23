#include "Stock.h"
#include "OpenPosition.h"
#include "DataProvider.h"
#include "Account.h"
#include "enumErrorOutputs.h"
#include <iostream>
#include <map>
#include <string>
#include <ctime>
#include <utility>
#include <vector>

using namespace std;

#ifndef _MARKET_H_
#define _MARKET_H_

class Market {
    private:
        map<string, Stock> stocks;//maps stock symbol to stock struct
        DataProvider dataProvider;
 public:
	Market();
        Market(DataProvider &data);
        //account to buy stock, stock symbol, returns true iff stock is successfully purchased
        int buyStock(Account &currAccount, string symbol, int count, double price = -1);
	int createLimitBuy(Account &account, OpenPosition &position);
        //account to sell stock, stock symbol, returns true iff stock is successfully sold
        int sellStock(Account &currAccount, OpenPosition position, int shares =1, double price=-1);
        map<string, Stock> getStockList();
        //pass in the stock symbol
        Stock getSingleStock(string symbol);
        void updateStocks();
        int updatePositionType(Account &currAccount, OpenPosition position, int type, double price);
};

#endif
