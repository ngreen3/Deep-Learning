SOURCE = pythonInterface.cpp 

LIBNAME = Platform
INSTALLDIR = ./delivery
INCLUDE = -I$(INSTALLDIR)/include
LIBRARY = -L$(INSTALLDIR)/lib -l$(LIBNAME)

OBJS = $(SOURCE:.cpp=.o)

#GNU C/C++ Compiler
GCC = g++

# GNU C/C++ Linker
LINK = g++

# Archive
AR = ar rs

# Compiler flags
INC =
CFLAGS = -fPIC -Wall -std=c++11 $(INC) -D_GLIBCXX_USE_CXX11_ABI=0
CXXFLAGS = $(CFLAGS)

# Fill in special libraries needed here
LIBS =

.PHONY: clean

# Targets include all, clean, debug, tar

all : libInterface.so

libInterface.so: $(OBJS)
	$(LINK) -shared $^ -o $@ $(INCLUDE) $(LIBRARY)

clean:
	rm -rf *.o *.d trading

debug: CXXFLAGS = -Wall -std=c++11 -D_GLIBCXX_USE_CXX11_ABI=0
debug: libInterface.so

tar: clean
	tar zcvf trading.tgz $(SOURCE) *.h Makefile

help:
	@echo "	make trading  - same as make all"
	@echo "	make all   - builds the main target"
	@echo "	make       - same as make all"
	@echo "	make clean - remove .o .d core trading"
	@echo "	make debug - make all with -g and -DDEBUG"
	@echo "	make tar   - make a tarball of .cpp and .h files"
	@echo "	make help  - this message"

-include $(SOURCE:.cpp=.d)

%.d: %.cpp
	@set -e; /usr/bin/rm -rf $@;$(GCC) -MM $< $(CXXFLAGS) > $@
