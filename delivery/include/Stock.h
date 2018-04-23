#ifndef _STOCK_H_
#define _STOCK_H_

#include <string>
#include <vector>

using namespace std;

//Struct representing a stock
struct Stock
{
    string symbol;
    vector<double> h_high, h_low, h_start, h_end;
    vector<int> h_volume;
};

#endif
