#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int f(char s[])
{
    int semn = 1;
    if(s[0] == "-")
        semn = -1;
    int nr = 0;
    if(semn == 1)
    {
        for(int i = 0; i<strlen(s); i++)
        {

            if (s[i] >= '0' && s[i] <= '9')
            {
                nr = nr * 10 + (s[i]-'0');
            }
            else
                break;
        }
    }
    if(semn == -1)
    {
        for(int i = 1; i<strlen(s); i++)
        {

            if (s[i] >= '0' && s[i] <= '9')
            {
                nr = nr * 10 + (s[i]-'0');
            }
            else
                break;
        }
    }
    return semn * nr;
}
int main()
{
    int suma = 0;
    char s[100];
    char linie[100];
    FILE *fisier;
    int numar = 0;
    fisier = fopen("in.txt", "r");
    while(fgets(linie, sizeof(linie), fisier)!= NULL)
    {
        numar = f(linie);
        suma = suma + numar;
    }
    fclose(fisier);
    printf("%d", suma);
    return 0;
}
