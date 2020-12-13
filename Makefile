CXX       := g++
CXX_FLAGS := -std=c++17 -ggdb

BIN     := bin
SRC     := src
INCLUDE := include
LIB 	:= lib

LIBRARIES   := -lboost_program_options
EXECUTABLE  := finalE

SO1_NAME	:= dataGen
SO2_NAME	:= functions


LIB_INSTALL_DIR := /usr/lib/x86_64-linux-gnu
BIN_INSTALL_DIR := /usr/local/bin



all: $(LIB)/lib$(SO1_NAME).so $(LIB)/lib$(SO2_NAME).so  $(BIN)/$(EXECUTABLE)

run: clean all
	clear

	LD_LIBRARY_PATH=$(pwd)/lib ./$(BIN)/$(EXECUTABLE) --outFile "testOne.txt" --size 100 --algorithm 3
	LD_LIBRARY_PATH=$(pwd)/lib ./$(BIN)/$(EXECUTABLE) --outFile "testTwo.txt" --size 100 --algorithm 5
	LD_LIBRARY_PATH=$(pwd)/lib ./$(BIN)/$(EXECUTABLE) --outFile "testThree.txt" --size 10


$(LIB)/lib$(SO1_NAME).so: $(SRC)/$(SO1_NAME)/*.cpp
	$(CXX) -fPIC -c -Wall -I$(INCLUDE) $^ -o $@ $(LIBRARIES)

$(LIB)/lib$(SO2_NAME).so: $(SRC)/$(SO2_NAME)/*.cpp
	$(CXX) -fPIC -c -Wall -I$(INCLUDE) $^ -o $@ $(LIBRARIES) 



$(BIN)/$(EXECUTABLE): $(SRC)/final.cpp
	$(CXX) $(CXX_FLAGS) -I$(INCLUDE) $^ -o $@ -L$(LIB) -l$(SO1_NAME) -l$(SO2_NAME) $(LIBRARIES)


clean:
	-rm $(BIN)/*
	-rm $(LIB)/*

install:
	cp $(LIB)/lib${SO1_NAME}.so $(LIB_INSTALL_DIR)/
	cp $(LIB)/lib${SO2_NAME}.so $(LIB_INSTALL_DIR)/
	cp $(BIN)/$(EXECUTABLE) $(BIN_INSTALL_DIR)/

remove:
	rm $(LIB_INSTALL_DIR)/lib$(SO1_NAME).so
	rm $(LIB_INSTALL_DIR)/lib$(SO2_NAME).so
	rm $(BIN_INSTALL_DIR)/$(EXECUTABLE)
