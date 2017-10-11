#include <stdio.h>
#include <stddef.h>

int gcd(int u, int v)
{
    if (u - v == 0)
    {
        return u;
    }
    else if (0 <= u - v)
    {
        gcd(u - v, v);
    }
    else
    {
        gcd(u, v - u);
    }
}

int main()
{
    printf("result: %u\n", gcd(6, 8));
}

