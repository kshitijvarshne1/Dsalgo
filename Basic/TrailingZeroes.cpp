/*  
*   Created by CLion IDE.
*   Author: Kshitij Varshney (kshitijvarshne1)
*   Date: 29-Oct-20
*   Time: 4:21 PM
*   File: TrailingZeroes.cpp
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

int findZeores(int n) {
    int ans = 0;
    for (int i = 5; n / i >= 1; i = i * 5) {
        ans = ans + (n / i);
    }
    return ans;
}

int main() {
    long long int n;
    cin >> n;
    cout << findZeores(n);

}

