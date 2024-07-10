#include <iostream>
using namespace std;
#include <vector>
#include <set>
#include <algorithm>
#include <unordered_map>

class Solution {
public:
    // 4 loops, just choose 3 elements and see if the 4th which would get us to the target exists.
    vector<vector<int>> bruteForce(vector<int>& nums, int target) {
        int n = nums.size();
        set<vector<int>> set1;
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                for(int k = j+1; k < n; k++){
                    int elementToFind = target - nums[i] - nums[j] - nums[k];
                    for(int l = k+1; l < n; l++){
                        if(nums[l] == elementToFind){
                            vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};
                            sort(temp.begin(), temp.end());
                            set1.insert(temp);
                        }
                    }
                }
            }   
        }
        vector<vector<int>> ans(set1.begin(), set1.end());
        return ans;
    }

    vector<vector<int>> hashingApproach(vector<int>& nums, int target) {
        int n = nums.size();
        set<vector<int>> set1;
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){

                unordered_map<int, int> dict;

                // eutai loop ma k ra l ko loop sakako ho ke, concept etti ho ki dubai elements k bata 
                // traverse hunchan nai, pair ta find garne ho, element1 of the pair traverse bhaepachi
                // tyaslai map ma store garne taaki element2 auda hamile aa pair rahecha bhanna sakiyos.
                
                for(int k = j+1; k < n; k++){
                    
                    // seeing the integer overflow condition. SEE FOR GOOD, ITS IMPORTANT
                    long long temp = (long long)target - nums[i] - nums[j] - nums[k];
                    if(temp < -1e9 || temp > 1e9){
                        continue;
                    }

                    int elementToFind = (int)temp;

                    // last loop lai set ya map bata replace garchau : n bata logn gareko
                    if(dict.find(elementToFind) != dict.end()){
                        vector<int> temp = {nums[i], nums[j], nums[k], elementToFind};
                        sort(temp.begin(), temp.end());
                        set1.insert(temp); 
                    }
                    // if not found, insert it so that if there is a pair it will find this element
                    dict[nums[k]] = k;
                }
            }
        }
        vector<vector<int>> ans(set1.begin(), set1.end());
        return ans;
    }

    vector<vector<int>> twoPointerApproach1(vector<int>& nums, int target) {
        int n = nums.size();
        set<vector<int>> set1;

        sort(nums.begin(), nums.end());
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                
                // two sum now.
                int k = j+1;  // left pointer
                int l = n-1;  // right pointer

                while(k<l){

                    long long temp = (long long)nums[i] + nums[j] + nums[k] + nums[l];
                    if(temp > 1e9 || temp < -1e9) {
                        if (temp > 1e9) {
                            l--; // Move right pointer leftward to reduce sum
                        } else {
                            k++; // Move left pointer rightward to increase sum
                        }
                        continue;
                    }

                    int sum = (int) temp;
                    if(temp > target){
                        l--;
                    }
                    else if(temp < target){
                        k++;
                    }

                    else{
                        vector<int> tempVec = { nums[i], nums[j], nums[k], nums[l]};
                        sort(tempVec.begin(), tempVec.end());
                        set1.insert(tempVec);

                        // searching for others
                        k++;
                        l--;
                    }
                }
            }
        }
        vector<vector<int>> ans(set1.begin(), set1.end());
        return ans;
    }

    vector<vector<int>> twoPointerApproach2(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> ans;

        sort(nums.begin(), nums.end());
        for(int i = 0; i < n; i++){
            if(i != 0 && nums[i] == nums[i-1]) continue; // i = 0, first element ma skip na garnu 

            for(int j = i+1; j < n; j++){
                if(j != i+1 && nums[j] == nums[j-1]) continue;  // j = i+1, first element ma skip nagarnu

                // two sum now.
                int k = j+1;  // left pointer
                int l = n-1;  // right pointer

                while(k<l){

                    long long temp = (long long)nums[i] + nums[j] + nums[k] + nums[l];
                    if(temp > 1e9 || temp < -1e9) {
                        if (temp > 1e9) {
                            l--; // Move right pointer leftward to reduce sum
                        } else {
                            k++; // Move left pointer rightward to increase sum
                        }
                        continue;
                    }

                    int sum = (int) temp;
                    if(temp > target){
                        l--;
                    }
                    else if(temp < target){
                        k++;
                    }

                    else{
                        vector<int> tempVec = {nums[i], nums[j], nums[k], nums[l]};
                        ans.push_back(tempVec);

                        // searching for others
                        k++;
                        l--;

                        // skipping if duplicates, nums being sorted alows it.
                        while(k<l && nums[k] == nums[k-1]) k++;
                        while(k<l && nums[l] == nums[l-1]) l++;

                    }
                }
            }
        }
        return ans;
    }


    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        // return bruteForce(nums, target); TLE 4 loops
        // return hashingApproach(nums, target);  just passes 1500ms, 3 loops + set + hashmap
        // return twoPointerApproach1(nums, target);  great 213ms, 2 loops, 2 pointer + set 
        return twoPointerApproach2(nums, target);  // best 213ms, 2 loops, 2 pointer bas. 


    }
};