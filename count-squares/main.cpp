//
//  main.cpp
//  count-squares
//
//  Created by mndx on 24/04/2022.
//

#include <iostream>
#include <vector>

using namespace std;

int num_sq(vector<vector<int>> & matrix, int row, int col, int n) {
    int num_squares = 0;
    int num_ones = 0;
    
    int n_r = (int) matrix.size();
    int n_c = (int) matrix[0].size();
    
    for(int r = row; (r < row + n) && r < n_r; ++r) {
        for(int c = col; (c < col + n) && c < n_c; ++c) {
            if(matrix[r][c] == 1) {
                num_ones++;
            }
        }
    }
    
    bool all_ones = num_ones == n * n;
    
    if(all_ones) {
        num_squares = 1 + num_sq(matrix, row, col, n + 1);
    }
    
    return num_squares;
}

int count_squares(vector<vector<int>> & matrix) {
    int num_squares = 0;
    
    int m = (int) matrix.size();
    int n = (int) matrix[0].size();
    
    for(int r = 0; r < m; ++r) {
        for(int c = 0; c < n; ++c) {
            num_squares = num_squares + num_sq(matrix, r, c, 1);
        }
    }
    
    return num_squares;
}

int main(int argc, const char * argv[]) {
    
    vector<vector<int>> matrix = {{0,1,1,1},{1,1,1,1},{0,1,1,1}};
    
    int num_squares = count_squares(matrix);
    
    cout << num_squares << endl;
    
    return 0;
}
