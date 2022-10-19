#include <stdio.h>
#include <stdlib.h>
#include <string.h>

size_t substrCount(char *str, char *substr)
{
    size_t counter = 0;

    while (1)
    {
        str = strstr(str, substr); // Returns pointerto to the first match substr into str or NULL if not any
        if (!str)
            break;
        ++counter;
        str += strlen(substr); // Iterate through the string
    }
    free(str);
    return counter;
}

char **getTokensFromTextAsArray(char *Rtext, char *delims)
{
    // Get the text copy
    char *text = malloc(strlen(Rtext + 1) * sizeof(char));
    strcpy(text, Rtext);
    char *token = strtok(text, delims);       // get the first token
    char **tokens = malloc(strlen(text) + 1); // init array of tokens as length of the text
    int tokenIndex = 0;
    tokens[tokenIndex++] = token;

    while (token) // fill the tokens array with individual token
    {
        token = strtok(NULL, delims);
        tokens[tokenIndex++] = token;
    }
    free(text);
    return tokens;
}

int main(void)
{
    char delims[10] = " ,.\t:;\"\'?!";

    char *text = "horse horse apple pen kitchen pen dog"; // source text
    char *resString = malloc(strlen(text + 1) * sizeof(char));
    printf("\n Source text - %s\n\n", text);

    char **tokens = getTokensFromTextAsArray(text, delims); // array of tokens (word's, splited by delimeters)
    printf("Tokens array -\n");
    for (int i = 0; i < sizeof(tokens) - 1; i++)
        printf("%d-th token - %s\n", i, tokens[i]);
    printf("\n\n");

    for (size_t i = 0; i < sizeof(tokens) - 1; i++)
    {
        size_t counterTokenInString = substrCount(text, tokens[i]);
        printf("Token \"%s\" enters the stirng %d times\n", tokens[i], counterTokenInString);
        if (counterTokenInString == 1)
        {
            strcat(resString, tokens[i]);
            strcat(resString, " ");
        }
    };

    printf("\n Result string of unic word's -  \n %s", resString);
    printf("\n\n");

    free(resString);
    free(tokens);
    return 0;
}