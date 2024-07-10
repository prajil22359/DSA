// LRU implement garna vector nai use garau.
#include <iostream>
using namespace std;
#include <vector>
#include <algorithm> 

// Below is the brute force code using vector. It works well, but the thing is find, erase operators in vector
// are not optimised ops. So use set and map together instead. set ma insert erase find optimised hunchan,
// ani ordering for LRU page find garna map use garne. tyasma index store gareko huncha. See In LEET CODE EDITORIAL.

 
// the code is self explanatory.
int pageFaults(int N, int C, int pages[]){

    vector <int> memory;
    int pageFaults = 0;
    for (int i = 0; i < N; i++){
        auto it = find(memory.begin(), memory.end(), pages[i]);
        if (it != memory.end()) {
            memory.erase(it);
            memory.push_back(pages[i]);
        } 
        else {
            memory.push_back(pages[i]);
            pageFaults++;

            // only if the cache is exceeded by last push, we erase from beginning.
            if(memory.size() > C){
                memory.erase(memory.begin());
            }
        }
    }
    return pageFaults;  
}