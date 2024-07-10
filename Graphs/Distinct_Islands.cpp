#include<iostream>
using namespace std;
#include<list>
#include<vector>
#include<unordered_map>


int dfs(vector<vector<int>> &grid, pair<int,int> node, vector<vector<bool>> &visited, vector<pair<int,int>> &component, bool flag){

    visited[node.first][node.second]=true;
    int n = grid.size();
    int m = grid[0].size();

    component.push_back(node);

    if(node.first==0 || node.first==n-1 || node.second==0 || node.second==m-1){
        flag=true;
    }
    int dx[]={1,-1,0,0};
    int dy[]={0,0,1,-1};

    for (int i = 0; i < 4; i++)
    {
        int newX = node.first + dx[i];
        int newY = node.second + dy[i];

        if(newX>=0 && newY >=0 && newX<n && newY<m){
            if(!visited[newX][newY] && grid[newX][newY]==1){
                dfs(grid,{newX,newY}, visited, component, flag);
            }
        }
    }
    return component.size();
}


int numEnclaves(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();

    int count = 0;
    bool flag = false;
    vector<vector<bool>> visited(n,vector<bool>(m, false));
    vector<pair<int,int>> component;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if(grid[i][j]==1 && !visited[i][j]){
                int x = dfs(grid, {i,j}, visited, component,flag);
                if(flag==true){
                    count+=0;
                }
                else{
                    count += x;
                }
            }
        }
    }
}
