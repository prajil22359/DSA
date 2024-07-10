// topoSort is just the descending postOrdering of verices in DFS
// whichever node gets out of DFS recursion stack is put into answer stack for lifo. 
// jo sabse pehle nikla wo last mein hoga topoSort mein.
// The ans thus is whatever is printed from this answer stack.

// topoSort only makes sense in dag so directed graph


//ALERT : might not pass in large test cases: wherever possible use vector instead on map, to quicken up.

#include <iostream>
using namespace std;
#include <unordered_map>
#include <vector>
#include <list>
#include <stack>

void prepareAdjList( unordered_map<int, list<int> > &adjList, vector<vector<int> > &edges){
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        //directed so..
        adjList[u].push_back(v);      
    }
}

void topoSort(unordered_map<int, list<int> > &adjList, unordered_map<int, bool> &visited, int node, stack<int> &answer)
{
    visited[node]=true;
    for (auto neighbour: adjList[node]){
        if(!visited[neighbour]){
            topoSort(adjList, visited, neighbour, answer);
        }
    }
    answer.push(node);
}

void printAns(vector<int> ans)
{
    for(auto i: ans){
        cout << i << " ";
    }
}

// // taking input
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

    unordered_map<int, list<int> > adjList;
    unordered_map<int, bool> visited;
    stack<int> answer;

    prepareAdjList(adjList, edges);

    // the wrapper fn 
    // nodes numbered from 0 to N-1
    for(int i=0; i< n; i++){
        if(!visited[i]){
            topoSort(adjList, visited, i, answer);
        }
    }

    vector<int> ans;

    while(!answer.empty()){
        ans.push_back(answer.top());
        answer.pop();
    }
    printAns(ans);
}
// // if need in sorted preference to neighbours use set, insert is used instead of push_back as in list.