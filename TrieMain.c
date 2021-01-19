#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "Trie.c"
#define NUM_LETTERS ((int)26)
#define WORD 30

int main(int argc, char *argv[]) {
    //printf("Hello, Welcome to check Trie words!\n"); // get input text.
    int rev;
    if(argc == 2 && strcmp(argv[1], "r") == 0)
        rev=1;
    else
        rev=0;
//    printf("this is rev : %d \n",rev);
//    printf("there is %d argc. \n",argc);
    //init node Trie.

    node * root = NULL;
    root = (node *)malloc(sizeof(node));
    if (root) // check if succeed assemble memory
    {
        root->count = 0;
        root->last=false;
        for (int i = 0; i < NUM_LETTERS; i++){
            root->children[i] = NULL;
        }
    }
    else{
        printf("could not create Node. check memory.");
        return 0;
    }
    char word[WORD];
    memset(word , 0 , WORD);
    int wordsize = get_word(word);
    lower_str(word, wordsize);
    //struct node *tNode = root;
    while(wordsize>0)
    {
//        printf("---next word is '%s' ! size: %d ---\n", word, wordsize);
        insert_word(root, word, wordsize);
//        printf("insert word ok.");
        wordsize = get_word(word);
//        printf("wordsize ok.");
        lower_str(word, wordsize);
//        printf("!===next word is '%s' ! size: %d ===\n", word, wordsize);
    }
    int maxLength = maxWordLength(root,0);
    //printf("max length is %d \n",maxLength);
    char * str = (char *)malloc(maxLength);

    if(!rev)
    {
        printTrie(root,str,0);
    }
    else
    {
        printrevTrie(root,str,0);
    }
    free(str);
    cleanNode(root);
    return 0;
}
