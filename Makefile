CC = gcc
CFLAGS = -Wall -Wextra -g

TARGET = main
SRCS = main.c lps.c

all:
	$(CC) $(CFLAGS) $(SRCS) -o $(TARGET)

clean:
	rm -f $(TARGET)

.PHONY: all clean