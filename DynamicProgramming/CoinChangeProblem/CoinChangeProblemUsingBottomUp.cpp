/*
*   Created by CLion IDE.
*   Author: Kshitij Varshney (kshitijvarshne1)
*   Date: 22-Nov-20
*   Time: 2:14 AM
*   File: CoinChangeProblemUsingBottomUp.cpp
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

int minCoins(int Num, int coins[], int t) {
    int dp[1000] = {0};

    for (int n = 1; n <= Num; n++) {
        dp[n] = INT_MAX;
        for (int i = 0; i < t; i++) {
            if (n - coins[i] >= 0) {
                int subProblem = dp[n - coins[i]];
                dp[n] = min(dp[n], subProblem + 1);
            }
        }
    }
    return dp[Num];
}
int main() {
    int n;
    cin >> n;
    int coins[] = {1, 7, 10};
    int t = sizeof(coins) / sizeof(int);
    cout << minCoins(n, coins, t);
    return 0;
}