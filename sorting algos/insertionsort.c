#include <stdio.h>

void insertionsort(int A[], int n)
{
    for (int i = 1; i < n; i++)
    // no. of pass, n-1 starting from index 1.
    {
        int j=i-1;
        int x=A[i];
        while (j>-1 && A[j]>x)
        {
            A[j+1]=A[j];
            j--;
        }
        A[j+1]=x;
    }
    
}
void printarray(int array[])
{
    for (int i = 0; i < 14; i++)
    {
        printf("%d\n", array[i]);
    }
}
int main()
{
    int array[] = {2, 1, 0, 3, 1, 2, 3, 11, 3, 1, 6, 4, 8, 3};
    insertionsort(array, 14);
    printarray(array);

    return 0;
}