 // we are to find the maximum possible content children.
    // aba hera: 
    //    1. We will ensure that every child that receives the smallest cookie that 
    //       meets their greed so no larger cookies are wasted on children with smaller greed.
    //    2. Sabse kam greedy child lai cookies dine kosis garchau, yadi uslai ni satisfy garna sakdaina bhane
    //       tyo bhanda dherai lai ta kasari garcha -> so leftover cookies wont satisfy any available child.

    // So, we sort both the greed and satisfaction array. 
    // contentChildren lai 0 le initialize garyo -> 0th child le paunu paryo satisfying cookie pahila, if it 
    // doesnot satisfy we keep looking into next cookie by increasing cookieIndex by 1. only if any 
    // cookieIndex satisfies, we turn to satisfy the next children so contentChildren++.

#include <iostream>
using namespace std;
#include <vector>
#include <algorithm> 

int findContentChildren(vector<int>& g, vector<int>& s) {
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());

    int contentChildren = 0;
    int cookieIndex = 0;
    while (cookieIndex < s.size() && contentChildren < g.size()){
        if(s[cookieIndex] >= g[contentChildren]){
            contentChildren ++; 
        }
        cookieIndex++;
    }
    return contentChildren;
}