/*  
*   Created by CLion IDE.
*   Author: Kshitij Varshney (kshitijvarshne1)
*   Date: 13-Dec-20
*   Time: 9:44 PM
*   File: Sudoku.cpp
*/
# include<iostream>
# include<bits/stdc++.h>
# include<climits>
# include<cmath>
# include<algorithm>
# include<cstring>
# include<iomanip>
# include<vector>
# include<stack>
# include<queue>
# include<map>
# include<unordered_map>
# include<unordered_set>

# define modValue 1e9 + 7
# define ll long long int
# define N 9
using namespace std;

bool isSafe(int board[N][N], int row, int col, int num) {

    for (int d = 0; d < N; d++) {

        if (board[row][d] == num) {
            return false;
        }
    }

    for (int r = 0; r < N; r++) {

        if (board[r][col] == num) {
            return false;
        }
    }
    int s = (int) sqrt(N);
    int boxRowStart = row - row % s;
    int boxColStart = col - col % s;

    for (int r = boxRowStart;
         r < boxRowStart + s; r++) {
        for (int d = boxColStart;
             d < boxColStart + s; d++) {
            if (board[r][d] == num) {
                return false;
            }
        }
    }
    return true;
}

bool solve(int board[N][N], int n) {
    int row = -1;
    int col = -1;
    bool isEmpty = true;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] == 0) {
                row = i;
                col = j;
                isEmpty = false;
                break;
            }
        }
        if (!isEmpty) {
            break;
        }
    }

    if (isEmpty) {
        return true;
    }

    for (int num = 1; num <= n; num++) {
        if (isSafe(board, row, col, num)) {
            board[row][col] = num;
            if (solve(board, n)) {
                // print(board, n);
                return true;
            } else {
                board[row][col] = 0;
            }
        }
    }
    return false;
}

void printGrid(int grid[N][N]) {
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++)
            cout << grid[row][col] << " ";
        cout << endl;
    }
}

int main() {   /*ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    */

    int grid[N][N] = {{3, 0, 6, 5, 0, 8, 4, 0, 0},
                      {5, 2, 0, 0, 0, 0, 0, 0, 0},
                      {0, 8, 7, 0, 0, 0, 0, 3, 1},
                      {0, 0, 3, 0, 1, 0, 0, 8, 0},
                      {9, 0, 0, 8, 6, 3, 0, 0, 5},
                      {0, 5, 0, 0, 9, 0, 6, 0, 0},
                      {1, 3, 0, 0, 0, 0, 2, 5, 0},
                      {0, 0, 0, 0, 0, 0, 0, 7, 4},
                      {0, 0, 5, 2, 0, 6, 3, 0, 0}};
    if (solve(grid, N) == true)
        printGrid(grid);
    else
        cout << "No solution exists";
    return 0;
}

