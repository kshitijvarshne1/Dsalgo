/*  
*   Created by CLion IDE.
*   Author: Kshitij Varshney (kshitijvarshne1)
*   Date: 26-Oct-20
*   Time: 6:55 PM
*   File: FastPower.cpp
*/
# include<iostream>
# include<climits>
# include<cmath>
# include<algorithm>
# include<bits/stdc++.h>
# include<cstring>
# include<iomanip>
# include<vector>

using namespace std;

int fastPower(int a, int n) {
    int ans = 1;
    while (n > 0) {
        int last_bit = (n & 1);
        if (last_bit) {
            ans = ans * a;
        }
        a = a * a;
        n = n >> 1;
    }
    return ans;
}

int main() {
    long long int a, n;
    cin >> a >> n;
    cout << fastPower(a, n);
    return 0;
}

