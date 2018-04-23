#ifndef _ACCOUNT_H_
#define _ACCOUNT_H_

#include "OpenPosition.h"
#include "enumErrorOutputs.h"
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Account
{
private:
    // Current cash level
    double cash = 0;

    // List of all open positions held by the account
    vector<OpenPosition> openPositions;

public:

    // ---- Constructors ----

    // New Account
    Account() { }
    // Account with cash
    Account(double cashAmt) : cash(cashAmt) { }
    // Account with cash and stocks
    Account(int cashAmt, vector<OpenPosition> positions) : cash(cashAmt), openPositions(positions) { }

    //---- Getters ----

    // Get the current cash level
    double getCash();

    // Get the list of open positions
    vector<OpenPosition> getOpenPositions();

    // ---- Setters ----

    // Change the cash level by given amount
    void addCash(double value);

    // Add an open position to the list
    void addOpenPosition(OpenPosition position);

    // Remove an open position from the list
    int removeOpenPosition(OpenPosition position, int count = 1);

    int updatePositionType(OpenPosition position, int type, double price);
};

#endif
