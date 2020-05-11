#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_HASH 9

typedef struct node
{
    char name[MAX_HASH];
    struct node *next;
} node;

// Looks like a gun lmao
void get_input(node *table[MAX_HASH], int num, node *temp);
void hash_insert(node *table[MAX_HASH], int hash, node *temp);
void free_table(node *table[MAX_HASH], int num);
void free_list(node *listp);
int hash_get(node *nodep);

int main(void)
{
    int num, inpt;
    bool isrunning = true;
    node *table[MAX_HASH];
    node *temp = NULL;

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
            printf("How many names?: ");
            scanf("%i", &num);
            get_input(table, num, temp);
        }
        else if (inpt == 2)
        {

        }
        else if (inpt == 3)
        {

        }
        else
        {
            isrunning = false;
        }
    }
    while(isrunning);

    free_table(table, MAX_HASH);
}

void get_input(node *table[MAX_HASH], int num, node *temp)
{
    int hash;
    char *name = malloc(30 * sizeof(char));

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

        hash = hash_get(temp);
        hash_insert(table, hash, temp);
    }
    free(name);
}

int hash_get(node *nodep)
{
    int hash_num = 0;
    hash_num = strlen(nodep->name);

    return hash_num % MAX_HASH;
}

void hash_insert(node *table[MAX_HASH], int hash, node *temp)
{
    if (table[hash]->next == NULL)
    {
        table[hash]->next = temp;
    }
    else
    {
        temp->next = table[hash]->next;
        table[hash]->next = temp;
    }
}

void free_table(node *table[MAX_HASH], int num)
{
    if (num == 0){
        return;
    }

    free_table(table, num -1);
    free_list(table[num-1]);
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
