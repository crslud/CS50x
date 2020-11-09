#include <stdio.h>
#include <cs50.h>

int getNumber();
void spaceGenerator(int spaces);
void blockGenerator(int blocks);
void pyramidGenerator(int x);


int main(void)
{
    pyramidGenerator(getNumber());
}

/* Functions */

int getNumber()
{
    /* Gets the number with CS50's function and a while loop */
    int num = 0;
    do
    {
        num = get_int("Enter your number (1 through 8) for the height: ");
    }
    while (num < 1 || num > 8);
    return num;
}

void spaceGenerator(int spaces)
{
    /* Creates the space blocks */
    for (int i = spaces; i > 1; i--)
    {
        printf(" ");
    }
}

void blockGenerator(int blocks)
{
    /* Creates the # blocks */
    for (int i = blocks; i > 0; i--)
    {
        printf("#");
    }
}

void pyramidGenerator(int x)
{
    /* Runs through the sequence to construct the pyramid. */
    for (int i = 0; i < x; i++)
    {
        spaceGenerator(x - i);
        blockGenerator(i + 1);
        printf("  ");
        blockGenerator(i + 1);
        printf("\n");
    }
}

