#include <stdio.h>
int fn(int a){
    if(a==0){
        return 0;}
    else{
        return fn(a-1)+a;
    }
}
int main(){
    int n;
    scanf("%d",&n);
    int sum=fn(n);
    printf("%d", sum);
    return 0;
}