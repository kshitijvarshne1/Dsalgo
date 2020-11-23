/*  
*   Created by CLion IDE.
*   Author: Kshitij Varshney (kshitijvarshne1)
*   Date: 23-Nov-20
*   Time: 7:51 PM
*   File: RodCuttingProblemDpBased.cpp
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

int maxProfitDp(int prices[], int n) {
    int dp[n + 1];
    dp[0] = 0;
    for (int len = 1; len <= n; len++) {
        int ans = INT_MIN;
        for (int i = 0; i < len; i++) {
            int cut = i + 1;
            int currentAns = prices[i] + dp[len - cut];
            ans = max(currentAns, ans);
        }
        dp[len] = ans;
    }
    return dp[n];
}

int main() {
    int prices[] = {1, 5, 8, 9, 10, 17, 17, 20};
    int n = sizeof(prices) / sizeof(int);
    cout << maxProfitDp(prices, n);
    return 0;
}