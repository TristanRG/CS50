#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, string argv[])
{
    if (argc > 2 || argc < 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    for (int i = 0, len = strlen(argv[1]); i < len; i++)
    {
        if (!isdigit(argv[1][i]))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }

    string key = argv[1];
    string plain_text = get_string("Plain text: ");
    int k = atoi(key);
    printf("ciphertext: ");

    for (int i = 0, len = strlen(plain_text); i < len; i++)
    {
        if (isupper(plain_text[i]))
        {
            printf("%c", (((plain_text[i] - 65) + k) % 26) + 65);
        }
        else if (islower(plain_text[i]))
        {
            printf("%c", (((plain_text[i] - 97) + k) % 26) + 97);
        }
        else
        {
            printf("%c", plain_text[i]);
        }
    }
    printf("\n");
}
