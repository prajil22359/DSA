#include <bits/stdc++.h>
using namespace std;

// prefix sum and lower_bound concept.

int main(){
    int n, m;
    cin >> n;
    cin >> m;
    int temp;
    vector <int> arr;
    arr.push_back(0);
    for(int i = 1; i < n + 1; i++){
        cin >> temp;
        arr.push_back(temp + arr[i-1]);
    }

    int l, s;
    for(int i = 0; i < m; i++){
        cin >> l;
        cin >> s;

        int ans = s + arr[l-1];
        // harek ko lagi prefix sum nikalna wont work optimally. 
        // what we need to understand is
        // s is sum from A[l] to A[r]. however in A[l] we have A[1] to A[l] and in A[r] we have A[1] to A[r].
        // so if I add A[l-1] to s, that will be A[r], so yes we can use lower_bound.

        auto it = lower_bound(arr.begin(), arr.end(), ans);
        if(it == arr.end()){
            cout << -1;
        }
        else{
            int index = it - arr.begin();
            cout << index;
        }
        cout << endl;

    }
}
