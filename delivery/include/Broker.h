#ifndef _BROKER_H_
#define _BROKER_H_

#include "AccountProvider.h"
#include "Stock.h"
#include "OpenPosition.h"
#include "Account.h"
#include "Market.h"
#include "enumErrorOutputs.h"

class Broker {
    public:
  Broker();
        Broker(Market &m, string account = "default");
	    void changeAccount(string account);
		string getAccount();
        int buyStock(string symbol, int shares, double price = -1);
        int sellStock(OpenPosition openPosition, int shares = 1, double price = -1);
        int takeProfit(OpenPosition openPosition);
        int buyLimitOrder(string symbol, int shares, double price);
        vector<OpenPosition> getOpenPositions();
        map<string, Stock> getAvailablePositions();
        double getAccountCash();
        double getAccountValue();
	    int createLimitBuy(string symbol, int shares, double price);
        Stock getStockInfo(string symbol);
	    int updatePositionType(OpenPosition position, int type, double price = 0);
    private:
	    int stopLoss(OpenPosition openPosition);
        string accountId = "default";
        Market market;
		void dailyOperations();
};

#endif
