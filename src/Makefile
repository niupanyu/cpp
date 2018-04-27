# 编译器  
CC  = gcc
CXX = g++

BASE ?= ./
SRC ?= ../src
BIN ?= ../bin
TMP=../tmp


# 头文件
INC += -I../include


# 库文件
LIB +=   \
	-lm -lz \
	-Wl,-Bstatic -L/usr/lib64 -lpthread \
	-Wl,-Bdynamic -lstdc++ 

OBJ :=\
$(addprefix $(TMP)/, \
$(addsuffix .o, $(basename $(notdir $(wildcard *.cpp)))))

OBJ2 +=\
$(addprefix $(TMP)/, \
$(addsuffix .o, $(basename $(notdir $(wildcard fact/*.cpp)))))

TARGET=$(BIN)/test
CFLAGS = -Wall 
#-MF 将依赖关系输出到指定.d文件路径 DEP
CXXFLAGS =  -Wall -std=c++11 -MMD -MP -MF 

DEP:=$(wildcard $(addsuffix .d, ${OBJ})) 


$(TARGET):$(OBJ2)  $(OBJ)
	$(CXX) -o $@ $^ $(LIB)

$(OBJ2):$(TMP)/%.o:$(SRC)/fact/%.cpp 
	$(CXX) -c  $(INC) $(CXXFLAGS)  $@.d -o $@ $< 


$(OBJ):$(TMP)/%.o:$(SRC)/%.cpp 
	$(CXX)  -c  $(INC) $(CXXFLAGS)  $@.d -o $@ $< 


#test: test.o  fact/fact.o
#	$(CXX) -Wall test.o  ./fact/fact.o -o test  $(LIB)


#test.o: test.cpp
#	$(CC) -c $(CFLAGS) test.cpp  $(INC)

#./fact/fact.o: fact/fact.cpp
#	$(CXX) -c $(CXXFLAGS) $@.d -o $@ $< #$@.d 依赖文件

	
# clean声明为伪目标，每次都执行对应的命令
.PHONEY: clean 
clean:
	-rm -f $(TMP)/* $(BIN)/*
	#-rm -fr *.o test  

-include $(DEP)
