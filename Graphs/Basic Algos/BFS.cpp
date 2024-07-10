#include <iostream>
using namespace std;
#include <unordered_map>
#include <vector>
#include <list>
#include <queue>

// undirected.

void prepareAdjList( unordered_map<int, list<int> > &adjList, vector<pair<int, int> > &edges){
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;

        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
}
  
void bfsHelper(unordered_map<int, list<int> > &adjList,unordered_map<int, bool> &visited, vector<int> &ans, int node)
{
    queue<int> q;
    q.push(node);
    visited[node]=true;

    while(!q.empty()){
        int frontNode =q.front();
        q.pop();

        //store frontNode int ans
        ans.push_back(frontNode);

        //traverse all neighbours of frontNode
        for (auto i: adjList[frontNode]){
            if(!visited[i]){
                q.push(i);
                visited[i]=1;
            }
        }
    }
}

vector<int> BFS (int n, vector <pair<int, int> > &edges)
{
    unordered_map<int, list<int> > adjList;
    vector<int> ans;
    unordered_map<int, bool> visited;

    prepareAdjList(adjList, edges);

    // traverse all components of a graph, yadi disconnected cha bhane yesle help garcha
    for(int i=0; i< n; i++){
        if(!visited[i]){
            bfsHelper(adjList, visited, ans, i);
        }
    }
    return ans;
}

void printAns(vector<int> ans)
{
    for(auto i: ans){
        cout<<i;
    }
}

int main()
{   
    int n, m;
    cin>>n;
    cin>>m;
    vector <pair<int, int> > edges;
    for (int i = 0; i < m; i++)
    {   
        int u,v;
        cin >> u;
        cin >> v;
        edges.push_back(make_pair(u, v));
    }
    printAns(BFS(n, edges));
}

// ans vector will have the bfs traversal order.
// list ki jaga set rakhlo fir sorted order mein miljaega