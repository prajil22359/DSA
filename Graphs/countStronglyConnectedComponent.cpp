# include <iostream>
using namespace std;
#include <unordered_map>
#include <vector>
#include <list>
#include <stack>
#include <set>

// Kosaraju Algo for finding strongly connected components in directed graphs.

// to do dfs, wrapper function ko lagi euta order chahiyo. tyo order ke ho bhane reverse postorder of reverse of G
// reverse postorder bhaneko : topological sort order


void prepAdjList( vector<vector<int>> &edges, int isDirected,unordered_map<int, list<int>> &adjList, int toReverse){
	for(auto i : edges){

        if(toReverse==0){
		    adjList[i[0]].push_back(i[1]);
	    }

        // if you are making adjList for reverse of G.
        else{
            adjList[i[1]].push_back(i[0]);
        }
    }
}

void findTopoSort( unordered_map<int, list<int>> &adjListofReverseofG,stack<int> &stackForTopoOrderofReverseofG, vector<bool> &visited, int node)
{
    visited[node] = true;
    for(auto neighbour : adjListofReverseofG[node]){
        if(!visited[neighbour]){
            findTopoSort(adjListofReverseofG, stackForTopoOrderofReverseofG, visited, neighbour);
        }
    }
    stackForTopoOrderofReverseofG.push(node);
}

void DFSofG( unordered_map<int, list<int>> &adjList,vector<bool> &visitedAgain, int node, set<int> &component)
{
    visitedAgain[node] = true;
    for(auto neighbour : adjList[node]){
        if(!visitedAgain[neighbour]){
            DFSofG(adjList, visitedAgain, neighbour, component);
        }
    }
    component.insert(node);
}


int stronglyConnectedComponents(int v, vector<vector<int>> &edges)
{

	unordered_map<int, list<int>> adjList;
	// Write your code here.
	prepAdjList(edges, 1, adjList, 0);

    unordered_map<int, list<int>> adjListofReverseofG;

    prepAdjList(edges, 1, adjListofReverseofG, 1);

    stack<int> stackForTopoOrderofReverseofG;
    vector<bool> visited(v, false);

    for(int i = 0; i < v; i++ ){
        if(!visited[i])
            findTopoSort(adjListofReverseofG, stackForTopoOrderofReverseofG, visited, i);
    }

    // to track visited nodes for DFS
	vector<bool> visitedAgain(v, false);

    int count = 0;
	while(!stackForTopoOrderofReverseofG.empty()){
        int node = stackForTopoOrderofReverseofG.top();
        stackForTopoOrderofReverseofG.pop();
        set<int> component;
        if(!visitedAgain[node]){
            count = count+1;
            DFSofG(adjList, visitedAgain, node, component);
        }

        // print strong components
        for(auto i: component){
            cout<<i<<" ";
        }
        cout<<endl;
    }
    return count;

}