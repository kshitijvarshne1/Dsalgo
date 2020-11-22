/*  
*   Created by CLion IDE.
*   Author: Kshitij Varshney (kshitijvarshne1)
*   Date: 22-Nov-20
*   Time: 12:55 PM
*   File: WinesSaleProblem.cpp
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
int profit(int wines[], int i, int j, int y, int dp[][100]) {
    if (i > j) {
        return 0;
    }
    if (dp[i][j] != 0) {
        return dp[i][j];
    }
    int op1 = wines[i] * y + profit(wines, i + 1, j, y + 1, dp);
    int op2 = wines[j] * y + profit(wines, i, j - 1, y + 1, dp);
    return dp[i][j] = max(op1, op2);
}

int main() {
    int wines[] = {2, 3, 5, 1, 4};
    int n = sizeof(wines) / sizeof(int);
    int dp[100][100] = {0};
    int year = 1;
    cout << profit(wines, 0, n - 1, year, dp);

    return 0;
}

