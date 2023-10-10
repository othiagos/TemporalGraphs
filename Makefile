NAME = TemporalGraphs
TEST_NAME = $(NAME)Test
CC = g++
SRC_DIR = ./src
INC_DIR = ./include
LIB_DIR = ./lib
BIN_DIR = ./bin
BUILD_DIR = ./build
TEST_DIR = ./test
CFLAGS = --std=c++11 -Wall -O0 -g
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

leak_check: all
	valgrind --leak-check=full --show-leak-kinds=all $(EXE) < $(ARGS) > /dev/null 

heap_profiler: all
	valgrind --tool=massif --massif-out-file=massif.txt $(EXE) < $(ARGS) > /dev/null
	ms_print massif.txt > ms_out.txt

clean:
	rm -f $(BUILD_DIR)/*
	rm -f $(EXE)
	rm -f $(EXE_TEST)

file:
	cpp-merge -i $(INC_DIR) -s $(SRC_DIR) $(SRC_DIR)/$(NAME).cpp -o tp.cpp