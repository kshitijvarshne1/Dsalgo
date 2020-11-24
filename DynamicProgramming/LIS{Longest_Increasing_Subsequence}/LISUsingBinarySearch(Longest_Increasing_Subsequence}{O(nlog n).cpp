/*  
*   Created by CLion IDE.
*   Author: Kshitij Varshney (kshitijvarshne1)
*   Date: 24-Nov-20
*   Time: 1:51 PM
*   File: LISUsingBinarySearch(Longest_Increasing_Subsequence}{O(nlog n).cpp
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
int main() {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int dp[n + 1];
    dp[0] = INT_MIN;

    for (int i = 1; i <= n; i++) {
        dp[i] = INT_MAX;
    }

    for (int i = 0; i <= n; i++) {
        int length = upper_bound(dp, dp + n + 1, a[i]) - dp;
        if (dp[length - 1] < a[i] && a[i] < dp[length]) {
            dp[length] = a[i];
        }
    }
    int lis = 0;
    for (int i = 1; i <= n; i++) {
        if (dp[i] != INT_MAX) {
            lis = i;
        }
    }
    cout << lis;
    return 0;
}