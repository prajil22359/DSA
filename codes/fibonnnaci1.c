#include<stdio.h>

int iterative(int n){
    if (n<=1){
        return n;
    }
    int prev=1;
    int pprev=0;
    int sum=0;
    for (int i=2; i<=n; i++){
        sum=prev+pprev;
        pprev=prev;
        prev=sum;
    }
    return sum;

}


// int memo_recursive(int n, int *ptr){
//     if (n<=1){
//         *(ptr +n)=n;
//         return n;
//     }
//     else{
//         if (*(ptr+(n-2))=-1){
//             *(ptr + (n-2))=memo_recursive(n-2, ptr);
//         }
//         if (*(ptr+(n-1))=-1){
//             *(ptr + (n-1))=memo_recursive(n-1, ptr);}
//         return *(ptr+(n-2))+ *(ptr+(n-1));
//     }
// }


int main(){
    int n;
    scanf("%d", &n);
    
  
    printf("nth fibonnaci is ");
    // int array[n+1];
    // for (int i=0; i<(n+1) ; i++){
    //     array[i]=-1;
    // }
    // printf("%d", memo_recursive(n, array));

    printf("%d", iterative(n));
    return 0;
}