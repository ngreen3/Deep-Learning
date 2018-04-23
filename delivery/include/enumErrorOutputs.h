#ifndef _ENUM_ERROR_OUTPUTS_H_
#define _ENUM_ERROR_OUTPUTS_H_

#include <iostream>

//first element in enum is default (no error message needed)
enum errorOutputs
{
  SUCCESS,
  OPEN_POSITION_NOT_FOUND, //Could not remove open positions because open position not found.
  COUNT_TOO_LARGE,  //Could not remove open positions because count requested is greater than existing count.
  ERROR_SERIALIZING,       //Error serializing account.
  STOCK_DOESNT_EXIST,       //Stock does not exist.
  NOT_ENOUGH_CASH,         //Not enough cash! 
  LIMIT_ORDER_NOT_MET,      //Price specified by limit order is not available
  POSITION_TYPE_LIMIT,     //trying to update limit order
  POSITION_ALREADY_SET,    //trying to update an existing stop loss or take profit
  INVALID_AMOUNT_OF_STOCKS  //BUYING LESS THAN 0 STOCKS
};

#endif
