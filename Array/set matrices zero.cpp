#include<iostream>
using namespace std;
#include<vector>

class Solution {
public:

    // extra space na li garna lai, marker ko lagi kunai element chodenan constraints ma.
    // use 1st row and column as marker.
    // and 2 flags for row 0 and col 0.

    void setZeroes(vector<vector<int>>& matrix) {
            int row0 = -1;
            int col0 = -1;
            int m = matrix.size();
            int n = matrix[0].size();

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(matrix[i][j] == 0){
                    if(i == 0) row0 = 0;
                    else matrix[i][0] = 0;

                    if(j == 0) col0 = 0;
                    else matrix[0][j] = 0;
                }
            }
        }

        // forget the first row and column, will deal later
        // so tyo row0 col0 wala ni jhanjhat bhaena.
        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){

                if(matrix[i][j] != 0){
                    if(matrix[i][0] == 0 || matrix[0][j] == 0){
                        matrix[i][j] = 0;
                    }
                }
            }
        }

        // taking care of 1st row and 1st column
        if(row0 == 0){
            for(int j = 0; j < n; j++){
                matrix[0][j] = 0;
            }
        }

        if(col0 == 0){
            for(int i = 0; i < m; i++){
                matrix[i][0] = 0;
            }
        }

    }
};