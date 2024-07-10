#include <iostream>
using namespace std;
#include <unordered_map>
#include <set>
#include <vector>

int main(){

    int n, m, l;
    cin >> n >> m >> l;
    int u, v;
    set <pair<int, int>> edges;
    unordered_map<int, vector<int>> adjList;

    for(int i = 0; i < m; i++){
        cin >> u >> v;
        edges.insert(make_pair(u, v));
        edges.insert(make_pair(v, u));
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    int ans = 0;
    for(auto i : adjList){
        int count = 0;
        int node = i.first;
        vector<int> temp = i.second;

        for(int k = 0; k < temp.size(); k++){
            for(int l = k+1; l < temp.size(); l++){
                if(edges.find({temp[k],temp[l]}) != edges.end()){
                    count++;
                }
            }
        }
        if(count >= l){
            ans++;
        }
    }
    cout << ans;

}