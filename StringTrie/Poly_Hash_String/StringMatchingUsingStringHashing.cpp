/*  
*   Created by CLion IDE.
*   Author: Kshitij Varshney (kshitijvarshne1)
*   Date: 27-Nov-20
*   Time: 12:24 AM
*   File: StringMatchingUsingStringHashing.cpp
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

# define ll long long int
# define modValue 1e9 + 7
const ll mod = 1e9 + 7;
const ll p = 31;
using namespace std;

ll poly_hash_string(string s) {
    ll p_power = 1;
    ll hash = 0;
    for (ll i = 0; i < s.size(); i++) {
        hash += (p_power * (s[i] - 'a' + 1));
        p_power *= p;
        p_power %= mod;
        hash %= mod;
    }
    return hash;
}
int main() {
    /*ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    */
    string text = "ababab", pat = "aba";
    int pat_hash = poly_hash_string(pat);
    int n = text.size(), m = pat.size();

    for (int i = 0; i + m <= n; i++) {
        int new_hash = poly_hash_string(text.substr(i, m));
        if (new_hash == pat_hash) {
            cout << "YES at " << i << endl;
        }
    }

    return 0;
}

