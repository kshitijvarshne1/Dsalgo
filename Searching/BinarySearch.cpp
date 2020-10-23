/*  
*   Created by Clion IDE.
*   Author: Kshitij Varshney (kshitijvarshne1)
*   Date: 22-Oct-20
*   Time: 7:45 PM
*   File: binary_search.cpp
*/
# include<iostream>
# include<climits>
# include<algorithm>
# include<bits/stdc++.h>
# include<cstring>
# include<iomanip>

using namespace std;

int binary_search(int ar[], int s, int e, int x) {
    while (s <= e) {
        int m = s + (e - s) / 2;
        if (ar[m] == x)
            return m;
        if (ar[m] < x)
            s = m + 1;
        else
            e = m - 1;
    }
    return -1;
}

int main() {
    int n, key;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cin >> key;
    cout << binary_search(a, 0, n - 1, key);
    return 0;
}


