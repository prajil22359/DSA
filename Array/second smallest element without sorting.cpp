#include <iostream>
using namespace std;

// simply, largest sangai second largest lai track gareko.
int print2largest(int arr[], int n) {
    int largest = -1e9;
    int secondlargest = -1e9;

    for(int i = 0; i < n; i++){
        if (arr[i] > largest){
            secondlargest = largest;
            largest = arr[i];
        }
        else{
            if(arr[i] > secondlargest && arr[i] != largest){ // distinct element bhaneko cha 
                secondlargest = arr[i]; 
            }
        }
    }
    return secondlargest == -1e9 ? -1 : secondlargest;
}