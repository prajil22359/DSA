#include <stdio.h>
#include <stdlib.h>
int main(){
    int n;
    int x=0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {   char str[10];
        scanf("%s",str);
        if (str[1]=='+')
        {
            x++;
        }
        else{
            x--;
        }
        
    }
    printf("%d", x);
    
return 0;
}