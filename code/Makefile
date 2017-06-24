ODIR=.obj
SOURCE:= $(wildcard *.c) $(wildcard *.cpp)
OBJ= $(patsubst %.cpp,$(ODIR)/%.o,$(SOURCE))
LIB_PATH=/home/esinple/Test/lib
INCLUDE_PATH=../include
INCLUDE:=-I$(INCLUDE_PATH) -I$(INCLUDE_PATH)/ssj -I$(INCLUDE_PATH)/log4cxx -I$(INCLUDE_PATH)/boost
LIB=-L$(LIB_PATH) -llog4cxx -lSSJ -lpthread -lboost_thread -lboost_log -lboost_system -lboost_log_setup


CC=g++
CCFLAGS= -g -std=c++11 -DBOOST_ALL_DYN_LINK -DBOOST_LOG_DYN_LINK $(INCLUDE) $(LIB)

TARGET = test

$(ODIR)/%.o: %.cpp
	@echo $(INCLUDE)
	$(CC) -c -o $@ $< $(CCFLAGS)

$(TARGET): $(OBJ)
	gcc -o $@ $^ $(CFLAGS) $(LIB)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~ $(TARGET)
