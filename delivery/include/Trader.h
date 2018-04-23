#ifndef _TRADER_H_
#define _TRADER_H_

#include "Broker.h"
#include "OpenPosition.h"
#include "Stock.h"
#include "enumErrorOutputs.h"

#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <map>
#include <algorithm>

using std::string;

class Trader
{
 private:
  Market market;
  Broker broker;

 public:

  Trader(string accountId);
  int createLimitBuy(string symbol, int shares, double pricediscdisc);
  void setAccountID(string account);
  string getAccountID();
  int buy(string symbol, int shares);
  int sell(OpenPosition openPosition, int shares = 1);
  int sell(string symbol, int shares = 1);
  vector<OpenPosition> getOpenPositions();
  map<string, Stock> getAvailablePositions();
  double getStockPrice(string symbol);
  double getAccountCash();
  double getAccountValue();
  Stock singleStock(string symbol);
  int createStopLoss(OpenPosition openPosition, double price);
  int createTakeProfit(OpenPosition openPosition, double price);

};

#endif
