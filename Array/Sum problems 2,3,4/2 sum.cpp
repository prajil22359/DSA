#include <iostream>
using namespace std;
#include <vector>
#include <unordered_map>
#include <algorithm>

class Solution {
public:
    vector<int> bruteForce(vector<int> &nums, int target){
        // brute force ma ni yesari na sochne ki, i ra j duita element choose garira, target jatri pugyo bhane 
        // good, no yesari haina. kasari sochne bhanda euta element i line, if it makes an answer

        for(int i = 0; i < nums.size(); i++){
            int elementToFind = target - nums[i];
            for(int j = i+1; j < nums.size(); j++){
                if(nums[j] == elementToFind){
                    return {i,j};
                }
            }
        }
        // if no such pair
        return {-1,-1};
    }

    vector<int> hashingApproach(vector<int> &nums, int target){
        // concept ke ho, bhanda aghi ko elementToFind lai euta traverse ma nikalne. Map use garne ani herne if
        // there is the pair we need to make the target. Ans {i,j} ho bhane its possible ki i auda j ahile samma
        // map ma nahola, tara pair ta ho, j huda i paihalcha ni.

        unordered_map<int, int> dict;
        for(int i = 0; i < nums.size(); i++){
            int elementToFind = target - nums[i];
            if(dict.find(elementToFind) != dict.end()){
                // cout << "hi";
                return {i, dict[elementToFind]};
            }
            dict[nums[i]] = i;
        }
        return {-1, -1};
    }

    vector<int> twoPointerApproach(vector<int>& nums, int target){
        // its the greedy approach : very intuitive

        // a new vector needed, as while sorting we will lose the original indices.
        vector<vector<int>> vec;
        for(int i = 0; i < nums.size(); i++){
            vec.push_back({nums[i], i});
        }
        int left = 0;
        int right = vec.size()-1;

        sort(vec.begin(), vec.end());
        while(left < right){
            if((vec[left][0] + vec[right][0]) < target){ 
            // sum pugena target jati sano paryo, so thulo number chahiyo, left ++ 
                left ++;
            }
            else if((vec[left][0] + vec[right][0]) > target){ 
            // sum thulo bho target bhanda sano number chahiyo, right--
                right --;
            }
            else{
                return {vec[left][1], vec[right][1]};
            }
        }
        // if there isnt any such pair.
        return {-1, -1};
    }

    vector<int> twoSum(vector<int>& nums, int target) {
        // return bruteForce(nums, target);
        // return hashingApproach(nums, target);
        return twoPointerApproach(nums, target);
    }
};