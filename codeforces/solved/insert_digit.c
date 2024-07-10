#include<stdio.h>
#include<string.h>
int main(){
    int n;

    scanf("%d",&n);
    for(int i=0; i<n ; i++){
        int a, b,d;
        scanf("%d %d", &a , &b);
        char string[a];
        scanf("%s", string);
        char*ptr= &string[0];
        for (int j=0; j<a; j++){
            char c=string[j];
            const char* s =&c ;
            int x;
            sscanf(s, "%d", &x);
            d=a;
            if (b>x){
                d=j;
                break;
            }
        }
        
        for (int k=0; k<d; k++){
            printf("%c", *(ptr+k));
        }
        printf("%d",b);
       

        for(int l=d; l<a; l++){
            printf("%c", *(ptr+l));
        }
     

        }

    
}