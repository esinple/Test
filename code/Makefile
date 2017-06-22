ODIR=.obj
SOURCE:= $(wildcard *.c) $(wildcard *.cpp)
OBJ= $(patsubst %.cpp,$(ODIR)/%.o,$(SOURCE))
LIB_PATH=/home/esinple/Test/lib
INCLUDE_PATH=../include
INCLUDE:=-I$(INCLUDE_PATH) -I$(INCLUDE_PATH)/ssj -I$(INCLUDE_PATH)/log4cxx
LIB=-L$(LIB_PATH) -llog4cxx -lSSJ


CC=g++
CCFLAGS= -g -std=c++11 $(INCLUDE) $(LIB)

TARGET = test

$(ODIR)/%.o: %.cpp
	@echo $(INCLUDE)
	$(CC) -c -o $@ $< $(CCFLAGS)

$(TARGET): $(OBJ)
	gcc -o $@ $^ $(CFLAGS) $(LIB)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~ $(TARGET)
