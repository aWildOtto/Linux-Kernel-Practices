# Makefile for building multi-file application
# by Brian Fraser

# final executable to build:
TARGET= cs300_testapp
# .o files to link in (for all .c files)
OBJS = cs300_testapp.o


CFLAGS = -std=c99 -D _GNU_SOURCE -static
CC_C = gcc

all: clean $(TARGET)

run:
	echo *********************************
	./cs300_testapp

valgrind:
	valgrind --leak-check=full --show-leak-kinds=all --num-callers=20 ./cs300_testapp

%.o : %.c
	$(CC) -c $(CFLAGS) $<

$(TARGET): $(OBJS)
	$(CC_C) $(CFLAGS) $(OBJS) -o $@

clean:
	rm -f $(TARGET)
	rm -f $(OBJS)

transfer:
	scp -P 2222 cs300_testapp root@localhost:~
