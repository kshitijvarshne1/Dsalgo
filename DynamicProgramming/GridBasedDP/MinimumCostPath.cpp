/*  
*   Created by CLion IDE.
*   Author: Kshitij Varshney (kshitijvarshne1)
*   Date: 24-Nov-20
*   Time: 10:55 PM
*   File: MinimumCostPath.cpp
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

using namespace std;

int minCost(int cost[][100], int r, int c, int dp[100][100]) {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (i == 0 and j == 0) {
                dp[i][j] = cost[0][0];
            } else if (i == 0) {
                dp[i][j] = dp[0][j - 1] + cost[0][j];
            } else if (j == 0) {
                dp[i][j] = dp[i - 1][0] + cost[i][j];
            } else {
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + cost[i][j];
            }
        }
    }
    return dp[r - 1][c - 1];
}

int main() {
    int r, c;
    cin >> r >> c;
    int cost[100][100];
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> cost[i][j];
        }
    }
    int dp[100][100] = {0};
    cout << minCost(cost, r, c, dp);
    cout << endl;
    return 0;
}
