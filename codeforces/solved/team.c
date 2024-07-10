#include <stdio.h>
#include <stdlib.h>
int main(){
    int n;
    scanf("%d", &n);
    int count=0;
    for (int i = 0; i < n; i++)
    {   int a,b,c;
        scanf("%d %d %d", &a, &b, &c);
        if ((a+b+c)>=2){
            count+=1;
        }
    }
    printf("%d", count);
    
return 0;
}