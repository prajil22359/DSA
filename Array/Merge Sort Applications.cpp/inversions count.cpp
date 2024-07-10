#include <vector>
using namespace std;

class Solution {
public:
    int merge_and_count(vector<int> &arr, vector<int> &temp_arr, int left, int mid, int right) {
        int i = left;    // Starting index for left subarray
        int j = mid + 1; // Starting index for right subarray
        int k = left;    // Starting index to be sorted
        int inv_count = 0;

        // Merge the two halves
        i = left;
        j = mid + 1;
        
        while (i <= mid && j <= right) {
            if (arr[i] > arr[j]) {
                temp_arr[k++] = arr[j++];
                inv_count += mid-i+1;
            }
            else {
                temp_arr[k++] = arr[i++];
            }
        }

        // Copy the remaining elements of left subarray, if any
        while (i <= mid) {
            temp_arr[k++] = arr[i++];
        }

        // Copy the remaining elements of right subarray, if any
        while (j <= right) {
            temp_arr[k++] = arr[j++];
        }

        // Copy the sorted subarray into the original array
        for (i = left; i <= right; i++) {
            arr[i] = temp_arr[i];
        }

        return inv_count;
    }

    int merge_sort_and_count(vector<int> &arr, vector<int> &temp_arr, int left, int right) {
        int inv_count = 0;
        if (left < right) {
            int mid = left + (right - left) / 2;

            inv_count += merge_sort_and_count(arr, temp_arr, left, mid);
            inv_count += merge_sort_and_count(arr, temp_arr, mid + 1, right);
            inv_count += merge_and_count(arr, temp_arr, left, mid, right);
        }
        return inv_count;
    }

    int inversionPairs(vector<int> &nums) {
        if (nums.empty()) return 0;
        vector<int> temp_arr(nums.size());
        return merge_sort_and_count(nums, temp_arr, 0, nums.size() - 1);
    }
};