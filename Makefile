# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -O2 -march=native

# Executable name
TARGET = maintance

# Rule to build the executable
$(TARGET): main.c
	$(CC) $(CFLAGS) main.c -o $(TARGET)

# Clean rule
clean:
	rm -f $(TARGET)
