#ifndef _DATAPROVIDER_H_
#define _DATAPROVIDER_H_

#include "Stock.h"
#include <map>
#include <vector>
#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

class DataProvider
{
private:
    map<string, Stock> stocks;
    vector<double> parseHistory(string line);

public:
    DataProvider();
    void loadStocks();
    map<string, Stock> getStocks();
};

#endif
