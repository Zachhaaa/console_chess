#remember fshort -enums  

SRC := $(wildcard src/*.c) $(wildcard src/*/*.c)
INCLUDE := $(wildcard include/*.h)
INCLUDE_DIR := include/
EXECUTABLE_NAME := debug_console_chess
CC := gcc
CFLAGS := -g -Wall

$(EXECUTABLE_NAME): $(SRC) $(INCLUDE)
	$(CC) $(CFLAGS) -I $(INCLUDE_DIR) -o $(EXECUTABLE_NAME) $(SRC)

run: $(EXECUTABLE_NAME)
	$(EXECUTABLE_NAME)

debug: $(EXECUTABLE_NAME)
	gdb $(EXECUTABLE_NAME)
