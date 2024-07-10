#include <stdio.h>
double power(double m, int n){
    if(n==0)
        return 1;
    else if (n%2==0)
        return power(m*m, n/2);
    else
        return m*power(m*m, (n-1)/2);
}
int main(){
    double m;
    int n;
    scanf("%f %d",&m, &n);
    double result=power(m,n);
    printf("%f", result);
    return 0;
}