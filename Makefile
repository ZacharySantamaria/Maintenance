# Makefile for maintenance CLI program

# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -Wextra

# SQLite library
LIBS = -lsqlite3

# Source files
SRC = main.c

# Executable name
TARGET = maintenance

# Default target
all: $(TARGET)

# Rule to create the executable
$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC) $(LIBS)

# Clean rule to remove the executable
clean:
	rm -f $(TARGET)

