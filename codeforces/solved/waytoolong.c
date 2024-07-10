#include <stdio.h>
#include <stdlib.h>
int main(){
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
    char word[105];
    for (int i=0; i<105; i++){
        word[i]='\0';
    }
    char first, last;
    char rest[100];

    scanf("%s", &word);
    char a=word[0];
    char c=word[0];
    int count=0;
    int i=1;
    while(a!='\0'){
        count+=1;
        a=word[i];
        i++;
    }
    char b=word[count-1];
    if((count)>10){
    printf("%c%d%c\n",c, count-2, b);}
    else{
        printf("%s\n", word);
    }
    }
return 0;
}