#include <stdio.h>
#include <stdlib.h>

// Defines what a node is
typedef struct node
{
    int value;
    struct node *next;
} node;

// Prototypes
node *createlist(int size);
void printlist(node *head);
void freelist(node *head);

// I just realized I made it unnecessarily complicated
int main(int argc, char *argv[])
{
    int num = strtol(argv[1], NULL, 10);
    char *var = getenv("NAME");

    // Checks if the environment variable exists first
    if (var){
        printf_s("Hello, %s, for some reason you wanted to enter %s numbers\n",  var, argv[1]);
    }

    node *list1 = createlist(num);
    if (!list1){
        return 1;
    }

    printf_s("YOU ENTERED THESE NUMBERS: ");
    printlist(list1);
    freelist(list1);
    return 0;
}


// Returns a list of size n
node *createlist(int n)
{
    // Initializes the pointers (points them to null)
    node *head = NULL,
         *c = NULL;

    for (int i = 0; i < n; i++)
    {
        node *temp = malloc(sizeof(node));
        if (temp == NULL)
        {
            return NULL;
        }
        temp->next = NULL;

        printf_s("ENTER THE DESIRED AMOUNT for number %i: ", i + 1);
        scanf("%i", &temp->value);

        if (head == NULL)
        {
            head = temp;
            c = head;
        }
        else
        {
            c->next = temp;
            c = c->next;
        }
    }
    return head;
}


// Prints the list
void printlist(node *head)
{
    if (head == NULL){
        return;
    }
    printf_s("%i ", head->value);
    printlist(head->next);
}


// Frees em
void freelist(node *head)
{
    if (head == NULL)
    {
        return;
    }
    freelist(head->next);
    free(head);
}
