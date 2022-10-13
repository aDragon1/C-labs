
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *Rtext = "horse horse apple pen kitchen pen dog";

size_t substrCount(char *str, char *substr)
{
    size_t counter = 0;

    while (1)
    {
        str = strstr(str, substr); // Возвращает указатель на первое вхождение подстроки в строку, либо NULL, если вхождений нет
        if (!str)
            break;
        ++counter;
        str += strlen(substr); // Идём дальше по строке (откидываем то, что уже найдено)
    }
    return counter;
}

int main(void)
{
    char delims[10] = " ,.\t:;\"\'?!";
    char *text = malloc(strlen(Rtext) + 1);
    strcpy(text, Rtext);

    char **tokens = malloc(strlen(text) + 1);
    char *res = malloc(strlen(text) + 1);
    int tokenIndex = 0;

    printf("\nИсходный текст -\n%s\n\n", text);

    char *token = strtok(text, delims);
    tokens[tokenIndex++] = token;

    while (token)
    {
        token = strtok(NULL, delims);
        tokens[tokenIndex++] = token;
    }

    printf("Массив токенов -\n");
    for (int i = 0; i < tokenIndex - 1; i++)
        printf("%d-й токен - %s\n", i, tokens[i]);

    printf("\n\n");

    for (size_t i = 0; i < tokenIndex - 1; i++)
    {
        size_t counterTokenInString = substrCount(Rtext, tokens[i]);
        printf("Токен %s входит в строку %d раз\n", tokens[i], counterTokenInString);
        if (counterTokenInString == 1)
        {
            strcat(res, tokens[i]);
            strcat(res, " ");
        }
    };

    printf("\n Итоговая строка уникальных слов -  \n %s", res);

    printf("\n\n");

    free(text);
    free(res);
    // free(tokens);

    return 0;
}