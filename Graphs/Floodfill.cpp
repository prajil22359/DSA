// floodfill opration is a bfs operation.
// non diagonal neighbours bhanepachi mathi, tala, right, left index
// see dx, dy array creation to enable changes in x, y 

#include<iostream>
using namespace std;
#include<queue>
#include<vector>


void bfs( vector<vector<int>> &image, vector<vector<bool>> &visited, int x, int y, int p, int c){
    queue<pair<int, int>> line;
    line.push({x,y});
    image[x][y]=p;
    visited[x][y]=true;

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
            if(newX>=0 && newX<image.size() && newY>=0 && newY<image[0].size()){
                if (image[newX][newY] == c && !visited[newX][newY]){
                    image[newX][newY] = p;
                    visited[newX][newY] = true;
                    line.push({newX, newY});
                }
            }
        }
    }
}


vector<vector<int>> floodFill(vector<vector<int>> &image, int n, int m, int x, int y, int p) {
    // Write your code here.

    vector<vector<bool>> visited(n, vector<bool>(m, false));
    int c = image[x][y];
    bfs (image, visited, x, y, p, c);
    return image;
}