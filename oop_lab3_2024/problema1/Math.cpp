#include "Math.h"
#include <cstring>

int Math::Add(int a, int b)
{
    return a + b;
}

int Math::Add(int a, int b, int c)
{
    return a + b + c;
}

int Math::Add(double a, double b)
{
    return a + b;
}

int Math::Add(double a, double b, double c)
{
    return a + b + c;
}

int Math::Mul(int a, int b)
{
    return a * b;
}

int Math::Mul(int a, int b, int c)
{
    return a * b * c;
}

int Math::Mul(double a, double b)
{
    return a * b;
}

int Math::Mul(double a, double b, double c)
{
    return a * b * c;
}

int Math::Add(int count, int v[])
{
    int sum = 0;
    for (int i = 0; i < count; ++i) {
        sum += v[i];
    }
    return sum;
}

char* Math::Add(const char* s1, const char* s2)
{
    if (s1 == nullptr || s2 == nullptr)
        return nullptr;
    int size = strlen(s1) + strlen(s2);
    char* sum = new char[size + 1];
    strcpy(sum, s1);
    strcat(sum, s2);

    return sum;
}
