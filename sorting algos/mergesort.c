#include <stdio.h>
#include <stdlib.h>

void merge(int a[], int l, int mid, int h){
    int i, j, k;
    int b[100];
    i=l; j= mid+1; k=l;
    while (i<= mid && j<=h){
        if (a[i]< a[j]){
            b[k++]=a[i++];
    }else{
            b[k++]=a[j++];
    }} 
    for( ;i<=mid; i++){
        b[k++]=a[i];
    }
    for ( ; j<=h;j++){
        b[k++]=a[j];
    }
    for(int i=l; i<=h; i++){
        a[i]=b[i];
    }   
}

void mergesort(int a[], int l, int h){
    int mid;
    if( l<h){
    mid=(l+h)/2;
    mergesort(a,l,mid);
    mergesort(a, mid+1, h);
    merge(a, l, mid, h);
    }
}

void printarray(int array[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d", array[i]);
    }
}

int main()
{
    // int array[] = {2, 1, 03, 13, 01, 21, 30, 11, 3, 1, 6, 4, 8, 1,2};
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    // taking array as an input, first taking its size.
    mergesort(arr, 0, (n-1));
    printarray(arr, n);
    return 0;
}
