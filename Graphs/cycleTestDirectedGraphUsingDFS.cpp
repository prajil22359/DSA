// do dfs in each of the components of the graph and output them in increasing order whenever a choice.
// different components lai chutta chuttai line ma print garaunu
#include <iostream>
using namespace std;
#include <unordered_map>
#include <vector>
#include <list>


void prepareAdjList( unordered_map<int, list<int> > &adjList, vector<vector<int> > &edges){
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        cout<< u << " "<< v << endl;

        //directed so..
        adjList[u].push_back(v);
      
    }
}

bool testCycle(unordered_map<int, list<int> > &adjList, unordered_map<int, bool> &visited, int node, unordered_map<int, bool> &activityStatus)
{
    visited[node]=true;
    activityStatus[node]=true;
    for (auto neighbour: adjList[node]){
        
        // self loop
        if(neighbour == node){
			return true;
		}

        if(!visited[neighbour]){
            bool cycleDetected = testCycle(adjList, visited, neighbour, activityStatus);
            if(cycleDetected){
                return true;
            }
        }
        else if(activityStatus[neighbour]==true){
            return true;
        }    
    }
    activityStatus[node]=false;
    return false;
}


// taking input
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
    unordered_map<int, bool> activityStatus;

    prepareAdjList(adjList, edges);

    // the wrapper fn 
    // nodes numbered from 0 to N
    for(int i=0; i< n; i++){
        if(!visited[i]){
            bool status = testCycle(adjList, visited, i, activityStatus);
            if(status==true){
                cout<<"has cycle";
                return 0;
            }
        }
    }
    cout<< "no cycle";
}
// if need in sorted preference to neighbours use set, insert is used instead of push_back as in list.