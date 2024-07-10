#include <bits/stdc++.h> 
// dijkstra algo : for finding shortest path in a weighted graph : directed or undirected,
// the qn here though is for undirected, the important thing is it doesnot work for negative weights.
// How we solve : apart from source node who will be at distance 0, all other vertices are initially
// marked at infinity distance.
// the loop is : we pick node with the smallest distance among unvisited vertex, mark them visited 
// and try relax the distance of other vertex, to which there is an edge.
// we can use priority queue / min heap or set for tracking the node with least distance.
// it is accurate to say that which ever node is marked visited is based on if it is the smallest distance 
// among the unvisited now, so certainly any other positive edge wont relax it more.

#include <iostream>
using namespace std;
#include <vector>
#include <unordered_map>
#include <list>
#include <set>

void prepAdjList(vector<vector<int>> &edges, int isDirected,unordered_map<int, list<pair<int,int>>> &adjList ){
    for (auto i : edges){
        adjList[i[0]].push_back(make_pair(i[1], i[2]));
        if(isDirected==0){
            adjList[i[1]].push_back(make_pair(i[0], i[2]));  // both direction being undirected
        }
    }
}

vector<int> solve(vector<vector<int>> &edges, int n, int source){

    unordered_map<int, list<pair<int,int>>> adjList;
    // 0 for undirected edges
    prepAdjList(edges, 0, adjList);

    // node count from 0 to n-1, source node is 0.
    vector <int> distance(n);
    set <pair<int, int>> setToTrackMinDistanceUnvisitedNode;

    for(int i=0 ; i<n; i++){
        distance[i]=INT32_MAX;
        setToTrackMinDistanceUnvisitedNode.insert({INT32_MAX, i});
    }
    
    setToTrackMinDistanceUnvisitedNode.erase({distance[0], 0}); // Remove old distance from set
    distance[0] = 0; // updated distance of source
    setToTrackMinDistanceUnvisitedNode.insert({distance[0], 0}); // Insert updated distance into set

    while(!setToTrackMinDistanceUnvisitedNode.empty()){

        auto minNode = *setToTrackMinDistanceUnvisitedNode.begin(); // First element of set is the smallest
        int node = minNode.second; // Get the node
        int dist = minNode.first; // Get the distance

        // if at this point a node is still at infinity distance means, it's unreachable,
        // and it doesnot make sense to relax other edges based on an unreachable node,
        // it would not have been too much of problem except for the integer overflow issue.
        // as we could add INT_MAX with 10^5 and get a negative value, could use 1e9 and solve it as well.

        if(distance[node]!=INT32_MAX){
            for( auto neighbour: adjList[node]){
                if( distance[neighbour.first] > distance[node] + neighbour.second){
                    setToTrackMinDistanceUnvisitedNode.erase({distance[neighbour.first], neighbour.first }); // Remove old distance from set
                    distance[neighbour.first] = distance[node] + neighbour.second;
                    setToTrackMinDistanceUnvisitedNode.insert({distance[neighbour.first], neighbour.first }); // Insert updated distance into set
                }
            }
        }
        setToTrackMinDistanceUnvisitedNode.erase({distance[node], node }); // Remove old distance from set
    }

    return distance;
}

vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges,
                     int source) {
    // Write your code here.
    return solve(vec, vertices, source);
}
