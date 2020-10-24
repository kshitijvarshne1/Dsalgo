/*  
*   Created by CLion IDE.
*   Author: Kshitij Varshney (kshitijvarshne1)
*   Date: 24-Oct-20
*   Time: 9:34 PM
*   File: NQueensCountOutcomes.cpp
*/
# include<iostream>
# include<climits>
# include<cmath>
# include<algorithm>
# include<bits/stdc++.h>
# include<cstring>
# include<iomanip>

using namespace std;

bool isSafe(int board[][100], int i, int j, int n) {
    //You can check for col
    for (int row = 0; row < i; row++) {
        if (board[row][j] == 1) {
            return false;
        }
        //You can check for for first left diagonal
        int x = i;
        int y = j;
        while (x >= 0 && y >= 0) {
            if (board[x][y] == 1) {
                return false;
            }
            x--;
            y--;

        }
        //You can check for right diagonal
        x = i;
        y = j;
        while (x >= 0 && y < n) {
            if (board[x][y] == 1) {
                return false;
            }
            x--;
            y++;
        }
    }
    //The Position is now safe for col and diagonal
    return true;
}

int nQueen(int board[][100], int i, int j, int n) {
    //Base case
    if (i == n) {
        //you have successfully place queens in n rows(0...n-1)
        // print the board
        //   ways++;
        //   cout<<"ways:-"<<ways<<endl;
        return 1;
    }
    int cnt = 0;
    //Recusive case
    //Try to place the queen in the urrent reo and call on the remaining part which will be solved by recursion
    for (int j = 0; j < n; j++) {
        // I have to check if i,j th position is safe to place the queen or not
        if (isSafe(board, i, j, n)) {
            //place the queen -Assuming i,j is the right position
            board[i][j] = 1;
            cnt += nQueen(board, i + 1, j, n);
            //Means i,j is not right position
            board[i][j] = 0;  //Backtracking
        }
    }
    return cnt;
}

int main() {
    int n;
    cin >> n;
    int board[100][100] = {0};
    cout << nQueen(board, 0, 0, n);
    return 0;
}


