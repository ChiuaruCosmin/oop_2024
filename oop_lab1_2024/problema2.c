#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char s[100];
    char cuv[30][30];
    scanf("%[^\n]", s);
    printf("\n");
    char *p = strtok(s, " ");
    int k = 0;
    while(p)
    {
        strcpy(cuv[++k], p);
        p = strtok(NULL, " ");
    }
    for(int i = 1; i <= k; i++)
        for(int j = i + 1; j <= k; j++)
            if((strlen(cuv[i]) < strlen(cuv[j])) || ((strlen(cuv[i]) == strlen(cuv[j])) && strcmp(cuv[i], cuv[j])>0))
            {
                char aux[20];
                strcpy(aux, cuv[i]);
                strcpy(cuv[i], cuv[j]);
                strcpy(cuv[j], aux);
            }
    for(int i = 1; i <= k; i++)
    {
        printf("%s", cuv[i]);
        printf("\n");
    }
    return 0;
}
