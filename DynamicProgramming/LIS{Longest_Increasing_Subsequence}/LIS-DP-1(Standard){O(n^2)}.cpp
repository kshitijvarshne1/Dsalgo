/*  
*   Created by CLion IDE.
*   Author: Kshitij Varshney (kshitijvarshne1)
*   Date: 24-Nov-20
*   Time: 12:05 PM
*   File: LIS-DP-1(Standard){O(n^2)}.cpp
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
    int dp[n];
    for (int i = 0; i < n; i++) {
        dp[i] = 1;
        for (int j = 0; j < i; j++) {
            if (a[j] < a[i]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    int lis = 0;
    for (int i = 0; i < n; i++) {
        lis = max(lis, dp[i]);
    }
    cout << lis;
    return 0;
}
