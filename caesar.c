#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

int main(int avg, string avc[])
{
    if (avg != 2)
    {
        printf("Usage: ./caesar key \n");
        return 1;
    }

    string s = avc[1];
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        if (isdigit(s[i]) == 0)
        {
            printf("Usage: ./caesar Test key \n");
            return 1;
        }
    }

    int k = atoi(s);
    string b = get_string("Input Text: ");
    printf("ciphertext: ");
    
    for (int o = 0, m = strlen(b); o < m; o++)
    {
        if (isalpha(b[o]) && isupper(b[o]))
        {
            char c = (((b[o]) - 65) + k) % 26;
            printf("%c", c + 65);
        }
        else if (isalpha(b[o]) && islower(b[o]))
        {
            char c = (((b[o]) - 97) + k) % 26;
            printf("%c", c + 97);
        }
        else
        {
            printf("%c", b[o]);
        }
    }
    printf("\n");

}
