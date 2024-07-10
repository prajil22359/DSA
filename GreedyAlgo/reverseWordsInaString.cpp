#include <iostream>
using namespace std;
#include <vector>
#include <string>
#include <algorithm>

//Function to reverse words in a given string.
string reverseWords(string S) 
{ 
    string str = "";
    string ans = "";
    for( int i = S.size() - 1; i >= 0 ; i--){
        
        if(S[i] == '.'){
            reverse(str.begin() , str.end());
            ans += str;
            ans += ".";
            str = "";
        }
        else{
            str += S[i];
        }   
    }
    
    // agadi ko lagi ke garne ta, tyaha '.' audaina. so loop sakincha, str ma saved cha,
    // ahile aera reverse gari add gardine
    reverse(str.begin() , str.end());
    ans += str;
    return ans;
} 