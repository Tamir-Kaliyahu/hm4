CC = gcc
FLAGS = -Wall -g

all: frequency

frequency: TrieMain.o Trie.o
	$(CC) $(FLAGS) -o frequency TrieMain.o

TrieMain.o: TrieMain.c Trie.h
	$(CC) $(FLAGS) -c TrieMain.c 

Trie.o: Trie.c Trie.h
	$(CC) $(FLAGS) -c Trie.c 

.PHONY: clean all

clean:
	rm -f *.o frequency
