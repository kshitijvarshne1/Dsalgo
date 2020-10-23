/*  
*   Created by CLion IDE.
*   Author: Kshitij Varshney (kshitijvarshne1)
*   Date: 23-Oct-20
*   Time: 10:05 PM
*   File: RatInMaze.cpp
*/
# include<iostream>
# include<climits>
# include<algorithm>
# include<bits/stdc++.h>
# include<cstring>
# include<iomanip>

using namespace std;

bool ratInMaze(char maze[][10], int soln[][10], int i, int j, int m, int n) {
    //Base Case
    if (i == m && j == n) {
        soln[m][n] = 1;
        for (int i = 0; i <= m; i++) {
            for (int j = 0; j <= n; j++) {
                cout << soln[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
        return true;
    }
    //Rat should be inside in a grid
    if (i > m || j > n) {
        return false;
    }
    if (maze[i][j] == 'X') {
        return false;
    }
    //Asume solution exists through current cell
    soln[i][j] = 1;
    //Recursive case
    bool rightSuccess = ratInMaze(maze, soln, i, j + 1, m, n);
    bool downSuccess = ratInMaze(maze, soln, i + 1, j, m, n);
    //Backtracking
    soln[i][j] = 0;
    if (rightSuccess || downSuccess) {
        return true;
    }
    return false;
}

int main() {
    int m, n;
    cin >> m >> n;
    char maze[10][10];
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> maze[i][j];
        }
    }
    /*
     * char maze[10][10]={
     *                     OXOO
     *                     OOOX
     *                     OOXO
     *                     XOOO
     *                     XXOO
     *                   };
     */
    int soln[10][10] = {0};
    bool ans = ratInMaze(maze, soln, 0, 0, m - 1, n - 1);
    if (ans == false) {
        cout << "No paths";
    }
    return 0;
}

