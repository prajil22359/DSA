#include <iostream>
using namespace std;
#include <vector>

// union nikaldai duita array ko.
// brute force would be ki dubai vector lai euta map ya set ma add garyo, 
// and just print them out, the DS will keep them sorted and only include uniques. TC: o(nlogn)
// works for unsorted array as well.

// optimized code using the sortedness: 2 pointer method. Lesser element of the 2 arrays lai include
// garne : just like merging 2 sorted arrays, just keeping a check on not including duplicates
// only the last included element can be duplicated at any time, so just check for that.

// EUTA KURA KE RAHECHA BHANE OR MA CASES LEKHDA KAM TA CHALCHA KI, SEG FAULT DIDAINA BUT ORDER
// THIK HUNUPARYO. ORDER MATTERS THAT'S IT.

vector < int > findUnion(int arr1[], int arr2[], int n, int m) {
    int i = 0, j = 0; // pointers
    vector < int > Union; // Union vector
    while (i < n && j < m) {
        if (arr1[i] <= arr2[j]) // Case 1 and 2
        {
            if (Union.size() == 0 || Union.back() != arr1[i])
                Union.push_back(arr1[i]);
            i++;
        } 
        else // case 3
        {
            if (Union.size() == 0 || Union.back() != arr2[j])
                Union.push_back(arr2[j]);
            j++;
        }
    }
    while (i < n) // If any element left in arr1
    {
        if (Union.back() != arr1[i])
            Union.push_back(arr1[i]);
        i++;
    }
    while (j < m) // If any elements left in arr2
    {
        if (Union.back() != arr2[j])
        Union.push_back(arr2[j]);
        j++;
    }
    return Union;
}