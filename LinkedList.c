#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int num;
	struct node* next;
}node;

void print_and_free_list(node* head);

int main(void)
{
    int nums;
	node* temp = NULL;
	node* head = NULL;
	node* c = NULL;

    printf("How many Numbers?: ");
    scanf("%i", &nums);
	for (int i = 0; i < nums; i++)
	{
		temp = malloc(sizeof(node));
		if (temp == NULL){
		    printf("Unable to Allocate Memory");
		    return 1;
		}
		temp->next = NULL;
		scanf("%i", &temp->num);

		if (head == NULL)
		{
			head = temp;
			c = head;
		}
		else {
			c->next = temp;
			c = c->next;
		}
	}
    print_and_free_list(head);
}

void print_and_free_list(node* head)
{
    if (head == NULL) {
	return;
	}

	printf("%i \n", head->num);
	free(head);
	print_and_free_list(head->next);
}
