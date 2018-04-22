# 编译器
CC = gcc
CXX= g++

BASE ?= ./
SRC ?= ./src/
BIN ?= ./bin/
CFLAGS = -Wall 
CXXFLAGS = -Wall






# 头文件
INC += -I../include


# 库文件
LIB +=   \
	-lm -lz \
	-Wl,-Bstatic -L/usr/lib64 -lpthread \
	-Wl,-Bdynamic -lstdc++ -std=c++11
	


	
	
all:test

test: test.o ./fact/fact.o
	$(CXX) -Wall test.o  ./fact/fact.o -o test  $(LIB)


test.o: test.cpp
	$(CC) -c $(CFLAGS) test.cpp  $(INC)

./fact/fact.o:./fact/fact.cpp
	$(CC) -c $(CXXFLAGS) $@.d -o $@ $<

	
# clean声明为伪目标，每次都执行对应的命令
.PHONEY: clean 
clean:
	rm -fr *.o test
