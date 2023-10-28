# @author: Gildardo (Quinn) Haro
# @NSHE: 5004465396
# @brief: makefile
CXXFLAGS =  -std=c++20 -Wall -Wextra -pedantic -Wshadow -Wconversion $\
		    -Werror=vla -Werror=old-style-cast -Werror=return-type $\
		    -Werror=missing-declarations -Wno-deprecated-copy -g -Ilib

CXX = g++

BUILD = ./build
SRC = ./src
LIB = ./lib

# creates assignment program
$(BUILD)/hw2: $(BUILD)/hw2.o
	$(CXX) $(CXXFLAGS) $(BUILD)/hw2.o -o $(BUILD)/hw2

# pretty name for buliding unit test
unit_test: $(BUILD)/Stack_Test

# creates unit tests
$(BUILD)/Stack_Test: $(BUILD)/Stack_Test.o
	$(CXX) $(CXXFLAGS) $(BUILD)/Stack_Test.o -o $(BUILD)/Stack_Test

# creates all object files needed
$(BUILD)/%.o: $(SRC)/%.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

.PHONY: clean
clean:
	rm -f ./build/*