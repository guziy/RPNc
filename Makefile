


FC = pgf90
CC = pgcc 


BASE_INC_PATH = $(ARMNLIB)/include
LIB = -L$(ARMNLIB)/lib/Linux_x86-64_pgi904 -L$(ARMNLIB)/lib
INCLUDE = -I$(BASE_INC_PATH) -I$(BASE_INC_PATH)/Linux_x86-64_pgi904

SOURCES_C = $(wildcard *.c) 
SOURCES_F = $(wildcard *.f)
OBJ = $(patsubst %.c, %.o, $(notdir $(SOURCES_C))) \
      $(patsubst %.f, %.o, $(notdir $(SOURCES_F))) 
	

all : $(OBJ)
	@echo $(OBJ)
	$(FC) -shared $(OBJ) -o rmnlib.so -lrmn_beta013 $(LIB)
	

%.o : %.c
	$(CC) -g -c $< -o $@ $(INCLUDE) -fPIC

%.o : %.f
	$(FC) -g -c  $< -o $@ $(INCLUDE) -fPIC
	#gfortran -fPIC -c -g $< -o $@



clean:
	rm -f $(OBJ)
	rm -f *.so
