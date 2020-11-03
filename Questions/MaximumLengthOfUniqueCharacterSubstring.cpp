/*  
*   Created by CLion IDE.
*   Author: Kshitij Varshney (kshitijvarshne1)
*   Date: 03-Nov-20
*   Time: 12:18 PM
*   File: MaximumLengthOfUniqueCharacterSubstring.cpp
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

using namespace std;
//Maximum length of unique length substring
int main() {
    char a[10000];
    cin >> a;

    int n = strlen(a);
    int current_len = 1;
    int max_len = 1;

    int visited[256];

    for (int i = 0; i < 256; i++) {
        visited[i] = -1;
    }
    //OR int visited[256]={-1};

    visited[a[0]] = 0;

    for (int i = 1; i < n; i++) {
        int last_occ = visited[a[i]];

        //Expansion
        if (last_occ == -1 || i - current_len > last_occ) {
            current_len += 1;
        }
            //Expansion + Contraction
        else {
            if (current_len > max_len) {
                max_len = current_len;
            }
            current_len = i - last_occ;
        }
        visited[a[i]] = i;
    }

    if (current_len > max_len) {
        max_len = current_len;
    }
    cout << max_len << endl;
    return 0;
}

