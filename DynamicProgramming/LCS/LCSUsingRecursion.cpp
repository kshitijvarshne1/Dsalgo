/*  
*   Created by CLion IDE.
*   Author: Kshitij Varshney (kshitijvarshne1)
*   Date: 23-Nov-20
*   Time: 9:36 PM
*   File: LCSUsingRecursion.cpp
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

int lcs(string s1, string s2, int i, int j) {
    if (i == s1.length() or j == s2.length()) {
        return 0;
    }
    if (s1[i] == s2[j]) {
        return 1 + lcs(s1, s2, i + 1, j + 1);
    }
    int op1 = lcs(s1, s2, i, j + 1);
    int op2 = lcs(s1, s2, i + 1, j);
    return max(op1, op2);
}


int main() {
    string s1, s2;
    cin >> s1 >> s2;
    cout << lcs(s1, s2, 0, 0);

    return 0;
}