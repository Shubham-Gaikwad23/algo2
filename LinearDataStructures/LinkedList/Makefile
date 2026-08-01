CC = gcc
CFLAGS = -Wall -Wextra -std=c17 -I./ -L./ -Wl,-rpath,'$$ORIGIN'

.PHONY: all clean

all: revList

libdlist.so: dlist.c dlist.h
	$(CC) $(CFLAGS) -o $@ -shared $^

revList: reverseLinkedList.c dlist.h libdlist.so
	$(CC) $(CFLAGS) -o $@ $< -ldlist

clean:
	rm -f revList *.so
