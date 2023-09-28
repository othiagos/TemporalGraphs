NAME = TemporalGraphs
TEST_NAME = TemporalGraphsTest
CC = g++
SRC_DIR = ./src
INC_DIR = ./include
LIB_DIR = ./lib
BIN_DIR = ./bin
BUILD_DIR = ./build
TEST_DIR = ./test
CFLAGS = --std=c++20 -Wall -O0 -g 
EXE = $(BIN_DIR)/$(NAME)
EXE_TEST = $(BIN_DIR)/$(TEST_NAME)

OBJS = \
	$(BUILD_DIR)/Connection.o \
	$(BUILD_DIR)/Village.o \
	$(BUILD_DIR)/Graph.o

TEST_OBJS = \

all: $(EXE)

run: all
	$(EXE) $(ARGS)

$(EXE): $(BUILD_DIR)/$(NAME).o $(OBJS) 
	$(CC) $(CFLAGS) $< $(OBJS) -o $@

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp $(INC_DIR)/%.hpp
	$(CC) -c $(CFLAGS) $< -I $(INC_DIR) -o $@

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CC) -c $(CFLAGS) $< -I $(INC_DIR) -o $@ 

test: $(EXE_TEST)

run_test: test
	$(EXE_TEST)

$(EXE_TEST): $(BUILD_DIR)/$(TEST_NAME).o $(OBJS) $(TEST_OBJS)
	$(CC) $(CFLAGS) $< $(OBJS) $(TEST_OBJS) -o $(EXE_TEST)

$(BUILD_DIR)/%.o: $(TEST_DIR)/%.cpp
	$(CC) -c $(CFLAGS) $< -I $(INC_DIR) -I $(LIB_DIR) -o $@

$(BUILD_DIR)/%.o: $(TEST_DIR)/%.cpp
	$(CC) -c $(CFLAGS) $< -I $(INC_DIR) -I $(LIB_DIR) -o $@

clean:
	rm -f $(BUILD_DIR)/*
	rm -f $(EXE)
	rm -f $(EXE_TEST)