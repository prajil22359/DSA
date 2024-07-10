// do dfs in each of the components of the graph and output them in increasing order whenever a choice.
// different components lai chutta chuttai line ma print garaunu

// NOTE : this code is currently in undirected edges mode : see in line 21

#include <iostream>
using namespace std;
#include <unordered_map>
#include <vector>
#include <list>
#include <queue>
#include <set>

void prepareAdjList( unordered_map<int, set<int> > &adjList, vector<vector<int> > &edges){
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        // undirected edge
        adjList[u].insert(v);
        adjList[v].insert(u);
    }
}

void dfsHelper(unordered_map<int, set<int> > &adjList, unordered_map<int, bool> &visited, vector<int> &component, int i){
    component.push_back(i);
    visited[i]=true;
    for (auto j: adjList[i]){
        if(!visited[j]){
            dfsHelper(adjList, visited, component, j);
        }
    }
}

vector<vector<int>> DFS (int V, vector<vector<int>> &edges)
{
    // Write your code here
    unordered_map<int, set<int> > adjList;
    vector<vector<int>> ans;
    unordered_map<int, bool> visited;

    prepareAdjList(adjList, edges);

    // traverse all components of a graph, yadi disconnected cha bhane yesle help garcha
    for(int i=0; i< V; i++){
        if(!visited[i]){
            vector<int> component;
            dfsHelper(adjList, visited, component, i);
            ans.push_back(component);
        }
    }
    return ans;
}
  
// printing all components separately.
void printAns(vector<vector<int>> ans)
{
    for(auto i: ans){
        for(auto j: i){
            cout<<j<<" ";
    }
    cout<<endl;
    }
}


int main()
{   
    int n, m;
    cin>>n;
    cin>>m;
    vector < vector<int> > edges;
    for (int i = 0; i < m; i++)
    {   
        int u,v;
        cin >> u;
        cin >> v;
        vector<int> temp;
        temp.push_back(u);
        temp.push_back(v);
        edges.push_back(temp);
    }
    printAns(DFS(n, edges));
}
// if need in sorted preference to neighbours use set, insert is used instead of push_back as in list.