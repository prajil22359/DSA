#include<iostream>
using namespace std;
#include<unordered_map>
#include<vector>
#include<list>
#include <stack>
# include <algorithm>


// shortest path in weighted DAG to every vertex for vertex 0;
// positive/  negative weights all okay
// pahilo kura find topological sort.

void makeAdjList(vector<vector<int>>&edges, unordered_map<int, list<pair<int, int>>> &adjList){
    for( auto i: edges){
        adjList[i[0]].push_back({i[1], i[2]});
    }
}

void findTopoSort(unordered_map<int, list<pair<int,int>>> &adjList, stack<int> &s, unordered_map<int, bool> &visited, int node){
    visited[node]=true;
    for(auto neighbour: adjList[node]){
        if(!visited[neighbour.first]){
            findTopoSort(adjList, s, visited, neighbour.first);
        }
    }
    s.push(node);
}

void shortestPath(stack<int> &s, vector<int> &distance, int source, unordered_map<int, list<pair<int,int>>> &adjList)
{   
    distance[source]=0;

    while(!s.empty()){
        int node =s.top();
        s.pop();


        // yo kam sabaiko lagi garne hoina, only from source nodes, so the if cond, and topological sort
        if(distance[node]!=1e9){
            for(auto neighbour : adjList[node]){
                distance[neighbour.first]= min(distance[neighbour.first],(distance[node]+neighbour.second));
            }
        }
    }

// ans needs -1 for vertices that cant be reached from source.
    for( int i =0; i< adjList.size(); i++){
        if(distance[i]==1e9){
            distance[i]=-1;
        }
    }

}

vector<int> solve(vector<vector<int>>&edges, int n){
    unordered_map<int, list<pair<int,int>>> adjList;
    makeAdjList( edges, adjList);

    // topoSort
    stack<int> s;
    unordered_map<int, bool> visited;

    for (int i = 0; i < n; i++)
    {
        if(!visited[i]){
            findTopoSort(adjList, s, visited, i);
        }
    }

    vector<int> path(n, 1e9);

    shortestPath(s, path, 0, adjList);
    return path;
}




vector<int> shortestPathInDAG(int n, int m, vector<vector<int>> &edges)
{
    // Write your code here
    return solve(edges, n);
}
