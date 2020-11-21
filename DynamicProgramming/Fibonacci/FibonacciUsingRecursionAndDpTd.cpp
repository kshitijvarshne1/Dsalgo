/*  
*   Created by CLion IDE.
*   Author: Kshitij Varshney (kshitijvarshne1)
*   Date: 21-Nov-20
*   Time: 11:33 PM
*   File: FibonacciUsingRecursionAndDpTD.cpp
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
//nth fibonacci number using recursion and DP->O(n)
//Top Down Approach
int nthFib(int n, int dp[]) {
    //Base case
    if (n == 0 or n == 1) {
        return n;
    }
    if (dp[n] != 0) {
        return dp[n];
    }
    int ans;
    ans = nthFib(n - 1, dp) + nthFib(n - 2, dp);
    return dp[n] = ans;
}

int main() {
    int n;
    cin >> n;
    int dp[10000] = {0};
    cout << nthFib(n, dp);
    return 0;
}
