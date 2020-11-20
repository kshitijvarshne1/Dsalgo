/*  
*   Created by CLion IDE.
*   Author: Kshitij Varshney (kshitijvarshne1)
*   Date: 20-Nov-20
*   Time: 10:53 PM
*   File: FLoodFillAlgo.cpp
*/
# include<iostream>
# include<climits>
# include<cmath>
# include<algorithm>
# include<bits/stdc++.h>
# include<cstring>
# include<iomanip>
# include<vector>
# include<stack>
# include<queue>
# include<map>
# include<unordered_map>
# include<unordered_set>

using namespace std;
int R, C;
int dx[] = {-1, 0, 1, 0}; //{west,north,east,south}
int dy[] = {0, -1, 0, 1};

void floodFill(char mat[][50], int i, int j, char ch, char color) {
    //Base case ->Matrix bounds
    if (i <= 0 || j < 0 || i >= R || j >= C) {
        return;
    }
    //Figure Boundary condition
    if (mat[i][j] != ch) {
        return;
    }
    //Recursive boundary condition
    mat[i][j] = color;
    for (int k = 0; i < 4; k++) {
        floodFill(mat, i + dx[k], j + dy[k], ch, color);
    }
}

int main() {


    cin >> R >> C;
    char input[15][50];
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> input[i][j];
        }
    }
    floodFill(input, 8, 13, '.', '&');
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cout << input[i][j];
        }
        cout << endl;
    }

    return 0;
}

