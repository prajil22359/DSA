// Jaha pani O dekhiyo, we call bfs there, so all connected components get called once,
// if they oblige to be bounded by X, its good, we store them in a vector, and later when bfs call ends,
// we update in our character array.
// The main logic is:
// 1. its either the whole component that becomes an island or none from there.
// 2. we track how the bfs call ends? 
//          Its either X or O, bfs will keeping pushing neighbours as it finds O in its 4 directional 
//          neighbours, if its not O its X, so good, boundary there. 

// kura ho bfs yadi naturally end huncha, by the queue getting empty, means we found a component
// where all the nodes have X as boundaries, so great accepted as island.
// iif its returned going out of bounds in search of O, means even the last  element was O
// so no boundary of X there, so rejected. 
// But wait, we dont want to return before marking all member of this unaccepted component visited,
// as that troubles later, justifying the use of flag.


#include <iostream>
using namespace std;
#include <vector>
#include<queue>

void fun(char** &arr, pair<int,int> coordinate, int n, int m, vector<vector<bool>> &visited){
    queue<pair<int,int>> line;
    vector<pair<int, int>> nodesInThisComponent;
    bool flag = false;

    // bfs initialization
    line.push(coordinate);
    visited[coordinate.first][coordinate.second]=true;

    while(line.empty()==false){

        pair<int,int> node = line.front();
        nodesInThisComponent.push_back(node);
        line.pop();
        
        int dx[]={-1,1,0,0};
        int dy[]={0,0,-1,1};

        for (int i = 0; i < 4; i++)
        {
            int newX=node.first + dx[i];
            int newY= node.second + dy[i];
            
            // checking within bounds
            if(newX>=0 && newX<n && newY>=0 && newY<m){
                if(arr[newX][newY]=='O' && visited[newX][newY]== false){
                    nodesInThisComponent.push_back({newX, newY}); 
                    line.push({newX, newY});
                    visited[newX][newY]=true;
                }
            }
            else{
                // BFS call gets out of bound, didnt got X as boundary, the component failed as island.
                // keeping flag, so that we atleast visit all the connected components, 
                // than return in first case we find it. 
                flag = true;
            }
        }
    }
    if(flag==true){
        return;
    }

    // if doesnot go out of bound and return, mark them all X
    for(auto i: nodesInThisComponent){
        arr[i.first][i.second]='X';
    }
}

void replaceOWithX(char** arr, int n, int  m)
{
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    for(int i=0; i<n; i++){
        for (int j = 0; j<m; j++)
        {
            // wont be calling again if we have already tried that a vertex from that component.
            if(!visited[i][j] && arr[i][j]=='O'){
                fun(arr,{i,j}, n, m, visited);
            }
        }
    }
}