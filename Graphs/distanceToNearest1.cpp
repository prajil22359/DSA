// distance when we try to solve manually is nothing but bfs levels,
// level 0 for wherever there is 1 initially.


#include<iostream>
using namespace std;
#include<queue>
#include<vector>


void bfs( vector<vector<int>> &mat,int n, int m){
    queue<pair<int, int>> line;
    vector<vector<bool>> visited(n, vector<bool>(m, false));

// bfs kaha bata start garne, all those cells with 1, so add all of them in queue with level / distance 0.
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if(mat[i][j]==1){
                line.push({i,j});
                visited[i][j]=true;
                mat[i][j]=0;
            }
        }   
    }

    while(!line.empty()){
        pair<int, int> node= line.front();
        line.pop();

        // Array to represent the possible directions: up, down, left, right
        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        // Check each direction
        for (int i = 0; i < 4; ++i) {
            int newX = node.first + dx[i];
            int newY = node.second + dy[i];

            if(newX>=0 && newX<mat.size() && newY>=0 && newY<mat[0].size()){
                if (mat[newX][newY] == 0 && visited[newX][newY]==false){
                    mat[newX][newY] = mat[node.first][node.second]+1;
                    line.push({newX, newY});
                    visited[newX][newY]=true;
                }
            }
        }
    }
}


vector < vector < int > > nearest(vector < vector < int >> & mat, int n, int m) {
    // Write your code here.
    bfs(mat, n, m);
    return mat;
}