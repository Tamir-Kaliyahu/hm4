#ifndef EX4_TRIE_H
#define EX4_TRIE_H
#define NUM_LETTERS ((int)26)
typedef enum {false, true} bool;

typedef struct node {
    bool last;
    char letter;
    long unsigned int count;
    struct node* children[NUM_LETTERS];
} node;

//void lower_str(char * word, int size);
//int get_word(char * word); // scan a word and return size of the scanned word
int get_word(char word[]);

void lower_str(char * word, int size);

void insert_word(node * root, char * word, int size);

void printTrie(node* head,char word[], int pos);

int maxWordLength(node * tNode, int counter);

void cleanNode(struct node * root);


void printrevTrie(node* head,char word[], int pos);


#endif //EX4_TRIE_H
