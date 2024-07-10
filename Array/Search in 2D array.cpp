#include <iostream>
using namespace std;
#include <vector>

class Solution {
public:

    // binary search lagaune ho: flatten this 2D array into a linear one, and apply binary search.
    // flatten is in mind only, convert 1D coordinate of elements to 2D coordinate.

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        int low = 0;
        int high = m * n - 1;

        while(low <= high){
            int mid = low + (high - low)/2;

            // convert into 2D array.
            int row = mid / n; // divide by number of cols. here thats n.
            int col = mid % n;

            if(matrix[row][col] == target){
                return true;
            }
            else if(matrix[row][col] < target){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        return false;
    }
};