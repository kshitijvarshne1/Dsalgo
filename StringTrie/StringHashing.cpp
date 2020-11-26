/*
*   Created by CLion IDE.
*   Author: Kshitij Varshney (kshitijvarshne1)
*   Date: 26-Nov-20
*   Time: 9:56 PM
*   File: StringHashing.cpp
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

#define ll long long int
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

    string text = "abababab", pat = "aba";
    cout << poly_hash_string(text);

    return 0;
}