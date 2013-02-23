
BASE_INC_PATH = $(ARMNLIB)/include


CXX = pgCC
LIB = -L$(ARMNLIB)/lib/Linux_x86-64_pgi904 -L$(ARMNLIB)/lib
INCLUDE = -I$(BASE_INC_PATH) -I$(BASE_INC_PATH)/Linux_x86-64_pgi904

#See why .f is not in sources

SOURCES = $(*.cpp)
OBJ = $(patsubst %.cpp, %.o, $(notdir $(SOURCES)))


all : $(OBJ)
	$(CXX) -shared $(OBJ) -o rmnlib.so $(LIB) -lrmn -lstd -lc -lpgc -lpgf90 -lpgf90_rpm1 -lpgf902 -lnetcdf_c++ -lnetcdf -pgf90libs

%.o : %.cpp
	$(CXX) -c -g -fPIC $< -o $@ $(INCLUDE)

clean:
	rm -f *.o
	rm -f *.so
