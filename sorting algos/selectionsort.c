#include <stdio.h>
int swap(int *ptr1, int *ptr2)
{
    int temp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = temp;
}

void selectionsort(int A[], int n)
{
    int flag;
    for (int i = 0; i < n - 1; i++)
    {   int j,k;
        for (j= k=i; j < n; j++)
        {   
            if (A[j]<A[k])
            {
                k=j;
            }
        swap(&A[k], &A[i]); 
            
        }
        

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
    int array[] = {2, 1, 11, 3, 1, 2, 3, 11, 3, 1, 6, 4, 8, 3};
    selectionsort(array, 14);
    printarray(array);

    return 0;
}