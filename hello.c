#include <stdio.h>
#include <stdbool.h>

// Function Prototypes
void print_asterisk(void);
void print_triangle(int x, int mx);

int main(void)
{
    // for Loop
    for (int i = 0; i < 5; i++)
    {
        printf("HELLO %i \n", i);
    }

    // while loop
    int c = 0;
    while (true)
    {
        // if statement
        if (c == 0)
        {
            printf("Zero\n");
        }
        // else if
        else if (c == 1)
        {
            printf("One\n");
        }
        // else statement
        else
        {
            break;
        }
        c++;
    }

    print_asterisk();

    for (int i = 0; i < 4; i++)
    {
        for (int j = 4 - i; j > 1; j--)
        {
            printf(" ");
        }

        for (int k = 0; k <= i; k++)
        {
            printf("*");
        }

        if (i != 0)
        {
            for(int l = 0; l < i; l++)
            {
                printf("*");
            }
        }
        printf("\n");
    }
    
    print_triangle(7, 7);
}

// Function prints an asterisk
void print_asterisk(void)
{
    printf("*\n");
}

// Function prints a triangle according to the number of x and mx via recursion
void print_triangle(int x, int mx)
{
    if (mx <= 0)
    {
        return;
    }

    for (int i = mx; i > 0; i--){
        printf(" ");
    }
    for (int j = 0; j <= x - mx; j++){
        printf("*");
    }
    if (mx != 7)
    {
        for (int l = 0; l < x - mx; l++)
        {
            printf("*");
        }
    }
    printf("\n");

    print_triangle(x, mx - 1);
}