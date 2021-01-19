#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include "Trie.h"
#define LINE 256
#define WORD 30


int get_word(char word[])
{
    int i = 0;
    char c;
    c = getchar();
    if(c=='\n')
        c=getchar();
    //printf("this is c: '%c'",c);
    while((c != '\n')&&( c != '\0' )&&(c != '\t' )&&(c != ' ')&&(c!='\r')&&(c!=EOF))
    {
//        printf("-%c-",c);
        if(((c-'a'>=0)&&(c-'a'<=25))||((c-'A'>=0)&&(c-'A'<=25)))
        {
            word[i] = c;
            i++;
        }
        c=getchar();
    }
    word[i]='\0';
//    printf("word is '%s'. \n",word);
    return i;
}

void lower_str(char * word, int size)
{
    for (int i = 0; i < size; ++i) {
        word[i]=tolower(word[i]);
    }
}

void insert_word(node * root, char * word, int size)
{
    int i;
    int index;
    struct node *curtNode = root;
    for (i = 0; i < size; i++)
    {
        index = (word[i]-'a');
//        printf("index is : %d char is %c \n", index, word[i]);
        if (curtNode->children[index]==NULL)
        {
//            printf("creating new letter: %c \n",word[i]);
            struct node *goNode = NULL;
            goNode = (struct node *)malloc(sizeof(struct node));
            goNode->letter = word[i];
            goNode->last=false;
            goNode->count=0;
            if(i==size-1) {
                goNode->last = true;
                goNode->count++;

            }
            for (int j = 0; j < NUM_LETTERS; j++){
                goNode->children[j] = NULL;
            }
            curtNode->children[index]=goNode;
//            printf("added '%s': count is %lu \n \n",word,curtNode->children[index]->count);
        }
        else {
            //children is alive, need to enter inside.
            if (i == size - 1) {
                curtNode->children[index]->count++;
                curtNode->last = true;
//                printf("added '%s': count is %lu \n \n",word,curtNode->children[index]->count);
            }
        }

        curtNode=curtNode->children[index];
    }

}

void printTrie(node* head,char word[], int pos){
    node* curtNode = head;
    if(curtNode == NULL) return;
    if(curtNode->count > 0){
        word[pos] = '\0';
        printf("%s %lu \n",word,curtNode->count);
    }

    for(int i = 0; i < NUM_LETTERS; i++){
        if(curtNode->children[i] != NULL){
//            printf("i is %d, pos is %d \n",i,pos);
            word[pos]=curtNode->children[i]->letter;
            printTrie(curtNode->children[i], word, pos + 1); //recursive call for position of next letter.
        }
    }
}

int maxWordLength(node * tNode, int counter){
    int max = counter;
    for(int i = 0; i < NUM_LETTERS; i++){
        if(tNode->children[i] != NULL){
            int x = maxWordLength(tNode->children[i], counter + 1);
            if(max < x)
                max = x;
        }
    }
    return max;
}


void cleanNode(struct node * root)
{
    node* tNode = root;
    for (size_t i = 0; i < NUM_LETTERS; i++)
    {
        if(tNode->children[i] != NULL){
            cleanNode(tNode->children[i]);
        }
    }
    free(tNode);
}


void printrevTrie(node* head,char word[], int pos){
    node* curtNode = head;
    if(curtNode == NULL) return;
    

    for(int i = NUM_LETTERS-1;i>=0; i--){
        if(curtNode->children[i] != NULL){
//            printf("i is %d, pos is %d \n",i,pos);
            word[pos]=curtNode->children[i]->letter;
            printrevTrie(curtNode->children[i], word, pos + 1); //recursive call for position of next letter.
        }
    }
    if(curtNode->count > 0){
        word[pos] = '\0';
        printf("%s %lu \n",word,curtNode->count);
    }
}
