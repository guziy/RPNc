
BASE_INC_PATH = $(ARMNLIB)/include


CXX = pgCC
LIB = -L$(ARMNLIB)/lib/Linux_x86-64_pgi904 -L$(ARMNLIB)/lib
INCLUDE = -I$(BASE_INC_PATH) -I$(BASE_INC_PATH)/Linux_x86-64_pgi904

all : *.o
	$(CXX) -shared *.o -o rmnlib.so $(LIB) -lrmn -lstd -lc -lpgc -lpgf90 -lpgf90_rpm1 -lpgf902 -lnetcdf_c++ -lnetcdf -pgf90libs

*.o : *.cpp
	$(CXX) -c -g -fPIC *.cpp $(INCLUDE)

clean: *.o
	rm -f *.o
	rm -f *.so