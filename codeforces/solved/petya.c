#include <stdio.h>
#include <stdlib.h>
int main()
{
    char arr[105];
    char arr2[105];
    for (int i = 0; i < 105; i++)
    {
        arr[i] = '\0';
        arr2[i] = '\0';
    }
    scanf("%s", arr);
    scanf("%s", arr2);
    int j = 0;
    int flag = 1;

    while (arr[j]  != '\0' && arr2[j] !='\0')

    {
        int a, b;
        a=arr[j];
        b=arr2[j];
        if (arr[j] > 96)
        {
            a = a - 32;
        }
        
            if (arr2[j] > 96){

                b = b - 32;
        }

        if (a > b)
        {
            printf("1");
            flag = 0;
            break;
        }
        else if (a < b)
        {
            printf("-1");
            flag = 0;
            break;
        }
        j++;
    }
    if (flag == 1)
    {
        printf("0");
    }
    return 0;
}