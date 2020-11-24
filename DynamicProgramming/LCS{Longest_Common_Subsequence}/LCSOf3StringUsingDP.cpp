/*  
*   Created by CLion IDE.
*   Author: Kshitij Varshney (kshitijvarshne1)
*   Date: 24-Nov-20
*   Time: 11:22 AM
*   File: LCSOf3StringUsingDP.cpp
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

int lcs(string s1, string s2, string s3, int i, int j, int k, vector<vector<vector<int >>> &dp) {
    if (i == s1.length() or j == s2.length() or k == s3.length()) {
        return 0;
    }
    //check if a state is already computed or not
    if (dp[i][j][k] != -1) {
        return dp[i][j][k];
    }
    if (s1[i] == s2[j] and s1[i] == s3[k]) {
        return dp[i][j][k] = 1 + lcs(s1, s2, s3, i + 1, j + 1, k + 1, dp);

    }
    int op1 = lcs(s1, s2, s3, i, j + 1, k, dp);
    int op2 = lcs(s1, s2, s3, i + 1, j, k, dp);
    int op3 = lcs(s1, s2, s3, i, j, k + 1, dp);
    return dp[i][j][k] = max(op1, max(op2, op3));
}

int main() {
    string s1, s2, s3;
    cin >> s1 >> s2 >> s3;
    int n1 = s1.length();
    int n2 = s2.length();
    int n3 = s3.length();
    vector<vector<vector<int>>> dp(n1, vector<vector<int> >(n2, vector<int>(n3, -1)));
    cout << lcs(s1, s2, s3, 0, 0, 0, dp);
    return 0;
}