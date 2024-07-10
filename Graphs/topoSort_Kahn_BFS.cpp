
// Kahn's algo -> steps: 
// 1. find indegree of all vertices. add whichever vertex has indegree 0 into the BFS queue. 
// 2. pop from queue, put it in ans vector, look upto the neighbours of that vertex, decrease their indegree by 1; 
//    if anyone's indegree gets to 0 add it in the queue.
// 3. will work till queue gets empty.


#include <iostream>
using namespace std;
#include <unordered_map>
#include <vector>
#include <list>
#include <queue> 

void prepareAdjList( unordered_map<int, list<int> > &adjList, vector<vector<int> > &edges){
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        //directed so..
        adjList[u].push_back(v);      
    }
}
void kahnTopoSort(unordered_map<int, list<int> > &adjList, vector<bool> &visited, vector<int> &ans, int node, vector<int> &indegree)
{
    queue<int> q;
    for (int i =0; i< indegree.size(); i++){
        if (indegree[i]==0)
            q.push(i);
        }
    
    while(!q.empty()){
        int node = q.front();
        q.pop();
        ans.push_back(node);
        visited[node]=1;

        // neighbour indegree update
        for(auto neighbour: adjList[node]){
            indegree[neighbour]--;
            if(indegree[neighbour]==0){
                q.push(neighbour);
            }
        }
    }
}


vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    // Write your code here
    unordered_map<int, list<int> > adjList;
    vector<int> ans;
    vector< bool> visited(v);

    prepareAdjList(adjList, edges);

    vector<int> indegree(v,0); 

    // find indegree of all vertices
    for(auto node : adjList){
        for (auto j: node.second){
            indegree[j]++;
        }
    }

    // traverse all components of a graph, yadi disconnected cha bhane yesle help garcha
    for(int i=0; i< v; i++){
        if(!visited[i]){
            kahnTopoSort(adjList, visited, ans, i, indegree);
        }
    }
    return ans;
}

void printAns(vector<int> ans)
{
    for(auto i: ans){
        cout << i<< " ";
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
    printAns(topologicalSort(edges, n, m));
}




