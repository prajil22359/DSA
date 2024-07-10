#include <stdio.h>
int combi(int n, int r)
{
    if (r == 0 || r == n)
        return 1;
    return combi(n - 1, r - 1) + combi(n - 1, r);
}

int main()
{
    int n, r;
    scanf("%d %d", &n, &r);
    printf("%d", combi(n, r));
    return 0;
}
