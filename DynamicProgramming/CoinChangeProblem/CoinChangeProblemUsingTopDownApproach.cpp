/*  
*   Created by CLion IDE.
*   Author: Kshitij Varshney (kshitijvarshne1)
*   Date: 22-Nov-20
*   Time: 1:58 AM
*   File: CoinChangeProblemUsingTopDownApproach.cpp
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
int minCoins(int n, int coins[], int t, int dp[]) {
    if (n == 0) {
        return 0;
    }
    if (dp[n] != 0) {
        return dp[n];
    }
    int ans = INT_MAX;
    for (int i = 0; i < t; i++) {
        if (n - coins[i] >= 0) {
            int subproblem = minCoins(n - coins[i], coins, t, dp);
            ans = min(ans, subproblem + 1);
        }
    }
    dp[n] = ans;
    return dp[n];
}

int main() {
    int n;
    cin >> n;
    int coins[] = {1, 7, 10};
    int t = sizeof(coins) / sizeof(int);
    int dp[1000] = {0};
    cout << minCoins(n, coins, t, dp);

    return 0;
}
