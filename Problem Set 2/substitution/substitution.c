#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    for (int i = 0, len = strlen(argv[1]); i < len; i++)
    {
        if (!isalpha(argv[1][i]))
        {
            printf("Usage: ./substitution key\n");
            return 1;
        }
    }

    if (strlen(argv[1]) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }

    for (int i = 0, len = strlen(argv[1]); i < len; i++)
    {
        for (int j = i + 1; j < len; j++)
        {
            if (toupper(argv[1][i]) == toupper(argv[1][j]))
            {
                printf("Usage: ./substitution key\n");
                return 1;
            }
        }
    }

    string key = argv[1];
    string plain_text = get_string("plaintext: ");

    for (int i = 0, len = strlen(key); i < len; i++)
    {
        if (islower(key[i]))
        {
            key[i] = key[i] - 32;
        }
    }

    printf("ciphertext: ");

    for (int i = 0, len = strlen(plain_text); i < len; i++)
    {
        if (isupper(plain_text[i]))
        {
            int letter = plain_text[i] - 65;
            printf("%c", key[letter]);
        }
        else if (islower(plain_text[i]))
        {
            int letter = plain_text[i] - 97;
            printf("%c", key[letter] + 32);
        }
        else
            printf("%c", plain_text[i]);
    }
    printf("\n");
}
