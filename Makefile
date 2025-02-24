all: memoize

OBJS = 03-memoize-money.o memoize.o money_words.o
CC = gcc
CFLAGS = -Wall -gdwarf-3

memoize: $(OBJS)
	gcc -o a.out $(CFLAGS) $(OBJS) -lm

03-memoize-money.o: 03-memoize-money.c

memoize.o: memoize.c memoize.h

money_words: money_words.c money_words.h

clean:
	rm -f a.out $(OBJS)
