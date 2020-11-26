/*  
*   Created by CLion IDE.
*   Author: Kshitij Varshney (kshitijvarshne1)
*   Date: 26-Nov-20
*   Time: 5:57 PM
*   File: StringMatchingBruteForce.cpp
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

void matching(string txt, string pattern, int m, int n) {
    int c = 1;
    for (int i = 0; i < m; i++) {
        if (txt.substr(i, n) == pattern) {
            cout << " YES " << endl;
            cout << " from the index " << i;
            c == 0;
        }
    }
    if (c) {
        cout << "No";
    }
}

int main() {
    string txt = "abaacadabacad";
    string pattern = "aaca";
    int m = txt.size();
    int n = pattern.size();
    matching(txt, pattern, m, n);

    return 0;
}

