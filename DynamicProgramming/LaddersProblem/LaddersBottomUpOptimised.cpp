/*  
*   Created by CLion IDE.
*   Author: Kshitij Varshney (kshitijvarshne1)
*   Date: 22-Nov-20
*   Time: 6:41 PM
*   File: LaddersBottomUpOptimised.cpp
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

int ladders_bottomUp(int n, int k) {
    int dp[100] = {0};
    dp[0] = dp[1] = 1;
    for (int i = 2; i <= k; i++) {
        dp[i] = 2 * dp[i - 1];
    }
    for (int i = k + 1; i <= n; i++) {
        dp[i] = 2 * dp[i - 1] - dp[i - k - 1];
    }
    return dp[n];
}

int main() {
    int n, k;
    cin >> n >> k;
    cout << ladders_bottomUp(n, k);
    return 0;
}