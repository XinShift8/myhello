CC = gcc
CFLAGS = -Wall -Wextra -g -O0

hello: hello.c
	$(CC) $(CFLAGS) hello.c -o hello

clean:
	rm -f hello
