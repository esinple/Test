ODIR=.obj
SOURCE:= $(wildcard *.c) $(wildcard *.cpp)
OBJ= $(patsubst %.cpp,$(ODIR)/%.o,$(SOURCE))
LIB_PATH=/home/esinple/Test/lib
INCLUDE=/home/esinple/Test/include
LIB=-L$(LIB_PATH) -llog4cxx -lSSJ

CC=g++
CCFLAGS= -g -std=c++11 -I$(INCLUDE) $(LIB)

TARGET = test

$(ODIR)/%.o: %.cpp
	$(CC) -c -o $@ $< $(CCFLAGS)

$(TARGET): $(OBJ)
	gcc -o $@ $^ $(CFLAGS) $(LIB)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~ $(TARGET)
