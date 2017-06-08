CC=g++
CCFLAGS= -std=c++11
ODIR=obj
SOURCE  := $(wildcard *.c) $(wildcard *.cpp)
OBJ = $(patsubst %.cpp,$(ODIR)/%.o,$(SOURCE))
#LIBS = /usr/local/lib

TARGET = test

$(ODIR)/%.o: %.cpp
	$(CC) -c -o $@ $< $(CCFLAGS)

$(TARGET): $(OBJ)
	gcc -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~ $(TARGET)
