#include <stdio.h>
#include <stdlib.h>

void merge(int a[][2], int l, int mid, int h){
    int i, j, k;
    int b[100][2];
    i=l; j= mid+1; k=l;
    while (i<= mid && j<=h){
        if (a[i][0]< a[j][0]){
            b[k][0]=a[i][0];
            b[k++][1]=a[i++][1];
    }else{
            b[k][0]=a[j][0];
            b[k++][1]=a[j++][1];
    }}
    for( ;i<=mid; i++){
        b[k][0]=a[i][0];
        b[k++][1]=a[i][1];
}

    for ( ; j<=h;j++){
        b[k][0]=a[j][0];
        b[k++][1]=a[j][1];
    }
    for(int i=l; i<=h; i++){
        a[i][0]=b[i][0];
         a[i][1]=b[i][1];
}}

void mergesort(int a[][2], int l, int h){
    int mid;
    if( l<h){
    mid=(l+h)/2;
    mergesort(a,l,mid);
    mergesort(a, mid+1, h);
    merge(a, l, mid, h);
    }
}

void printarray(int array[][2], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d", array[i][0]);
        printf("%d", array[i][1]);
        printf("\n");
    }
}

int main()
{
    // int array[] = {2, 1, 03, 13, 01, 21, 30, 11, 3, 1, 6, 4, 8, 1,2};
    int n;
    scanf("%d", &n);
    int arr[n][2];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i][0]);
        scanf("%d",&arr[i][1]);
    }
    // taking array as an input, first taking its size.
    mergesort(arr, 0, (n-1));
    printarray(arr, n);
    return 0;
}
// 0 1
// 4 2
// 2 8
// 9 4