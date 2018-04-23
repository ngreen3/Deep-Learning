#!/usr/bin/python

import ctypes
lib = ctypes.cdll.LoadLibrary('./libInterface.so')

class Trade(object):
    def __init__(self):
        self.obj = lib.new_trader()

    ###gets the account Id add b'' to the string
    def getID(self):
        return lib.get_account_ID(self.obj)
    ###sets the account ID
    def setAccount(self, a):
        lib.set_account_ID(self.obj, a)
    ###gets the stock history for a single stock
    ###returns a stock pointer
    def stockHistory(self):
        return lib.single_stock(self.obj)
    def checkStock(self, stock):
        lib.check_stock(self.obj, stock)
    ###gets all the open positions, and their history
    ###returns a pointer to a map of them
    def getPositions(self):
        return lib.get_available_positions(self.obj)
    def checkPositions(self, pos):
        lib.check_map(self.obj, pos)
        
#.contents

def main():
    ###works for an array of ints of length 2
    #lib.get_account_ID.restype = ctypes.POINTER(ctypes.c_int * 2)
    lib.get_account_ID.restype = ctypes.c_char_p
    a = Trade();
    #account = "hello"
    #a.setAccount(account)
    print(a.getID())

    stock = a.stockHistory()
    #a.checkStock(stock)

    ###pos is a pointer to map<string, Stock> of all the stocks, and their history
    pos = a.getPositions()
    #a.checkPositions(pos)
    

    print ("end") 
#    c = a.getID()
#    print(lib.get_account_ID(a).value)
#    print (c)
    #Class_ctor_wrapper = TestLib.Trader
    #Class_ctor_wrapper.restype = c_void_p
   # test = TestLib.Trader("")
    #print (test.getAvailablePositions())
    #print TestLib.SampleAddInt(1, 2)

if __name__ == '__main__':
    main()
