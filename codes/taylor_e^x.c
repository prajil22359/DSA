// better algo O(n) using Horner's rule than normal multiplication O(n^2)

//Horner's rule: search..


#include <stdio.h>
double e(double x, double n)
{
    static double s = 1;
    if (n == 0)
        return s;
    s = s * (x / n) + 1;
    return e(x, n - 1);
}

int main()
{
    int x, n;
    scanf("%d %d", &x, &n);

    // expansion till nth term.
    printf("value is %lf", e(x, n)); 
    return 0;
}