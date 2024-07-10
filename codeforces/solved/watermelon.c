#include<stdio.h>
#include<stdlib.h>
int main(){
    int w;
    scanf("%d", &w);
    if (w==2){
        printf("NO");
        exit(0);
    }
    if (w%2!=0){
        printf("NO");
    }
    else{
        printf("YES");
    }
}