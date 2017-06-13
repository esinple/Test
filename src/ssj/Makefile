GCC := g++
LD  := ld
AR  := ar

LDFLAGS := -shared -fpic
ARFLAGS := -crus
CFLAGS  := -g -Wall -fpic

DIR_INC := ../../include/ssj 
DIR_SRC := .
DIR_OBJ := ./.obj
DIR_LIB := ./.obj

LIB_NAME    := libSSJ

SRC := $(wildcard ${DIR_SRC}/*.cpp) $(wildcard ${DIR_SRC}/*.cpp)
OBJ := $(patsubst %.cpp, ${DIR_OBJ}/%.o, $(notdir ${SRC}))

SHARE_LIB   := $(LIB_NAME).so
DYNAMIC_LIB := $(LIB_NAME).a

INC := -I${DIR_INC}

all:$(DYNAMIC_LIB)

${DIR_OBJ}/%.o:${DIR_SRC}/%.cpp
	@echo Compiling $(OBJ) ...
	$(GCC) $(CFLAGS) -o $@ -c $< ${INC} -g

$(DYNAMIC_LIB):$(OBJ)
	#$(LD) $(LDFLAGS) -o $(DIR_LIB)/$(SHARE_LIB) $(OBJ)
	@echo ${ARFLAGS} $(DIR_LIB)/$(DYNAMIC_LIB) objis$(OBJ)
	@echo $(DIR_LIB)/$(DYNAMIC_LIB)
	${AR} ${ARFLAGS} $(DIR_LIB)/$(DYNAMIC_LIB) $(OBJ)
	@ctags -R -h".c.cpp.h" -o tags


clean:
	rm -rf $(DIR_OBJ)/*.o $(DIR_LIB)/*.so $(DIR_LIB)/*.a
