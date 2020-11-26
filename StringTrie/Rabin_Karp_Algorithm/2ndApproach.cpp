/*  
*   Created by CLion IDE.
*   Author: Kshitij Varshney (kshitijvarshne1)
*   Date: 27-Nov-20
*   Time: 1:06 AM
*   File: 2ndApproach.cpp
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
// Rabin kalp algorithm
// 2nd approach using prefix sum
ll power(ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b & 1) {
            res *= a;
            res %= mod;
        }
        b /= 2;
        a *= a;
        a %= mod;
    }
    return res;
}

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

    string text = "aaaaaaaaaaaaa", pat = "aaaa";
    int pat_hash = poly_hash_string(pat);
    int n = text.size(), m = pat.size();
    int pref[n];

    for (int i = 0; i < n; i++) {
        pref[i] = (text[i] - 'a' + 1) * power(p, i);
        pref[i] %= mod;
    }
    for (int i = 1; i < n; ++i) {
        pref[i] += pref[i - 1];
        pref[i] %= mod;
    }
    for (int i = 0; i < n; ++i) {
        //Substring from s[l.....r]
        //r=i+m-1
        int new_hash = pref[i + m - 1];
        if (i - 1 >= 0) {
            new_hash -= pref[i - 1];
        }
        new_hash += mod;
        new_hash %= mod;
        if (new_hash == (pat_hash * power(p, i)) % mod) {
            cout << "Yes at " << i << endl;
        }
    }
    return 0;
}

