#include<stdio.h>
int main(){
    int d, sumtime;
    scanf("%d %d",&d, &sumtime);
    int mini, maxi;
    int maxtime=0, mintime=0;
    for (int i=0; i<d; i++){
        scanf("%d %d", maxi, mini);
        maxtime+=maxi;
        mintime+=mini;
    }
    if (sumtime<mintime || sumtime>maxtime){
        printf("NO\n");
        return 0;
    }
    else{
        printf("YES");
    }
    
}
