#include <stdio.h>
#include <string.h>
#include <cs50.h>

int diff(char x);

int main(int argc, char *argv[])
{
    // check 1: check for correct command line usage
    if (argc != 2)
    {
        printf("Usage: ./substitution key.\n");
        return 1;
    }

    // check 2: check for key length
    if (strlen(argv[1]) != 26)
    {
        printf("Please try again with a 26 letter key\n");
        return 1;
    }

    // check 3: check only letters appear in key
    for (int i = 0; i < strlen(argv[1]); i++)
    {
        if ((argv[1][i] >= 'a' && argv[1][i] <= 'z') || (argv[1][i] >= 'A' && argv[1][i] <= 'Z'))
        {
            continue;
        }
        else
        {
            printf("Please try again with a 26 letter key.\n");
            return 1;
        }
    }

    // check 4: check each letter appears once
    for (int i = 0; i < strlen(argv[1]); i++)
    {
        for (int j = 1; j < strlen(argv[1]) - i; j++)
        {
            printf("%c and %c\n", argv[1][i], argv[1][i + j]);
            if (argv[1][i] == argv[1][i + j])
            {
                printf("Please try again with all alphabetic characters.\n");
                return 1;
            }
            else
            {
                continue;
            }
        }
    }

    // get string and define output string
    string text = get_string("plaintext: ");
    char output[strlen(text) + 1];
    output[strlen(text) + 1] = '\0';


    // main for-loop
    for (int i = 0; i <= strlen(text); i++)
        // runs through each character and modifies letter characters according to cipher
    {
        if (text[i] > 96 && text[i] < 123)
            // lowercase modification
        {
            output[i] = 97 + diff(argv[1][diff(text[i])]);

        }
        else if (text[i] > 64 && text[i] < 91)
            // uppercase modification
        {
            output[i] = 65 + diff(argv[1][diff(text[i])]);
        }
        else
            // other characters stay the same
        {
            output[i] = text[i];
        }
    }
    printf("ciphertext: %s\n", output);
    return 0;
}

int diff(char x)
/* returns difference from A/a in alphabetic position */
{
    if (x > 96 && x < 123)
        //lowercase
    {
        return x - 97;
    }
    else if (x > 64 && x < 91)
        //uppercase
    {
        return x - 65;
    }
    else
    {
        //neither
        return x;
    }
}

