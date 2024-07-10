// qn is to count no. of trapped cells, that has no reach to an edge.
// yadi euta connected component ko kunai ni node if is in edge position, 
// then all elements there are free.
// kasari garne ta, bfs call garne sabai component ko lagi. check if any element is in edge,
// if yes turn flag true. Then, after full traversal in component, if it remains false i.e they are trapped cells,
// return node count in that component, else if its true return 0. Sum it over all components

#include<iostream>
using namespace std;
#include<vector>
#include<queue>

int bfs(vector<vector<int>> &Matrix, pair<int, int> source, vector<vector<bool>> &visited, int N, int M){
    queue<pair<int, int>> line;
    bool flag =false;
    vector<pair<int, int>> nodeInThisComponent;

    //initialization of BFS
    line.push(source);
    visited[source.first][source.second]=true;
    nodeInThisComponent.push_back(source); // don't forget

    while(!line.empty()){
        pair<int, int> node = line.front();
        line.pop();
        
        // kunai node yo component ko if lies in edge -> queue ma sab neighbour with 0 aihalchan,
        // so yaha check garda best.
        if(node.first == 0 || node.second == 0 || node.first == N-1 || node.second == M-1){
            flag = true;
        }  

        int dx[]={-1,1,0,0};
        int dy[]={0,0,-1,1};

        for (int i = 0; i < 4; i++)
        {
            int newX = node.first + dx[i];
            int newY = node.second +dy[i]; 

            if(newX>=0 && newX<N && newY>=0 && newY<M){
                if(Matrix[newX][newY] == 0 && !visited[newX][newY]){
                    line.push({newX, newY});
                    visited[newX][newY]=true;
                    nodeInThisComponent.push_back({newX, newY});

                }
            }
        }
    }

    // no node in edge, i.e the component has no reach to edge: trapped
    if(flag==false){
        int trapCellsCount = nodeInThisComponent.size();
        return trapCellsCount;
    }
    else{
        return 0;
    }
}

int matrixTraps(int N,int M,vector<vector<int>> &Matrix)
{
    vector<vector<bool>> visited(N, vector<bool>(M, false));
    int trappedCells = 0;
    // Write your code here.
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if(Matrix[i][j]==0 && !visited[i][j]){
                trappedCells += bfs(Matrix, {i,j}, visited, N, M);
            }
        }   
    }
    return trappedCells;
}
