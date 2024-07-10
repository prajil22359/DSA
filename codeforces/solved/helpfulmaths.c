#include <stdio.h>
#include <stdlib.h>
char swap(char *ptr1, char *ptr2)
{
    char temp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = temp;
}

void bubblesort(char A[], int n)
{
    int flag;
    for (int i = 0; i < n - 1; i++)
    {
        flag = 0;
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (A[j] > A[j + 1])
            {
                swap(&A[j], &A[j + 1]);
                flag = 1;
            }
        }
        if (flag == 0)
            break;
    }
}
void printarray(char array[], int length)
{
    for (int i = 0; i < length; i++)
    {   
        printf("%c", array[i]);
        if (i!=(length-1))printf("+");
    }
}

int main()
{
    char word[105];
    for (int i = 0; i < 105; i++)
    {
        word[i] = '\0';
    }
    scanf("%s", word);
    int k = 0;
    while ((word[k] != '\0'))
    {
        k++;
    }

    char arr[(k / 2) + 1];
    for (int i = 0; i < ((k/2)+1); i++)
    {
        arr[i] = '\0';
    }
    int j = 1;
    int s=1;
    arr[0]=word[0];
    while (word[j] != '\0')
    {
        if (word[j] == '+')
        {
            arr[s] = word[j+1];
      
            s++;
        }
        j++;
    }
    
    bubblesort(arr,(k/2)+1);
    printarray(arr, (k/2)+1);


    return 0;
}