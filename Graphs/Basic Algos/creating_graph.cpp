# include<iostream>
#include <unordered_map>
#include <list>
using namespace std;

// this is for making a generic graph,
// template <typename T>

class Graph{
  
public:
    unordered_map<int, list<int>> adj;
    
    void addEdge(int u, int v, bool direction){
        // direction = 0 -> undirected
        // direction =1 -> directed graph

        //create an edge from u to v
        adj[u].push_back(v);

        // if it says undirected, put edge from other side as well
        if(direction==0){
            adj[v].push_back(u);
        }
    }

    void printAdjList(){
        for(auto i: adj){
            cout << i.first << "->";
            for(auto j: i.second){
                cout<< j<< ", ";
            }
            cout << endl;
        }
    }

};

int main(){

    int n;
    cout<<"enter no. of vertices ";
    cin>>n;

    int m;
    cout<<"enter no. of edges ";
    cin>>m;

    Graph g;
    
    cout<<"enter the edges ";

    for(int i=0; i<m;i++){
        int u;
        int v;
        cin>> u>>v;

        //creating an undirected graph
        g.addEdge(u,v,0);
    }

    g.printAdjList();
} 