/*  
*   Created by CLion IDE.
*   Author: Kshitij Varshney (kshitijvarshne1)
*   Date: 12-Nov-20
*   Time: 4:03 PM
*   File: SlidingWindowTwoPointerApproach.cpp
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

int main() {
    string s, t;
    getline(cin, s);
    getline(cin, t);
    int n = s.size(), m = t.size();
    int l = 0, r;
    map<char, int> freq_s, freq_t;
    int resl = -1, resr = 1e9;
    for (auto x:t) {
        freq_t[x]++;
    }
    for (r = 0; r < n; r++) {
        freq_s[s[r]]++;
        bool good = true;
        for (auto x:freq_t) {
            // x is { char,int}
            if ((freq_s.count(x.first) == 0 || freq_s[x.first < x.second])) {
                good = false;
                break;
            }
        }
        // string window 1 to r is not good
        if (!good)continue;
        //otherwise it is a good window
        // move 1 forward for every r
        while (l < n && l <= r && (freq_t.count(s[l]) == 0 || freq_s[s[l]] > freq_t[s[l]])) {
            freq_s[s[l]]--;
            if (freq_s[s[l]] == 0) freq_s.erase(s[l]);
            l++;
        }

        if (resr - resl + 1 > r - l + 1) {
            resl = l;
            resr = r;
        }
    }
    // cout << l << " " << r << endl;
    //cout<<resl<<" "<<resr;
    if (resl == -1) {
        cout << "No String";
    } else {
        cout << s.substr(resl, resr - resl + 1);
    }

    return 0;
}
