#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>  

// minimum number of platforms needed to accomodate all the trains in a railway is what we need to find.
// we are given the arrival and departure time of every train in the two arrays.
// it is also said that if at a time, there is a train leaving and at the same time a train is arriving,
// we will need one more platform to accomodate the arriving train.

// How we find it, we see how many platforms are needed in any point of time in the day.
// certainly, we wont be looking at every minute but at every important time when a train arrived 
// cause thats when we might need a new platform if it cant be accomodated already.

// steps:
//  1. we will be sorting both the arrival and departure time arrays. this will lead to loss of a train's
//      info on when it arrived or departed but thats not how we will look into the qn.
//  2. the earliest arriving train will take up 1 platform that will be the max by then. -> initials
//  3. then, we put two pointers, i pointing to the arrival array and j to the departing array. As we 
//     already counted for the first arriving train, i will be pointed at 1, and j at 0.
//  4. a while loop till we take care of all trains: now if the ith train arrives before or even at 
//     the same time as the departure of the jth train, we will be needing one more platform, while if 
//     the jth train departed before the new train arrival one plaform will be free.  



int findPlatform(int arr[], int dep[], int n)
{
    
    sort(arr, arr + n);
    sort(dep, dep + n);

    int plat_needed = 1;
    int maxPlatform = 1;

    int i = 1;
    int j = 0;

    while ( i < n && j < n){

        if(arr[i] <= dep[j]){
            plat_needed ++;
            i++;
        }
        else if (arr[i] > dep[j]){
            plat_needed --;
            j++;
        }

        maxPlatform = max(maxPlatform, plat_needed);
    }
    return maxPlatform;
}