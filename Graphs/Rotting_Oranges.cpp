
#include<iostream>
using namespace std;
#include<queue>
#include<vector>

class Solution {
public:
    // adjacent cells (4 directional) in grid, feels like bfs
    // sabai 2 bhako cell ko 4 directional neighbour ma yadi 1 bhae 2 garne, also keep in queue,
    // to further track their neighbours. Multithreading ta hunna, but sabailai source bhani level 0 ma 
    // queue ma halne, then normal dfs. level bhanekai minTime bhaihalcha.
    // lvl x samma cha bhane x time lagne bho rott huna

    // maxlevel track garana jaroori chaina, tree ma level wise traversal garda level track garna for loop
    // lagauchau ni ho tyahi loop laga ani check gar ki while loop kati choti chalirahacha.that will give us 
    // idea for max level. 


    void bfs( vector<vector<int>> &grid, vector<vector<int>> &level, int n, int m){
        queue<pair<int, int>> line;

        // bfs kaha bata start garne, all those cells with 2, so add all of them in queue with level 0.
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if(grid[i][j]==2){
                    line.push({i,j});
                    level[i][j]=0;
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

                if(newX>=0 && newX<grid.size() && newY>=0 && newY<grid[0].size()){
                    // visited track garina, didn't feel it was needed, 1 unvisited cell ma matra huna sakcha,
                    // repetition is not possible, ek choti bfs garepachi pheri 1 rahadaina
                    if (grid[newX][newY] == 1){
                        grid[newX][newY] = 2;

                        // updating child's level
                        level[newX][newY] = level[node.first][node.second]+1;
                        line.push({newX, newY});
                    }
                }
            }
        }
    }

    int minTimeToRot(vector<vector<int>>& grid, int n, int m)
    {
        // Write your code here. 
        vector<vector<int>> level(n, vector<int>(m, 0));    
        bfs(grid, level, n, m);
        int maximumLevel = 0;

        // check if fresh oranges still in any grid
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if(grid[i][j]==1){
                    return -1;
                }
            }   
        }

        // if no fresh oranges, track the maximum level of dfs, that's the min time taken to rott all oranges.
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                maximumLevel = max( maximumLevel, level[i][j] );
            }
        }
        return maximumLevel;

    }

    int orangesRotting(vector<vector<int>>& grid) {
        return minTimeToRot(grid, grid.size(), grid[0].size());
    }
};