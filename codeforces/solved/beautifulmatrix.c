#include <stdio.h>
#include <stdlib.h>
int main()
{
    int arr[5][5];
    int a, b;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            scanf("%d", &arr[i][j]);
            if (arr[i][j] == 1)
            {
                a = i;
                b = j;
            }
        }
    }
  
    
    printf("%d", abs(3-a-1)+ abs(3-b-1));
    return 0;
}