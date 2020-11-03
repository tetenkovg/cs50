#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>


string encrypt(string original_key, string input_value);
int validate_key(string A);

int main(int avg, string avs[])
{
    if (avg != 2)
    {
        printf("Usage: ./substitution key \n");
        return 1;
    }

    string key = avs[1];

    if (strlen(key) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }

    for (int i = 0, n = strlen(key); i < n; i++)
    {
        if (isalpha(key[i]) == 0)
        {
            printf("Key must contain aphabetic characters.\n");
            return 1;
        }
    }

    for (int i = 0, n = strlen(key); i < n; i++)
    {
        if (isupper(key[i]) == 0)
        {
            key[i] = toupper(key[i]);
        }
    }

    if (validate_key(key) == 1)
    {
        printf("Key must not contain repeated alphabets.\n");
        return 1;
    }



    string plaintext = get_string("plaintext: ");

    printf("ciphertext: %s", encrypt(key, plaintext));
    printf("\n");
}



string encrypt(string original_key, string input_value)
{
    for (int o = 0, m = strlen(input_value); o < m; o++)
    {
        if (isalpha(input_value[o]) && isupper(input_value[o]))
        {
            int c = ((input_value[o]) - 65);
            input_value[o] = original_key[c];
        }
        else if (isalpha(input_value[o]) && islower(input_value[o]))
        {
            int c = ((input_value[o]) - 97);
            input_value[o] = original_key[c] + 32;
        }
        else
        {
            input_value[o] = input_value[o];
        }
    }
    return input_value;
}


int validate_key(string A)
{
    for (int i = 0, m = strlen(A); i < m; i++)
    {
        for (int x = i + 1; x < m; x++)
        {
            if (A[i] == A[x])
            {
                return 1;
            }
        }

        for (int y = i - 1; y >= 0; y--)
        {
            if (A[i] == A[y])
            {
                return 1;
            }
        }
    }
    return 0;
}
