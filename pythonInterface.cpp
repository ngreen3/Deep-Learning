/*
This library  is designed to allow python to access the program trader platform.
*/
#include <iostream>
#include "./delivery/include/Trader.h"

using namespace std;

extern "C" {
    /*
    This function returns a new trader.
    */
    Trader* new_trader() {
        return new Trader("YouHadMeAtHelloWorld");
    }
    /*
    This function sets the account ID
        trader - pointer to the trader object
        account - new account name spaced out with 4 chars per char
                  I have no idea why
    */
    void set_account_ID(Trader* trader, char* account) {
        int i = 0;
        string s;
        //because it returns it as 4 spots per char
        while (isalnum(account[i]) | ispunct(account[i])) {
            s.append(1, account[i]);
            i += 4;
        }

        trader->setAccountID(s);
    }
    /*
        This function returns the account ID
    */
    const char* get_account_ID(Trader* trader) {
        return trader->getAccountID().c_str();
    }

    //cmap<string, Stock> getAvailablePositions();
    map<string, Stock>* get_available_positions(Trader* trader) {
        map<string, Stock> available = trader->getAvailablePositions();
        map<string, Stock>::iterator it;
        map<string, Stock>* m = new map<string, Stock>;

        for(it = available.begin(); it != available.end(); it++)
        {
            (*m)[it->first] = it->second;
        }
        return m;
    }

    void check_map(Trader* trader, map<string, Stock>* m) {
        map<string, Stock> available = trader->getAvailablePositions();
        map<string, Stock>::iterator it;

        for(it = available.begin(); it != available.end(); it++)
        {
            cout << it->first << " ";
            cout << it->second.h_end.size() << " ";
            cout << (*m)[it->first].h_end.size() << endl;
        }
    }





    /*
       This function creates a limit Buy for stocks
       trader - the pointer to the trader object that calls the limit buy
       symbol - stock symbol to buy for
       shares - how many shares to buy
       price - the price to set the limit buy
       returns the error code on execution
     */
    int limitBuy(Trader* trader, string symbol, int shares, double price) {
        return trader->createLimitBuy(symbol, shares, price);
    }



    /*
       This function returns a pointer to a stock
     */
    Stock* single_stock(Trader* trader){
        Stock s = trader->singleStock("aal");
        Stock* n = new Stock;
        n->symbol = s.symbol;
        n->h_volume = s.h_volume;
        n->h_high = s.h_high;
        n->h_low = s.h_low;
        n->h_start = s.h_start;
        n->h_end = s.h_end;
        return n;
    }

    void check_stock(Trader* trader, Stock* stock) {
        Stock s = trader->singleStock("aal");
        cout << stock->symbol << " " << s.symbol << endl;
        cout << stock->h_volume.size() << " " << s.h_volume.size() << endl;
        cout << stock->h_high.size() << " " << s.h_high.size() << endl;
        cout << stock->h_low.size() << " " << s.h_low.size() << endl;
        cout << stock->h_start.size() << " " << s.h_start.size() << endl;
        cout << stock->h_end.size() << " " << s.h_end.size() << endl;
    }
    /*
       int buy(string symbol, int shares);
       int sell(OpenPosition openPosition, int shares = 1);
       int sell(string symbol, int shares = 1);
       vector<OpenPosition> getOpenPositions();
       double getStockPrice(string symbol);
       double getAccountCash();
       double getAccountValue();
       Stock singleStock(string symbol);
       int createStopLoss(OpenPosition openPosition, double price);
       int createTakeProfit(OpenPosition openPosition, double price);
     */
}

