
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *Rtext = "А ещё независимые государства объединены в целые кластеры себе подобных. Господа, граница обучения кадров выявляет срочную потребность переосмысления внешнеэкономических политик. Следует отметить, что высокое качество позиционных исследований способствует повышению качества модели развития.";

int main(void)
{
    char delims[10] = " ,.-!?;";
    char *text = malloc(strlen(Rtext) + 1);
    strcpy(text, Rtext);

    char **tokens = malloc(strlen(text) + 1);
    int tokenIndex = 1;

    printf("\nИсходный текст -\n%s\n\n", text);

    char *token = strtok(text, delims);
    tokens[0] = token;

    while (token)
    {
        token = strtok(NULL, delims);
        tokens[tokenIndex++] = token;
    }

    printf("Массив токенов -\n");
    for (int i = 0; i < tokenIndex - 1; i++)
        printf("%s ", tokens[i]);

    printf("\n%s\n", text);

    printf("\n\n\n\n\n\n");

    return 0;
}