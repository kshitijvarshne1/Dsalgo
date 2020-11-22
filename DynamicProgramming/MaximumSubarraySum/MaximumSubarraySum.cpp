/*  
*   Created by CLion IDE.
*   Author: Kshitij Varshney (kshitijvarshne1)
*   Date: 22-Nov-20
*   Time: 3:14 PM
*   File: MaximumSubarraySum.cpp
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
//Using Dp->Bottom up
int maxSum(int a[], int n) {
    int dp[100] = {0};
    dp[0] = a[0] > 0 ? a[0] : 0;
    int maxSoFar = a[0];
    for (int i = 1; i < n; i++) {
        dp[i] = dp[i - 1] + a[i];
        if (dp[i] < 0) {
            dp[i] = 0;
        }
        maxSoFar = max(dp[i], maxSoFar);
    }
    return maxSoFar;
}

int main() {
    int a[] = {-3, 2, 5, -1, 6, 3, -2, 7, -5, 2};
    int n = sizeof(a) / sizeof(int);
    cout << maxSum(a, n);
    return 0;
}