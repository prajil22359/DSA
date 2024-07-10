#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n, k, t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++)
    {
        scanf("%d %d", &n, &k);
        if ((n % 2) == 0)
        {
            printf("YES\n");
            
        }
        else if ((n % 2 != 0) && (k % 2) == 0)
        {
            printf("NO\n");
            
        }
        else if ((n % 2) != 0 && (k % 2) != 0)
        {
            printf("YES\n");
        }
    }
}