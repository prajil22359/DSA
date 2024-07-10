#include <vector>
#include <iostream>
#include <unordered_map>
#include <list>
#include <queue>
#include<algorithm>
using namespace std;

// shortest path according to no. of vertices needed to traverse from source to target.
// also if you say counting any edge with one weight, good. but  not for real weighted vertices.

// simple bfs traversal, we keep track of parent of every node during the traversal. 
// using parent array, we backtrack and find the shortest path between two nodes.
// print out the vertices along the path between source and target



void makeAdjList(vector<pair<int, int>>&edges, unordered_map<int, list<int>> &adjList){
    for( auto i: edges){
        adjList[i.first].push_back(i.second);
        // undirected
        adjList[i.second].push_back(i.first);
    }
}



vector<int> solve(vector<pair<int, int>>&edges, int source, int target ){

    unordered_map<int, list<int>> adjList;
    makeAdjList( edges, adjList);

    queue<int> q;
    q.push(source);

    unordered_map<int, int> visited;
    unordered_map<int, int> parent;

    // wrapper function ko kam chaina, yadi source bata connected nai chaina bhane 
    // matra na bhetiyela yaha bata, in which case print -1e9

	// though in qn given the graph  is connected.


    // making parent array through bfs
    while(!q.empty()){
        int node = q.front();
        q.pop();
        visited[node]=true;

        for(auto neighbour : adjList[node]){
            if(!visited[neighbour]){
                q.push(neighbour);
                parent[neighbour]=node;
                visited[neighbour]=true;
            }
        }
    }

    // backtrack from target to source to find shortest path
    // makes sense to just get back to the lower level from your parent,
    // wont be wasting travelling to other vertices of same level
    // at the end, source is in lvl 0, and target at some level x,
    // so just backtrack to source as it is eventually the ancestor of target

    vector <int> ans;
    int node = target;
    ans.push_back(target);
    while(node!=source){
        node= parent[node];
        ans.push_back(node);
    }
    reverse(ans.begin(), ans.end());
    
    return ans;
}

