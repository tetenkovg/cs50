#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <math.h>

int main (void)
{
    string s = get_string("Input: ");

    int count_sentecies = 0;
    int count_words = 1;
    int count_letters = 0;

    for (int i = 0; s[i] != '\0'; i++)
    {
        if (isalnum(s[i]))
        {
            count_letters++;
        }
        else if (isspace(s[i]))
        {
            count_words++;
        }
        else if (s[i] == '!' || s[i] == '?' || s[i] == '.')
        {
            count_sentecies++;
        }
    }

    float multiplier = 100 / (float)count_words;

    int index = (int) round((0.0588 * ((float)count_letters * multiplier)) - (0.296 * ((float)count_sentecies * multiplier)) - 15.8);

    if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (index >= 1)
    {
        printf("Grade %i\n", index);
    }
    else if (index < 1)
    {
        printf("Before Grade 1\n");
    }
}

