#include <stdio.h>
#include <stdlib.h>
int main(){
    int m,n;
    scanf("%d %d", &m, &n);
    int a=n/2;
    int b=n%2;
    int c=b*m;
    int d=c/2;
    printf("%d", a*m+d);
return 0;
}