#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    char name[32];
    struct node *next;
} node;

void freelist(node *listp);

int main(void)
{
    int num;
    char *name = malloc(32 * sizeof(char));
    node *list, *tmp, *c;

    list = malloc(sizeof(node));
    if (list == NULL)
    {
        printf("MALLOC GAE");
        return 1;
    }

    list->next = NULL;
    c = list;

    printf("Number of names?: ");
    scanf("%i", &num);

    for (int i = 0; i < num; i++)
    {
        tmp = malloc(sizeof(node));
        if (tmp == NULL)
        {
            printf("MALLOC GAE");
            return 1;
        }

        printf("PLEASE ENTER NAME HERE: ");
        scanf("%s", name);
        strcpy(tmp->name, name);
        tmp->next = NULL;

        tmp = list->next;
        list->next = tmp;
    }

    tmp = list->next;

    while (tmp != NULL)
    {
        printf("%s\n", tmp->name);
        tmp = tmp->next;
    }

    freelist(list);
    free(name);
}

void freelist(node *listp)
{
    if (listp == NULL)
    {
        return;
    }

    freelist(listp->next);
    free(listp);
}
