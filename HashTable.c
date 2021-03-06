#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX_HASH 9

typedef struct node
{
    char name[MAX_HASH];
    struct node *next;
} node;

// Function prototypes
void insert_input(node *table[MAX_HASH]);
void table_insert(node *table[MAX_HASH], node *temp, int hash);
void table_search(node *table[MAX_HASH], char *word);
void traverse_table(node *table[MAX_HASH], int num);
void traverse_list(node *index);
void free_table(node *table[MAX_HASH], int num);
void free_list(node *listp);

bool go_to_find(node *index, char *word);

unsigned int hash_get(const char *word);

int main(void)
{
    char word[30];
    int inpt;
    bool isrunning = true;
    node *table[MAX_HASH] = {NULL};

    do
    {
        printf("[1] INSERT TO TABLE\n[2] FIND IN TABLE\n[3] SHOWTABLE\n[Else] DONE\n>>>");
        scanf("%i", &inpt);

        if (inpt == 1)
        {
            insert_input(table);
        }
        else if (inpt == 2)
        {
            printf("ENTER WORD TO BE SEARCHED: ");
            scanf("%s", word);
            table_search(table, word);
        }
        else if (inpt == 3)
        {
            traverse_table(table, MAX_HASH);
        }
        else
        {
            isrunning = false;
        }
    }
    while(isrunning);

    free_table(table, MAX_HASH);
}

void insert_input(node *table[MAX_HASH])
{
    int hash, num;
    node *temp = NULL;
    char *name = malloc(30 * sizeof(char));
    if (name == NULL)
    {
        printf("malloc() GAE (name)");
        exit(1);
    }

    printf("How many names?: ");
    scanf("%i", &num);

    for (int i = 0; i < num; i++)
    {
        temp = malloc(sizeof(node));
        if (temp == NULL)
        {
            printf("malloc() GAE (temp)");
            exit(1);
        }
        temp->next = NULL;
        do
        {
        printf("Enter text here: ");
        scanf("%s", name);
        }
        while (strlen(name) > MAX_HASH);
        strcpy(temp->name, name);

        hash = hash_get(temp->name);
        table_insert(table, temp, hash);

    }
    free(name);
}

// https://en.wikipedia.org/wiki/Fowler-Noll-Vo_hash_function
unsigned int hash_get(const char *word)
{
    unsigned int h = 2166136261; // FNV_OFFSET_BASIS
    const unsigned char* ptr = (const unsigned char *)word;

    while (*ptr)
    {
            h = (*ptr++ ^ h) * 16777619; // FNV_PRIME
    }

    return h % MAX_HASH;
}

void table_insert(node *table[MAX_HASH], node *temp, int hash)
{
    if (table[hash] == NULL)
        {
            table[hash] = temp;
        }
        else
        {
            temp->next = table[hash];
            table[hash] = temp;
        }
}


void table_search(node *table[MAX_HASH], char *word)
{
    int hash = hash_get(word);
    bool isfound = go_to_find(table[hash], word);
    if(isfound)
    {
        printf("at [%i] index.\n", hash);
    }
    else
    {
        printf("NOT FOUND\n");
    }
}

bool go_to_find(node *index, char *word)
{
    if (index == NULL)
    {
        return false;
    }

    if (strcmp(index->name, word) == 0)
    {
        printf("%s is found! ", word);
        return true;
    }

    return go_to_find(index->next, word);
}

void traverse_table(node *table[MAX_HASH], int num)
{
    if (num == 0){
        return;
    }

    traverse_table(table, num - 1);
    traverse_list(table[num - 1]);
}

void traverse_list(node *index)
{
    if (index == NULL)
    {
        return;
    }
    printf("%s\n", index->name);
    traverse_list(index->next);
}

void free_table(node *table[MAX_HASH], int num)
{
    if (num == 0){
        return;
    }

    free_table(table, num - 1);
    free_list(table[num - 1]);
}

void free_list(node *listp)
{
    if (listp == NULL)
    {
        return;
    }

    free_list(listp->next);
    free(listp);
}
