#include<stdio.h>

int swap(int *ptr1, int  *ptr2){
    int temp=*ptr1;
    *ptr1= *ptr2;
    *ptr2= temp;

}
int main()
{
    int a, b;
    a=34;
    b=23;
    swap(&a, &b);
    printf("%d %d", a,b);
    return 0;
}

