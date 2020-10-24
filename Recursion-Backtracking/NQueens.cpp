/*  
*   Created by CLion IDE.
*   Author: Kshitij Varshney (kshitijvarshne1)
*   Date: 24-Oct-20
*   Time: 1:41 PM
*   File: NQueens.cpp
*/
# include<iostream>
# include<climits>
# include<algorithm>
# include<bits/stdc++.h>
# include<cstring>
# include<iomanip>

using namespace std;

bool isSafe(int board[][10], int i, int j, int n) {
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

bool nQueen(int board[][10], int i, int j, int n) {
    //Base case
    if (i == n) {
        //you have successfully place queens in n rows(0...n-1)
        // print the board
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 1) {
                    cout << "Q ";
                } else {
                    cout << "_";
                }
            }
            cout << endl;
        }
        cout << endl;
        return false;
    }
    //Recusive case
    //Try to place the queen in the urrent reo and call on the remaining part which will be solved by recursion
    for (int j = 0; j < n; j++) {
        // I have to check if i,j th position is safe to place the queen or not
        if (isSafe(board, i, j, n)) {
            //place the queen -Assuming i,j is the right position
            board[i][j] = 1;
            bool nextQueenCanBePutUp = nQueen(board, i + 1, j, n);
            if (nextQueenCanBePutUp) {
                return true;
            }
            //Means i,j is not right position
            board[i][j] = 0;  //Backtracking
        }
    }
    return false;
}

int main() {
    int n;
    cin >> n;
    int board[][10] = {0};
    nQueen(board, 0, 0, n);
    return 0;
}

