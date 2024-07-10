#include<iostream>
using namespace std;
#include<vector>
#include <unordered_map>

// hashing use, currSubString tracked by (start, i). naya element that is considered in
// current substring if reappears, toh naya substring purane wale ke baad se ka abhi tak ka hoga.


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        unordered_map<char, int> map1;
        int currLength = 0;
        int maxLength = 0;
        int start = 0; // Start index of the current substring

        for (int i = 0; i < s.size(); i++) {
            if (map1.find(s[i]) != map1.end() && map1[s[i]] >= start) {
                // Update start to the next position after the last occurrence of s[i]
                start = map1[s[i]] + 1;
            }
            // Update the last seen index of s[i]
            map1[s[i]] = i;

            // Calculate the current length of the substring
            currLength = i - start + 1;

            // Update the maximum length
            maxLength = max(maxLength, currLength);
        }

        return maxLength;
    }

};