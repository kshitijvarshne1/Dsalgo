/*  
*   Created by CLion IDE.
*   Author: Kshitij Varshney (kshitijvarshne1)
*   Date: 22-Nov-20
*   Time: 5:27 PM
*   File: LaddersTopDown.cpp
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

int ladders_topdown(int n, int k, int dp[]) {
    if (n == 0) {
        return 1;
    }
    if (dp[n] != 0) {
        return dp[n];
    }
    int ways = 0;
    for (int i = 1; i <= k; i++) {
        if (n - i >= 0) {
            ways = ways + ladders_topdown(n - i, k, dp);
        }
    }
    return dp[n] = ways;
}

int main() {
    int n, k;
    cin >> n >> k;
    int dp[1000] = {0};
    cout << ladders_topdown(n, k, dp);
    return 0;
}