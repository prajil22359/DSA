#include <iostream>
using namespace std;
#include <vector>

class Solution {
public:

    // merge 2 sorted arrays : tyaha auxillary array linthim, yaha na li bhaneko cha.
    // her aba agadi bata smaller element lai lidai jane ho bhane ta arkai array ma halnu
    // parcha else data lose huncha. Tara yaha euta array ko last m elements ma 0 bhareko cha,
    // we use that, hami right bata auchau storing greater elements there. Worst case ma
    // ni kahile data lose hudaina, as there is m spaces to store all of the second array.

    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m-1;
        int j = n-1;
        int last = m+n-1;









        while (i >= 0 && j >= 0){
            if(nums1[i] > nums2[j]){
                nums1[last] = nums1[i];
                i--;
            }       
            else{
                nums1[last]= nums2[j];
                j--;
            }         
            last--;
        }

        // nums2 sakiyo compare garera bhane ta kehi garnu parena kinaki nums1 lai nums1 mai transfer garnu
        //   pardaina tara nums2 bata ta nums1 ma shift garnu paryo ni.
        for( ; j >= 0; j--){ 
            nums1[last--] = nums2[j];
        }

    }
};