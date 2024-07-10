#include <iostream>
using namespace std;
#include <vector>
#include <unordered_map>
#include <unordered_set>

class Solution {
public:

    // brute force le ke bhancha malai?
    // number of occurences nikal, duplicates ko lagi check gar.
    
    // euta loop ma sabai ko occurence nikalera unordered map ma update gar. feri loop laga tyo unordered map 
    // ma, tyasko .second lai set ma haldaija, halna aghi check garne if its not already in the set. if there 
    // is return false

    bool uniqueOccurrences(vector<int>& arr) {

        unordered_map<int, int> dict;
        for(int i = 0; i < arr.size(); i++){
            dict[arr[i]] += 1;   
            // .count use gari check garda hunthyo if element pahila dekhi cha ki nai bhanera tara int ko lagi 
            // sajilo cha, tyo key nabhae tyaslai initially 0  bhanera setup garidincha.
        }

        // set use garera membership check garda bho.
        unordered_set <int> set1;
        for(pair<int, int> i : dict){
            if(set1.count(i.second)){
                return false;
            }
            else{
                set1.insert(i.second);
            }
        }
        return true;
    }
};