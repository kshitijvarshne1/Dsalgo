/*  
*   Created by CLion IDE.
*   Author: Kshitij Varshney (kshitijvarshne1)
*   Date: 26-Nov-20
*   Time: 12:31 PM
*   File: CellMitosis.cpp
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

# define mod 10000000007
using namespace std;

int solveCellProblem(int n, int x, int y, int z) {
    int *dp = new int[n + 1];
    dp[0] = 0;
    dp[1] = 0;
    for (int i = 2; i <= n; i++) {
        if (i % 2 == 0) {
            dp[i] = min(dp[i / 2] = x, dp[i - 1] + y);
        } else {
            dp[i] = min(dp[i - 2] + y, dp[(i + 1) / 2] + x + z);
        }
    }
    return dp[n];
}

int main() {
    int n, x, y, z;
    cin >> n >> x >> y >> z;
    cout << solveCellProblem(n, x, y, z);
    return 0;
}
