#remember fshort -enums  

SRC := $(wildcard src/*.c) $(wildcard src/*/*.c)
INCLUDE := $(wildcard include/*.h)
INCLUDE_DIR := include/
EXECUTABLE_NAME := debug_console_chess
RELEASE_EXECUTABLE_NAME := release_console_chess
CC := gcc
CFLAGS := -g -Wall
RELEASE_FLAGS := -Wall -O3

$(EXECUTABLE_NAME): $(SRC) $(INCLUDE)
	$(CC) $(CFLAGS) -I $(INCLUDE_DIR) -o $(EXECUTABLE_NAME) $(SRC)

release:  $(SRC) $(INCLUDE)
	$(CC) $(RELEASE_FLAGS) -I $(INCLUDE_DIR) -o $(RELEASE_EXECUTABLE_NAME) $(SRC)

run: $(EXECUTABLE_NAME)
	$(EXECUTABLE_NAME)

debug: $(EXECUTABLE_NAME)
	gdb $(EXECUTABLE_NAME)
