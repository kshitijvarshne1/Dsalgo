/*  
*   Created by CLion IDE.
*   Author: Kshitij Varshney (kshitijvarshne1)
*   Date: 22-Nov-20
*   Time: 1:01 AM
*   File: MinimumStepToOneBottomUp.cpp
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
//Down up approach
int minSteps(int n) {
    int dp[1000] = {0};
    dp[1] = 0;
    for (int i = 2; i <= n; i++) {
        int op1, op2, op3;
        op1 = op2 = op3 = INT_MAX;
        if (n % 3 == 0) {
            op1 = dp[i / 3];
        }
        if (n % 2 == 0) {
            op2 = dp[i / 2];
        }
        op3 = dp[i - 1];
        dp[i] = min(min(op1, op2), op3) + 1;
    }
    return dp[n];
}

int main() {
    int n;
    cin >> n;
    cout << minSteps(n);

    return 0;
}