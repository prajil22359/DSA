#include <stdio.h>
#include <stdlib.h>
int main(){
    int n, k;
    scanf("%d %d", &n, &k);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    int score=arr[k-1];
    int j=0;
    while (arr[j]>=score && arr[j]>0 &&j<n)
    {

        j++;
    }
    printf("%d",j);
return 0;
}