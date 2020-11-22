/*  
*   Created by CLion IDE.
*   Author: Kshitij Varshney (kshitijvarshne1)
*   Date: 22-Nov-20
*   Time: 6:17 PM
*   File: LaddersBottomUp.cpp
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
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        dp[i] = 0;
        for (int j = 1; j <= k; j++) {
            if (i - j >= 0) {
                dp[i] = dp[i] + dp[i - j];
            }
        }
    }
    return dp[n];
}

int main() {
    int n, k;
    cin >> n >> k;
    cout << ladders_bottomUp(n, k);
    return 0;
}