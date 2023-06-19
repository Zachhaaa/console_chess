#remember fshort -enums  

SRC := $(wildcard src/*.c) $(wildcard src/*/*.c)
INCLUDE := $(wildcard include/*.h)
INCLUDE_DIR := include/
EXECUTABLE_NAME := console_chess
CC := gcc
CFLAGS := -g -Wall

debug/$(EXECUTABLE_NAME): $(SRC) $(INCLUDE)
	$(CC) $(CFLAGS) -I $(INCLUDE_DIR) -o debug/$(EXECUTABLE_NAME) $(SRC)

run: debug/$(EXECUTABLE_NAME)
	debug/$(EXECUTABLE_NAME)

debug: debug/$(EXECUTABLE_NAME)
	gdb debug/$(EXECUTABLE_NAME)
