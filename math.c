#include <stdio.h>
#include <stddef.h>

int gcd(int u, int v)
{
    if (u == v)
    {
        return u;
    }
    else if (v < u)
    {
        gcd(u - v, v);
    }
    else
    {
        gcd(u, v - u);
    }
}

int lcm(int u, int v, int r, int s)
{
    if (r == s)
    {
        return r;
    }
    else if (r < s)
    {
        lcm(u, v, u + r, s);
    }
    else
    {
        lcm(u, v, r, v + s);
    }
}

int main()
{
    printf("result: %d\n", lcm(6, 7, 6, 7));
}

