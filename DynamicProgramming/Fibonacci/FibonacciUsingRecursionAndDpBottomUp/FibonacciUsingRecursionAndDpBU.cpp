/*  
*   Created by CLion IDE.
*   Author: Kshitij Varshney (kshitijvarshne1)
*   Date: 21-Nov-20
*   Time: 11:48 PM
*   File: FibonacciUsingRecursionAndDpBU.cpp
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
//nth fibonacci number using recursion and DP Time->O(n) spcace ->o(n)
//Bottom up approach
int nthFib(int n) {
    int dp[10000] = {0};
    dp[1] = 1;

    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}

int main() {
    int n;
    cin >> n;
    cout << nthFib(n);
    return 0;
}