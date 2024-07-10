#include <iostream>
using namespace std;
#include <vector>
#include <algorithm> 

// her 0/1 knapsack ma ya ta purai le nabhae na le bhanne thyo, tara fractional knapsack ma you can take
// any item in fractions. --> task is again to maximize the value.

// the greedy approach says, take that item thats most valuable first, but considering its weight.
// it says, best value per unit weight dine item uthaudai jane ho. this way maximizing the value of our 
// knapsack. yadi max value/weight item purai lida ni hamro knapsack bharisakena bhane, tyaspachi ko 
// valuable item uthaune.

struct Item{
    int value;
    int weight;
};

static bool cmp( pair<double, Item> a, pair<double, Item> b){
    // descending
    return a.first > b.first;
}

// Function to get the maximum total value in the knapsack.
double fractionalKnapsack(int w, Item arr[], int n) {
    
    vector <pair<double, Item>> v; 
    
    for(int i = 0; i < n; i++){
        double valWtRatio = ((1.0)*arr[i].value) / arr[i].weight; 
        // dubai int bhako karan euta lai double gareko
        v.push_back( make_pair(valWtRatio, arr[i]));
    }
    
    sort(v.begin(), v.end(), cmp);
    
    double value = 0;
    for(int i = 0; i < n; i++){
        
        // euta case ki purai ith item halna sakincha knapsack ma
        if(w >= v[i].second.weight){
            value += v[i].second.value;
            w -= v[i].second.weight;
        }

        // else jaba fractional matra lina sakincha
        else{ 
            value = value + v[i].first * w;
            w = 0;
        }

        // please ensure you have updated both value and weight.
    }
    return value;
    
}