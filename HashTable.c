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
void get_input(node *table[MAX_HASH]);
void table_insert(node *index, node *temp);

void table_search(node *table[MAX_HASH], char *word);
bool go_to_find(node *index, char *word);

void traverse_table(node *table[MAX_HASH], int num);
void traverse_list(node *index);

void free_table(node *table[MAX_HASH], int num);
void free_list(node *listp);

int hash_get(char *word);

int main(void)
{
    char word[20];
    int inpt;
    bool isrunning = true;
    node *table[MAX_HASH];

    for (int i = 0; i < MAX_HASH; i++)
    {
        table[i] = malloc(sizeof(node));
        if (table[i] == NULL)
        {
            printf("malloc() GAE (table)");
            return 1;
        }
        table[i]->next = NULL;
    }
    
    do
    {
        printf("[1] INSERT TO TABLE\n[2] FIND IN TABLE\n[3] SHOWTABLE\n[Else] DONE\n>>>");
        scanf("%i", &inpt);

        if (inpt == 1)
        {
            get_input(table);
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

void get_input(node *table[MAX_HASH])
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

        do
        {
        printf("Enter text here: ");
        scanf("%s", name);
        }
        while (strlen(name) > MAX_HASH);
        strcpy(temp->name, name);

        hash = hash_get(temp->name);
        table_insert(table[hash], temp);
    }
    free(name);
}

int hash_get(char *word)
{
    int hash_num = 0;
    hash_num = strlen(word);

    return (hash_num - 1) % MAX_HASH;
}

void table_insert(node *index, node *temp)
{
    if (index->next == NULL)
    {
        index->next = temp;
    }
    else
    {
        temp->next = index->next;
        index->next = temp;
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
    if (index->next == NULL)
    {
        return;
    }
    printf("%s\n", index->next->name);
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
