#!/usr/bin/python

import ctypes
lib = ctypes.cdll.LoadLibrary('./libInterface.so')#/libPlatform.so')

class Trade(object):
    def __init__(self):
        self.obj = lib.new_trader()

    #def bar(self):
     #   lib.get_stocks(self.obj)

def main():
    a = Trade();
    #print (a.bar())
    print ("end") 
    #Class_ctor_wrapper = TestLib.Trader
    #Class_ctor_wrapper.restype = c_void_p
   # test = TestLib.Trader("")
    #print (test.getAvailablePositions())
    #print TestLib.SampleAddInt(1, 2)

if __name__ == '__main__':
    main()
