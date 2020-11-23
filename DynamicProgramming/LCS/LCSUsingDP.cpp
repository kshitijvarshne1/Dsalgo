/*  
*   Created by CLion IDE.
*   Author: Kshitij Varshney (kshitijvarshne1)
*   Date: 23-Nov-20
*   Time: 9:43 PM
*   File: LCSUsingDP.cpp
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

int lcs(string s1, string s2, int i, int j, vector<vector<int>> &dp) {
    if (i == s1.length() or j == s2.length()) {
        return 0;
    }
    //check if a state is already computed or not
    if (dp[i][j] != -1) {
        return dp[i][j];
    }
    if (s1[i] == s2[j]) {
        return dp[i][j] = 1 + lcs(s1, s2, i + 1, j + 1, dp);
    }
    int op1 = lcs(s1, s2, i, j + 1, dp);
    int op2 = lcs(s1, s2, i + 1, j, dp);
    return dp[i][j] = max(op1, op2);
}


int main() {
    string s1, s2;
    cin >> s1 >> s2;
    int n1 = s1.length();
    int n2 = s2.length();
    vector<vector<int>> dp(n1, vector<int>(n2, -1));
    cout << lcs(s1, s2, 0, 0, dp);

    return 0;
}
