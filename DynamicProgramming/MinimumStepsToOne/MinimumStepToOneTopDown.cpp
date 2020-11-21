/*  
*   Created by CLion IDE.
*   Author: Kshitij Varshney (kshitijvarshne1)
*   Date: 22-Nov-20
*   Time: 12:42 AM
*   File: MinimumStepToOneTopDown.cpp
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
// find minimum steps to 1
//n->n/2
//n->n/3
//n=n-1

int minSteps(int n, int dp[]) {
    if (n == 1) {
        return 0;
    }
    if (dp[n] != 0) {
        return dp[n];
    }
    int op1, op2, op3;
    op1 = op2 = op3 = INT_MAX;
    if (n % 2 == 0) {
        op1 = minSteps(n / 2, dp) + 1;
    }
    if (n % 3 == 0) {
        op2 = minSteps(n / 3, dp) + 1;
    }
    op3 = minSteps(n - 1, dp) + 1;
    int ans = min(min(op1, op2), op3);
    return dp[n] = ans;
}

int main() {
    int n;
    cin >> n;
    int dp[10000] = {0};
    cout << minSteps(n, dp);
    return 0;
}
